`ifndef SYNTHESIS
module testbench();
  // registers for inputs to the module
  logic clk;
  logic reset;
  logic in;

  // wires for the outputs of the module
  logic [1:0] out;

  // Device-under-Test (DUT) instantiation
  state_machine fsm(
    .clk_i(clk),
    .reset_i(reset),
    .in_i(in),
    .out_o(out)
  );

  // create dump file
  initial begin
    $dumpfile("mealy_fsm.vcd");
    $dumpvars(0, testbench);
  end

  // create clock
  integer cc = 0;
  integer i;
  initial begin
    clk = 0;

    for (i = 0; i < 40; i++) begin
      if (clk == 0)
        cc = cc + 1;

      clk = ~clk;
      #1;
    end

    $finish();
  end

  // handle reset
  initial reset = 1;
  always begin
    #10;
    reset = 0;
  end

  // testbench
  initial begin
    // executed whenever some value in the format string changes
    $monitor("[STATE] clock cycle = %d  reset_i = %d, out_o = %d", cc, reset, out);

    in = 0;
    #11
    in = 1;
    #1
    in = 0;
    #1 
    in = 1;
    #2 
    in = 0;
    #1 
    in = 1;
    #10
    in = 0;
  end
endmodule
`endif
