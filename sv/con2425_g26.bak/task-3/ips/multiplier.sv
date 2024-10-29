module multiplier(
  input logic         clk_i,
  input logic         rst_i,
  input logic         start_i,
  input logic [31:0]  a_i,
  input logic [31:0]  b_i,
  output logic        busy_o,
  output logic        finish_o,
  output logic [63:0] result_o
);

endmodule
