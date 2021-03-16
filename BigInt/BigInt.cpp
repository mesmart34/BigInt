#include "BigInt.h"

BigInt::BigInt(std::vector<int> data = {0}, int sign = 1)
	: m_data(data), m_sign(sign) { }

BigInt::BigInt(std::string data)
{
	m_sign = 1;
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
			for (i = 0; i < size - 1; i++)	// ищем первую ненулевую цифру, кроме последней цифры
				if (digits[i] != 0)
					break;

			if (i > 0)   // есть ведущие нули
				digits.erase(digits.begin(), digits.begin() + i);// удаляем ведущие нули, кроме возможно, последнего

		}
		if (sign == 1)
			sign = 1;
		else
			sign = -1;
	}

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
	return BigInt();
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
	return (GetData() == const_cast<BigInt&>(bigint).GetData()) && (bigint.GetSign() == GetSign());
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
