`ifndef SYNTHESIS
module testbench();
  // wires for inputs to the module
  logic[31:0] in_a;
  logic[31:0] in_b;
  

  // wires for the outputs of the module
  logic out_q1;
  logic out_q2;

  // create a simple_circuit and connect the logic elements to it
  ripple_circuit circ(
    .in_a(in_a),
    .in_b(in_b),
    .out_q1(out_q1),
    .out_q2(out_q2)
  );

  // create dump file
  initial begin
    $dumpfile("ripple_circuit.vcd");
    $dumpvars(0, testbench);
  end

  // this happens only once, you can use this to test your circuit
  initial begin
    
    $monitor("[Time: %04t] out_q1: %x, out_q2 %x", $time, out_q1, out_q2);
        
    in_a <= 31'hFFFF;
    in_b <= 31'hF7DA;


    #500

    in_a <= 1;
    in_b <= 3;
    

    #500

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
