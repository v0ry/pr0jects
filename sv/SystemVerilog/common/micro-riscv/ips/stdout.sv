`include "defines.vh"

module stdout(
  input logic        clk_i,
  input logic        write_i,
  input logic [31:0] din_i
);
  integer std_out_handle; // file handle
  initial std_out_handle = $fopen(`STDOUT_FILE, "w");

  always_ff @(posedge clk_i)
    if (write_i == 1) begin
      // write to file whenever the cpu writes to address 0xFF:
      $fdisplay(std_out_handle, "%H", din_i);
    end
endmodule
