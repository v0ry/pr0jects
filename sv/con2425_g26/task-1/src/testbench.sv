`ifndef SYNTHESIS
module testbench();
  // wires for inputs to the module
  logic A, B, C;

  // wires for the outputs of the module
  logic Y, X;

  // create a fulladder and connect the logic elements to it
  fulladder uut (
    .A(A),
    .B(B),
    .C(C),
    .Y(Y),
    .X(X)
  );

  // create dump file
  initial begin
    $dumpfile("fulladder.vcd");
    $dumpvars(0, testbench);
  end

  // this happens only once, you can use this to test your fulladder circuit
  initial begin
    A <= 0;
    B <= 0;
    C <= 0;
    #1
    $display("[Time: %04t, TESTCASE 1] A = %d, B = %d, C = %d results in Y = %d, X = %d", $time, A, B, C, Y, X);
    #1

    A <= 1;
    B <= 0;
    C <= 0;
    #1
    $display("[Time: %04t, TESTCASE 2] A = %d, B = %d, C = %d results in Y = %d, X = %d", $time, A, B, C, Y, X);
    #1

    A <= 0;
    B <= 1;
    C <= 0;
    #1
    $display("[Time: %04t, TESTCASE 3] A = %d, B = %d, C = %d results in Y = %d, X = %d", $time, A, B, C, Y, X);
    #1

    A <= 1;
    B <= 1;
    C <= 0;
    #1
    $display("[Time: %04t, TESTCASE 4] A = %d, B = %d, C = %d results in Y = %d, X = %d", $time, A, B, C, Y, X);
    #1

    A <= 0;
    B <= 0;
    C <= 1;
    #1
    $display("[Time: %04t, TESTCASE 5] A = %d, B = %d, C = %d results in Y = %d, X = %d", $time, A, B, C, Y, X);
    #1

    A <= 1;
    B <= 0;
    C <= 1;
    #1
    $display("[Time: %04t, TESTCASE 6] A = %d, B = %d, C = %d results in Y = %d, X = %d", $time, A, B, C, Y, X);
    #1

    A <= 0;
    B <= 1;
    C <= 1;
    #1
    $display("[Time: %04t, TESTCASE 7] A = %d, B = %d, C = %d results in Y = %d, X = %d", $time, A, B, C, Y, X);
    #1

    A <= 1;
    B <= 1;
    C <= 1;
    #1
    $display("[Time: %04t, TESTCASE 8] A = %d, B = %d, C = %d results in Y = %d, X = %d", $time, A, B, C, Y, X);
    #1

    $finish;
  end

endmodule
`endif
