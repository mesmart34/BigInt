#include "BigInt.h"

using namespace std;

BigInt::BigInt(vector<int> data = {0}, int sign = 1)
	: m_digits(data), m_sign(sign) { }

BigInt::BigInt(const std::string& data)
{
	StringToData(data);
}

BigInt::BigInt(const char* data)
{
	StringToData({ data });
}

BigInt::BigInt(const int number)
{

}

vector<int> BigInt::GetData() const
{
	return m_digits;
}

int BigInt::GetSize() const
{
	return m_digits.size();
}

int BigInt::GetSign() const
{
	return m_sign;
}

bool BigInt::operator>(const BigInt& other) const
{
	if (this->m_sign == other.m_sign)
	{
		auto d1 = vector<int>();
		auto d2 = vector<int>();
		FillSameSize(*this, other, d1, d2);
		for (auto i = 0; i < d2.size(); i++)
		{
			if (d1[i] * this->m_sign > d2[i] * other.m_sign)
				return true;
			if (d1[i] * this->m_sign < d2[i] * other.m_sign)
				return false;
		}

		return false;
	}

	return this->m_sign > other.m_sign;
}

bool BigInt::operator<(const BigInt& other) const
{
	return !(*this > other) && *this != other;
}

bool BigInt::operator<=(const BigInt& other) const
{
	return *this < other || *this == other;
}

bool BigInt::operator>=(const BigInt& other) const
{
	return *this > other || *this == other;
}

BigInt BigInt::operator+(const BigInt& other) const
{	
	if (this->m_sign * other.m_sign > 0)
	{
		auto carry = 0;
		auto result = vector<int>();
		auto d1 = vector<int>();
		auto d2 = vector<int>();
		FillSameSize(*this, other, d1, d2);
		for (auto i = (int)d1.size() - 1; i >= 0; i--)
		{
			auto sum = (d1[i] + d2[i] + carry) % 10;
			carry = (d1[i] + d2[i] + carry) / 10;
			result.insert(result.begin(), (int)labs(sum));
		}
		result.insert(result.begin(), (int)carry);
		auto sign = this->m_sign;
		result = EraseLeadingZeros(result);
		return BigInt(result, sign);
	}
	if (this->m_sign < 0)
		return other - -*this;
	return *this - -other;
}

BigInt BigInt::operator*(const int d) const
{
	if (d < 0 || d > 9)
		throw "Out of range";
	else
	{
		auto result = *this;
		for (auto i = 1; i < d; i++)
			result = result + *this;
		return result;
	}
}

BigInt BigInt::operator*(const BigInt& bigint) const
{
	
	auto sum = BigInt();
	auto temp = BigInt();
	for (auto i = 0; i < bigint.GetSize(); i++)
	{
		temp = *this * bigint.m_digits[i];
		temp = temp.multByTen(bigint.GetSize() - i - 1);
		sum = sum + temp;
	}
	sum.m_sign = m_sign * bigint.m_sign;
	return sum;
}

BigInt BigInt::operator-(const BigInt& other) const
{
	if (this->m_sign * other.m_sign > 0)
	{
		auto carry = 0;
		auto result = vector<int>();
		auto d1 = vector<int>();
		auto d2 = vector<int>();
		FillSameSize(*this, other, d1, d2);
		auto max = d1;
		auto min = d2;
		if (other > *this && other.m_sign > 0 || other < *this && other.m_sign < 0)
		{
			max = d2;
			min = d1;
		}
		for (auto i = (int)d1.size() - 1; i >= 0; i--)
		{
			auto sum = (10 + max[i] - min[i] - carry) % 10;
			carry = max[i] - carry < min[i] ? 1 : 0;
			result.insert(result.begin(), (int)labs(sum));
		}
		auto sign = *this >= other ? 1 : -1;
		result = EraseLeadingZeros(result);
		return BigInt(result, sign);
	}
	return *this + -other;
}

BigInt BigInt::operator-() const
{
	return BigInt(this->GetData(), this->GetSign() * -1);
}

BigInt BigInt::operator++()
{
	*this = *this + BigInt(1);
	return *this;
}

BigInt BigInt::operator--()
{
	*this = *this - BigInt(1);
	return *this;
}

BigInt BigInt::operator/(const BigInt& other) const
{
	if (other ==BigInt("0"))
		throw "Division by zero";
	if (*this ==BigInt("0"))
		return *this;
	if (other == BigInt("1"))
		return *this;
	if (other == BigInt("-1"))
		return -*this;
	if (*this == other)
		return BigInt("1");
	if (*this == -other)
		return BigInt("-1");
	auto n1Abs = Abs(*this);
	auto n2Abs = Abs(other);
	auto remainder = vector<int>();
	auto result = vector<int>();
	for(auto digit : n1Abs.m_digits)
	{
		remainder.push_back(digit);
		auto smallDivResult = Divide(BigInt(remainder, 1), n2Abs);
		result.push_back(std::get<0>(smallDivResult));
		remainder = std::get<1>(smallDivResult).m_digits;
	}

	result = EraseLeadingZeros(result);
	if (other.m_sign * this->m_sign < 0)
		return BigInt(result, -1);
	return BigInt(result, 1);
}

BigInt BigInt::operator%(const BigInt& other) const
{
	auto division = *this / other;
	auto temp = other * (division.m_sign == 1 ? division : division - "1");
	auto mod = *this - temp;
	return mod;
}

BigInt BigInt::multByTen(int power)
{
	std::vector<int> digits{m_digits};
	for (auto i = 0; i < power; i++)
		digits.push_back(0);
	return BigInt(digits, this->m_sign);
}

bool BigInt::operator!=(const BigInt& other) const
{
	return !(other == *this);
}


void BigInt::StringToData(const std::string& str)
{
	m_sign = 1;
	m_digits = std::vector<int>();
	if (str.at(0) == '-')
	{
		m_sign = -1;
		if (str.size() == 1)
			return;
	}
	m_digits.reserve(str.size());
	for (auto i = m_sign < 0 ? 1 : 0; i < str.size(); i++)
	{
		m_digits.push_back((int)str.at(i) - 48);
	}
}

std::vector<int> BigInt::EraseLeadingZeros(const std::vector<int>& v)
{
	auto result = v;
	while (result[0] == 0 && result.size() > 1)
		result.erase(result.begin());
	return result;
}

void BigInt::FillSameSize(const BigInt& a, const BigInt& b, vector<int>& aDigits, vector<int>& bDigits)
{
	auto delta = std::labs(a.GetSize() - b.GetSize());
	aDigits = a.m_digits;
	bDigits = b.m_digits;
	for (auto i = 0; i < delta; i++)
	{
		if (a.GetSize() > b.GetSize())
			bDigits.insert(bDigits.begin(), 0);
		else 
			aDigits.insert(aDigits.begin(), 0);
	}
}

std::tuple<int, BigInt> BigInt::Divide(const BigInt& a, const BigInt& b)
{
	auto result = 0;
	auto remainder = BigInt(a.m_digits, 1);
	while (remainder >= b)
	{
		remainder = remainder - b;
		result++;
	}

	return tuple<int, BigInt>(result, remainder);
}

BigInt BigInt::Abs(const BigInt& b)
{
	return BigInt(b.GetData(), 1);
}

bool BigInt::operator==(const BigInt& other) const
{
	if (other.m_digits == vector<int>{0}&& other.m_digits == this->m_digits)
		return true;
	return other.m_sign == this->m_sign && other.m_digits == this->m_digits;
}

std::ostream& operator<<(std::ostream& os, const BigInt& bigint)
{
	os << ((bigint.GetSign() == 1) ? '+' : '-');
	for (auto i = 0; i < bigint.GetSize(); i++)
	{
		os << std::to_string(bigint.GetData()[i]);
	}
	return os;
}
