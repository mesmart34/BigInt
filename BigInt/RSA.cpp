#include "RSA.h"

RSA::RSA(const BigInt& a, const BigInt& b)
{
	auto p = a;
	auto q = b;
	n = p * q;
	auto t = (p - 1) * (q - 1);
	e = CalculateE(t);
	d = BigInt::MultInv(e, t);
}

BigInt RSA::CalculateE(const BigInt& t)
{
	auto e = t - 1;	
	while (!(BigInt::GCD(e, t) == 1 && BigInt::IsPrime(e)))
		e = e - 2;	
	return e;
}

tuple<BigInt, BigInt, BigInt> RSA::GetKeys() const
{
	std::cout << e << "   " << d << "   " << n << std::endl;
	return tuple<BigInt, BigInt, BigInt>(e, d, n);
}


std::vector<BigInt> RSA::Encode(const string& msg, const BigInt& e, const BigInt& n)
{
	auto result = std::vector<BigInt>();

	for (auto symbol : msg)
	{
		uint64_t data = symbol;
		auto temp = BigInt(symbol);
		auto message = BigInt::ModPow(temp, e, n);
		result.push_back(message);
	}
	return result;
}

std::string RSA::Decode(const vector<BigInt> msg, const BigInt& d, const BigInt& n)
{
	auto text = stringstream();
	for (auto b : msg)
	{
		auto temp = BigInt::ModPow(b, d, n);
		uint64_t data = temp.GetData()[0];
		text << (char)data;
	}
	return text.str();
}

