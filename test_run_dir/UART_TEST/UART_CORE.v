module UART_CORE(
  input         clock,
  input         reset,
  input         io_ren,
  input         io_we,
  input  [31:0] io_wdata,
  input  [7:0]  io_addr,
  input         io_rx_i,
  output [31:0] io_rdata,
  output        io_tx_o,
  output        io_intr_tx
);
  wire  u_core_clk_i; // @[UART_CORE.scala 41:22]
  wire  u_core_rst_ni; // @[UART_CORE.scala 41:22]
  wire  u_core_ren; // @[UART_CORE.scala 41:22]
  wire  u_core_we; // @[UART_CORE.scala 41:22]
  wire [31:0] u_core_wdata; // @[UART_CORE.scala 41:22]
  wire [7:0] u_core_addr; // @[UART_CORE.scala 41:22]
  wire  u_core_rx_i; // @[UART_CORE.scala 41:22]
  wire [31:0] u_core_rdata; // @[UART_CORE.scala 41:22]
  wire  u_core_tx_o; // @[UART_CORE.scala 41:22]
  wire  u_core_intr_tx; // @[UART_CORE.scala 41:22]
  uart_core u_core ( // @[UART_CORE.scala 41:22]
    .clk_i(u_core_clk_i),
    .rst_ni(u_core_rst_ni),
    .ren(u_core_ren),
    .we(u_core_we),
    .wdata(u_core_wdata),
    .addr(u_core_addr),
    .rx_i(u_core_rx_i),
    .rdata(u_core_rdata),
    .tx_o(u_core_tx_o),
    .intr_tx(u_core_intr_tx)
  );
  assign io_rdata = u_core_rdata; // @[UART_CORE.scala 56:12]
  assign io_tx_o = u_core_tx_o; // @[UART_CORE.scala 57:11]
  assign io_intr_tx = u_core_intr_tx; // @[UART_CORE.scala 58:14]
  assign u_core_clk_i = ~clock; // @[UART_CORE.scala 46:22]
  assign u_core_rst_ni = ~reset; // @[UART_CORE.scala 47:23]
  assign u_core_ren = io_ren; // @[UART_CORE.scala 50:17]
  assign u_core_we = io_we; // @[UART_CORE.scala 51:16]
  assign u_core_wdata = io_wdata; // @[UART_CORE.scala 52:19]
  assign u_core_addr = io_addr; // @[UART_CORE.scala 53:18]
  assign u_core_rx_i = io_rx_i; // @[UART_CORE.scala 54:18]
endmodule
