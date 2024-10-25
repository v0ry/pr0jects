`include "defines.vh"

module riscv_core(
  input logic clk_i,
  input logic reset_i
);
  logic cpu_finish;

  // Instruction memory interface
  logic [31:0] instr_addr;   // Address, word aligned
  logic [31:0] instr_rdata;  // Data read from memory

  // Data memory interface
  logic        data_we;      // Write Enable, high for writes
  logic        data_re;      // Read Enable, high for reads
  logic [31:0] data_addr;    // Address, word aligned
  logic [31:0] data_wdata;   // Data to be written to memory
  logic [31:0] data_rdata;   // Data read from memory

  logic [31:0] mem_data_rdata;
  logic [31:0] mem_instr_rdata;
  logic [31:0] stdin_rdata;

  logic instr_mem_sel, mem_sel, stdin_sel, stdout_sel;
  logic stdin_re;
  logic mem_we, stdin_we, stdout_we;


  // Model selection signals for all peripherals/memory
  always_comb begin
    instr_mem_sel = instr_addr >= `MEM_START    && instr_addr < `MEM_START + `MEM_SIZE;
    mem_sel       = data_addr  >= `MEM_START    && data_addr  < `MEM_START + `MEM_SIZE;
    stdin_sel     = data_addr  >= `STDIN_START  && data_addr  < `STDIN_START  + `STDIN_SIZE;
    stdout_sel    = data_addr  >= `STDOUT_START && data_addr  < `STDOUT_START + `STDOUT_SIZE;
  end

  // Model read/write-enable signals for all peripherals
  always_comb begin
    stdin_re  = data_re & stdin_sel;
    mem_we    = data_we & mem_sel;
    stdin_we  = data_we & stdin_sel;
    stdout_we = data_we & stdout_sel;
  end

  // Model output logic
  always_comb begin
    // Default assignment
    if (instr_mem_sel) instr_rdata = mem_instr_rdata;
    else               instr_rdata = {32{1'bx}};

    if (mem_sel)        data_rdata = mem_data_rdata;
    else if (stdin_sel) data_rdata = stdin_rdata;
    else                data_rdata = {32{1'bx}};
  end

  micro_riscv cpu_i(
    .clk_i(clk_i),
    .reset_i(reset_i),
    .cpu_data_addr_o(data_addr),
    .cpu_data_rdata_i(data_rdata),
    .cpu_data_wdata_o(data_wdata),
    .cpu_data_re_o(data_re),
    .cpu_data_we_o(data_we),
    .cpu_instr_addr_o(instr_addr),
    .cpu_instr_rdata_i(instr_rdata),
    .cpu_finish_o(cpu_finish)
  );
  memory mem_i(
    .clk_i(clk_i),
    .mem_data_addr_i(data_addr),
    .mem_instr_addr_i(instr_addr),
    .mem_data_wdata_i(data_wdata),
    .mem_data_rdata_o(mem_data_rdata),
    .mem_instr_rdata_o(mem_instr_rdata),
    .write_i(mem_we)
  );
  stdin stdin_i(
    .clk_i(clk_i),
    .reset_i(reset_i),
    .read_i(stdin_re),
    .dout_o(stdin_rdata)
  );
  stdout stdout_i(
    .clk_i(clk_i),
    .write_i(stdout_we),
    .din_i(data_wdata)
  );
endmodule

