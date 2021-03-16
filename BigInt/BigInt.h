#pragma once

#include <vector>
#include <string>
#include <iostream>

class BigInt
{
public:
	BigInt(std::vector<int> data, int sign);
	BigInt(std::string data);

	std::vector<int> GetData() const;
	int GetSize() const;
	int GetSign() const;


	BigInt operator+(const BigInt& bigint);
	BigInt operator*(const BigInt& bigint);
	BigInt operator*(const int d);
	BigInt operator-(const BigInt& bigint);
	BigInt operator-();
	bool operator==(const BigInt& bigint);

	friend std::ostream& operator<<(std::ostream& os, const BigInt& bigint);

private:
	void EraseLeadingZeros(std::vector<int>& v);
	int Div(const int a, const int b) const;
	int Mod(const int a, const int b) const;

private:
	std::vector<int> m_data;
	int m_sign;
};
