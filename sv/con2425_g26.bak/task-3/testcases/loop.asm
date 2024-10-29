# loop example
# implementation of a loop with 10 iterations
# adding values of stdin and finally printing the sum
    .org 0x00
    ADDI x4, x0, 10     # iteration count
    ADD x3, x0, x0      # clear counter
    ADD x1, x0, x0      # clear x1
                        #    ┌───────────────────────┐
                        #    ↆ                       │
    LW x2, 0x7fc(x0)    # load input                 │
    ADD x1, x1, x2      # x1 += input                │
                        #                            │
    ADDI x3, x3, 1      # counter++                  │
    BLT x3, x4, -12     # if (counter < 10) goto loop_start

    SW x1, 0x7fc(x0)    # output sum
    EBREAK
