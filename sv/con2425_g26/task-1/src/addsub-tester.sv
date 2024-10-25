
module addsub (
    input logic [4:0] a_i,
    input logic [4:0] b_i,
    input logic       mode_i,

    output logic [4:0] result_o
    );

    // add your implementation here

    logic [3:0] value_p, value_n;

    // sequential logic
    always_ff @(posedge clk_i or posedge reset_i) begin
        value_p <= value_n;
        if (reset_i == 1) begin
            value_p <= 0;
        end
    end

    // combinational logic This is where all complexities are
    always_comb begin
        value_n = value_p + 1;
        if (addsub_i == 1) begin
            value_n = value_p - 1;
        end
        
    end

    // combinational logic / output logic
    always_comb begin
        out_o = value_p;        
    end

endmodule
