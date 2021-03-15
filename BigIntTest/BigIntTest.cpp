#include "pch.h"
#include "CppUnitTest.h"
#include "../BigInt/BigInt.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BigIntTest
{
	TEST_CLASS(BigIntTest)
	{
	public:

		TEST_METHOD(TestSize)
		{
			auto bigint = BigInt(std::vector<int> {1, 2, 3}, 1);
			Assert::IsTrue(bigint.GetSize() == 3);
		}

		TEST_METHOD(TestData)
		{
			auto bigint = BigInt(std::vector<int> {1, 2, 3}, 1);
			Assert::IsTrue(bigint.GetData() == std::vector<int> {1, 2, 3});
		}

		TEST_METHOD(TestSign)
		{
			auto bigint = BigInt(std::vector<int> {1, 2, 3}, 1);
			Assert::IsTrue(bigint.GetSign() == 1);
		}

		TEST_METHOD(TestStringInput)
		{
			auto bigint = BigInt("-12");
			auto excepted = BigInt(std::vector<int>{1, 2}, -1);
			Assert::IsTrue(bigint == excepted);
		}

		TEST_METHOD(TestStringInputOneDigit)
		{
			auto bigint = BigInt("1");
			Assert::IsTrue(bigint.GetData() == std::vector<int> {1});
		}

		TEST_METHOD(TestStringInputSignOnly)
		{
			auto bigint = BigInt("-");
			Assert::IsTrue(bigint.GetSize() == 0);
		}

		TEST_METHOD(TestStringInputNegativeSign)
		{
			auto bigint = BigInt("-12");
			Assert::IsTrue(bigint.GetSign() == -1);
		}

		TEST_METHOD(TestSum)
		{
			auto bigint1 = BigInt(std::vector<int> {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9}, 1);
			auto bigint2 = BigInt(std::vector<int> {9, 9, 9, 9, 9, 9}, 1);
			auto sum = bigint1 + bigint2;
			auto expected = BigInt(std::vector<int>{1, 9, 8}, 1);
			Assert::IsTrue(sum.GetData() == expected.GetData());
		}
	};
}
