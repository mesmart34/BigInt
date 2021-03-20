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

		TEST_METHOD(TestSum1)
		{
			auto bigint1 = BigInt(std::vector<int> {1, 1, 5, 2}, 1);
			auto bigint2 = BigInt(std::vector<int> {7, 4}, 1);
			auto sum = bigint1 + bigint2;
			auto expected = BigInt(std::vector<int>{1, 2, 2, 6}, 1);
			Assert::IsTrue(sum.GetData() == expected.GetData());
		}

		TEST_METHOD(TestSum2)
		{
			auto bigint1 = BigInt(std::vector<int> {1, 1, 5, 2}, 1);
			auto bigint2 = BigInt(std::vector<int> {0}, 1);
			auto sum = bigint1 + bigint2;
			auto expected = BigInt(std::vector<int>{1, 1, 5, 2}, 1);
			Assert::IsTrue(sum.GetData() == expected.GetData());
		}

		TEST_METHOD(TestSum3)
		{
			auto bigint1 = BigInt(std::vector<int> {1, 1, 5, 2}, 1);
			auto bigint2 = BigInt(std::vector<int> {1, 1, 5, 2}, 1);
			auto sum = bigint1 + bigint2;
			auto expected = BigInt(std::vector<int>{2, 3, 0, 4}, 1);
			Assert::IsTrue(sum.GetData() == expected.GetData());
		}

		TEST_METHOD(TestSum4)
		{
			auto bigint1 = BigInt(std::vector<int> {9, 9, 9, 9}, 1);
			auto bigint2 = BigInt(std::vector<int> {9, 9}, 1);
			auto sum = bigint1 + bigint2;
			auto expected = BigInt(std::vector<int>{1, 0, 0, 9, 8}, 1);
			Assert::IsTrue(sum.GetData() == expected.GetData());
		}

		TEST_METHOD(TestSum5)
		{
			auto bigint1 = BigInt(std::vector<int> {9, 9}, 1);
			auto bigint2 = BigInt(std::vector<int> {9, 9}, 1);
			auto sum = bigint1 + bigint2;
			auto expected = BigInt(std::vector<int>{1, 9, 8}, 1);
			Assert::IsTrue(sum.GetData() == expected.GetData());
		}

		TEST_METHOD(TestSum6)
		{
			auto bigint1 = BigInt(std::vector<int> {9, 9}, 1);
			auto bigint2 = BigInt(std::vector<int> {9, 9}, 1);
			auto sum = bigint1 + bigint2;
			auto expected = BigInt(std::vector<int>{1, 9, 8}, 1);
			Assert::IsTrue(sum.GetData() == expected.GetData());
		}

		TEST_METHOD(TestSum7)
		{
			auto bigint1 = BigInt(std::vector<int> {9}, 1);
			auto bigint2 = BigInt(std::vector<int> {5}, -1);
			auto sum = bigint1 + bigint2;
			auto expected = BigInt(std::vector<int>{4}, 1);
			Assert::IsTrue(sum.GetData() == expected.GetData());
		}

		TEST_METHOD(TestSum8)
		{
			auto bigint1 = BigInt(std::vector<int> {3}, 1);
			auto bigint2 = BigInt(std::vector<int> {5}, -1);
			auto sum = bigint1 + bigint2;
			auto expected = BigInt(std::vector<int>{2}, -1);
			Assert::IsTrue(sum.GetData() == expected.GetData());
		}

		TEST_METHOD(TestSum9)
		{
			auto bigint1 = BigInt(std::vector<int> {9, 9, 9}, 1);
			auto bigint2 = BigInt(std::vector<int> {9, 9}, -1);
			auto sum = bigint1 + bigint2;
			auto expected = BigInt(std::vector<int>{9, 0, 0}, 1);
			Assert::IsTrue(sum.GetData() == expected.GetData());
		}

		TEST_METHOD(Equal1)
		{
			auto bigint1 = BigInt(std::vector<int> {9, 9, 9}, 1);
			auto bigint2 = BigInt(std::vector<int> {9, 9}, -1);
			Assert::IsFalse(bigint1 == bigint2);
		}

		TEST_METHOD(Equal2)
		{
			auto bigint1 = BigInt(std::vector<int> {9, 9, 9}, 1);
			auto bigint2 = BigInt(std::vector<int> {9, 9, 9}, 1);
			Assert::IsTrue(bigint1 == bigint2);
		}

		TEST_METHOD(TestSub1)
		{
			auto bigint1 = BigInt(std::vector<int> {3}, 1);
			auto bigint2 = BigInt(std::vector<int> {5}, -1);
			auto sum = bigint1 - bigint2;
			auto expected = BigInt(std::vector<int>{8}, -1);
			Assert::IsTrue(sum.GetData() == expected.GetData());
		}

		TEST_METHOD(TestSub2)
		{
			auto bigint1 = BigInt(std::vector<int> {3}, 1);
			auto bigint2 = BigInt(std::vector<int> {5}, 1);
			auto sum = bigint1 - bigint2;
			auto expected = BigInt(std::vector<int>{2}, -1);
			Assert::IsTrue(sum.GetData() == expected.GetData());
		}

		TEST_METHOD(TestSub3)
		{
			auto bigint1 = BigInt(std::vector<int> {1, 0}, 1);
			auto bigint2 = BigInt(std::vector<int> {1, 2, 5}, 1);
			auto sum = bigint1 - bigint2;
			auto expected = BigInt(std::vector<int>{1, 1, 5}, -1);
			Assert::IsTrue(sum.GetData() == expected.GetData());
		}

		TEST_METHOD(TestSub4)
		{
			auto bigint1 = BigInt(std::vector<int> {1, 0, 0, 0}, 1);
			auto bigint2 = BigInt(std::vector<int> {2, 0, 0, 0}, -1);
			auto sum = bigint1 - bigint2;
			auto expected = BigInt(std::vector<int>{3, 0, 0, 0}, -1);
			Assert::IsTrue(sum.GetData() == expected.GetData());
		}

		TEST_METHOD(TestSub5)
		{
			auto bigint1 = BigInt(std::vector<int> {1, 0, 0, 0}, 1);
			auto bigint2 = BigInt(std::vector<int> {2, 0, 0, 0}, 1);
			auto sum = bigint1 - bigint2;
			auto expected = BigInt(std::vector<int>{1, 0, 0, 0}, -1);
			Assert::IsTrue(sum.GetData() == expected.GetData());
		}

		TEST_METHOD(TestMult1)
		{
			auto bigint1 = BigInt(std::vector<int> {1, 0, 0, 0}, 1);
			auto bigint2 = BigInt(std::vector<int> {5, 0, 0, 0}, 1);
			bigint1 = bigint1 * 5;
			Assert::IsTrue(bigint1 == bigint2);
		}


		TEST_METHOD(TestMult2)
		{
			auto bigint1 = BigInt(std::vector<int> {1, 1, 1}, 1);
			auto bigint2 = BigInt(std::vector<int> {5}, 1);
			auto result = bigint1 * bigint2;
			Assert::IsTrue(result == BigInt({5, 5, 5}, 1));
		}

		TEST_METHOD(TestMult3)
		{
			auto bigint1 = BigInt(std::vector<int> {1, 2, 8, 1}, 1);
			auto bigint2 = BigInt(std::vector<int> {3, 2, 5}, -1);
			auto result = bigint1 * bigint2;
			Assert::IsTrue(result == BigInt({ 4, 1, 6, 3, 2, 5}, -1));
		}
	};
}
