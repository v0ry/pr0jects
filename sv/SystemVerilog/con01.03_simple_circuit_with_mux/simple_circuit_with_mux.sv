// store this file as "simple_circuit_with_mux.sv" to run the design flow based on this file

module simple_circuit_with_mux (
  input logic in_a,
  input logic in_b,
  input logic in_c,
  input logic in_x,
  input logic in_y,
  input logic in_z,
  input logic mux_sel,
  output logic out_q
);

//logic i;

// this block describes the combinational circuit
always_comb begin
  
   
  if (mux_sel == 0) 
    out_q = (~in_a & in_b) | in_c;
  else
    out_q = (in_x & in_y) | ~in_z;

// This will invert the result, explain why!
//  out_q = i^out_q;
//  i = 1;

end

endmodule
