module blocking_vs_nonblocking(
    input logic clk_i,
    input logic reset_i,
    output logic [3:0] out_o1, out_o2, out_o3
);
    logic [3:0] value_1, value_2, value_3;

    // DO NOT WRITE CODE LIKE THIS !!!!

    // THIS IS FOR ILLUSTRATION OF WHAT NOT TO DO !!!

    always_ff @(posedge clk_i or posedge reset_i) begin
        
        value_1 <= value_1 + 1;
              
        value_2 = value_1 + 1;
        
        value_3 <= value_2 + 1;    
        
        if (reset_i == 1) begin
            value_1 <= 0;
            value_2 <= 0;
            value_3 <= 0;
        end
    end
       
    // combinational logic / output logic
    always_comb begin
        out_o1 = value_1;        
        out_o2 = value_2;        
        out_o3 = value_3;                        
    end


endmodule
