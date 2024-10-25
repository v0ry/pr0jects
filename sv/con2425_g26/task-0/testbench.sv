module testbench();

    // clk generation
    logic clk;
    initial clk = 0;
    always begin
        #1 clk = ~clk;
    end

    // reset generation
    logic reset;
    initial begin
        reset = 0;
        reset = 1;
        #10
        reset = 0;
    end

    logic [31:0] lfsr_state_o;

    lfsr dut(clk, reset, lfsr_state_o);

    // wait and display result :)
    initial begin
        #1000
        $display("Magic value: %d", lfsr_state_o);
        $finish();
    end
endmodule
