# simple multiplication example

    .org 0x00
    ADDI x1, x0, 0x13
    ADDI x2, x0, 0x90
    ADDI x3, x0, 0xA3

    MUL x4, x1, x2    # 19 * 144  == 2736 == 0xAB0
    MUL x5, x1, x3    # 19 * 163  == 3097 == 0xC19
    MUL x6, x2, x3    # 144 * 163 == 23472 == 0x5BB0

    # Write results to stdout
    SW x4, 0x7fc(x0)
    SW x5, 0x7fc(x0)
    SW x6, 0x7fc(x0)

    EBREAK
