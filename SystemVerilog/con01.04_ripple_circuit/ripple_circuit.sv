module ripple_circuit (
  input logic[31:0] in_a,  
  input logic[31:0] in_b,  
  
  output logic out_q1,
  output logic out_q2
);

// this block describes the combinational circuit
always_comb begin
  
  
  out_q1 = in_a[0]^in_a[2]^in_a[3] ^ in_b;
  out_q1 = &in_a ^ in_a[6] | (in_a[2] == 0) ^ in_b[8] | (in_a[6] ^ in_a[7]);  
  out_q2 = ^in_b | (in_a[1] & in_a[4]) ^ &in_a[6] ;  

end

endmodule

