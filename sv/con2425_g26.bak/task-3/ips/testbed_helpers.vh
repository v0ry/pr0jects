 task print_decode;
  begin
    print_opcodes;
    print_argregs;
    print_immediates;
  end
endtask

task print_opcodes;
  // begin
  //   $write(
  //     "== opc =  %b, f3  =      %b, f7  =  %b\n",
  //       riscv_i.cpu_i.opcode, riscv_i.cpu_i.funct3, riscv_i.cpu_i.funct7
  //   );
  // end
endtask

task print_argregs;
  // begin
  //   $write(
  //     "== rd  =       %d, rs1 =       %d, rs2 =       %d\n",
  //       riscv_i.cpu_i.rd, riscv_i.cpu_i.rs1, riscv_i.cpu_i.rs2
  //   );
  // end
endtask

task print_immediates;
  // begin
  //   $write(
  //     "== i_i = %H, s_i = %H, b_i = %H, u_i = %H, j_i = %H\n",
  //       riscv_i.cpu_i.i_imm, riscv_i.cpu_i.s_imm, riscv_i.cpu_i.b_imm,
  //       riscv_i.cpu_i.u_imm, riscv_i.cpu_i.j_imm
  //   );
  // end
endtask

task print_registers;
  // begin
  //   $write(
  //     ":: x0  = %H, x1  = %H, x2  = %H, x3  = %H, x4  = %H, x5  = %H, x6  = %H, x7  = %H\n",
  //       riscv_i.cpu_i.X_p[0], riscv_i.cpu_i.X_p[1], riscv_i.cpu_i.X_p[2], riscv_i.cpu_i.X_p[3],
  //       riscv_i.cpu_i.X_p[4], riscv_i.cpu_i.X_p[5], riscv_i.cpu_i.X_p[6], riscv_i.cpu_i.X_p[7],

  //     ":: x8  = %H, x9  = %H, x10 = %H, x11 = %H, x12 = %H, x13 = %H, x14 = %H, x15 = %H\n",
  //       riscv_i.cpu_i.X_p[8], riscv_i.cpu_i.X_p[9], riscv_i.cpu_i.X_p[10], riscv_i.cpu_i.X_p[11],
  //       riscv_i.cpu_i.X_p[12], riscv_i.cpu_i.X_p[13], riscv_i.cpu_i.X_p[14], riscv_i.cpu_i.X_p[15],

  //     ":: x16 = %H, x17 = %H, x18 = %H, x19 = %H, x20 = %H, x21 = %H, x22 = %H, x23 = %H\n",
  //       riscv_i.cpu_i.X_p[16], riscv_i.cpu_i.X_p[17], riscv_i.cpu_i.X_p[18], riscv_i.cpu_i.X_p[19],
  //       riscv_i.cpu_i.X_p[20], riscv_i.cpu_i.X_p[21], riscv_i.cpu_i.X_p[22], riscv_i.cpu_i.X_p[23],

  //     ":: x24 = %H, x25 = %H, x26 = %H, x27 = %H, x28 = %H, x29 = %H, x30 = %H, x31 = %H\n",
  //       riscv_i.cpu_i.X_p[24], riscv_i.cpu_i.X_p[25], riscv_i.cpu_i.X_p[26], riscv_i.cpu_i.X_p[27],
  //       riscv_i.cpu_i.X_p[28], riscv_i.cpu_i.X_p[29], riscv_i.cpu_i.X_p[30], riscv_i.cpu_i.X_p[31]
  //   );
  // end
endtask

task dump_memory;
  input [31:0] end_addr;
  integer i;
  integer j;
  begin
    $write("         ");
    for (j = 0; j < 16; j = j + 1) begin
      $write("  %01h", j[3:0]);
    end
    $display("");

    for (i = 0; i < end_addr; i = i + 16) begin
      $write("%08h:", i[31:0]);
      for (j = 0; j < 16 && i + j < end_addr; j = j + 1) begin
          $write(" %02h", riscv_i.mem_i.mem[i + j]);
      end
      $display("");
    end
  end
endtask