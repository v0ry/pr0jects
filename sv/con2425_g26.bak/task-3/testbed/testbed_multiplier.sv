
module testbench_multiplier ();
  logic         clk;
  logic         reset;
  logic         start;
  logic         busy;
  logic [31:0]  a;
  logic [31:0]  b;
  logic         finish;
  logic [63:0]  result;

  integer infile, outfile, read;
  longint unsigned expected_res;

  multiplier mult(
    .clk_i      (clk),
    .rst_i      (reset),
    .start_i    (start),
    .a_i        (a),
    .b_i        (b),
    .busy_o     (busy),
    .finish_o   (finish),
    .result_o   (result)
  );


  always begin
    #50 clk = ~clk;
  end

  initial
  begin
    $dumpfile("_sim/multiplier.vcd");
    $dumpvars(0, testbench_multiplier);
  end

  initial begin
    infile = $fopen("./testcases/testcases_multiplier.txt", "r");
    outfile = $fopen("_sim/output_multiplier.txt", "w");

    clk   = 0;
    start = 0;
    reset = 1;
    #100
    reset = 0;
    #100
    a = 0;
    b = 0;

    while (1 == 1) begin
      read = $fscanf(infile, "%d %d %d", a, b, expected_res);
      if (read == -1) begin
        $fdisplay(outfile, "All tests completed successfully!");
        $display("All tests completed successfully!");
        #200
        $finish();
      end

      #120
      start = 1;
      #120
      start = 0;
      wait(finish);
      $fdisplay(outfile, "%d * %d = %d (expected %d)", a, b, result, expected_res);

      if (expected_res != result) begin
        $fdisplay(outfile, "Unexpected result on last computation!");
        $display("Unexpected result on last computation!");
        #200
        $finish();
      end
    end
  end

endmodule