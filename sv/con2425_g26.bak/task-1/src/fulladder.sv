module fulladder (
    input  logic a_i,
    input  logic b_i,
    input  logic c_i,

    output logic sum_o,
    output logic c_o
    );

    // add your implementation here
    // Basic boolean logic
    assign sum_o = a_i ^ b_i ^ c_i;
    assign c_o   = (a_i & b_i) | (b_i & c_i) | (a_i & c_i);
endmodule
