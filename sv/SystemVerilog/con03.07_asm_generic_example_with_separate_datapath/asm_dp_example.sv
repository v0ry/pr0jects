module light_moserhofgasse(
  input logic clk_i,
  input logic reset_i,
  input logic in_i,
  output logic [2:0] out_o
);

  // Control Unit
  typedef enum logic [1:0] { STATE_A, STATE_B, STATE_C } state_t;
  state_t state_p, state_n;

  logic [2:0] out_value;
  logic clrx, incx, clry, ldy;



  // Control Unit

  // State registers 
  always_ff @(posedge clk_i or posedge reset_i) begin
    if (reset_i) begin
      state_p <= STATE_A;
    end else begin
      state_p <= state_n;
    end
  end

  // combinational logic
  // … consisting of next state logic and output logic
  // … (generating control and actual output signals)
  always_comb begin
    // Default assignments
    state_n = state_p;
    clrx = 0;
    incx = 0;
    clry = 0;
    ldy = 0;
    out_value = 3'b000;
    
    case (state_p)
      default: begin
        state_n = state_p;
        clrx = 0;
        incx = 0;
        clry = 0;
        ldy = 0;
        out_value = 3'b000;
      end

      STATE_A: begin
        out_value = 3'b100;
        state_n = STATE_B;
        clrx = 1;
        clry = 1;
      end
      STATE_B: begin
        out_value = 3'b011;
        ldy = 1;
        if (in_i) begin
          state_n = STATE_C;
        end else begin
          state_n = STATE_A;
        end
      end
      STATE_C: begin
        state_n = STATE_A;
        out_value = 3'b010;
        incx = 1;
        ldy = 1;
      end
    endcase
  end


  ////////////////////////////////////////////////////////////////
  // data path
  logic [2:0] x_n, x_p, y_n, y_p;

  // registers of the data path
  always_ff @(posedge clk_i or posedge reset_i) begin
    if (reset_i) begin
      x_p <= 3'b000;
      y_p <= 3'b000;
    end else begin
      x_p <= x_n;
      y_p <= y_n;
    end
  end

  // Combinational logic of the data path
  always_comb begin
        
    // operations for register X
    x_n = x_p;
    
    if (incx)
      x_n = x_p +1;

    if (clrx)
      x_n = 3'b000;
    
    // operations for register Y
    y_n = y_p;

    if (ldy)
      y_n = x_p;
    
    if (clry)
      y_n = 3'b000;
  end

  assign out_o = out_value;
endmodule
