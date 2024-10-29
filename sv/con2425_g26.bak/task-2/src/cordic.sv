//------------------------------------------------------------------------------
//
// RTL model of cordic accelerator
// Computes the sine or cosine of a given angle in Q3.28 data format
//
//------------------------------------------------------------------------------

module cordic (
  input  logic        clk_i,
  input  logic        reset_i,
  input  logic [31:0] angle_i,
  input  logic        sine_cosine_i,
  input  logic        start_i,
  output logic [31:0] result_o,
  output logic        busy_o,
  output logic        valid_o
);

  localparam logic [31:0] K       = 32'h09b74edb;
  localparam logic [31:0] PI_1    = 32'h3243f6a9;
  localparam logic [31:0] PI_2    = 32'h6487ed52;
  localparam logic [31:0] PI_HALF = 32'h1921fb54;

  // Initialize the angle table
  logic [31:0] alpha[29];
  initial begin
    alpha[0]  = 32'h0c90fdaa;
    alpha[1]  = 32'h076b19c1;
    alpha[2]  = 32'h03eb6ebf;
    alpha[3]  = 32'h01fd5baa;
    alpha[4]  = 32'h00ffaade;
    alpha[5]  = 32'h007ff557;
    alpha[6]  = 32'h003ffeab;
    alpha[7]  = 32'h001fffd5;
    alpha[8]  = 32'h000ffffb;
    alpha[9]  = 32'h0007ffff;
    alpha[10] = 32'h00040000;
    alpha[11] = 32'h00020000;
    alpha[12] = 32'h00010000;
    alpha[13] = 32'h00008000;
    alpha[14] = 32'h00004000;
    alpha[15] = 32'h00002000;
    alpha[16] = 32'h00001000;
    alpha[17] = 32'h00000800;
    alpha[18] = 32'h00000400;
    alpha[19] = 32'h00000200;
    alpha[20] = 32'h00000100;
    alpha[21] = 32'h00000080;
    alpha[22] = 32'h00000040;
    alpha[23] = 32'h00000020;
    alpha[24] = 32'h00000010;
    alpha[25] = 32'h00000008;
    alpha[26] = 32'h00000004;
    alpha[27] = 32'h00000002;
    alpha[28] = 32'h00000001;
  end

  // put your implementation here

endmodule

