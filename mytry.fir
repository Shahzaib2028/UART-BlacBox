;buildInfoPackage: chisel3, version: 3.4.2, scalaVersion: 2.12.12, sbtVersion: 1.3.10
circuit mytry : 
  module mytry : 
    input clock : Clock
    input reset : UInt<1>
    output io : {result : UInt<1>}
    
    node _max_T = dshl(UInt<1>("h01"), UInt<3>("h04")) @[mytry.scala 11:24]
    node _max_T_1 = sub(_max_T, UInt<1>("h01")) @[mytry.scala 11:40]
    node max = tail(_max_T_1, 1) @[mytry.scala 11:40]
    reg count : SInt<16>, clock with : (reset => (reset, asSInt(UInt<16>("h00")))) @[mytry.scala 12:29]
    node _T = asSInt(max) @[mytry.scala 13:28]
    node _T_1 = eq(count, _T) @[mytry.scala 13:20]
    when _T_1 : @[mytry.scala 13:36]
      count <= asSInt(UInt<1>("h00")) @[mytry.scala 14:23]
      skip @[mytry.scala 13:36]
    else : @[mytry.scala 15:21]
      node _count_T = add(count, asSInt(UInt<2>("h01"))) @[mytry.scala 16:32]
      node _count_T_1 = tail(_count_T, 1) @[mytry.scala 16:32]
      node _count_T_2 = asSInt(_count_T_1) @[mytry.scala 16:32]
      count <= _count_T_2 @[mytry.scala 16:23]
      skip @[mytry.scala 15:21]
    node _io_result_T = dshr(count, UInt<4>("h0f")) @[mytry.scala 18:27]
    node _io_result_T_1 = bits(_io_result_T, 0, 0) @[mytry.scala 18:27]
    io.result <= _io_result_T_1 @[mytry.scala 18:19]
    
