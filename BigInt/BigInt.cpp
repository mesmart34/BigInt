#include "BigInt.h"

using namespace std;

BigInt::BigInt(vector<uint8_t> data, int8_t sign)
	: m_digits(data), m_sign(sign) { }

BigInt::BigInt(const std::string& data)
{
	*this = StringToData(data);
}

BigInt::BigInt(const char* data)
{
	*this = StringToData({ data });
}

BigInt::BigInt(const int number)
{
	*this = StringToData(to_string(number));
} 

vector<uint8_t> BigInt::GetData() const
{
	return m_digits;
}

uint8_t BigInt::GetSize() const
{
	return m_digits.size();
}

int8_t BigInt::GetSign() const
{
	if (m_digits == vector<uint8_t>(0))
		return 1;
	return m_sign;
}

bool BigInt::operator>(const BigInt& other) const
{
	if (this->m_sign == other.m_sign)
	{
		auto d1 = vector<uint8_t>();
		auto d2 = vector<uint8_t>();
		FillSameSize(*this, other, d1, d2);
		for (auto i = 0; i < d1.size(); i++)
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
		auto result = vector<uint8_t>();
		auto d1 = vector<uint8_t>();
		auto d2 = vector<uint8_t>();
		FillSameSize(*this, other, d1, d2);
		for (auto i = (int)d1.size() - 1; i >= 0; i--)
		{
			auto sum = (d1[i] + d2[i] + carry) % 10;
			carry = (d1[i] + d2[i] + carry) / 10;
			result.insert(result.begin(), (uint8_t)labs(sum));
		}
		result.insert(result.begin(), (uint8_t)carry);
		auto sign = this->m_sign;
		result = EraseLeadingZeros(result);
		return BigInt(result, sign);
	}
	if (this->m_sign < 0)
		return other - -*this;
	return *this - -other;
}

BigInt BigInt::operator+=(const BigInt& other)
{
	*this = *this + other;
	return *this;
}

BigInt BigInt::operator-=(const BigInt& other)
{
	*this = *this - other;
	return *this;
}

BigInt BigInt::operator*(const uint8_t d) const
{
	if (d < 0 || d > 9)
		throw "Out of range";
	else
	{
		auto result = BigInt("0");
		for (auto i = 0; i < d; i++)
			result = result + *this;
		return result;
	}
}

BigInt BigInt::operator*(const BigInt& other) const
{

	if (*this == BigInt("0") || other == BigInt("0"))
		return BigInt("0");
	auto n1Abs = *this;
	if (this->m_sign < 0)
		n1Abs = -*this;
	auto mult = BigInt("0");
	auto power = 0;
	for (auto i = (int)other.m_digits.size() - 1; i >= 0; i--)
	{
		auto temp = n1Abs * other.m_digits[i];
		mult += MultByTen(temp, power);
		power++;
	}

	if (this->m_sign * other.m_sign < 0)
		return -mult;
	return mult;
}

BigInt BigInt::operator-(const BigInt& other) const
{
	if (this->m_sign * other.m_sign > 0)
	{
		auto carry = 0;
		auto result = vector<uint8_t>();
		auto d1 = vector<uint8_t>();
		auto d2 = vector<uint8_t>();
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
			result.insert(result.begin(), (uint8_t)labs(sum));
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
	*this = *this + BigInt("1");
	return *this;
}

BigInt BigInt::operator--()
{
	*this = *this - BigInt("1");
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
	auto remainder = vector<uint8_t>();
	auto result = vector<uint8_t>();
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
	if (other == BigInt("0"))
		throw "Div by zero";
	auto n1Abs = Abs(*this);
	auto n2Abs = Abs(other);
	auto remainderAbs = n1Abs - n1Abs / n2Abs * n2Abs;
	if (this->m_sign * other.m_sign < 0 && remainderAbs != BigInt("0"))
		return -remainderAbs;
	return remainderAbs;
}

BigInt BigInt::operator*=(const BigInt& other)
{
	*this = *this * other;
	return *this;
}

BigInt BigInt::operator/=(const BigInt& other)
{
	*this = *this / other;
	return *this;
}

BigInt BigInt::operator%=(const BigInt& other)
{
	*this = *this % other;
	return *this;
}

BigInt BigInt::MultByTen(const BigInt& other, const uint8_t power)
{
	std::vector<uint8_t> digits{ other.m_digits};
	for (auto i = 0; i < power; i++)
		digits.push_back(0);
	return BigInt(digits, other.m_sign);
}

bool BigInt::operator!=(const BigInt& other) const
{
	return !(other == *this);
}


BigInt BigInt::StringToData(const std::string& str)
{
	auto sign = 1;
	auto digits = std::vector<uint8_t>();
	if (str.at(0) == '-')
	{
		sign = -1;
		if (str.size() == 1)
			throw "Wrong format!";
	}
	digits.reserve(str.size());
	for (auto i = sign < 0 ? 1 : 0; i < str.size(); i++)
	{
		digits.push_back((uint8_t)str.at(i) - 48);
	}
	return BigInt(digits, sign);
}

std::vector<uint8_t> BigInt::EraseLeadingZeros(const std::vector<uint8_t>& v)
{
	auto result = v;
	while (result[0] == 0 && result.size() > 1)
		result.erase(result.begin());
	return result;
}

void BigInt::FillSameSize(const BigInt& a, const BigInt& b, vector<uint8_t>& aDigits, vector<uint8_t>& bDigits)
{
	auto delta = std::labs(a.GetSize() - b.GetSize());
	aDigits = vector<uint8_t>(a.m_digits);
	bDigits = vector<uint8_t>(b.m_digits);
	for (auto i = 0; i < delta; i++)
	{
		if (a.GetSize() > b.GetSize())
			bDigits.insert(bDigits.begin(), 0);
		else 
			aDigits.insert(aDigits.begin(), 0);
	}
}

std::tuple<uint64_t, BigInt> BigInt::Divide(const BigInt& a, const BigInt& b)
{
	auto result = 0;
	auto remainder = BigInt(a.m_digits, 1);
	while (remainder >= b)
	{
		remainder = remainder - b;
		result++;
	}

	return tuple<uint64_t, BigInt>(result, remainder);
}

BigInt BigInt::ModPow(const BigInt& n1, const BigInt& power, const BigInt& mod)
{
	if (power == BigInt("0")) 
		return BigInt("1");
	if (power % BigInt("2") == BigInt("1"))
		return n1 * ModPow(n1, power - BigInt("1"), mod) % mod;
	auto n2 = ModPow(n1, power / BigInt("2"), mod);
	return n2 * n2 % mod;
}

uint8_t BigInt::ParseToInt(const BigInt& other)
{
	auto result = 0;
	auto index = other.m_digits.size() - 1;
	for (auto i = other.m_digits.begin(); i < other.m_digits.end(); i++)
	{
		result += pow(10, index) * *i;
		index -= 1;
	}
	return result;
}

BigInt BigInt::Abs(const BigInt& b)
{
	return BigInt(b.GetData(), 1);
}

BigInt BigInt::GCD(const BigInt& n1, const BigInt& n2, BigInt& x, BigInt& y)
{
	if (n1.m_sign < 0 || n2.m_sign < 0)
		throw "Numbers must be positive";
	if (n1 == BigInt("0"))
	{
		x = BigInt("0");
		y = BigInt("1");
		return n2;
	}
	auto x1 = BigInt("0");
	auto y1 = BigInt("0");
	auto d = GCD(n2 % n1, n1, x1, y1);
	x = y1 - n2 / n1 * x1;
	y = x1;
	return d;
}

bool BigInt::IsPrime(const BigInt& other)
{
	auto i = BigInt("2");
	while (i * i <= other)
	{
		if (other % i == BigInt("0"))
			return false;
		i = i + 1;
	}

	return true;
}

std::string BigInt::ToString() const
{
	auto line = string();
	auto ss = std::stringstream();
	if (m_sign < 0)
		line += "-";
	for (auto digit : m_digits)
		line += to_string(digit);
	return line;
}

BigInt BigInt::GetInverseElementModulo(const BigInt& n1, const BigInt& n2)
{
	if (n1 < BigInt("1") || n2 <= BigInt("1"))
		throw "n1 must be >=1, n2 must be >1";
	auto x = BigInt("0");
	auto y = BigInt("0");
	auto gcd = GCD(n1, n2, x, y);
	if (Abs(gcd) != BigInt("1"))
		throw "Numbers must be simple";
	return (x % n2 + n2) % n2;
}

bool BigInt::operator==(const BigInt& other) const
{
	return other.m_sign == this->m_sign && other.m_digits == this->m_digits;
}

std::ostream& operator<<(std::ostream& os, const BigInt& bigint)
{
	os << ((bigint.GetSign() == 1) ? '+' : '-');
	for (auto i = 0; i < bigint.GetSize(); i++)
	{
		os << to_string(bigint.GetData()[i]);
	}
	return os;
}
