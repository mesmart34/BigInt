#include "RSA.h"

RSA::RSA(const BigInt& a, const BigInt& b)
{
	auto p = a;
	auto q = b;
	n = p * q;
	auto t = (p - 1) * (q - 1);
	e = t - 1;
	while (!(BigInt::GCD(e, t) == 1 && BigInt::IsPrime(e)))
		e = e - 2;
	d = BigInt::GetInverseElementModulo(e, t);
}

std::vector<BigInt> RSA::Encode(const string& msg, const BigInt& e, const BigInt& n)
{
	auto result = std::vector<BigInt>();

	for(auto symbol : msg)
	{
		auto temp = BigInt(to_string(symbol));
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
		auto symbol = BigInt::ParseToInt(temp);
		text << (char)symbol;
	}

	return text.str();
}

std::tuple<BigInt, BigInt> RSA::GetOpenKeys() const
{
	return make_tuple(e, n);
}

std::tuple<BigInt, BigInt> RSA::GetCloseKeys() const
{
	return make_tuple(d, n);
}

