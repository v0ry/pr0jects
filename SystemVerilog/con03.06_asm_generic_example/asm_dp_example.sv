module asm_dp_example(
  input logic clk_i,
  input logic reset_i,
  input logic in_i,
  output logic [2:0] out_o
);

  // registers
  typedef enum logic [1:0] { STATE_A, STATE_B, STATE_C } state_t;
  state_t state_p, state_n;

  logic [2:0] x_n, x_p, y_n, y_p;

  //output signal
  logic [2:0] out_value;
  

  // State registers 
  //
  always_ff @(posedge clk_i or posedge reset_i) begin
    if (reset_i) begin
      // data path
      x_p <= 3'b000;
      y_p <= 3'b000;        
      
      // control
      state_p <= STATE_A;
    end else begin
      // data path
      x_p <= x_n;
      y_p <= y_n;
      // control
      state_p <= state_n;
    end
  end

  // combinational logic of
  // * state logic and output logic
  // * datapath

  always_comb begin
    // Default assignments
    state_n = state_p;
    x_n = x_p;
    y_n = y_p;
    out_value = 3'b000;
    
    // default statement makes sure all statements are defined
    // This is exaclty the same as in the slides from lecture today
    case (state_p)
      default: begin
        state_n = state_p;
        out_value = 3'b000;
      end

      STATE_A: begin
        out_value = 3'b100;
        state_n = STATE_B;

        x_n = 3'b000;
        y_n = 3'b000;
      end
  
      STATE_B: begin
        out_value = 3'b011;
        y_n = x_p;

        if (in_i) begin
          state_n = STATE_C;
        end else begin
          state_n = STATE_A;
        end
      end
  
      STATE_C: begin
        state_n = STATE_A;
        out_value = 3'b010;
        x_n = x_p + 1;
        y_n = x_p;
      end
    endcase
  end

  assign out_o = out_value;
  
endmodule
