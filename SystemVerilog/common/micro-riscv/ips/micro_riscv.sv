`include "defines.vh"
import cpu_pkg::*;

module micro_riscv(
  input logic         clk_i,
  input logic         reset_i,

  output logic [31:0] cpu_data_addr_o,
  input  logic [31:0] cpu_data_rdata_i,
  output logic [31:0] cpu_data_wdata_o,
  output logic        cpu_data_re_o,
  output logic        cpu_data_we_o,

  output logic [31:0] cpu_instr_addr_o,
  input  logic [31:0] cpu_instr_rdata_i,
  output logic        cpu_finish_o
);
  // Stop the testbench if we reach an illegal instruction or we finish the CPU via EBREAK
  logic illegal_insn, cpu_halt;
  assign cpu_finish_o = illegal_insn | cpu_halt;

  //##################################################################################################
  // Instruction Fetch
  //
  logic [31:0] PC_p, PC_n; // Program Counter
  logic [31:0] PC_incr;
  logic PC_src;


  // Next program counter
  assign PC_incr = PC_p + 4;

  always_comb begin
    PC_n = PC_p;
    casez({cpu_halt, PC_src})
      3'b1?: PC_n = PC_p;
      3'b01: PC_n = PC_alu;
      3'b00: PC_n = PC_incr;
    endcase
  end
  // Redirect PC to the instruction memory interface
  assign cpu_instr_addr_o = PC_p;

  // Model PC register
  always_ff @(posedge clk_i or posedge reset_i) begin
    if (reset_i) begin
      PC_p <= RESET_ADDR;
    end else begin
      PC_p <= PC_n;
    end
  end

  //##################################################################################################
  // Instruction Decode
  //
  // RISC-V Instruction Formats:
  //
  //           31          25 24      20 19      15 14  12 11       7 6            0
  //  R-Type: |    funct7    |   rs2    |   rs1    |funct3|   rd     |    opcode    |
  //  I-Type: |          imm[11:0]      |   rs1    |funct3|   rd     |    opcode    |
  //  S-Type: |  imm[11:5]   |   rs2    |   rs1    |funct3| imm[4:0] |    opcode    |
  //  U-Type: |                    imm                    |   rd     |    opcode    |
  //
  // RISC-V Immediate Formats:
  //
  //           31 30                 20 19            12 11 10         5 4      1  0
  // I-Imm:   |                 <-- sext 31                |    30:25   |  24:21 |20|
  // S-Imm:   |                 <-- sext 31                |    30:25   |  11:8  | 7|
  // B-Imm:   |               <-- sext 31               | 7|    30:25   |  11:8  | z|
  // U-Imm:   |31|        30:20        |      19:12     |          <-- zext         |
  // J-Imm:   |       <-- sext 31      |      19:12     |20|    30:25   |  24:21 | z|
  //
  //##################################################################################################

  logic [6:0]  opcode;
  logic [2:0]  funct3;
  logic [6:0]  funct7;
  logic [11:0] funct12;
  logic [4:0]  rd;
  logic [4:0]  rs1;
  logic [4:0]  rs2;
  logic rs1_valid, rs2_valid;

  // Just for renaming
  logic [31:0] Instruction;
  assign Instruction = cpu_instr_rdata_i;

  assign opcode  = Instruction[6:0];
  assign funct3  = Instruction[14:12];
  assign funct7  = Instruction[31:25];
  assign funct12 = Instruction[31:20];
  assign rd      = Instruction[11:7];
  assign rs1     = rs1_valid ? Instruction[19:15] : 5'b0;
  assign rs2     = rs2_valid ? Instruction[24:20] : 5'b0;

  logic signed [31:0] reg_data_1, reg_data_2, reg_write_data;
  logic alu_reg_write;

  // Register File
  register_file reg_file_i (
    .clk_i         (clk_i),
    .reset_i       (reset_i),
    .read_reg_1_i  (rs1),
    .read_data_1_o (reg_data_1),
    .read_reg_2_i  (rs2),
    .read_data_2_o (reg_data_2),
    .write_i       (alu_reg_write),
    .write_reg_i   (rd),
    .write_data_i  (reg_write_data)
  );

  logic alu_src, alu_is_branch, alu_is_jump, alu_mem_write, alu_mem_read,
        mem_to_reg, alu_pc_reg_src;
  imm_t imm_sel;
  alu_op_t alu_operator;

  // Decoder and ALU control
  always_comb begin
    alu_operator   = ALU_ADD;
    imm_sel        = IMM_I;
    alu_src        = 1'b0;
    alu_is_branch  = 1'b0;
    alu_is_jump    = 1'b0;
    alu_mem_read   = 1'b0;
    alu_mem_write  = 1'b0;
    alu_reg_write  = 1'b0;
    mem_to_reg     = 1'b0;
    alu_pc_reg_src = 1'b0;
    illegal_insn   = 1'b0;
    cpu_halt       = 1'b0;
    rs1_valid      = 1'b0;
    rs2_valid      = 1'b0;

    case(opcode)
      OPC_JAL: begin
        alu_operator  = ALU_ADD;
        imm_sel       = IMM_UJ;
        alu_is_jump   = 1'b1;
        alu_reg_write = 1'b1;
      end
      OPC_JALR: begin
        alu_operator   = ALU_ADD;
        imm_sel        = IMM_I;
        rs1_valid      = 1'b1;
        alu_is_jump    = 1'b1;
        alu_reg_write  = 1'b1;
        alu_pc_reg_src = 1'b1;
      end
      OPC_BRANCH: begin
        imm_sel       = IMM_SB;
        alu_is_branch = 1'b1;
        rs1_valid     = 1'b1;
        rs2_valid     = 1'b1;
        case (funct3)
          F3_BEQ:  alu_operator = ALU_EQ;
          F3_BNE:  alu_operator = ALU_NE;
          F3_BLT:  alu_operator = ALU_LTS;
          F3_BGE:  alu_operator = ALU_GES;
          default: illegal_insn = 1'b1;
        endcase
      end
      OPC_LOAD: begin
        alu_operator  = ALU_ADD;
        imm_sel       = IMM_I;
        rs1_valid     = 1'b1;
        alu_reg_write = 1'b1;
        alu_src       = 1'b1;
        alu_mem_read  = 1'b1;
        mem_to_reg    = 1'b1;
      end
      OPC_STORE: begin
        alu_operator  = ALU_ADD;
        imm_sel       = IMM_S;
        rs1_valid     = 1'b1;
        rs2_valid     = 1'b1;
        alu_src       = 1'b1;
        alu_mem_write = 1'b1;
      end
      OPC_LUI: begin
        alu_operator  = ALU_ADD;
        imm_sel       = IMM_U;
        alu_src       = 1'b1;
        alu_reg_write = 1'b1;
      end
      OPC_IMM: begin
        imm_sel       = IMM_I;
        rs1_valid     = 1'b1;
        alu_src       = 1'b1;
        alu_reg_write = 1'b1;

        case (funct3)
          default: illegal_insn = 1'b1;
          F3_ADD:  alu_operator = ALU_ADD;  // Add Immediate
        endcase
      end
      OPC_ALSU: begin
        alu_reg_write = 1'b1;
        rs1_valid     = 1'b1;
        rs2_valid     = 1'b1;

        case ({funct7, funct3})
          // RV32I ALU operations
          {7'b000_0000, F3_ADD}: alu_operator = ALU_ADD;   // Add
          {7'b010_0000, F3_ADD}: alu_operator = ALU_SUB;   // Sub
          {7'b000_0000, F3_XOR}: alu_operator = ALU_XOR;   // Xor
          {7'b000_0000, F3_OR }: alu_operator = ALU_OR;    // Or
          {7'b000_0000, F3_AND}: alu_operator = ALU_AND;   // And
          {7'b000_0000, F3_SLL}: alu_operator = ALU_SLL;   // Shift Left Logical
          {7'b000_0000, F3_SRL}: alu_operator = ALU_SRL;   // Shift Right Logical
          {7'b010_0000, F3_SRL}: alu_operator = ALU_SRA;   // Shift Right
          default:               illegal_insn = 1'b1;
        endcase
      end
      OPC_SYSTEM: begin
        if({funct12, rs1, funct3, rd } == 25'b0000000000010000000000000) begin  // EBREAK
          cpu_halt = 1'b1;
        end else begin
          illegal_insn = 1'b1;
        end
      end
      default: begin
        illegal_insn = 1'b1;
      end
    endcase
    // Gate out control signal in case of decoding an invalid instruction
    if(illegal_insn) begin
      alu_operator   = ALU_ADD;
      imm_sel        = IMM_I;
      alu_src        = 1'b0;
      alu_is_branch  = 1'b0;
      alu_is_jump    = 1'b0;
      alu_mem_write  = 1'b0;
      alu_mem_read   = 1'b0;
      alu_reg_write  = 1'b0;
      mem_to_reg     = 1'b0;
      alu_pc_reg_src = 1'b0;
      cpu_halt       = 1'b0;
      rs1_valid      = 1'b0;
      rs2_valid      = 1'b0;
    end
  end

  // Immediate generation
  logic signed [31:0] i_imm;
  logic signed [31:0] s_imm;
  logic signed [31:0] sb_imm;
  logic signed [31:0] u_imm;
  logic signed [31:0] uj_imm;
  logic signed [31:0] alu_imm;

  assign i_imm = {{20{Instruction[31]}}, Instruction[31:20]};
  assign s_imm = {{20{Instruction[31]}}, Instruction[31:25], Instruction[11:7]};
  assign sb_imm = {{19{Instruction[31]}}, Instruction[31], Instruction[7], Instruction[30:25], Instruction[11:8], 1'b0};
  assign u_imm = {Instruction[31:12], 12'b0};
  assign uj_imm = {{12{Instruction[31]}}, Instruction[19:12], Instruction[20], Instruction[30:21], 1'b0};

  // Immediate mux
  always_comb begin
    alu_imm = i_imm; // JALR, Load, ALUi,
    case(imm_sel)
      IMM_U:  alu_imm = u_imm; // LUI, AUIPC
      IMM_UJ: alu_imm = uj_imm; // JAL
      IMM_SB: alu_imm = sb_imm; // Conditional branches
      IMM_S:  alu_imm = s_imm;  // Store
    endcase
  end

  // ALU
  logic signed [31:0] alu_data_2;
  logic signed [31:0] alu_result;
  logic alu_branch_o;

  // Select sign-extended immediate from insruction or register value 2 as ALU input
  assign alu_data_2 = alu_src? alu_imm : reg_data_2;

  alu alu_i (
    .alu_rs1_i    (reg_data_1),
    .alu_rs2_i    (alu_data_2),
    .alu_op_i     (alu_operator),
    .alu_branch_o (alu_branch_o),
    .alu_result_o (alu_result)
  );

  // Compute PC from instruction. Source is either the current PC (direct jump)
  // or a register (indirect jump)
  logic [31:0] PC_alu;
  assign PC_alu = (alu_pc_reg_src? reg_data_1 : PC_p) + alu_imm;

  // Determine PC source based on instruction and branch result
  assign PC_src = (alu_branch_o & alu_is_branch) |  // Conditional branch taken
                   alu_is_jump;                     // Unconditional jump

  // Data memory interface
  assign cpu_data_addr_o  = alu_result;
  assign cpu_data_wdata_o = reg_data_2;
  assign cpu_data_re_o    = alu_mem_read;
  assign cpu_data_we_o    = alu_mem_write;

  // Write-back data to the register file
  always_comb begin
    reg_write_data = alu_result;
    priority casez ({mem_to_reg, alu_is_jump})
      2'b?1: reg_write_data = PC_incr;
      2'b0?: reg_write_data = alu_result;
      2'b1?: reg_write_data = cpu_data_rdata_i;
    endcase
  end
endmodule
