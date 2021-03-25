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
	if (m_sign > other.m_sign)
		return true;
	if (m_sign < other.m_sign)
		return false;
	auto cmp = AbsCompare(*this, other);
	if (cmp == 1)
		return m_sign > 0;
	if (cmp == 0)
		return m_sign > other.m_sign;
	if (cmp == -1)
		return m_sign < 0;
}

bool BigInt::operator<(const BigInt& other)
{
	if (m_sign < other.m_sign)
		return true;
	if (m_sign > other.m_sign)
		return false;

	auto cmp = AbsCompare(*this, other);
	if (cmp == -1)
		return m_sign > 0;
	if (cmp == 0)
		return m_sign > other.m_sign;
	if (cmp == 1)
		return m_sign < 0;
}


BigInt BigInt::operator+(const BigInt& other)
{
	if (m_sign == other.m_sign)
	{
		auto result = SumPositive(*this, other);
		result.m_sign = m_sign;
		return result;
	}
	auto absc = AbsCompare(*this, other);
	if (other.m_sign < 0) {
		if (absc >= 0)
		{
			auto result = SubPositive(*this, other);
			result.m_sign = 1;
			return result;
		}
		else
		{
			auto result = SubPositive(other, *this);
			result.m_sign = -1;
			return result;
		}
	}
	if (absc >= 0)
	{
		auto result = SubPositive(*this, other);
		result.m_sign = -1;
		return result;
	}
	else
	{
		auto result = SubPositive(other, *this);
		result.m_sign = 1;
		return result;
	}
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

void BigInt::EraseLeadingZeros(std::vector<uint64_t>& v)
{
	while (*(v.end() - 1) == 0)
		v.pop_back();
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

void BigInt::CarrySub(uint64_t a, uint64_t b, uint64_t& value, uint64_t& carry)
{

	if (a >= b)
	{
		value = a - b;
		carry = 0;
	}
	else
	{
		value = (UINT64_MAX - b) + a + 1;
		carry = 1;
	}
}

BigInt BigInt::SumPositive(const BigInt& a, const BigInt& b)
{
	auto result = BigInt(0);
	result.m_data.erase(result.m_data.begin());
	auto sz = GetMaxSize(a, b);
	uint64_t carry = 0;
	for (size_t i = 0; i < sz; i++)
	{
		uint64_t mValue, mCarry, mCarry2;
		uint64_t val1 = 0;
		uint64_t val2 = 0;
		if (i < a.m_data.size())
			val1 = a.m_data[i];
		if (i < b.m_data.size())
			val2 = b.m_data[i];
		CarryAdd(val1, val2, mValue, mCarry);
		CarryAdd(mValue, carry, mValue, mCarry2);
		carry = mCarry2 + mCarry;
		result.m_data.push_back(mValue);
	}
	if (carry != 0)
		result.m_data.push_back(carry);
	return result;
}

BigInt BigInt::SubPositive(const BigInt& a, const BigInt& b)
{
	auto result = BigInt(0);
	result.m_data.erase(result.m_data.begin());
	auto sz = GetMaxSize(a, b);
	uint64_t carry = 0;
	for (size_t i = 0; i < sz; i++)
	{
		uint64_t mValue, mCarry, mCarry2;
		uint64_t val1 = 0;
		uint64_t val2 = 0;
		if (i < a.m_data.size())
			val1 = a.m_data[i];
		if (i < b.m_data.size())
			val2 = b.m_data[i];
		CarrySub(val1, val2, mValue, mCarry);
		CarrySub(mValue, carry, mValue, mCarry2);
		carry = mCarry + mCarry2;
		result.m_data.push_back(mValue);
	}
	if (carry != 0)
		result.m_data.push_back(carry);
	EraseLeadingZeros(result.m_data);
	return result;
}

int BigInt::AbsCompare(const BigInt& a, const BigInt& b)
{
	if (a.m_data.size() > b.m_data.size())
		return 1;
	if (a.m_data.size() < b.m_data.size())
		return -1;

	auto ai = a.m_data.rbegin();
	auto bi = b.m_data.rbegin();

	while (ai != a.m_data.rend())
	{
		if (*ai > *bi)
			return 1;
		if (*ai < *bi)
			return -1;
		ai++;
		bi++;
	}
	return 0;
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
