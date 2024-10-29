# multiplication example with edge cases

    .org 0x00
    ADDI x1, x0, 0x00000001
    ADDI x2, x0, 0x00000002
    LUI x3, 0x80000    # 0x80000000
    ADDI x3, x3, 0x0
    LUI x4, 0x80000    # 0x80000001
    ADDI x4, x4, 0x1


    MUL    x5, x0, x3   # 0 * 2**31                 == 0
    MUL    x6, x1, x3   # 1 * 2**31                 == 2**31
    MUL    x7, x2, x3   # 2 * 2**31 mod 2**32       == 0
    MUL    x8, x2, x4   # 2 * (2**31+1) mod 2**32   == 2
    MULHU  x9, x2, x3   # (2 * 2**31) >> 32         == 1
    MULHU x10, x2, x4   # (2 * (2**31+1)) >> 32     == 1
    MULHU x11, x3, x4   # (2**31 * (2**31+1)) >> 32 == 0x40000000

    # Write results to stdout
    SW x5, 0x7fc(x0)
    SW x6, 0x7fc(x0)
    SW x7, 0x7fc(x0)
    SW x8, 0x7fc(x0)
    SW x9, 0x7fc(x0)
    SW x10, 0x7fc(x0)
    SW x11, 0x7fc(x0)

    EBREAK

