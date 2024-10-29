#!/usr/bin/env python3
import argparse
from asmlib import Assembler, Parsing, Riscv, Simulation
from functools import reduce
import os
import sys
import math
import unittest
import operator
from typing import List, Tuple, Optional, Union

LOW_BITS = 0xFFFF_FFFF
HIGH_BITS = 0xFFFF_FFFF << 32


def s2u_32bit(value):
    """Convert a signed [-2**31, 2**31-1] value
    to some unsigned [0, 2**32-1] value
    acc. to two's complement
    """
    assert -2**31 <= value < 2**31, value
    if value >= 0:
        return value
    return 2**32 + value


def u2s_32bit(value):
    """Convert a signed [-2**31, 2**31-1] value
    to some unsigned [0, 2**32-1] value
    acc. to two's complement
    """
    assert 0 <= value < 2**32, value
    if value >= 2**31:
        return -(2**32 - value)
    return value


def mul(factor1: int, factor2: int) -> int:
    """MUL rd, rs1, rs2
    ⇒ value(rs1) = factor1
      value(rs2) = factor2
      value(rd) = return value
    … gives lower bits of product
    """
    assert -2**31 <= factor1 <= 2**31 - 1
    assert -2**31 <= factor2 <= 2**31 - 1
    factor1 = s2u_32bit(factor1)
    factor2 = s2u_32bit(factor2)
    return u2s_32bit((factor1 * factor2) & LOW_BITS)


def mulh(factor1: int, factor2: int) -> int:
    """MULH rd, rs1, rs2
    ⇒ value(rs1) = factor1
      value(rs2) = factor2
      value(rd) = return value
    … gives high bits of signed×signed product
    """
    factor1 = s2u_32bit(factor1)
    factor2 = s2u_32bit(factor2)
    return u2s_32bit(((factor1 * factor2) & HIGH_BITS) >> 32)
    

def mulhsu(factor1: int, factor2: int) -> int:
    """MULHSU rd, rs1, rs2
    ⇒ value(rs1) = factor1
      value(rs2) = factor2
      value(rd) = return value
    … gives high bits of signed×unsigned product
    """
    factor1 = s2u_32bit(factor1)
    return u2s_32bit(((factor1 * factor2) & HIGH_BITS) >> 32)


def mulhu(factor1: int, factor2: int) -> int:
    """MULHU rd, rs1, rs2
    ⇒ value(rs1) = factor1
      value(rs2) = factor2
      value(rd) = return value
    … gives high bits of unsigned×unsigned product
    """
    return u2s_32bit(((factor1 * factor2) & HIGH_BITS) >> 32)


def div(dividend: int, divisor: int) -> int:
    """DIV rd, rs1, rs2
    ⇒ value(rs1) = dividend
      value(rs2) = divisor
      value(rd) = return value
    … gives signed quotient for signed arguments
    """
    if divisor == 0:
        return -1
    elif dividend == -2**31 and divisor == -1:
        return -2**31

    dividend = s2u_32bit(dividend)
    divisor = s2u_32bit(divisor)
    return u2s_32bit((dividend // divisor) & LOW_BITS)


def divu(dividend: int, divisor: int) -> int:
    """DIVU rd, rs1, rs2
    ⇒ value(rs1) = dividend
      value(rs2) = divisor
      value(rd) = return value
    … gives unsigned quotient for unsigned arguments
    """
    if divisor == 0:
        return 2**32-1

    return (dividend // divisor) & LOW_BITS


def rem(dividend: int, divisor: int) -> int:
    """REM rd, rs1, rs2
    ⇒ value(rs1) = dividend
      value(rs2) = divisor
      value(rd) = return value
    … gives signed remainder for signed arguments
    """
    if divisor == 0:
        return dividend
    elif dividend == -2**31 and divisor == -1:
        return 0
    dividend = s2u_32bit(dividend)
    divisor = s2u_32bit(divisor)
    return (dividend % divisor) & LOW_BITS


def remu(dividend: int, divisor: int) -> int:
    """REMU rd, rs1, rs2
    ⇒ value(rs1) = dividend
      value(rs2) = divisor
      value(rd) = return value
    … gives unsigned remainder for unsigned arguments
    """
    if divisor == 0:
        return dividend
    return (dividend % divisor) & LOW_BITS


def update_assembler_isa(isa: List[Union[Assembler.InstDescription, Simulation.InstDescription]],
                         cli_args: argparse.Namespace):
    shared = {'funct7': 0b000001, 'opcode': 0b110011}
    isa.append(Riscv.RType(**shared, mnemonic='MUL',    funct3=0, implementation=mul))
    isa.append(Riscv.RType(**shared, mnemonic='MULH',   funct3=1, implementation=mulh))
    isa.append(Riscv.RType(**shared, mnemonic='MULHSU', funct3=2, implementation=mulhsu))
    isa.append(Riscv.RType(**shared, mnemonic='MULHU',  funct3=3, implementation=mulhu))
    isa.append(Riscv.RType(**shared, mnemonic='DIV',    funct3=4, implementation=div))
    isa.append(Riscv.RType(**shared, mnemonic='DIVU',   funct3=5, implementation=divu))
    isa.append(Riscv.RType(**shared, mnemonic='REM',    funct3=6, implementation=rem))
    isa.append(Riscv.RType(**shared, mnemonic='REMU',   funct3=7, implementation=remu))


update_simulator_isa = update_assembler_isa





class MExtensionTests(unittest.TestCase):
    def test_s2u_32bit(self):
        self.assertEqual(s2u_32bit(-42), 0xFFFF_FFD6)
        self.assertEqual(s2u_32bit( -1), 0xFFFF_FFFF)
        self.assertEqual(s2u_32bit(  0), 0x0000_0000)
        self.assertEqual(s2u_32bit(  1), 0x0000_0001)
        self.assertEqual(s2u_32bit( 42), 0x0000_002A)

        self.assertEqual(s2u_32bit(2**31-1), 2**31-1)
        self.assertEqual(s2u_32bit( -2**31), 0x8000_0000)

    def test_u2s_32bit(self):
        self.assertEqual(u2s_32bit(      0), 0x0000_0000)
        self.assertEqual(u2s_32bit(      1), 0x0000_0001)
        self.assertEqual(u2s_32bit(     42), 0x0000_002A)
        self.assertEqual(u2s_32bit(2**31-1), 2**31-1)
        self.assertEqual(u2s_32bit(  2**31), -2**31)
        self.assertEqual(u2s_32bit(2**32-1), -1)

    def test_mul(self):
        self.assertEqual(mul(0, 1), 0)
        self.assertEqual(mul(1, 0), 0)
        self.assertEqual(mul(1, 1), 1)
        self.assertEqual(mul(2, 1), 2)
        self.assertEqual(mul(2, 2), 4)
        self.assertEqual(mul(2**31-1, 1), 2**31-1)

    def test_mulh(self):
        self.assertEqual(mulh(0x4400_0000, 0x7700_0000), 0x1f9c0000)

    def test_mulhu(self):
        self.assertEqual(mulhu(0xCC00_0000, 0x7700_0000), 0x5ed40000)
        self.assertEqual(mulhu(0x7700_0000, 0xCC00_0000), 0x5ed40000)

    def test_mulhsu(self):
        self.assertEqual(mulhsu(-1, 0x7700_0000), 0x76ffffff)
        self.assertEqual(mulhsu(1, 0xCC00_0000), 0)

    def test_div(self):
        self.assertEqual(div(1, 1), 1)
        self.assertEqual(div(0, 1), 0)
        self.assertEqual(div(2, 1), 2)
        self.assertEqual(div(2**31-1, 2), 2**30-1)
        self.assertEqual(div(42, 0), -1)
        self.assertEqual(div(-2**31, -1), -2**31)

    def test_divu(self):
        self.assertEqual(divu(1, 1), 1)
        self.assertEqual(divu(0, 1), 0)
        self.assertEqual(divu(2, 1), 2)
        self.assertEqual(divu(2**32-1, 2), 2**31-1)

    def test_rem(self):
        self.assertEqual(rem(8, 1), 0)
        self.assertEqual(rem(0, 1), 0)
        self.assertEqual(rem(6, 3), 0)
        self.assertEqual(rem(7, 3), 1)
        self.assertEqual(rem(8, 3), 2)
        self.assertEqual(rem(42, 0), 42)
        self.assertEqual(rem(-2**31, -1), 0)

    def test_remu(self):
        self.assertEqual(remu(8, 1), 0)
        self.assertEqual(remu(0, 1), 0)
        self.assertEqual(remu(6, 3), 0)
        self.assertEqual(remu(7, 3), 1)
        self.assertEqual(remu(8, 3), 2)
        self.assertEqual(remu(42, 0), 42)

if __name__ == '__main__':
    unittest.main()
