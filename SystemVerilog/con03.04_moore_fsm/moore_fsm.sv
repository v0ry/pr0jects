module state_machine(
    input logic clk_i,
    input logic reset_i,
    input logic in_i,
    output logic [2:0] out_o
);
    typedef enum logic [1:0] { STATE_A, STATE_B, STATE_C } state_t;
    state_t state_p, state_n;
    logic [2:0] out_value;

    always_ff @(posedge clk_i or posedge reset_i) begin
        if (reset_i) begin
            state_p <= STATE_A;
        end else begin
            state_p <= state_n;
        end
    end

    always_comb begin
        out_value = 3'b000;

        case (state_p)
            default: state_n = state_p;
            STATE_A: begin
                out_value = 3'b100;
                state_n = STATE_B;
            end
            STATE_B: begin
                out_value = 3'b011;
                if (in_i) begin
                    state_n = STATE_C;
                end else begin
                    state_n = STATE_A;
                end
            end
            STATE_C: begin
                out_value = 3'b010;

                if (in_i) begin
                    state_n = STATE_C;
                end else begin
                    state_n = STATE_A;
                end
            end
        endcase
    end

    assign out_o = out_value;
endmodule
