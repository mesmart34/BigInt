#include "pch.h"
#include "CppUnitTest.h"
#include "../BigInt/BigInt.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BigIntTest
{
	TEST_CLASS(BigIntTest)
	{
	public:

		TEST_METHOD(Sum1)
		{
			auto actual = BigInt("0") + BigInt("0");
			auto expected = BigInt("0");
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(Sum2)
		{
			auto b1 = BigInt("11111111111111111");
			auto b2 = BigInt("0");
			auto actual = b1 + b2;
			auto expected = BigInt("11111111111111111");
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(Sum3)
		{
			auto actual = BigInt("-11111111111111111") + BigInt("0");
			auto expected = BigInt("-11111111111111111");
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(Sum4)
		{
			auto actual = BigInt("11111111111111111") + BigInt("22222222222222222");
			auto expected = BigInt("33333333333333333");
			Assert::IsTrue(actual == expected);
		}
		TEST_METHOD(Sum5)
		{
			auto actual = BigInt("111111111111") + BigInt("222222222999");
			auto expected = BigInt("333333334110");
			Assert::IsTrue(actual == expected);
		}
		TEST_METHOD(Sum6)
		{
			auto actual = BigInt("111111111111") + BigInt("22222999");
			auto expected = BigInt("111133334110");
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(Sum7)
		{
			auto actual = BigInt("-22222222222222222") + BigInt("-11111111111111111");
			auto expected = BigInt("-33333333333333333");
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(Sum8)
		{
			auto actual = BigInt("-11111111111111111") + BigInt("-2222222222222222");
			auto expected = BigInt("-13333333333333333");
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(Sum9)
		{
			auto actual = BigInt("-111111111111") + BigInt("-222222222999");
			auto expected = BigInt("-333333334110");
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(Sum10)
		{
			auto actual = BigInt("-111111111111") + BigInt("-22222999");
			auto expected = BigInt("-111133334110");
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(Sub1)
		{
			auto actual = BigInt("0") - BigInt("0");
			auto expected = BigInt("0");
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(Sub2)
		{
			auto actual = BigInt("11111111111111111") - BigInt("0");
			auto expected = BigInt("11111111111111111");
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(Sub3)
		{
			auto actual = BigInt("-11111111111111111") - BigInt("0");
			auto expected = BigInt("-11111111111111111");
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(Sub4)
		{
			auto actual = BigInt("22222222222222222") - BigInt("11111111111111111");
			auto expected = BigInt("11111111111111111");
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(Sub5)
		{
			auto actual = BigInt("11111111111111111") - BigInt("11111111");
			auto expected = BigInt("11111111100000000");
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(Div1)
		{
			auto actual = BigInt("0") / BigInt("123456789123");
			auto expected = BigInt("0");
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(Div2)
		{
			auto actual = BigInt("0") / BigInt("-123456789123");
			auto expected = BigInt("0");
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(Div3)
		{
			auto actual = BigInt("123456789123") / BigInt("1");
			auto expected = BigInt("123456789123");
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(Div4)
		{
			auto actual = BigInt("-123456789123") / BigInt("1");
			auto expected = BigInt("-123456789123");
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(Div5)
		{
			auto actual = BigInt("123456789123") / BigInt("123456789123");
			auto expected = BigInt("1");
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(Div6)
		{
			auto actual = BigInt("123456789123") / BigInt("2");
			auto expected = BigInt("61728394561");
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(Div7)
		{
			auto actual = BigInt("-123456789123") / BigInt("-123456789123");
			auto expected = BigInt("1");
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(Div8)
		{
			auto actual = BigInt("-123456789123") / BigInt("123456789123");
			auto expected = BigInt("-1");
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(Mult1)
		{
			auto actual = BigInt("0") * BigInt("0");
			auto expected = BigInt("0");
			Assert::IsTrue(actual == expected);
		}
	};
}
