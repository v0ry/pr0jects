/* Generated by Yosys 0.46 (git sha1 e97731b9d, clang++ 16.0.0 -fPIC -O3) */

(* src = "simple_circuit_with_mux.sv:3.1-31.10" *)
module simple_circuit_with_mux(in_a, in_b, in_c, in_x, in_y, in_z, mux_sel, out_q);
  wire _00_;
  wire _01_;
  wire _02_;
  wire _03_;
  wire _04_;
  wire _05_;
  wire _06_;
  wire _07_;
  wire _08_;
  (* src = "simple_circuit_with_mux.sv:4.15-4.19" *)
  input in_a;
  wire in_a;
  (* src = "simple_circuit_with_mux.sv:5.15-5.19" *)
  input in_b;
  wire in_b;
  (* src = "simple_circuit_with_mux.sv:6.15-6.19" *)
  input in_c;
  wire in_c;
  (* src = "simple_circuit_with_mux.sv:7.15-7.19" *)
  input in_x;
  wire in_x;
  (* src = "simple_circuit_with_mux.sv:8.15-8.19" *)
  input in_y;
  wire in_y;
  (* src = "simple_circuit_with_mux.sv:9.15-9.19" *)
  input in_z;
  wire in_z;
  (* src = "simple_circuit_with_mux.sv:10.15-10.22" *)
  input mux_sel;
  wire mux_sel;
  (* src = "simple_circuit_with_mux.sv:11.16-11.21" *)
  output out_q;
  wire out_q;
  NOT _09_ (
    .A(in_b),
    .Y(_08_)
  );
  NAND _10_ (
    .A(in_y),
    .B(in_x),
    .Y(_00_)
  );
  NOT _11_ (
    .A(_00_),
    .Y(_01_)
  );
  NAND _12_ (
    .A(in_z),
    .B(mux_sel),
    .Y(_02_)
  );
  NOR _13_ (
    .A(_01_),
    .B(_02_),
    .Y(_03_)
  );
  NOR _14_ (
    .A(_08_),
    .B(in_a),
    .Y(_04_)
  );
  NOR _15_ (
    .A(mux_sel),
    .B(in_c),
    .Y(_05_)
  );
  NOT _16_ (
    .A(_05_),
    .Y(_06_)
  );
  NOR _17_ (
    .A(_04_),
    .B(_06_),
    .Y(_07_)
  );
  NOR _18_ (
    .A(_03_),
    .B(_07_),
    .Y(out_q)
  );
endmodule
