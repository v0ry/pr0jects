module calculator (
    input  logic       clk_i,
    input  logic       rst_i,

    input  logic [4:0] a_i,
    input  logic [4:0] b_i,
    input  logic       input_valid_i,
    input  logic       calc_i,
    input  logic       mode_i,
    input  logic       clear_i,

    output logic [4:0] result_o,
    output logic       output_valid_o
    );

    // add your implementation here
    typedef enum logic [1:0] {
        LOAD_A,
        LOAD_B,
        CALC
    } state_t;

    state_t state, next_state;

    logic [4:0] reg_a, reg_b;

    addsub addsub_inst (
        .a_i      (reg_a),
        .b_i      (reg_b),
        .mode_i   (mode_i),
        .result_o (result_o)
    );

    always_comb begin
        case (state)
            LOAD_A: begin
                if (input_valid_i)
                    next_state = LOAD_B;
                else
                    next_state = LOAD_A;
            end
            LOAD_B: begin
                if (input_valid_i)
                    next_state = CALC;
                else
                    next_state = LOAD_B;
            end
            CALC: begin
                if (calc_i)
                    next_state = LOAD_A;
                else
                    next_state = CALC;
            end
            default: next_state = LOAD_A;
        endcase
    end

    always_ff @(posedge clk_i or posedge rst_i) begin
        if (rst_i) begin
            state <= LOAD_A;
            reg_a <= 5'b0;
            reg_b <= 5'b0;
        end else begin
            state <= next_state;

            if (clear_i) begin
                reg_a <= 5'b0;
                reg_b <= 5'b0;
                state <= LOAD_A;
            end else begin
                case (state)
                    LOAD_A: begin
                        if (input_valid_i)
                            reg_a <= a_i;
                    end
                    LOAD_B: begin
                        if (input_valid_i)
                            reg_b <= b_i;
                    end
                    CALC: begin
                    end
                    default: ;
                endcase
            end
        end
    end

    assign output_valid_o = (state == CALC);
endmodule
