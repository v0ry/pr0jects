
module stopwatch(
    input logic clk_i,
    input logic reset_i,
    input logic count_i,
    input logic clear_i,
    output logic [7:0] time_o
);

enum logic {STATE_STOPPED, STATE_COUNTING} state_p, state_n;

logic [7:0] time_p, time_n;


always_ff@(posedge clk_i, posedge reset_i) begin
    if(reset_i == 1) begin
        state_p <= STATE_STOPPED;
        time_p <= 0;
    end
    else begin
        state_p <= state_n;
        time_p <= time_n;
    end
end

always_comb begin
    state_n = state_p;
    time_n = time_p;        

    case(state_p)
        default: begin
            state_n = state_p;   
            time_n = time_p;        
        end
        
        STATE_STOPPED:  begin
            state_n = STATE_STOPPED;            
            if (count_i)
                state_n = STATE_COUNTING;

        end
        
        STATE_COUNTING: begin
            // Default
            time_n = time_p + 1;        // data path
            state_n = STATE_COUNTING;   // control                      

            if (count_i ==0) 
                state_n = STATE_STOPPED;    // control                    
            
            if (clear_i) begin
                time_n = 0;                 // data path
                state_n = STATE_STOPPED;    // control                    
            end
        end
                            
    endcase
end

assign time_o = time_p;


endmodule
