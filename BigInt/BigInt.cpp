#include "BigInt.h"

BigInt::BigInt(uint64_t value)
{
	m_sign = 1;
	m_data = std::vector<uint64_t>();
	m_data.push_back(value);
}

std::vector<uint64_t> BigInt::GetData() const
{
	return m_data;
}

size_t BigInt::GetSize() const
{
	return m_data.size();
}

int16_t BigInt::GetSign() const
{
	return m_sign;
}

bool BigInt::operator>(const BigInt& other)
{
	return false;
}

bool BigInt::operator<(const BigInt& other)
{
	return false;
}


BigInt BigInt::operator+(const BigInt& other)
{
	auto result = BigInt(0);
	result.m_data.erase(result.m_data.begin());
	auto sz = GetMaxSize(*this, other);
	uint64_t carry = 0;
	for (size_t i = 0; i < sz; i++)
	{
		uint64_t mValue, mCarry, mCarry2;
		uint64_t val1 = 0;
		uint64_t val2 = 0;
		if (i < m_data.size())
			val1 = m_data[i];
		if (i < other.m_data.size())
			val2 = other.m_data[i];
		CarryAdd(val1, val2, mValue, mCarry);
		CarryAdd(mValue, carry, mValue, mCarry2);
		result.m_data.push_back(mValue);
		carry = mCarry2 + mCarry;
	}
	if (carry != 0)
		result.m_data.push_back(carry);
	return result;
}

BigInt BigInt::operator*(const int d)
{
	return BigInt(0);
}

BigInt BigInt::operator*(const BigInt& other)
{
	return BigInt(0);
}

BigInt BigInt::operator-(const BigInt& other)
{
	return BigInt(0);
}

BigInt BigInt::operator-()
{
	return BigInt(0);
}

BigInt BigInt::operator/(const BigInt& other)
{
	return BigInt(0);
}

BigInt BigInt::operator%(const BigInt& other)
{
	return BigInt(0);
}

BigInt BigInt::Mod(BigInt& m)
{
	return BigInt(0);
}

bool BigInt::operator!=(const BigInt& other)
{
	return false;
}

BigInt BigInt::Abs(const BigInt& other)
{
	return BigInt(0);
}

BigInt BigInt::multInv(const BigInt& e, const BigInt& t)
{
	return BigInt(0);
}

void BigInt::StringToData(const std::string& str)
{
	
}

void BigInt::EraseLeadingZeros(std::vector<int>& v)
{
	for (auto i = 0; i < v.size(); i++)
	{
		if (v[i] != 0)
		{
			v.erase(v.begin(), v.begin() + i);
			break;
		}
	}
}

size_t BigInt::GetMaxSize(const BigInt& a, const BigInt& b)
{
	return std::max(a.GetSize(), b.GetSize());
}

size_t BigInt::GetMinSize(const BigInt& a, const BigInt& b)
{
	return std::min(a.GetSize(), b.GetSize());
}

void BigInt::CarryAdd(uint64_t a, uint64_t b, uint64_t& value, uint64_t& carry)
{
	auto sum = a + b;
	if (sum >= a || sum >= b)
	{
		value = sum;
		carry = 0;
	}
	else
	{
		auto max = std::max(a, b);
		auto min = std::min(a, b);
		value = min - (UINT64_MAX - max) - 1;
		carry = 1;
	}
}

bool BigInt::operator==(const BigInt& other)
{
	return false;
}

std::ostream& operator<<(std::ostream& os, const BigInt& bigint)
{
	os << "(";
	for (auto i = bigint.m_data.rbegin(); i != bigint.m_data.rend(); ++i)	
		os << *i << ":";	
	os << ")";
	return os;
}
