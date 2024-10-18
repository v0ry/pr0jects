`ifndef SYNTHESIS
module testbench();
  // signal for inputs to the module
  logic in_a;
  logic in_b;
  logic in_c;
  logic in_x;
  logic in_y;
  logic in_z;
  logic mux_sel;
  

  // wires for the outputs of the module
  logic out_q;

  // create a module and connect the registers and wires to it
  simple_circuit_with_mux logic_i(
    .in_a(in_a),
    .in_b(in_b),
    .in_c(in_c),
    .in_x(in_x),
    .in_y(in_y),
    .in_z(in_z),
    .mux_sel(mux_sel),
    .out_q(out_q)
  );

  // create dump file
  initial begin
    $dumpfile("simple_circuit_with_mux.vcd");
    $dumpvars(0, testbench);
  end

  // this happens only once, you can use this to test your circuit
  initial begin
    mux_sel <= 0;
    in_x <= 0;
    in_y <= 0;
    in_z <= 0;

    in_a <= 0;
    in_b <= 0;
    in_c <= 0;
    #1
    $display("[Time: %04t, TESTCASE 1] mux_sel = %d, in_a = %d, in_b = %d, in_c = %d results in output = %d ", $time, mux_sel, in_a, in_b, in_c, out_q);
    #1

    in_a <= 1;
    in_b <= 0;
    in_c <= 0;
    #1
    $display("[Time: %04t, TESTCASE 2] mux_sel = %d, in_a = %d, in_b = %d, in_c = %d results in output = %d ", $time, mux_sel, in_a, in_b, in_c, out_q);
    #1

    in_a <= 0;
    in_b <= 1;
    in_c <= 0;
    #1
    $display("[Time: %04t, TESTCASE 3] mux_sel = %d, in_a = %d, in_b = %d, in_c = %d results in output = %d ", $time, mux_sel, in_a, in_b, in_c, out_q);
    #1

    in_a <= 1;
    in_b <= 1;
    in_c <= 0;
    #1
    $display("[Time: %04t, TESTCASE 4] mux_sel = %d, in_a = %d, in_b = %d, in_c = %d results in output = %d ", $time, mux_sel, in_a, in_b, in_c, out_q);
    #1

    in_a <= 0;
    in_b <= 0;
    in_c <= 1;
    #1
    $display("[Time: %04t, TESTCASE 5] mux_sel = %d, in_a = %d, in_b = %d, in_c = %d results in output = %d ", $time, mux_sel, in_a, in_b, in_c, out_q);
    #1

    in_a <= 1;
    in_b <= 0;
    in_c <= 1;
    #1
    $display("[Time: %04t, TESTCASE 6] mux_sel = %d, in_a = %d, in_b = %d, in_c = %d results in output = %d ", $time, mux_sel, in_a, in_b, in_c, out_q);
    #1

    in_a <= 0;
    in_b <= 1;
    in_c <= 1;
    #1
    $display("[Time: %04t, TESTCASE 7] mux_sel = %d, in_a = %d, in_b = %d, in_c = %d results in output = %d ", $time, mux_sel, in_a, in_b, in_c, out_q);
    #1

    in_a <= 1;
    in_b <= 1;
    in_c <= 1;
    #1
    $display("[Time: %04t, TESTCASE 8] mux_sel = %d, in_a = %d, in_b = %d, in_c = %d results in output = %d ", $time, mux_sel, in_a, in_b, in_c, out_q);
    #1

    $display("");
    mux_sel <= 1;
    in_a <= 0;
    in_b <= 0;
    in_c <= 1;

    in_x <= 0;
    in_y <= 0;
    in_z <= 0;
    #10
    $display("[Time: %04t, TESTCASE 1] mux_sel = %d, in_x = %d, in_y = %d, in_z = %d results in output = %d ",$time,mux_sel, in_x, in_y, in_z, out_q);
    #1

    in_x <= 1;
    in_y <= 0;
    in_z <= 0;
    #1
    $display("[Time: %04t, TESTCASE 2] mux_sel = %d, in_x = %d, in_y = %d, in_z = %d results in output = %d ",$time,mux_sel, in_x, in_y, in_z, out_q);
    #1

    in_x <= 0;
    in_y <= 1;
    in_z <= 0;
    #1
    $display("[Time: %04t, TESTCASE 3] mux_sel = %d, in_x = %d, in_y = %d, in_z = %d results in output = %d ",$time,mux_sel, in_x, in_y, in_z, out_q);
    #1

    in_x <= 1;
    in_y <= 1;
    in_z <= 0;
    #1
    $display("[Time: %04t, TESTCASE 4] mux_sel = %d, in_x = %d, in_y = %d, in_z = %d results in output = %d ",$time,mux_sel, in_x, in_y, in_z, out_q);
    #1

    in_x <= 0;
    in_y <= 0;
    in_z <= 1;
    #1
    $display("[Time: %04t, TESTCASE 5] mux_sel = %d, in_x = %d, in_y = %d, in_z = %d results in output = %d ",$time,mux_sel, in_x, in_y, in_z, out_q);
    #1


    in_x <= 1;
    in_y <= 0;
    in_z <= 1;
    #1
    $display("[Time: %04t, TESTCASE 6] mux_sel = %d, in_x = %d, in_y = %d, in_z = %d results in output = %d ",$time,mux_sel, in_x, in_y, in_z, out_q);
    #1

    in_x <= 0;
    in_y <= 1;
    in_z <= 1;
    #1
    $display("[Time: %04t, TESTCASE 7] mux_sel = %d, in_x = %d, in_y = %d, in_z = %d results in output = %d ",$time,mux_sel, in_x, in_y, in_z, out_q);
    #1

    in_x <= 1;
    in_y <= 1;
    in_z <= 1;
    #1
    $display("[Time: %04t, TESTCASE 8] mux_sel = %d, in_x = %d, in_y = %d, in_z = %d results in output = %d ",$time,mux_sel, in_x, in_y, in_z, out_q);
    #1

    $finish;
  end

endmodule
`endif

/* 

truth table of out_q <= (~in_a & in_b) | in_c

in_a  in_b  in_c  | out_q
 0     0     0    |  0
 1     0     0    |  0
 0     1     0    |  1
 1     1     0    |  0
 0     0     1    |  1
 1     0     1    |  1
 0     1     1    |  1
 1     1     1    |  1

 truth table of out_q <= (in_x ^ in_y) | ~in_c

in_x  in_y  in_z  | out_q
 0     0     0    |  1
 1     0     0    |  1
 0     1     0    |  1
 1     1     0    |  1
 0     0     1    |  0
 1     0     1    |  1
 0     1     1    |  1
 1     1     1    |  0

*/
