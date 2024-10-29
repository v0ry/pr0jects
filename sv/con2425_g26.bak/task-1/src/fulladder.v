module fulladder (
	a_i,
	b_i,
	c_i,
	sum_o,
	c_o
);
	input wire a_i;
	input wire b_i;
	input wire c_i;
	output wire sum_o;
	output wire c_o;
	assign sum_o = (a_i ^ b_i) ^ c_i;
	assign c_o = ((a_i & b_i) | (b_i & c_i)) | (a_i & c_i);
endmodule