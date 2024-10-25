package cpu_pkg;

parameter RESET_ADDR = 32'h00000000;

// OPCODE Field of RISC-V instruction
parameter OPC_LOAD   = 7'h03;
parameter OPC_IMM    = 7'h13;
parameter OPC_STORE  = 7'h23;
parameter OPC_ALSU   = 7'h33;
parameter OPC_BRANCH = 7'h63;
parameter OPC_SYSTEM = 7'h73;
parameter OPC_AUIPC  = 7'h17;
parameter OPC_LUI    = 7'h37;
parameter OPC_JALR   = 7'h67;
parameter OPC_JAL    = 7'h6F;

// Branch codes
parameter F3_BEQ =  3'b000;
parameter F3_BNE =  3'b001;
parameter F3_BLT =  3'b100;
parameter F3_BGE =  3'b101;

parameter F3_ADD  = 3'b000;
parameter F3_SLL  = 3'b001;
parameter F3_SRL  = 3'b101;
parameter F3_OR   = 3'b110;
parameter F3_AND  = 3'b111;
parameter F3_XOR  = 3'b100;
parameter F3_LW   = 3'b010;

typedef enum logic [2:0] { IMM_I, IMM_U, IMM_UJ, IMM_SB, IMM_S } imm_t;

typedef enum logic [3:0] { ALU_ADD, ALU_SUB, ALU_XOR, ALU_OR,
                           ALU_AND, ALU_SRL, ALU_SRA, ALU_SLL,
                           ALU_EQ, ALU_NE, ALU_GES, ALU_LTS } alu_op_t;

endpackage
