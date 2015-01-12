#include "TestCase_EndToEndCompiler.h"

namespace MFM {

  BEGINTESTCASECOMPILER(t3295_test_compiler_sizeofclass_bytype)
  {
    std::string GetAnswerKey()
    {
      /* gen output:
	 Unsigned Arg: 4
	 Int Arg: -8
	 Int(3) Arg: 0x3
	 Unsigned Arg: 4
	 Int Arg: 0
	 Unsigned Arg: 15
	 Unsigned Arg: 4
	 Int Arg: 0
	 Unsigned Arg: 4
	 Unsigned Arg: 3
	 Int Arg: 0
	 Bool(3) Arg: 0x7 (true)
	 Unsigned Arg: 2
      */

      //constant fold minus
      return std::string("Ue_Fu { System s();  Int(32) test() {  Unsigned(32) u;  Int(4) z;  u 4u cast = s ( u )print . Int(32) i;  i -8 cast = s ( i )print . s ( 7 cast )print . Unsigned(4) y;  u 4u cast = s ( u )print . i 0u cast = s ( i )print . s ( 15u cast )print . Unary(4) x;  u 4u cast = s ( u )print . i 0u cast = s ( i )print . s ( 4u cast )print . Bool(3) v;  u 3u cast = s ( u )print . i false cast = s ( i )print . s ( true cast )print . Bits(2) t;  u 2u cast = s ( u )print . 0 cast return } }\nExit status: 0");
    }

    std::string PresetTest(FileManagerString * fms)
    {
      bool rtn1 = fms->add("Fu.ulam", "ulam 1;\nuse System;\nelement Fu {\nSystem s;\nInt u, v;\nInt test(){\nu = System.sizeof;\ns.print(u);\n  v = Fu.sizeof;\n return v;\n}\n}\n");

      // test system quark with native overloaded print funcs; assert
      bool rtn3 = fms->add("System.ulam", "ulam 1;\nquark System {\nVoid print(Unsigned arg) native;\nVoid print(Int arg) native;\nVoid print(Int(4) arg) native;\nVoid print(Int(3) arg) native;\nVoid print(Unary(3) arg) native;\nVoid print(Bool(3) arg) native;\nVoid assert(Bool b) native;\n}\n");

      if(rtn1 && rtn3)
	return std::string("Fu.ulam");

      return std::string("");
    }
  }

  ENDTESTCASECOMPILER(t3295_test_compiler_sizeofclass_bytype)

} //end MFM

