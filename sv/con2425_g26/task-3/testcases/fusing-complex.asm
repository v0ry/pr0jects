# multiplication example with the typical fusion sequence

    .org 0x00
    LUI x1, 0x55555
    ADDI x1, x1, 0x555
    ADDI x2, x0, 0x24

    # 0x55555555 * 0x24 == 0xbfffffff4
    MULHU  x1, x1, x2   # == 0xb
    # 0xb * 0x24 == 0x30
    MUL    x3, x1, x2   # == 0x18c

    ADDI x4, x0, 3
    ADDI x5, x0, 4
    ADDI x6, x0, 5

    # 0x3 * 0x4 == 0xc
    MULHU  x7, x4, x5 # == 0x0
    # 0x4 * 0x5 == 0x14
    MUL    x8, x5, x6 # == 0x14

    ADDI x4, x0, 3
    ADDI x5, x0, 4
    ADDI x6, x0, 5

    # 0x3 * 0x4 == 0xc
    MULHU  x9, x4, x5 # == 0x0
    ADDI x4, x4, 1
    # 0x4 * 0x4 == 0x10
    MUL    x10, x4, x5 # == 0x10

    # Write results to stdout
    SW x1, 0x7fc(x0)
    SW x3, 0x7fc(x0)
    SW x7, 0x7fc(x0)
    SW x8, 0x7fc(x0)
    SW x9, 0x7fc(x0)
    SW x10, 0x7fc(x0)

    EBREAK

