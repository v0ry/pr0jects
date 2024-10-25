`define STDIN_FILE  "stdin.txt"
`define STDOUT_FILE "stdout.txt"
`define PAROUT_FILE "parout.txt"

// amount of memory locations to be printed:
`define PRINT_MEM_LOCATIONS 128

// for clock and reset
`define HALF_PERIOD  10
`define RESET_DELAY  (`HALF_PERIOD + 1)

`define MEM_START     32'h00000000
`define MEM_SIZE      32'h000007c0

`define PAR_IN_START   32'h000007ec
`define PAR_IN_SIZE    32'h8

`define PAR_OUT_START   32'h000007f4
`define PAR_OUT_SIZE    32'h8

`define STDOUT_START   32'h000007fc
`define STDOUT_SIZE    32'h4

`define STDIN_START    32'h000007fc
`define STDIN_SIZE     32'h4
