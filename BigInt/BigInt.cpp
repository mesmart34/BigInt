#include "BigInt.h"

BigInt::BigInt(std::vector<int> data = {0}, int sign = 1)
	: m_data(data), m_sign(sign) { }

BigInt::BigInt(const std::string& data)
{
	StringToData(data);
}

BigInt::BigInt(const char* data)
{
	StringToData({ data });
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

bool BigInt::operator>(const BigInt& bigint)
{
	auto res = *this - bigint;
	return res.m_sign == 1 && res != "0";
}

bool BigInt::operator<(const BigInt& bigint)
{
	auto temp = *this;
	auto res = temp - bigint;
	return res.m_sign == -1 && res != "0";
}

int BigInt::Div(const int a, const int b) const
{
	if (a >= 0)
		return a / b;
	else if ((-a) % b != 0)					
		return -((-a) / b + 1);
	else
		return -((-a) / b);
}

int BigInt::Mod(const int a, const int b) const
{
	return a - b * Div(a, b);
}

std::tuple<BigInt, BigInt> BigInt::Divide(const BigInt& bigint)
{
	if (GetSize() < bigint.GetSize())
		return std::tuple<BigInt, BigInt>("0", *this);
	if (BigInt("0") == bigint)
		throw "Division by zero!";

	auto reminder = *this;
	auto subtrahend = BigInt(bigint.GetData(), 1);

	auto result = BigInt("0");
	reminder.m_sign = 1;

	while (reminder > "0")
	{
		reminder = reminder - subtrahend;
		result = result + "1";
	}
	if (reminder < "0")
	{
		result = result - "1";
		reminder = subtrahend + reminder;
	}
	reminder.m_sign = this->m_sign;
	result.m_sign = m_sign * bigint.m_sign;
	EraseLeadingZeros(result.m_data);
	EraseLeadingZeros(reminder.m_data);
	return std::tuple<BigInt, BigInt>(result, reminder);
}

BigInt BigInt::operator+(const BigInt& bigint)
{
	auto digits = std::vector<int>();
	auto sign = m_sign;

	auto b = bigint;
	auto size = GetSize();
	auto b_size = b.GetSize();

	if (size < b_size)
	{
		for (auto i = 0; i < b_size - size; i++)
			m_data.insert(m_data.begin(), 0);
		size = b_size;
	}
	else if (size > b_size) {
		for (auto i = 0; i < -(b_size - size); i++)
			b.m_data.insert(b.m_data.begin(), 0);
		b_size = size;
	}

	if (m_sign == b.m_sign)
	{
		auto carry = 0;
		for (auto i = size - 1; i >= 0; i--)
		{
			auto sum = Mod(m_data[i] + b.m_data[i] + carry, 10);
			carry = Div(m_data[i] + b.m_data[i] + carry, 10);
			digits.insert(digits.begin(), sum);
		}
		if(carry != 0)
			digits.insert(digits.begin(), carry);
	}
	else {
		if (m_data > b.m_data) {
			auto carry = 0;
			for (auto i = size - 1; i >= 0; i--)
			{
				auto sum = Mod(m_data[i] - b.m_data[i] + carry, 10);
				carry = Div(m_data[i] - b.m_data[i] + carry, 10);
				digits.insert(digits.begin(), sum);
			}

		}
		else if (m_data < b.m_data) {
			auto carry = 0;
			for (auto i = size - 1; i >= 0; i--)
			{
				auto sum = Mod(b.m_data[i] - m_data[i] + carry, 10);
				carry = Div(b.m_data[i] - m_data[i] + carry, 10);
				digits.insert(digits.begin(), sum);
			}

			int i;
			for (i = 0; i < size - 1; i++)	
				if (digits[i] != 0)
					break;

			if (i > 0)  
				digits.erase(digits.begin(), digits.begin() + i);
			if (sign == 1)
				sign = -1;
			else
				sign = 1;
		}
		else
		{
			sign = 1;
			digits = { 0 };
		}

	}

	if (digits.size() == 0)
		digits.push_back(0);
	else
		EraseLeadingZeros(digits);

	return BigInt(digits, sign);
}

BigInt BigInt::operator*(const int d)
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

BigInt BigInt::operator*(const BigInt& bigint)
{
	
	auto sum = BigInt();
	auto temp = BigInt();
	for (auto i = 0; i < bigint.GetSize(); i++)
	{
		temp = *this * bigint.m_data[i];
		temp = temp.multByTen(bigint.GetSize() - i - 1);
		sum = sum + temp;
	}
	sum.m_sign = m_sign * bigint.m_sign;
	return sum;
}

BigInt BigInt::operator-(const BigInt& bigint)
{
	auto negative = -const_cast<BigInt&>(bigint);
	return *this + negative;
}

BigInt BigInt::operator-()
{
	return BigInt(this->GetData(), this->GetSign() * -1);
}

BigInt BigInt::operator/(const BigInt& bigint)
{
	return std::get<0>(Divide(bigint));
}

BigInt BigInt::operator%(const BigInt& bigint)
{
	return std::get<1>(Divide(bigint));
}

BigInt BigInt::multByTen(int power)
{
	std::vector<int> digits{m_data};
	for (auto i = 0; i < power; i++)
		digits.push_back(0);
	return BigInt(digits, this->m_sign);
}

BigInt BigInt::Mod(BigInt& m)
{
	return *this - m * (*this / m);
}

bool BigInt::operator!=(const BigInt& bigint)
{
	return (GetData() != const_cast<BigInt&>(bigint).GetData()) || (bigint.GetSign() != GetSign());
}

BigInt BigInt::Abs(const BigInt& bigint)
{
	return BigInt(bigint.GetData(), 1);
}

BigInt BigInt::multInv(const BigInt& e, const BigInt& t)
{
	BigInt d;
	BigInt k = "1";

	while (true)
	{
		k = k + t;

		if (k % e == "0")
		{
			d = (k / e);
			return d;
		}
	}
}

int BigInt::toBin() const
{
	auto result = 0;
	auto index = m_data.size() - 1;
	for (auto i = m_data.begin(); i < m_data.end(); i++) 
	{
		result += pow(10, index) * *i;
		index -= 1;
	}
	return result;
}

void BigInt::StringToData(const std::string& str)
{
	m_sign = 1;
	m_data = std::vector<int>();
	if (str.at(0) == '-')
	{
		m_sign = -1;
		if (str.size() == 1)
			return;
	}
	m_data.reserve(str.size());
	for (auto i = m_sign < 0 ? 1 : 0; i < str.size(); i++)
	{
		auto symbol = (int)str.at(i) - 48;
		if (symbol < 0 || symbol > 9)
			throw "Out of range";
		m_data.push_back(symbol);
	}
	EraseLeadingZeros(m_data);
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

bool BigInt::operator==(const BigInt& bigint)
{
	auto result = *this - bigint;
	return result.m_data == std::vector<int>{0};
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
