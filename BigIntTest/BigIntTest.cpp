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

		TEST_METHOD(Mult2)
		{
			auto actual = BigInt("12345678") * BigInt("0");
			auto expected = BigInt("0");
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(Mult3)
		{
			auto actual = BigInt("-12345678") * BigInt("0");
			auto expected = BigInt("0");
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(Mult4)
		{
			auto actual = BigInt("12345678") * BigInt("1");
			auto expected = BigInt("12345678");
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(Mult5)
		{
			auto actual = BigInt("-12345678") * BigInt("1");
			auto expected = BigInt("-12345678");
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(Mult6)
		{
			auto actual = BigInt("12345678") * BigInt("12345678");
			auto expected = BigInt("152415765279684");
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(Mult7)
		{
			auto actual = BigInt("-12345678") * BigInt("-12345678");
			auto expected = BigInt("152415765279684");
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(Mult8)
		{
			auto actual = BigInt("-12345678") * BigInt("12345678");
			auto expected = BigInt("-152415765279684");
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(Mod1)
		{
			auto actual = BigInt("0") % BigInt("123456789");
			auto expected = BigInt("0");
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(Mod2)
		{
			auto actual = BigInt("0") % BigInt("-123456789");
			auto expected = BigInt("0");
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(Mod3)
		{
			auto actual = BigInt("123456789") % BigInt("123456789");
			auto expected = BigInt("0");
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(Mod4)
		{
			auto actual = BigInt("-123456789") % BigInt("-123456789");
			auto expected = BigInt("0");
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(Mod5)
		{
			auto actual = BigInt("-123456789") % BigInt("123456789");
			auto expected = BigInt("0");
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(Mod6)
		{
			auto actual = BigInt("123456789") % BigInt("1");
			auto expected = BigInt("0");
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(Mod7)
		{
			auto actual = BigInt("-123456789") % BigInt("1");
			auto expected = BigInt("0");
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(Mod8)
		{
			auto actual = BigInt("123456789") % BigInt("2");
			auto expected = BigInt("1");
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(GetInverseElementModulo1)
		{
			auto n1BigInt = BigInt("123456789");
			auto n2BigInt = BigInt("19");
			auto actual = BigInt::GetInverseElementModulo(n1BigInt, n2BigInt);
			auto expected = BigInt("1");
			Assert::IsTrue(actual * n1BigInt % n2BigInt == expected);
		}

		TEST_METHOD(GetInverseElementModulo2)
		{
			auto n1BigInt = BigInt("123456789");
			auto n2BigInt = BigInt("23");
			auto actual = BigInt::GetInverseElementModulo(n1BigInt, n2BigInt);
			auto expected = BigInt("1");
			Assert::IsTrue(actual * n1BigInt % n2BigInt == expected);
		}

		TEST_METHOD(GetInverseElementModulo3)
		{
			auto n1BigInt = BigInt("1111111111111111111");
			auto n2BigInt = BigInt("11");
			auto actual = BigInt::GetInverseElementModulo(n1BigInt, n2BigInt);
			auto expected = BigInt("1");
			Assert::IsTrue(actual * n1BigInt % n2BigInt == expected);
		}

		TEST_METHOD(GetInverseElementModulo4)
		{
			auto n1BigInt = BigInt("1");
			auto n2BigInt = BigInt("123456789");
			auto actual = BigInt::GetInverseElementModulo(n1BigInt, n2BigInt);
			auto expected = BigInt("1");
			Assert::IsTrue(actual * n1BigInt % n2BigInt == expected);
		}
	};
}
