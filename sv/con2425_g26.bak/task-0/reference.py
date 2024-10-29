#!/bin/python

import sys

def lfsr(seed, cycles):
    result = seed
    mask = 0b0000_1000_1000_1100_1000_1000_1001_0010
    for i in range(cycles):
        xor = 0
        for j in range(32):
            if (mask & (1 << j)) != 0:
                if (result & (1 << j)) != 0:
                    xor ^= 1
        result = ((result << 1) | xor) & (2**32 - 1)
    return result

number = sys.argv[1]

print("Reference: {}".format(lfsr(int(sys.argv[1]), 495)))
