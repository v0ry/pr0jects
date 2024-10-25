`define HALF_PERIOD 10
`define PERIOD 20
`define RESET_DELAY (`HALF_PERIOD + 1)
`define TIMEOUT 100

module calc_tb ();

    // reset generation
    logic reset = 0;
    initial begin
        reset = 0;
        reset = 1;
        #`RESET_DELAY
        reset = 0;
    end

    // clock generation
    logic clk;
    initial clk = 0;
    always begin
        #`HALF_PERIOD clk = ~clk;
    end

    // tick counter
    integer ticks = 0;
    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            ticks <= 0;
        end else begin
            ticks <= ticks + 1;
            if (ticks > `TIMEOUT) begin
                $write("Testbench ran into TIMEOUT!\n");
                $finish();
            end
        end
    end

    // dut signals
    logic [4:0] calc_inp_a;
    logic [4:0] calc_inp_b;
    logic       calc_inp_v;
    logic       calc_calc;
    logic       calc_mode;
    logic       calc_clear;

    logic [4:0] calc_result;
    logic       calc_output_v;

    // file descriptors
    integer inp_file, outp_file, ret;


    // device under test (DUT)
    calculator dut (
        .clk_i          ( clk           ),
        .rst_i          ( reset         ),
        .a_i            ( calc_inp_a    ),
        .b_i            ( calc_inp_b    ),
        .input_valid_i  ( calc_inp_v    ),
        .calc_i         ( calc_calc     ),
        .mode_i         ( calc_mode     ),
        .clear_i        ( calc_clear    ),
        .result_o       ( calc_result   ),
        .output_valid_o ( calc_output_v )
        );

    // dump variables for gtkwave
    initial begin
        $dumpfile("calculator.vcd");
        $dumpvars(0, calc_tb);
    end

    task static run_testcase(input integer tc_file, input integer out_file, output integer ret);
        ret = $fscanf(tc_file, "%d %d %b", calc_inp_a, calc_inp_b, calc_mode);
        if (ret) begin
            #`PERIOD
            calc_inp_v = 1'b1;
            #`PERIOD
            #`PERIOD
            calc_inp_v = 1'b0;
            calc_calc  = 1'b1;
            #`PERIOD
            $fdisplay(out_file, "%d %b", calc_result, calc_output_v);
            calc_clear = 1'b1;
            calc_calc = 1'b0;
            #`PERIOD
            #`PERIOD
            calc_clear = 1'b0;
        end
    endtask

    // feel free to add other testcase tasks here

    initial begin
        ret = 1;
        inp_file = $fopen("input.txt", "r");
        outp_file = $fopen("output.txt", "w");
        calc_calc = 0;
        calc_mode = 0;
        calc_clear = 0;
        calc_inp_v = 0;

        while (ret != 0) begin
            run_testcase(inp_file, outp_file, ret);
        end

        // run your custom testcases here
        // note that if you output additional text, the reference file in the
        // 'test' directory must contain your expected output too
        // otherwise 'make test' will consider your testcase as 'failed'
        // (your custom testbench is not graded - only your implementation)

        $finish();
    end

endmodule
