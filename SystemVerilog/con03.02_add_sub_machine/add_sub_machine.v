module add_sub_machine (
	clk_i,
	reset_i,
	addsub_i,
	out_o
);
	reg _sv2v_0;
	input wire clk_i;
	input wire reset_i;
	input wire addsub_i;
	output reg [3:0] out_o;
	reg [3:0] value_p;
	reg [3:0] value_n;
	always @(posedge clk_i or posedge reset_i) begin
		value_p <= value_n;
		if (reset_i == 1)
			value_p <= 0;
	end
	always @(*) begin
		if (_sv2v_0)
			;
		value_n = value_p + 1;
		if (addsub_i == 1)
			value_n = value_p - 1;
	end
	always @(*) begin
		if (_sv2v_0)
			;
		out_o = value_p;
	end
	initial _sv2v_0 = 0;
endmodule