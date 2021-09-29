module mytry(
  input   clock,
  input   reset,
  output  io_result
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_REG_INIT
  reg [15:0] count; // @[mytry.scala 12:29]
  wire [7:0] _T = 8'h10 - 8'h1; // @[mytry.scala 13:28]
  wire [15:0] _GEN_1 = {{8{_T[7]}},_T}; // @[mytry.scala 13:20]
  wire [15:0] _count_T_2 = $signed(count) + 16'sh1; // @[mytry.scala 16:32]
  wire  _GEN_2 = count[15]; // @[mytry.scala 18:27]
  wire [15:0] _io_result_T = {16{_GEN_2}}; // @[mytry.scala 18:27]
  assign io_result = _io_result_T[0]; // @[mytry.scala 18:27]
  always @(posedge clock) begin
    if (reset) begin // @[mytry.scala 12:29]
      count <= 16'sh0; // @[mytry.scala 12:29]
    end else if ($signed(count) == $signed(_GEN_1)) begin // @[mytry.scala 13:36]
      count <= 16'sh0; // @[mytry.scala 14:23]
    end else begin
      count <= _count_T_2; // @[mytry.scala 16:23]
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  count = _RAND_0[15:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
