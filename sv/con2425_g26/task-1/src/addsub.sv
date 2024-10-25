module addsub (
    input logic [4:0] a_i,
    input logic [4:0] b_i,
    input logic       mode_i,

    output logic [4:0] result_o
    );

    // add your implementation here
    // use the mode_i signal to select between addition and subtraction
    // use two's complement for subtraction
    // start simple by doing addition with one bit only
    always_comb begin
        if (mode_i == 1'b0) begin
            result_o = a_i + b_i;
        end else begin
            result_o = a_i - b_i;
        end
    end
endmodule
