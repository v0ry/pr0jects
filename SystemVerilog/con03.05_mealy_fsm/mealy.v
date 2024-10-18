module state_machine (
	clk_i,
	reset_i,
	in_i,
	out_o
);
	reg _sv2v_0;
	input wire clk_i;
	input wire reset_i;
	input wire in_i;
	output wire [2:0] out_o;
	reg [1:0] state_p;
	reg [1:0] state_n;
	reg [2:0] out;
	always @(posedge clk_i or posedge reset_i)
		if (reset_i)
			state_p <= 2'd0;
		else
			state_p <= state_n;
	always @(*) begin
		if (_sv2v_0)
			;
		out = 3'b000;
		case (state_p)
			default: state_n = state_p;
			2'd0: begin
				out = 3'b100;
				state_n = 2'd1;
			end
			2'd1:
				if (in_i) begin
					state_n = 2'd2;
					out = 3'b011;
				end
				else begin
					state_n = 2'd0;
					out = 3'b001;
				end
			2'd2:
				if (in_i) begin
					state_n = 2'd2;
					out = 3'b000;
				end
				else begin
					state_n = 2'd0;
					out = 3'b010;
				end
		endcase
	end
	assign out_o = out;
	initial _sv2v_0 = 0;
endmodule