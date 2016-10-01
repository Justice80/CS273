#include "stdafx.h"
#include "CppUnitTest.h"
#include "readInt.h"
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTester
{		
	TEST_CLASS(READINT_TEST)
	{
	public:
		
		TEST_METHOD(Case1) {

			std::ifstream ss("\\UnitTester\\zeroinput.txt");
			if (ss.fail())
				throw int(-1);

			std::streambuf *orig_cin = std::cin.rdbuf(ss.rdbuf());

			Assert::AreEqual(read_int("My prompt: ", -3, 3), 0);

			std::cin.rdbuf(orig_cin);

			ss.close();

		}

		TEST_METHOD(Case2) {

			auto func = []() {
				read_int("My prompt: ", 5, 1);
			};
			Assert::ExpectException<std::invalid_argument>(func);

		}

		TEST_METHOD(Case3) {

			std::ifstream ss("\\UnitTester\\zeroinput.txt");
			if (ss.fail())
				throw int(-1);

			std::streambuf *orig_cin = std::cin.rdbuf(ss.rdbuf());

			Assert::AreEqual(read_int("My prompt: ", 0, 4), 0);

			std::cin.rdbuf(orig_cin);

			ss.close();

		}

		TEST_METHOD(Case4) {

			auto func = []() {
				read_int("My prompt: ", 0, 0);
			};
			Assert::ExpectException<std::invalid_argument>(func);

		}

	};
}