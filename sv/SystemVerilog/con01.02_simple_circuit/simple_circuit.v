module simple_circuit (
	in_a,
	in_b,
	in_c,
	out_q
);
	input wire in_a;
	input wire in_b;
	input wire in_c;
	output wire out_q;
	assign out_q = (~in_a & in_b) | in_c;
endmodule