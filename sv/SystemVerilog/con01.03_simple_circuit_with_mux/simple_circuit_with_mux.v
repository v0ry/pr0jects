module simple_circuit_with_mux (
	in_a,
	in_b,
	in_c,
	in_x,
	in_y,
	in_z,
	mux_sel,
	out_q
);
	reg _sv2v_0;
	input wire in_a;
	input wire in_b;
	input wire in_c;
	input wire in_x;
	input wire in_y;
	input wire in_z;
	input wire mux_sel;
	output reg out_q;
	always @(*) begin
		if (_sv2v_0)
			;
		if (mux_sel == 0)
			out_q = (~in_a & in_b) | in_c;
		else
			out_q = (in_x & in_y) | ~in_z;
	end
	initial _sv2v_0 = 0;
endmodule