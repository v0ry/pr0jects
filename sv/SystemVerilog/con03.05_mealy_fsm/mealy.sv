module state_machine(
  input logic clk_i,
  input logic reset_i,
  input logic in_i,
  output logic [2:0] out_o
);
  typedef enum logic [1:0] { STATE_A, STATE_B, STATE_C } state_t;
  state_t state_p, state_n;
  logic [2:0] out;

  always_ff @(posedge clk_i or posedge reset_i) begin
    if (reset_i) begin
      state_p <= STATE_A;
    end else begin
      state_p <= state_n;
    end
  end

  always_comb begin
    out = 3'b000;
    case (state_p)
      default: state_n = state_p;
      STATE_A: begin
        out = 3'b100;
        state_n = STATE_B;
      end
      STATE_B: begin
        if (in_i) begin
          state_n = STATE_C;
          out = 3'b011;
        end else begin
          state_n = STATE_A;
          out = 3'b001;
        end
      end
      STATE_C: begin               
        if (in_i) begin
          state_n = STATE_C;
          out = 3'b000;
        end else begin
          state_n = STATE_A;
          out = 3'b010;
        end
      end
    endcase
  end

  assign out_o = out;
endmodule
