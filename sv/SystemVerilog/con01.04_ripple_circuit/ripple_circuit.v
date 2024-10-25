module ripple_circuit (
	in_a,
	in_b,
	out_q1,
	out_q2
);
	reg _sv2v_0;
	input wire [31:0] in_a;
	input wire [31:0] in_b;
	output reg out_q1;
	output reg out_q2;
	always @(*) begin
		if (_sv2v_0)
			;
		out_q1 = ((in_a[0] ^ in_a[2]) ^ in_a[3]) ^ in_b;
		out_q1 = ((&in_a ^ in_a[6]) | ((in_a[2] == 0) ^ in_b[8])) | (in_a[6] ^ in_a[7]);
		out_q2 = ^in_b | ((in_a[1] & in_a[4]) ^ &in_a[6]);
	end
	initial _sv2v_0 = 0;
endmodule