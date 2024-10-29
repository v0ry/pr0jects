module calculator (
	clk_i,
	rst_i,
	a_i,
	b_i,
	input_valid_i,
	calc_i,
	mode_i,
	clear_i,
	result_o,
	output_valid_o
);
	reg _sv2v_0;
	input wire clk_i;
	input wire rst_i;
	input wire [4:0] a_i;
	input wire [4:0] b_i;
	input wire input_valid_i;
	input wire calc_i;
	input wire mode_i;
	input wire clear_i;
	output wire [4:0] result_o;
	output wire output_valid_o;
	reg [1:0] state;
	reg [1:0] next_state;
	reg [4:0] reg_a;
	reg [4:0] reg_b;
	addsub addsub_inst(
		.a_i(reg_a),
		.b_i(reg_b),
		.mode_i(mode_i),
		.result_o(result_o)
	);
	always @(*) begin
		if (_sv2v_0)
			;
		case (state)
			2'd0:
				if (input_valid_i)
					next_state = 2'd1;
				else
					next_state = 2'd0;
			2'd1:
				if (input_valid_i)
					next_state = 2'd2;
				else
					next_state = 2'd1;
			2'd2:
				if (calc_i)
					next_state = 2'd0;
				else
					next_state = 2'd2;
			default: next_state = 2'd0;
		endcase
	end
	always @(posedge clk_i or posedge rst_i)
		if (rst_i) begin
			state <= 2'd0;
			reg_a <= 5'b00000;
			reg_b <= 5'b00000;
		end
		else begin
			state <= next_state;
			if (clear_i) begin
				reg_a <= 5'b00000;
				reg_b <= 5'b00000;
				state <= 2'd0;
			end
			else
				case (state)
					2'd0:
						if (input_valid_i)
							reg_a <= a_i;
					2'd1:
						if (input_valid_i)
							reg_b <= b_i;
					2'd2:
						;
					default:
						;
				endcase
		end
	assign output_valid_o = state == 2'd2;
	initial _sv2v_0 = 0;
endmodule