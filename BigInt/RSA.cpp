#include "RSA.h"

RSA::RSA(const BigInt& _p, const BigInt& _q)
{
	auto p = _p;
	auto q = _q;
	if (p.GetSign() < 0 || q.GetSign() < 0)
		throw "Numbers must be positive";
	if (!BigInt::IsPrime(p) || !BigInt::IsPrime(q))
		throw "Numbers must be simple";
	n = p * q;
	auto fi = (p - BigInt("1")) * (q - BigInt("1"));
	auto x = BigInt("0");
	auto y = BigInt("0");
	e = fi - BigInt("1");
	while (!(BigInt::IsPrime(e) && BigInt::GCD(e, fi, x, y) == BigInt("1")))
		e -= BigInt("2");
	d = BigInt::GetInverseElementModulo(e, fi);
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

