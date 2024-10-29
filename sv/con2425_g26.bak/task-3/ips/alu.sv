import cpu_pkg::*;

module alu(
  input logic [31:0]  alu_rs1_i,
  input logic [31:0]  alu_rs2_i,
  input alu_op_t      alu_op_i,
  output logic        alu_branch_o,
  output logic [31:0] alu_result_o
);
  always_comb begin
    case(alu_op_i)
      default: alu_result_o = 32'b0;
      ALU_ADD: alu_result_o = alu_rs1_i + alu_rs2_i;            // ADD
      ALU_SUB: alu_result_o = alu_rs1_i - alu_rs2_i;            // SUB
      ALU_XOR: alu_result_o = alu_rs1_i ^ alu_rs2_i;            // XOR
      ALU_OR:  alu_result_o = alu_rs1_i | alu_rs2_i;            // OR
      ALU_AND: alu_result_o = alu_rs1_i & alu_rs2_i;            // AND
      ALU_SRL: alu_result_o = alu_rs1_i >> alu_rs2_i;           // SRL
      ALU_SRA: alu_result_o = $signed(alu_rs1_i) >>> alu_rs2_i; // SRA
      ALU_SLL: alu_result_o = alu_rs1_i <<  alu_rs2_i;          // SLL
    endcase
  end

  logic is_equal, is_greater;
  assign is_equal = alu_rs1_i == alu_rs2_i;
  assign is_greater = $signed(alu_rs1_i) > $signed(alu_rs2_i);

  always_comb begin
    case(alu_op_i)
      default: alu_branch_o = 1'b0;
      ALU_EQ:  alu_branch_o = is_equal;
      ALU_NE:  alu_branch_o = ~is_equal;
      ALU_LTS: alu_branch_o = ~is_greater & ~is_equal;
      ALU_GES: alu_branch_o = is_greater | is_equal;
    endcase
  end
endmodule
