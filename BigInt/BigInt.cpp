#include "BigInt.h"

BigInt::BigInt(std::vector<int> data, int sign) 
	: m_data(data), m_sign(sign) { }

BigInt::BigInt(std::string data)
{
	m_data = std::vector<int>();
	if (data.at(0) == '-')
	{
		m_sign = -1;
		if (data.size() == 1)
			return;
	}
	m_data.reserve(data.size());
	for (auto i = m_sign < 0 ? 1 : 0; i < data.size(); i++)
	{
		m_data.push_back((int)data.at(i) - 48);
	}
}

std::vector<int> BigInt::GetData() const
{
	return m_data;
}

int BigInt::GetSize() const
{
	return m_data.size();
}

int BigInt::GetSign() const
{
	return m_sign;
}

BigInt BigInt::operator+(const BigInt& bigint)
{
	return Sum(bigint, *this);
}

BigInt BigInt::operator-(const BigInt& bigint)
{
	return Sub(bigint, *this);
}

bool BigInt::operator==(const BigInt& bigint)
{
	if (bigint.GetSize() != GetSize())
		return false;
	if (bigint.GetData() != GetData())
		return false;
	if (bigint.GetSign() != GetSign())
		return false;
}

BigInt BigInt::Sum(const BigInt& a, const BigInt& b)
{
	std::vector<int> result;
	auto carry = 0;
	auto len = std::min(a.GetSize(), b.GetSize()) - 1;
	for (auto i = len; i >= 0; i--)
	{
		auto sum = a.m_data[i] + b.m_data[i] + carry;
		carry = sum >= 10;
		sum %= 10;
		result.push_back(sum);
	}
	if (carry > 0)
		result.push_back(carry);
	std::reverse(result.begin(), result.end());
	return BigInt(result, 1);
}

BigInt BigInt::Sub(const BigInt& a, const BigInt& b)
{
	std::vector<int> result;
	auto carry = 0;
	auto len = std::min(a.GetSize(), b.GetSize()) - 1;
	for (auto i = len; i >= 0; i--)
	{
		auto sum = a.m_data[i] - b.m_data[i] + carry;
		carry = sum >= 10;
		sum %= 10;
		result.push_back(sum);
	}
	if (carry > 0)
		result.push_back(carry);
	std::reverse(result.begin(), result.end());
	return BigInt(result, 1);
}
