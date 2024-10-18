module simple_circuit (
  input logic in_a,
  input logic in_b,
  input logic in_c,
  output logic out_q
);
  assign out_q = ((~ in_a & in_b) | in_c);
endmodule
