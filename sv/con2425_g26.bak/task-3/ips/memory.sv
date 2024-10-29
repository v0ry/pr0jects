`include "defines.vh"

module memory(
  input  logic        clk_i,
  input  logic [31:0] mem_data_addr_i,
  input  logic [31:0] mem_instr_addr_i,
  input  logic [31:0] mem_data_wdata_i,
  output logic [31:0] mem_data_rdata_o,
  output logic [31:0] mem_instr_rdata_o,
  input  logic        write_i
);
  // main memory
  logic [7:0] mem[`MEM_SIZE-1:0];

  // Read memory content
  logic [1023:0] hex_program;
  integer i = 0;
  integer ret = 1;
  integer fd;
  integer initial_length;
  initial begin
    if (!$value$plusargs("PROGRAM=%s", hex_program)) begin
      $display("ERROR: please specify +PROGRAM=<value> to start.");
      $finish;
    end

    fd = $fopen(hex_program, "r");
    if (fd == 0) begin
      $display("ERROR: cannot open file specified by +PROGRAM");
      $finish;
    end

    while (ret == 1) begin
      ret = $fscanf(fd, "%h", mem[i]);
      i = i + 1;
    end
    $fclose(fd);

    initial_length = i - 1;
  end

  // ------------------------------------
  // Read logic of the memory
  assign mem_data_rdata_o  = {
    mem[mem_data_addr_i + 3],
    mem[mem_data_addr_i + 2],
    mem[mem_data_addr_i + 1],
    mem[mem_data_addr_i]
  };
  assign mem_instr_rdata_o = {
    mem[mem_instr_addr_i + 3],
    mem[mem_instr_addr_i + 2],
    mem[mem_instr_addr_i + 1],
    mem[mem_instr_addr_i]
  };

  // ------------------------------------
  // Write logic of the memory
  always_ff @(posedge clk_i)
    if (write_i) begin
      mem[mem_data_addr_i] <= mem_data_wdata_i[7:0];
      mem[mem_data_addr_i + 1] <= mem_data_wdata_i[15:8];
      mem[mem_data_addr_i + 2] <= mem_data_wdata_i[23:16];
      mem[mem_data_addr_i + 3] <= mem_data_wdata_i[31:24];
    end
endmodule
