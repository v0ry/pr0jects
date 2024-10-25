module exampleFSM (
	clk,
	reset,
	x,
	y
);
	input wire clk;
	input wire reset;
	input wire x;
	output wire y;
	wire [2:0] currentState;
	wire [2:0] nextState;
endmodule