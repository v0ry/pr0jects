/*
  simple addition in SystemVerilog
*/  


module my_adder  (
  input [3:0] a_i,
  input [3:0] b_i,
  input carry_i,
  output [3:0] sum_o
);


always_comb begin
  sum_o = a_i + b_i + carry_i;
end

endmodule
