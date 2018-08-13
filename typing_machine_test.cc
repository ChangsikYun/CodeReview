// Copyright 2018 Minkyu Jo

#include "typing_machine.h"
#include "typing_machine_test.h"
#include "test.h"

class TmConstructorTestSuite
{
private:
  static void BarSeparatorTest() {
    TypingMachine tm;
    ASSERT_EQ(tm.Print('_'), std::string("_"));
	ASSERT_EQ(tm.Print('|'), std::string("|"));
	ASSERT_EQ(tm.Print('\0'), std::string(""));
  }

public:
  static void RunTest() {
  //  BarSeparatorTest();
    // add more..
  }
};
class SomeOtherTestSuite
{
private:
	static void HomeKeyTest() {
		TypingMachine tm;
		tm.HomeKey();
		ASSERT_EQ(tm.Print('|'), std::string("|"));
		tm.TypeKey('A');
		tm.HomeKey();
		ASSERT_EQ(tm.Print('|'), std::string("|A"));

	}
	static void EndKeyTest() {
		TypingMachine tm;
		tm.EndKey();
		ASSERT_EQ(tm.Print('|'), std::string("|"));
		tm.TypeKey('A');
		tm.EndKey();
		ASSERT_EQ(tm.Print('|'), std::string("A|"));
	}
	static void LeftKeyTest() {
		TypingMachine tm;
		tm.LeftKey();
		ASSERT_EQ(tm.Print('|'), std::string("|"));

		tm.TypeKey('A');
		tm.TypeKey('B');
		tm.LeftKey();
		ASSERT_EQ(tm.Print('|'), std::string("A|B"));
	}
	static void RightKeyTest() {
		TypingMachine tm;

		tm.RightKey();
		ASSERT_EQ(tm.Print('|'), std::string("|"));

		tm.TypeKey('A');
		tm.TypeKey('B');
		tm.RightKey();
		ASSERT_EQ(tm.Print('|'), std::string("AB|"));
	}

	static void TypeKeyTest() {
		TypingMachine tm;
		bool result;

		result = tm.TypeKey('A');
		ASSERT_EQ(result, true);
		result = tm.TypeKey('B');
		ASSERT_EQ(result, true);
		ASSERT_EQ(tm.Print('|'), std::string("AB|"));
	}

	static void TypeKeyCountTest() {
		TypingMachine tm;
		bool result;
		int i;
		for (i = 0; i < 101; i++) {

			result = tm.TypeKey('A');
			if (i < 100) {
				ASSERT_EQ(result, true);
			}
			else {
				ASSERT_EQ(result, false);
			}
		}		
	}
	static void TypeKeyValueTest() {
		TypingMachine tm;
		bool result;

		result = tm.TypeKey(0);
		ASSERT_EQ(result, false);

		result = tm.TypeKey(255);
		ASSERT_EQ(result, false);

		result = tm.TypeKey('a');
		ASSERT_EQ(result, true);
			
	}
	static void EraseKeyTest() {
		bool result;
		TypingMachine tm;

		result = tm.EraseKey();
		ASSERT_EQ(result, false);

		tm.TypeKey('A');
		tm.TypeKey('B');
		result  = tm.EraseKey();
		ASSERT_EQ(tm.Print('|'), std::string("A|"));	
		ASSERT_EQ(result, true);
	}

	static void PrintTest() {
	
		TypingMachine tm;
		ASSERT_EQ(tm.Print('\0'), std::string(""));
		tm.TypeKey('A');
		
		ASSERT_EQ(tm.Print('|'), std::string("A|"));
		ASSERT_EQ(tm.Print('\0'), std::string("A"));
	}

public:
  static void RunTest() {
	  HomeKeyTest();
	  EndKeyTest();
	  LeftKeyTest();
	  RightKeyTest();
	  TypeKeyTest();
	  TypeKeyValueTest();
	  TypeKeyCountTest();
	  EraseKeyTest();
	  PrintTest();
  }
};

void TypingMachineTest() {
  TmConstructorTestSuite::RunTest();
  SomeOtherTestSuite::RunTest();
  // add more..
}