`ifndef SYNTHESIS
module testbench();
  // wires for inputs to the module
  logic clk;
  logic reset;
  
  // wires for the outputs of the module
  logic [3:0] out1, out2, out3;

  // create an add-sub module and connect the logic elements to it
  blocking_vs_nonblocking fsm(
    .clk_i(clk),
    .reset_i(reset),
    .out_o1(out1),
    .out_o2(out2),
    .out_o3(out3)
  );

  // create dump file
  initial begin
    $dumpfile("blocking_vs_nonblocking.vcd");
    $dumpvars(0, testbench);
  end

  // create clock
  integer cc = 0;
  integer i;
  initial begin
    clk = 0;

    for (i = 0; i < 3; i++) begin
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
    #2;
    reset = 0;
  end

  // testbench
  initial begin
    // executed whenever some value in the format string changes
    $monitor("[STATE] clock cycle = %d  reset_i = %d, value_1 = %d, value_2 = %d, value_3 = %d", cc, reset, out1, out2, out3);
  end

endmodule
`endif
