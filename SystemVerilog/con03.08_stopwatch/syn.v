/* Generated by Yosys 0.46 (git sha1 e97731b9d, clang++ 16.0.0 -fPIC -O3) */

(* src = "stopwatch.sv:2.1-63.10" *)
module stopwatch(clk_i, reset_i, count_i, clear_i, time_o);
  wire _000_;
  wire _001_;
  wire _002_;
  wire _003_;
  wire _004_;
  wire _005_;
  wire _006_;
  wire _007_;
  wire _008_;
  wire _009_;
  wire _010_;
  wire _011_;
  wire _012_;
  wire _013_;
  wire _014_;
  wire _015_;
  wire _016_;
  wire _017_;
  wire _018_;
  wire _019_;
  wire _020_;
  wire _021_;
  wire _022_;
  wire _023_;
  wire _024_;
  wire _025_;
  wire _026_;
  wire _027_;
  wire _028_;
  wire _029_;
  wire _030_;
  wire _031_;
  wire _032_;
  wire _033_;
  wire _034_;
  wire _035_;
  wire _036_;
  wire _037_;
  wire _038_;
  wire _039_;
  wire _040_;
  wire _041_;
  wire _042_;
  wire _043_;
  wire _044_;
  wire _045_;
  wire _046_;
  wire _047_;
  (* src = "stopwatch.sv:6.17-6.24" *)
  input clear_i;
  wire clear_i;
  (* src = "stopwatch.sv:3.17-3.22" *)
  input clk_i;
  wire clk_i;
  (* src = "stopwatch.sv:5.17-5.24" *)
  input count_i;
  wire count_i;
  (* src = "stopwatch.sv:4.17-4.24" *)
  input reset_i;
  wire reset_i;
  (* enum_type = "$enum0" *)
  (* src = "stopwatch.sv:10.53-10.60" *)
  wire state_n;
  (* enum_type = "$enum0" *)
  (* src = "stopwatch.sv:10.44-10.51" *)
  wire state_p;
  (* src = "stopwatch.sv:7.24-7.30" *)
  output [7:0] time_o;
  wire [7:0] time_o;
  (* src = "stopwatch.sv:12.13-12.19" *)
  wire [7:0] time_p;
  NOT _048_ (
    .A(time_p[1]),
    .Y(_008_)
  );
  NOT _049_ (
    .A(time_p[2]),
    .Y(_009_)
  );
  NOT _050_ (
    .A(time_p[3]),
    .Y(_010_)
  );
  NOT _051_ (
    .A(time_p[4]),
    .Y(_011_)
  );
  NOT _052_ (
    .A(time_p[5]),
    .Y(_012_)
  );
  NOT _053_ (
    .A(time_p[7]),
    .Y(_013_)
  );
  NAND _054_ (
    .A(clear_i),
    .B(state_p),
    .Y(_014_)
  );
  NAND _055_ (
    .A(count_i),
    .B(_014_),
    .Y(_015_)
  );
  NOT _056_ (
    .A(_015_),
    .Y(state_n)
  );
  NAND _057_ (
    .A(time_p[0]),
    .B(state_p),
    .Y(_016_)
  );
  NOT _058_ (
    .A(_016_),
    .Y(_017_)
  );
  NOR _059_ (
    .A(time_p[0]),
    .B(state_p),
    .Y(_018_)
  );
  NOT _060_ (
    .A(_018_),
    .Y(_019_)
  );
  NAND _061_ (
    .A(_014_),
    .B(_019_),
    .Y(_020_)
  );
  NOR _062_ (
    .A(_017_),
    .B(_020_),
    .Y(_000_)
  );
  NOR _063_ (
    .A(_008_),
    .B(_016_),
    .Y(_021_)
  );
  NAND _064_ (
    .A(time_p[1]),
    .B(_017_),
    .Y(_022_)
  );
  NAND _065_ (
    .A(_008_),
    .B(_016_),
    .Y(_023_)
  );
  NAND _066_ (
    .A(_014_),
    .B(_023_),
    .Y(_024_)
  );
  NOR _067_ (
    .A(_021_),
    .B(_024_),
    .Y(_001_)
  );
  NOR _068_ (
    .A(_009_),
    .B(_022_),
    .Y(_025_)
  );
  NAND _069_ (
    .A(time_p[2]),
    .B(_021_),
    .Y(_026_)
  );
  NAND _070_ (
    .A(_009_),
    .B(_022_),
    .Y(_027_)
  );
  NAND _071_ (
    .A(_014_),
    .B(_027_),
    .Y(_028_)
  );
  NOR _072_ (
    .A(_025_),
    .B(_028_),
    .Y(_002_)
  );
  NOR _073_ (
    .A(_010_),
    .B(_026_),
    .Y(_029_)
  );
  NAND _074_ (
    .A(time_p[3]),
    .B(_025_),
    .Y(_030_)
  );
  NAND _075_ (
    .A(_010_),
    .B(_026_),
    .Y(_031_)
  );
  NAND _076_ (
    .A(_014_),
    .B(_031_),
    .Y(_032_)
  );
  NOR _077_ (
    .A(_029_),
    .B(_032_),
    .Y(_003_)
  );
  NOR _078_ (
    .A(_011_),
    .B(_030_),
    .Y(_033_)
  );
  NAND _079_ (
    .A(time_p[4]),
    .B(_029_),
    .Y(_034_)
  );
  NAND _080_ (
    .A(_011_),
    .B(_030_),
    .Y(_035_)
  );
  NAND _081_ (
    .A(_014_),
    .B(_035_),
    .Y(_036_)
  );
  NOR _082_ (
    .A(_033_),
    .B(_036_),
    .Y(_004_)
  );
  NOR _083_ (
    .A(_012_),
    .B(_034_),
    .Y(_037_)
  );
  NAND _084_ (
    .A(_012_),
    .B(_034_),
    .Y(_038_)
  );
  NAND _085_ (
    .A(_014_),
    .B(_038_),
    .Y(_039_)
  );
  NOR _086_ (
    .A(_037_),
    .B(_039_),
    .Y(_005_)
  );
  NAND _087_ (
    .A(time_p[6]),
    .B(_037_),
    .Y(_040_)
  );
  NOT _088_ (
    .A(_040_),
    .Y(_041_)
  );
  NOR _089_ (
    .A(time_p[6]),
    .B(_037_),
    .Y(_042_)
  );
  NOT _090_ (
    .A(_042_),
    .Y(_043_)
  );
  NAND _091_ (
    .A(_014_),
    .B(_043_),
    .Y(_044_)
  );
  NOR _092_ (
    .A(_041_),
    .B(_044_),
    .Y(_006_)
  );
  NOR _093_ (
    .A(_013_),
    .B(_040_),
    .Y(_045_)
  );
  NAND _094_ (
    .A(_013_),
    .B(_040_),
    .Y(_046_)
  );
  NAND _095_ (
    .A(_014_),
    .B(_046_),
    .Y(_047_)
  );
  NOR _096_ (
    .A(_045_),
    .B(_047_),
    .Y(_007_)
  );
  (* src = "stopwatch.sv:15.1-24.4" *)
  DFFSR _097_ (
    .C(clk_i),
    .D(_000_),
    .Q(time_p[0]),
    .R(reset_i),
    .S(1'h0)
  );
  (* src = "stopwatch.sv:15.1-24.4" *)
  DFFSR _098_ (
    .C(clk_i),
    .D(_001_),
    .Q(time_p[1]),
    .R(reset_i),
    .S(1'h0)
  );
  (* src = "stopwatch.sv:15.1-24.4" *)
  DFFSR _099_ (
    .C(clk_i),
    .D(_002_),
    .Q(time_p[2]),
    .R(reset_i),
    .S(1'h0)
  );
  (* src = "stopwatch.sv:15.1-24.4" *)
  DFFSR _100_ (
    .C(clk_i),
    .D(_003_),
    .Q(time_p[3]),
    .R(reset_i),
    .S(1'h0)
  );
  (* src = "stopwatch.sv:15.1-24.4" *)
  DFFSR _101_ (
    .C(clk_i),
    .D(_004_),
    .Q(time_p[4]),
    .R(reset_i),
    .S(1'h0)
  );
  (* src = "stopwatch.sv:15.1-24.4" *)
  DFFSR _102_ (
    .C(clk_i),
    .D(_005_),
    .Q(time_p[5]),
    .R(reset_i),
    .S(1'h0)
  );
  (* src = "stopwatch.sv:15.1-24.4" *)
  DFFSR _103_ (
    .C(clk_i),
    .D(_006_),
    .Q(time_p[6]),
    .R(reset_i),
    .S(1'h0)
  );
  (* src = "stopwatch.sv:15.1-24.4" *)
  DFFSR _104_ (
    .C(clk_i),
    .D(_007_),
    .Q(time_p[7]),
    .R(reset_i),
    .S(1'h0)
  );
  (* src = "stopwatch.sv:15.1-24.4" *)
  DFFSR _105_ (
    .C(clk_i),
    .D(state_n),
    .Q(state_p),
    .R(reset_i),
    .S(1'h0)
  );
  assign time_o = time_p;
endmodule
