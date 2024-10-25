`ifndef SYNTHESIS
module testbench();
  // registers for inputs to the module
  logic [3:0] a_i;
  logic [3:0] b_i;
  logic carry_i;

  // wires for the outputs of the module
  logic [3:0] sum_o;

  // create a 4bit adder and connect the logic elements to it
  my_adder adder(
    .a_i(a_i),
    .b_i(b_i),
    .carry_i(carry_i),
    .sum_o(sum_o)
  );

  // create dump file
  initial begin
    $dumpfile("my_adder.vcd");
    $dumpvars(0, testbench);
  end

  // this happens only once, you can use this to test your circuit
  initial begin
    a_i <= 0;
    b_i <= 0;
    carry_i <= 0;
    #1
    $display("[TESTCASE 1] a_i = %d, b_i = %d, carry_i = %d  gives  sum_o = %d", a_i, b_i, carry_i, sum_o);
    #1
    
    a_i <= 1;
    b_i <= 0;
    carry_i <= 0;
    #1
    $display("[TESTCASE 2] a_i = %d, b_i = %d, carry_i = %d  gives  sum_o = %d", a_i, b_i, carry_i, sum_o);
    #1

    a_i <= 7;
    b_i <= 0;
    carry_i <= 0;
    #1
    $display("[TESTCASE 3] a_i = %d, b_i = %d, carry_i = %d  gives  sum_o = %d", a_i, b_i, carry_i, sum_o);
    #1

    a_i <= 5;
    b_i <= 5;
    carry_i <= 0;
    #1
    $display("[TESTCASE 4] a_i = %d, b_i = %d, carry_i = %d  gives  sum_o = %d", a_i, b_i, carry_i, sum_o);
    #1

    a_i <= 0;
    b_i <= 7;
    carry_i <= 0;
    #1
    $display("[TESTCASE 5] a_i = %d, b_i = %d, carry_i = %d  gives  sum_o = %d", a_i, b_i, carry_i, sum_o);
    #1

    a_i <= 7;
    b_i <= 7;
    carry_i <= 0;
    #1
    $display("[TESTCASE 6] a_i = %d, b_i = %d, carry_i = %d  gives  sum_o = %d", a_i, b_i, carry_i, sum_o);
    #1

    a_i <= 7;
    b_i <= 0;
    carry_i <= 1;
    #1
    $display("[TESTCASE 7] a_i = %d, b_i = %d, carry_i = %d  gives  sum_o = %d", a_i, b_i, carry_i, sum_o);
    #1

    a_i <= 7;
    b_i <= 7;
    carry_i <= 1;
    #1
    $display("[TESTCASE 8] a_i = %d, b_i = %d, carry_i = %d  gives  sum_o = %d", a_i, b_i, carry_i, sum_o);
    #1

    a_i <= 14;
    b_i <= 5;
    carry_i <= 0;
    #1
    $display("[TESTCASE 9] a_i = %d, b_i = %d, carry_i = %d  gives  sum_o = %d", a_i, b_i, carry_i, sum_o);
    #1

    $finish;
  end

endmodule
`endif
