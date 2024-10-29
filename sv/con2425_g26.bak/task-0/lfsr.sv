// ----------------------------------------------------------------------------
// CON 2024 T0: linear feedback shift register (lfsr)
//
// 	- Module that implements a 32-bit LFSR
// 	- The LFSR should be initialized with a matriculation number
//
module lfsr(
    input logic clk_i,
    input logic reset_i,
    
    output logic [31:0] lfsr_state_o
);

    // 32-bit flip-flop for lfsr
    logic [31:0] lfsr_p, lfsr_n;
  
    // combinational logic for lfsr 
    always_comb begin 
        lfsr_n = (lfsr_p << 1) | {31'b0, lfsr_p[27] ^
                                         lfsr_p[23] ^
                                         lfsr_p[19] ^
                                         lfsr_p[18] ^
                                         lfsr_p[15] ^
                                         lfsr_p[11] ^
                                         lfsr_p[7]  ^
                                         lfsr_p[4]  ^ 
                                         lfsr_p[1] };
	
	// assign current value of flip-flop to output
        lfsr_state_o = lfsr_p;
    end
    
    // sequential logic modeling a d-flip-flop with asynchronous reset
    always @(posedge clk_i or posedge reset_i) begin
        if (reset_i) begin
            lfsr_p <= 32'd 12028653; // <--- Replace this with your matr.#
        end else begin
            lfsr_p <= lfsr_n; 
        end
    end
endmodule
