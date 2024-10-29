module testbed_cordic();

    logic clk, reset;

    // Input / Output
    logic [31:0] angle;
    logic        sine_cosine;
    logic        start;
    logic [31:0] result;
    logic        busy;
    logic        valid;
    integer inp_file, outp_file, tmp;

    // Instance of cordic module
    cordic cordic_i(
      .clk_i          (clk),
      .reset_i        (reset),
      .angle_i        (angle),
      .sine_cosine_i  (sine_cosine),
      .start_i        (start),
      .result_o       (result),
      .busy_o         (busy),
      .valid_o        (valid)
    );

    // Clock generator
    initial clk = 0;
    always begin
      #50 clk = ~clk;
    end

    // Reset
    initial begin
      reset = 0;
      reset = 1;
      #100
      reset = 0;
    end

    // dump all variables
    initial begin
      $dumpfile("cordic.vcd");
      $dumpvars(0, testbed_cordic);
    end

    initial begin
      // Init stuff
      start = 0;
      angle = 1;

      inp_file  = $fopen("input.txt", "r");
      outp_file = $fopen("output.txt", "w");

      #200

      while(angle != 0) begin
        // Read data from stdi
        tmp = $fscanf(inp_file, "%h %b", angle, sine_cosine);
        #100

        if(angle != 0) begin
          // Start the computation
          start = 1;
          #110
          start = 0;

          // Wait until computation finished
          wait(valid);
          #200

          // Write result to stdout
          $fdisplay(outp_file, "%H", result);
        end
      end

      #200
      // Stop the simulation
      $finish();
    end
endmodule
