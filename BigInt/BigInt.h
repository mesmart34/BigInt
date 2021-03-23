#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <tuple>

class BigInt
{
public:
	BigInt(std::vector<int> data, int sign);
	BigInt(const std::string& data);
	BigInt(const char* data);

	std::vector<int> GetData() const;
	int GetSize() const;
	int GetSign() const;


	BigInt operator+(const BigInt& bigint);
	BigInt operator*(const BigInt& bigint);
	BigInt operator*(const int d);
	BigInt operator-(const BigInt& bigint);
	BigInt operator/(const BigInt& bigint);
	BigInt operator%(const BigInt& bigint);
	bool operator<(const BigInt& bigint);
	bool operator>(const BigInt& bigint);
	BigInt operator-();
	BigInt multByTen(int power);
	bool operator==(const BigInt& bigint);
	bool operator!=(const BigInt& bigint);
	static BigInt Abs(const BigInt& bigint);

	friend std::ostream& operator<<(std::ostream& os, const BigInt& bigint);

private:
	void StringToData(const std::string& str);
	void EraseLeadingZeros(std::vector<int>& v);
	int Div(const int a, const int b) const;
	int Mod(const int a, const int b) const;
	std::tuple<BigInt, BigInt> Divide(const BigInt& bigint);

private:
	std::vector<int> m_data;
	int m_sign;
};
