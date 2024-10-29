module addsub (
	a_i,
	b_i,
	mode_i,
	result_o
);
	input wire [4:0] a_i;
	input wire [4:0] b_i;
	input wire mode_i;
	output wire [4:0] result_o;
	wire [4:0] b_mux;
	wire [5:0] c;
	assign c[0] = mode_i;
	assign b_mux = b_i ^ {5 {mode_i}};
	genvar _gv_i_1;
	generate
		for (_gv_i_1 = 0; _gv_i_1 < 5; _gv_i_1 = _gv_i_1 + 1) begin : FA_CHAIN
			localparam i = _gv_i_1;
			fulladder FA(
				.a_i(a_i[i]),
				.b_i(b_mux[i]),
				.c_i(c[i]),
				.sum_o(result_o[i]),
				.c_o(c[i + 1])
			);
		end
	endgenerate
endmodule