#pragma once

#include <vector>
#include <string>

class BigInt
{
public:
	BigInt(std::vector<int> data, int sign);
	BigInt(std::string data);

	std::vector<int> GetData() const;
	int GetSize() const;
	int GetSign() const;

	BigInt operator+(const BigInt& bigint);
	BigInt operator-(const BigInt& bigint);
	bool operator==(const BigInt& bigint);
private:
	BigInt Sum(const BigInt& a, const BigInt& b);
	BigInt Sub(const BigInt& a, const BigInt& b);

	std::vector<int> m_data;
	int m_sign;
};
