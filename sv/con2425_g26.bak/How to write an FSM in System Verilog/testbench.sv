// https://www.youtube.com/watch?v=-o3RBvTh4Hw
`timescale 1ns/1ns
module testbench;

    // Signals for DUT connections
    logic clk; 
    logic reset;
    logic in;
    logic out;

    // DUT Instantiation
    exampleFSM dut (
        .clk(clk),
        .reset(reset),
        .x(in),
        .y(out)
    );

    // Generate waveform file
    // So where does the vcd file come from?
    initial begin
        $dumpfile("exampleFSM.vcd");
        $dumpvars(0, testbench);
    end

    // Clock generation
    always
        begin
            clk = 1; #5;
            clk = 0; #5;
        end

    // Stimulus for test cases
    initial 
        begin
            // This means, set reset to 1, and weit 10ns and do nothing
            // So what do we want to do next... Well what if the reset
            // switches and goes form high to low, let's make some cool stuff
            reset <= 1; #10; 
            reset <= 0; in <= 0; #10;
        end

endmodule
