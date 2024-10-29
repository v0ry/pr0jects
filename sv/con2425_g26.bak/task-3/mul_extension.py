#!/usr/bin/env python3
import argparse
from asmlib import Assembler, Riscv, Simulation
from typing import List, Union

def mul(rs1, rs2):
    if rs1 < 0:
        rs1 += 2**32
    if rs2 < 0:
        rs2 += 2**32

    result =  ((rs1 * rs2) & 0xFFFF_FFFF_0000_0000) >> 32
    return result

def update_assembler_isa(isa: List[Union[Assembler.InstDescription, Simulation.InstDescription]],
                         cli_args: argparse.Namespace):
    isa.append(Riscv.RType("MUL",   0x33, 0x0, 0x1, lambda rs1, rs2: (rs1 * rs2) & 0x0000_0000_FFFF_FFFF))
    isa.append(Riscv.RType("MULHU", 0x33, 0x3, 0x1, mul))

update_simulator_isa = update_assembler_isa
