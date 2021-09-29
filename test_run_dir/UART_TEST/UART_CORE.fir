;buildInfoPackage: chisel3, version: 3.4.2, scalaVersion: 2.12.12, sbtVersion: 1.3.10
circuit UART_CORE : 
  extmodule uart_core : 
    input clk_i : UInt<1>
    input rst_ni : UInt<1>
    input ren : UInt<1>
    input we : UInt<1>
    input wdata : UInt<32>
    input addr : UInt<8>
    input rx_i : UInt<1>
    output rdata : UInt<32>
    output tx_o : UInt<1>
    output intr_tx : UInt<1>
    
    defname = uart_core
    
    
  module UART_CORE : 
    input clock : Clock
    input reset : UInt<1>
    output io : {flip ren : UInt<1>, flip we : UInt<1>, flip wdata : UInt<32>, flip addr : UInt<8>, flip rx_i : UInt<1>, rdata : UInt<32>, tx_o : UInt<1>, intr_tx : UInt<1>}
    
    inst u_core of uart_core @[UART_CORE.scala 41:22]
    u_core.intr_tx is invalid
    u_core.tx_o is invalid
    u_core.rdata is invalid
    u_core.rx_i is invalid
    u_core.addr is invalid
    u_core.wdata is invalid
    u_core.we is invalid
    u_core.ren is invalid
    u_core.rst_ni is invalid
    u_core.clk_i is invalid
    node _clk_T = asUInt(clock) @[UART_CORE.scala 43:34]
    node _clk_T_1 = bits(_clk_T, 0, 0) @[UART_CORE.scala 43:36]
    wire clk : UInt<1>
    clk <= _clk_T_1
    node _rst_T = bits(reset, 0, 0) @[UART_CORE.scala 44:36]
    wire rst : UInt<1>
    rst <= _rst_T
    node _u_core_io_clk_i_T = not(clk) @[UART_CORE.scala 46:22]
    u_core.clk_i <= _u_core_io_clk_i_T @[UART_CORE.scala 46:19]
    node _u_core_io_rst_ni_T = not(rst) @[UART_CORE.scala 47:23]
    u_core.rst_ni <= _u_core_io_rst_ni_T @[UART_CORE.scala 47:20]
    u_core.ren <= io.ren @[UART_CORE.scala 50:17]
    u_core.we <= io.we @[UART_CORE.scala 51:16]
    u_core.wdata <= io.wdata @[UART_CORE.scala 52:19]
    u_core.addr <= io.addr @[UART_CORE.scala 53:18]
    u_core.rx_i <= io.rx_i @[UART_CORE.scala 54:18]
    io.rdata <= u_core.rdata @[UART_CORE.scala 56:12]
    io.tx_o <= u_core.tx_o @[UART_CORE.scala 57:11]
    io.intr_tx <= u_core.intr_tx @[UART_CORE.scala 58:14]
    
