/* Generated by Yosys 0.33 (git sha1 2584903a060) */

(* src = "mealy.v:1.1-52.10" *)
module \$abstract\state_machine ();
endmodule

(* src = "mealy.sv:1.1-49.10" *)
module state_machine(clk_i, reset_i, in_i, out_o);
  wire _00_;
  wire _01_;
  wire _02_;
  wire _03_;
  wire _04_;
  wire _05_;
  (* src = "mealy.sv:2.15-2.20" *)
  input clk_i;
  wire clk_i;
  (* src = "mealy.sv:4.15-4.19" *)
  input in_i;
  wire in_i;
  (* src = "mealy.sv:9.15-9.18" *)
  wire [2:0] out;
  (* src = "mealy.sv:5.22-5.27" *)
  output [2:0] out_o;
  wire [2:0] out_o;
  (* src = "mealy.sv:3.15-3.22" *)
  input reset_i;
  wire reset_i;
  (* onehot = 32'd1 *)
  wire [2:0] state_p;
  NOT _06_ (
    .A(in_i),
    .Y(_02_)
  );
  NAND _07_ (
    .A(state_p[1]),
    .B(_02_),
    .Y(_03_)
  );
  NAND _08_ (
    .A(state_p[2]),
    .B(in_i),
    .Y(_04_)
  );
  NAND _09_ (
    .A(_03_),
    .B(_04_),
    .Y(out_o[1])
  );
  NOR _10_ (
    .A(state_p[2]),
    .B(state_p[1]),
    .Y(_05_)
  );
  NOR _11_ (
    .A(in_i),
    .B(_05_),
    .Y(_00_)
  );
  NOR _12_ (
    .A(_02_),
    .B(_05_),
    .Y(_01_)
  );
  BUF _13_ (
    .A(state_p[2]),
    .Y(out_o[0])
  );
  BUF _14_ (
    .A(state_p[0]),
    .Y(out_o[2])
  );
  DFFSR _15_ (
    .C(clk_i),
    .D(_00_),
    .Q(state_p[0]),
    .R(1'h0),
    .S(reset_i)
  );
  DFFSR _16_ (
    .C(clk_i),
    .D(_01_),
    .Q(state_p[1]),
    .R(reset_i),
    .S(1'h0)
  );
  DFFSR _17_ (
    .C(clk_i),
    .D(state_p[0]),
    .Q(state_p[2]),
    .R(reset_i),
    .S(1'h0)
  );
  assign out = out_o;
endmodule
