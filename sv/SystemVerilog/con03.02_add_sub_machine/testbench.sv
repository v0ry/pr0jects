`ifndef SYNTHESIS
`timescale 100ns/1ns
module testbench();
  // wires for inputs to the module
  logic clk;
  logic reset;
  logic addsub;

  // wires for the outputs of the module
  logic [3:0] out;

  // create an add-sub module and connect the logic elements to it
  add_sub_machine fsm(
    .clk_i(clk),
    .reset_i(reset),
    .addsub_i(addsub),
    .out_o(out)
  );

  // create dump file
  initial begin
    $dumpfile("add_sub_machine.vcd");
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
    #1;
    reset = 0;
  end

  // testbench
  initial begin
    // executed whenever some value in the format string changes
    $monitor("[STATE] clock cycle = %d  reset_i = %d, addsub_i = %d, out_o = %d", cc, reset, addsub, out);
  end

  // define input signals as time passes
  initial begin
    addsub = 0;
    #5;
    addsub = 1;
    #5;
    addsub = 0;
  end

endmodule
`endif
