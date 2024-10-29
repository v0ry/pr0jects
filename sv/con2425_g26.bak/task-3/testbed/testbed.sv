
module testbed();
  `include "defines.vh"
  `include "testbed_helpers.vh"
  import cpu_pkg::*;

  // reset signal
  logic reset = 0;

  // the oscillator
  integer cnt = 0;
  logic clk;
  initial clk = 0;
  always begin
    #`HALF_PERIOD clk = ~clk;
  end

  always_ff @(posedge clk or posedge reset) begin
    if(reset)
      cnt <= 0;
    else begin
      cnt <= cnt + 1;
      // Exit out long programs, you might increase that for large programs
      if(cnt > 5000)
        $finish();
    end
  end

  // dump all signals
  integer it;
  initial
  begin
    $dumpfile("riscv_core.vcd");
    $dumpvars(0, testbed);
    for (it = 0; it < 32; it++) begin
      $dumpvars(0, riscv_i.cpu_i.reg_file_i.X_p[it]);
    end
  end

  // reset signal generator
  initial
  begin
    reset = 0;
    reset = 1;
    #`RESET_DELAY
    reset = 0;
  end

  // instantiate the micro-riscv
  riscv_core riscv_i(clk, reset);

  // printing memory contents to the console
  // before and after simulation:
  initial begin
    #10
    $write("--------------------------------------------------------\n");
    $write("Memory contents before execution:\n");
    $write("--------------------------------------------------------\n");
    dump_memory(riscv_i.mem_i.initial_length);
    $write("--------------------------------------------------------\n");
    $write("\n");
    $write("Start simulation...\n\n");

    wait (riscv_i.cpu_finish); // wait until the CPU asserts finish

    // Wait a little bit to flush the pipeline and capture the last state
    #`HALF_PERIOD
    #`HALF_PERIOD
    #`HALF_PERIOD
    #`HALF_PERIOD
    #`HALF_PERIOD
    #`HALF_PERIOD
    #`HALF_PERIOD

    $write("\n");
    $write("--------------------------------------------------------\n");
    $write("Memory contents after execution:\n");
    $write("--------------------------------------------------------\n");
    dump_memory(riscv_i.mem_i.initial_length);
    $write("--------------------------------------------------------\n");
    $write("Clock cycles: %d\n", $time/(2*`HALF_PERIOD));
    $write("--------------------------------------------------------\n");
    $finish();
  end

  // print simulation results for each clock period:
  always @(posedge clk) #1
  begin
    $write("--------------------------------------------------------\n");
    print_registers;
    $write("--------------------------------------------------------\n");
  end

  always @(posedge clk) #2
  begin
    $write("[%0d]  ", $time - 2); // print $time of rising edge of clock
    $display("    PC  = %H, IR  = %H", riscv_i.cpu_i.PC_p, riscv_i.cpu_i.Instruction);
  end
endmodule
