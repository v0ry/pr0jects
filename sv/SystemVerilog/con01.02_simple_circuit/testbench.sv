`ifndef SYNTHESIS
module testbench();
  // wires for inputs to the module
  logic in_a;
  logic in_b;
  logic in_c;

  // wires for the outputs of the module
  logic out_q;

  // create a simple_circuit and connect the logic elements to it
  simple_circuit circ(
    .in_a(in_a),
    .in_b(in_b),
    .in_c(in_c),
    .out_q(out_q)
  );

  // create dump file
  initial begin
    $dumpfile("simple_circuit.vcd");
    $dumpvars(0, testbench);
  end

  // this happens only once, you can use this to test your circuit
  initial begin
    in_a <= 0;
    in_b <= 0;
    in_c <= 0;
    #1
    $display("[Time: %04t, TESTCASE 1] in_a = %d, in_b = %d, in_c = %d results in output = %d ", $time, in_a, in_b, in_c, out_q);
    #1

    in_a <= 1;
    in_b <= 0;
    in_c <= 0;
    #1
    $display("[Time: %04t, TESTCASE 2] in_a = %d, in_b = %d, in_c = %d results in output = %d ", $time, in_a, in_b, in_c, out_q);
    #1

    in_a <= 0;
    in_b <= 1;
    in_c <= 0;
    #1
    $display("[Time: %04t, TESTCASE 3] in_a = %d, in_b = %d, in_c = %d results in output = %d ", $time, in_a, in_b, in_c, out_q);
    #1

    in_a <= 1;
    in_b <= 1;
    in_c <= 0;
    #1
    $display("[Time: %04t, TESTCASE 4] in_a = %d, in_b = %d, in_c = %d results in output = %d ", $time, in_a, in_b, in_c, out_q);
    #1

    in_a <= 0;
    in_b <= 0;
    in_c <= 1;
    #1
    $display("[Time: %04t, TESTCASE 5] in_a = %d, in_b = %d, in_c = %d results in output = %d ", $time,in_a, in_b, in_c, out_q);
    #1

    in_a <= 1;
    in_b <= 0;
    in_c <= 1;
    #1
    $display("[Time: %04t, TESTCASE 6] in_a = %d, in_b = %d, in_c = %d results in output = %d ", $time, in_a, in_b, in_c, out_q);
    #1

    in_a <= 0;
    in_b <= 1;
    in_c <= 1;
    #1
    $display("[Time: %04t, TESTCASE 7] in_a = %d, in_b = %d, in_c = %d results in output = %d ", $time, in_a, in_b, in_c, out_q);
    #1

    in_a <= 1;
    in_b <= 1;
    in_c <= 1;
    #1
    $display("[Time: %04t, TESTCASE 8] in_a = %d, in_b = %d, in_c = %d results in output = %d ", $time, in_a, in_b, in_c, out_q);
    #1

    $finish;
  end

endmodule
`endif

/* 

truth table of out_q <= (~in_a & in_b) | in_c;

in_a  in_b  in_c  | out_q
 0     0     0    |  0
 1     0     0    |  0
 0     1     0    |  1
 1     1     0    |  0
 0     0     1    |  1
 1     0     1    |  1
 0     1     1    |  1
 1     1     1    |  1

*/ 
