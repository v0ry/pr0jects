module stopwatch (
	clk_i,
	reset_i,
	count_i,
	clear_i,
	time_o
);
	reg _sv2v_0;
	input wire clk_i;
	input wire reset_i;
	input wire count_i;
	input wire clear_i;
	output wire [7:0] time_o;
	reg state_p;
	reg state_n;
	reg [7:0] time_p;
	reg [7:0] time_n;
	always @(posedge clk_i or posedge reset_i)
		if (reset_i == 1) begin
			state_p <= 1'd0;
			time_p <= 0;
		end
		else begin
			state_p <= state_n;
			time_p <= time_n;
		end
	always @(*) begin
		if (_sv2v_0)
			;
		state_n = state_p;
		time_n = time_p;
		case (state_p)
			default: begin
				state_n = state_p;
				time_n = time_p;
			end
			1'd0: begin
				state_n = 1'd0;
				if (count_i)
					state_n = 1'd1;
			end
			1'd1: begin
				time_n = time_p + 1;
				state_n = 1'd1;
				if (count_i == 0)
					state_n = 1'd0;
				if (clear_i) begin
					time_n = 0;
					state_n = 1'd0;
				end
			end
		endcase
	end
	assign time_o = time_p;
	initial _sv2v_0 = 0;
endmodule