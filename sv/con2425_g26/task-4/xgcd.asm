###############################################################################
# Startup code
#
# Initializes the stack pointer, calls main, and stops simulation.
#
# Memory layout:
#   0 ... ~0x300  program
#   0x7F0       Top of stack, growing down
#   0x7FC       stdin/stdout
#
###############################################################################

.org 0x00
_start:                 ADDI sp, zero, 0x7F0
                        ADDI fp, sp, 0

                        # set saved registers to unique default values
                        # to make checking for correct preservation easier
                        LUI s1, 0x11111
                        ADDI s1, s1, 0x111
                        ADD s2, s1, s1
                        ADD s3, s2, s1
                        ADD s4, s3, s1
                        ADD s5, s4, s1
                        ADD s6, s5, s1
                        ADD s7, s6, s1
                        ADD s8, s7, s1
                        ADD s9, s8, s1
                        ADD s10, s9, s1
                        ADD s11, s10, s1

                        JAL ra, main
                        EBREAK

###############################################################################
# Function: xgcd
#
# Computes the extended eucledian algorithm for a given number of times.
# Input and out values are given in the form of an array pointer
#
#
# Input args:
# a0: Number of elements
# a1: Address for array a
# a2: Address for array b
# a3: Address for array x
# a4: Address for array y
# a5: Address for array gcd
#
###############################################################################
xgcd:


###############################################################################
# Function: input
#
# Reads at most 10 values from stdin to input arrays.
#
# Input args:
# a0: Address for array a
# a1: Address for array b
# Return value:
# a0: Number of read elements
#
###############################################################################
input:
                        ADDI t0, a0, 0          # Save a0
                        LW a0, 0x7fc(zero)      # Load size
                        ADDI t1, zero, 10       # Maximum
                        ADDI t2, zero, 0        # Loop counter
before_input_loop:
                        BGE t2, t1, after_input_loop   # Maximum values reached
                        BGE t2, a0,  after_input_loop  # All values read

                        # Read from stdin in store in array a and b
                        LW t3, 0x7fc(zero)
                        LW t4, 0x7fc(zero)
                        SW t3, 0(t0)
                        SW t4, 0(a1)
                        # Pointer increments
                        ADDI t0, t0, 4
                        ADDI a1, a1, 4

                        ADDI t2, t2, 1                  # Increment loop counter
                        JAL zero, before_input_loop     # Jump to loop begin

after_input_loop:       JALR zero, 0(ra)

###############################################################################
# Function: output
#
# Prints input and output values to stdout
#
# Input args:
# a0: Number of elements
# a1: Address for array a
# a2: Address for array b
# a3: Address for array x
# a4: Address for array y
# a5: Address for array gcd
#
###############################################################################
output:
                        BEQ a0, zero, after_output_loop
                        # Load values
                        LW t2, 0(a1)
                        LW t3, 0(a3)
                        LW t4, 0(a2)
                        LW t5, 0(a4)
                        LW t6, 0(a5)

                        # Output Values to stdout
                        SW t2, 0x7fc(zero)
                        SW t3, 0x7fc(zero)
                        SW t4, 0x7fc(zero)
                        SW t5, 0x7fc(zero)
                        SW t6, 0x7fc(zero)

                        # Pointer increments
                        ADDI a1, a1, 4
                        ADDI a2, a2, 4
                        ADDI a3, a3, 4
                        ADDI a4, a4, 4
                        ADDI a5, a5, 4

                        # Decrement loop counter
                        ADDI a0, a0, -1
                        # jump to beginning
                        JAL zero, output

after_output_loop:      JALR zero, 0(ra)

###############################################################################
# Function: main
#
# Calls input, xgcd, and output
#
###############################################################################
main:

                        JALR zero, 0(ra)
