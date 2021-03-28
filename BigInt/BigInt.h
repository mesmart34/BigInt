#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <tuple>

using namespace std;

class BigInt
{
public:
	BigInt(vector<int> data, int sign);
	BigInt(const std::string& data);
	BigInt(const char* data);
	BigInt(const int number);

	std::vector<int> GetData() const;
	int GetSize() const;
	int GetSign() const;


	BigInt operator+(const BigInt& other) const;
	BigInt operator*(const BigInt& other) const;
	BigInt operator*(const int d) const;
	BigInt operator-(const BigInt& other) const;
	BigInt operator/(const BigInt& other) const;
	BigInt operator%(const BigInt& other) const;
	BigInt operator+=(const BigInt& other);
	BigInt operator-=(const BigInt& other);
	BigInt operator*=(const BigInt& other);
	BigInt operator/=(const BigInt& other);
	BigInt operator%=(const BigInt& other);
	bool operator<(const BigInt& other) const;
	bool operator<=(const BigInt& other) const;
	bool operator>(const BigInt& other) const;
	bool operator>=(const BigInt& other) const;
	BigInt operator-() const;
	BigInt operator++();
	BigInt operator--();
	bool operator==(const BigInt& other) const;
	bool operator!=(const BigInt& other) const;

	friend std::ostream& operator<<(std::ostream& os, const BigInt& bigint);
	static BigInt GetInverseElementModulo(const BigInt& n1, const BigInt& n2);

private:
	static BigInt StringToData(const std::string& str) ;
	static BigInt MultByDigit(const BigInt& other, const int power);
	static std::vector<int> EraseLeadingZeros(const std::vector<int>& v);
	static void FillSameSize(const BigInt& a, const BigInt& b, vector<int>& aDigits, vector<int>& bDigits);
	static std::tuple<int, BigInt> Divide(const BigInt& a, const BigInt& b);
	static BigInt Abs(const BigInt& b);
	static BigInt GCD(const BigInt& n1, const BigInt& n2, BigInt& x, BigInt& y);

private:
	std::vector<int> m_digits;
	int m_sign;
};
