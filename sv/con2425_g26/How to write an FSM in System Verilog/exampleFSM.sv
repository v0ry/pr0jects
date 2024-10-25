/*
    https://www.youtube.com/watch?v=ENH-8zZLbK8&t=0s
*/
module exampleFSM(
    input logic clk, 
    input logic reset,
    input logic x,
    output logic y
);

/* 
   Why do we only need 3 bits for 5 stages?
   2^3 = 8, so we can represent 8 states with 3 bits.

   What does logic [2:0] mean?
   - This is a 3-bit wide logic type 
   - it can represent binary values from 000 to 111 or numbers up to 7.
   - { A, B, C, D, E } are the states of the FSM.
   - It is called State... but we could literally name it anything.
*/
typedef enum logic [2:0] { A, B, C, D, E } State;

/* 
   Creating state variables
*/
State currentState, nextState;

// Sequential logic for state transitions
always_ff @(posedge clk or posedge reset) begin
    if (reset)
        currentState <= A;
    else
        currentState <= nextState;
end

// Combinational logic for state transitions
always_comb

    case (currentState)
        A: if (x) 
                nextState = C;
           else 
                nextState = B;
                
        B: if (x) 
                nextState = D;
           else 
                nextState = B;

        C: if (x) 
                nextState = C;
           else 
                nextState = E;

        D: if (x) 
                nextState = C;
           else 
                nextState = E;

        E: if (x) 
                nextState = D;
           else 
                nextState = B;

        default: 
            nextState = A;
    endcase
assign y = (currentState == D | currentState == E);

endmodule

// How do we know it is working?
// We can use a testbench to simulate the FSM.
