`ifndef SYNTHESIS
module testbench();
  // wires for inputs to the module
  logic clk;
  logic reset;
  logic count;
  logic clearit;

  // wires for the outputs of the module
  logic [7:0] out;

  // Device-under-Test (DUT) instantiation
  stopwatch fsm(
    .clk_i(clk),
    .reset_i(reset),
    .count_i(count),
    .clear_i(clearit),
    .time_o(out)
  );

    // create dump file
  initial begin
    $dumpfile("stopwatch.vcd");
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
    $monitor("time: %4d, clock cycle = %4d  reset_i = %d, out_o = %d", $time, cc, reset, out);

    clearit = 0;
    count = 0;
    #3;    
    count = 1;
    #10;
    clearit = 1;   
    #2;
    clearit = 0;
    count = 1;
    #4;
    clearit = 0;
  end
endmodule
`endif
