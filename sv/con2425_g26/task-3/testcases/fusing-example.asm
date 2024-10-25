# multiplication example with the typical fusion sequence

    .org 0x00
    LUI x1, 0x10101    # load value 0x10101010
    ADDI x1, x1, 0x10

    # 0x10101010 * 0x10101010 == 0x0102030403020100
    MULHU  x2, x1, x1   # == 0x01020304
    MUL    x3, x1, x1   # == 0x03020100

    # Write results to stdout
    SW x2, 0x7fc(x0)
    SW x3, 0x7fc(x0)

    EBREAK

