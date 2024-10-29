`include "defines.vh"

module  stdin(
  input logic         clk_i,
  input logic         reset_i,
  input logic         read_i,
  output logic [31:0] dout_o
);
  ////////////////////////////////////////////////////////
  // providing data for standard input from a file whose
  // name is specified in STDIN_FILE:
  ////////////////////////////////////////////////////////
  logic [31:0] stdin_buffer[0:255];
  logic [7:0]  stdin_pointer;

  integer i = 0;
  integer ret = 1;
  integer fd;
  initial begin
    for (i=0; i<16; i = i+1) begin
      stdin_buffer[i] = 32'h0;
    end
    i = 0;

    // load data for stdin from file:
    fd = $fopen(`STDIN_FILE, "r");
    if (fd == 0) begin
      $display("WARNING: cannot open STDIN_FILE");
    end else begin
      while (ret == 1) begin
        ret = $fscanf(fd, "%h", stdin_buffer[i]);
        i = i + 1;
      end
      $fclose(fd);
    end

    stdin_pointer = 0;

    // for convenience: print the values
    // just read from the input file "std_in.dat"
    $write("--------------------------------------------------------\n");
    $write("Values on stdin (index 0 to 15 only):\n");
    $write("--------------------------------------------------------\n");
    for (i=0; i<8; i = i+1)
        $write("%H:%H ", i, stdin_buffer[i]);
    $write("\n");
    for (i=8; i<16; i = i+1)
        $write("%H:%H ", i, stdin_buffer[i]);
    $write("\n");
    $write("--------------------------------------------------------\n");
  end

  // Read logic
  assign dout_o = stdin_buffer[stdin_pointer];

  always_ff @(posedge clk_i or posedge reset_i) begin
    if(~reset_i) begin
      if (read_i) begin
        stdin_pointer <= stdin_pointer + 1;
      end
    end
  end
endmodule
