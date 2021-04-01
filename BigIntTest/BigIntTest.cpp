#include "pch.h"
#include "CppUnitTest.h"
#include "../BigInt/BigInt.h"
#include "../BigInt/RSA.h"


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

		TEST_METHOD(RSATest1)
		{
			auto rsa = RSA("31", "37");
			auto openKeys = rsa.GetOpenKeys();

			auto msg = "hello, world";

			auto encoded = rsa.Encode(msg, get<0>(openKeys), get<1>(openKeys));
			auto closeKeys = rsa.GetCloseKeys();
			auto initialMsg = rsa.Decode(encoded, get<0>(closeKeys), get<1>(closeKeys));

			Assert::IsTrue(msg == initialMsg);
		}

		TEST_METHOD(RSATest2)
		{
			auto rsa = RSA("11", "13");
			auto openKeys = rsa.GetOpenKeys();

			auto msg = "hi";

			auto encoded = rsa.Encode(msg, get<0>(openKeys), get<1>(openKeys));
			auto closeKeys = rsa.GetCloseKeys();
			auto initialMsg = rsa.Decode(encoded, get<0>(closeKeys), get<1>(closeKeys));

			Assert::IsTrue(msg == initialMsg);
		}

		TEST_METHOD(RSATest3)
		{
			auto rsa = RSA("19", "23");
			auto openKeys = rsa.GetOpenKeys();

			auto msg = "hello, world";

			auto encoded = rsa.Encode(msg, get<0>(openKeys), get<1>(openKeys));
			auto closeKeys = rsa.GetCloseKeys();
			auto initialMsg = rsa.Decode(encoded, get<0>(closeKeys), get<1>(closeKeys));

			Assert::IsTrue(msg == initialMsg);
		}

		TEST_METHOD(RSATest4)
		{
			auto rsa = RSA("83", "89");
			auto openKeys = rsa.GetOpenKeys();

			auto msg = "hello, world";

			auto encoded = rsa.Encode(msg, get<0>(openKeys), get<1>(openKeys));
			auto closeKeys = rsa.GetCloseKeys();
			auto initialMsg = rsa.Decode(encoded, get<0>(closeKeys), get<1>(closeKeys));

			Assert::IsTrue(msg == initialMsg);
		}

		TEST_METHOD(RSATest5)
		{
			auto rsa = RSA("73", "79");
			auto openKeys = rsa.GetOpenKeys();

			auto msg = "hello, world";

			auto encoded = rsa.Encode(msg, get<0>(openKeys), get<1>(openKeys));
			auto closeKeys = rsa.GetCloseKeys();
			auto initialMsg = rsa.Decode(encoded, get<0>(closeKeys), get<1>(closeKeys));

			Assert::IsTrue(msg == initialMsg);
		}

		TEST_METHOD(OperatorEqual1)
		{
			auto actual = BigInt("0") == BigInt("0");
			auto expected = true;
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(OperatorEqual2)
		{
			auto actual = BigInt("12345678990") == BigInt("0");
			auto expected = false;
			Assert::IsTrue(actual == expected);
		}
		TEST_METHOD(OperatorEqual3)
		{
			auto actual = BigInt("-12345678990") == BigInt("0");
			auto expected = false;
			Assert::IsTrue(actual == expected);
		}
		TEST_METHOD(OperatorEqual4)
		{
			auto actual = BigInt("1234567891234") == BigInt("2234567891234");
			auto expected = false;
			Assert::IsTrue(actual == expected);
		}
		TEST_METHOD(OperatorEqual5)
		{
			auto actual = BigInt("-1234567891234") == BigInt("-2234567891234");
			auto expected = false;
			Assert::IsTrue(actual == expected);
		}
		TEST_METHOD(OperatorEqual6)
		{
			auto actual = BigInt("-1234567891234") == BigInt("2234567891234");
			auto expected = false;
			Assert::IsTrue(actual == expected);
		}
		TEST_METHOD(OperatorEqual7)
		{
			auto actual = BigInt("-1234567891234") == BigInt("-1234567891234");
			auto expected = true;
			Assert::IsTrue(actual == expected);
		}
		TEST_METHOD(OperatorEqual8)
		{
			auto actual = BigInt("1234567891234") == BigInt("1234567891234");
			auto expected = true;
			Assert::IsTrue(actual == expected);
		}
		TEST_METHOD(OperatorEqua9)
		{
			auto actual = BigInt("1234567891234") == BigInt("-1234567891234");
			auto expected = false;
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(OperatorMore1)
		{
			auto actual = BigInt("123456789") > BigInt("123456789");
			auto expected = false;
			Assert::IsTrue(actual == expected);
		}
		TEST_METHOD(OperatorMore2)
		{
			auto actual = BigInt("-123456789") > BigInt("-123456789");
			auto expected = false;
			Assert::IsTrue(actual == expected);
		}
		TEST_METHOD(OperatorMore3)
		{
			auto actual = BigInt("-123456789") > BigInt("123456789");
			auto expected = false;
			Assert::IsTrue(actual == expected);
		}
		TEST_METHOD(OperatorMore4)
		{
			auto actual = BigInt("-123456789") > BigInt("-123456790");
			auto expected = true;
			Assert::IsTrue(actual == expected);
		}
		TEST_METHOD(OperatorMore5)
		{
			auto actual = BigInt("-123456789") > BigInt("-123456788");
			auto expected = false;
			Assert::IsTrue(actual == expected);
		}
		TEST_METHOD(OperatorMore6)
		{
			auto actual = BigInt("123456789") > BigInt("123456788");
			auto expected = true;
			Assert::IsTrue(actual == expected);
		}
		TEST_METHOD(OperatorMore7)
		{
			auto actual = BigInt("123456788") > BigInt("123456789");
			auto expected = false;
			Assert::IsTrue(actual == expected);
		}
		TEST_METHOD(OperatorMore8)
		{
			auto actual = BigInt("123456789") > BigInt("-1234");
			auto expected = true;
			Assert::IsTrue(actual == expected);
		}
		TEST_METHOD(OperatorMore9)
		{
			auto actual = BigInt("-123456789") > BigInt("1234");
			auto expected = false;
			Assert::IsTrue(actual == expected);
		}
		TEST_METHOD(OperatorMore10)
		{
			auto actual = BigInt("0") > BigInt("-123456789");
			auto expected = true;
			Assert::IsTrue(actual == expected);
		}
		TEST_METHOD(OperatorMore11)
		{
			auto actual = BigInt("0") > BigInt("123456789");
			auto expected = false;
			Assert::IsTrue(actual == expected);
		}
	};
}
