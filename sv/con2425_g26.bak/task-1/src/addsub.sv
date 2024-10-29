module addsub (
    input logic [4:0] a_i,
    input logic [4:0] b_i,
    input logic       mode_i,

    output logic [4:0] result_o
    );

    // Wires for inverted b_i and carry chain
    logic [4:0] b_mux;
    logic [5:0] c; // Carry chain, including carry-in and carry-out

    assign c[0] = mode_i; // Carry-in is mode_i (0 for addition, 1 for subtraction)

    // Invert b_i if mode_i is 1 (subtraction)
    assign b_mux = b_i ^ {5{mode_i}};

    // Instantiate five full adders for 5-bit operation
    genvar i;
    generate
        for (i = 0; i < 5; i = i + 1) begin : FA_CHAIN
            fulladder FA (
                .a_i   (a_i[i]),
                .b_i   (b_mux[i]),
                .c_i   (c[i]),
                .sum_o (result_o[i]),
                .c_o   (c[i+1])
            );
        end
    endgenerate
endmodule
