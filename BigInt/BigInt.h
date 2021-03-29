#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <tuple>
#include <sstream>

using namespace std;

class BigInt
{
public:
	BigInt(vector<uint8_t> data = { 0 }, int8_t sign = 1);
	BigInt(const std::string& data);
	BigInt(const char* data);
	BigInt(const int number);

	std::vector<uint8_t> GetData() const;
	uint8_t GetSize() const;
	int8_t GetSign() const;


	BigInt operator+(const BigInt& other) const;
	BigInt operator*(const BigInt& other) const;
	BigInt operator*(const uint8_t d) const;
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
	string ToString() const;

	friend std::ostream& operator<<(std::ostream& os, const BigInt& bigint);
	static BigInt GetInverseElementModulo(const BigInt& n1, const BigInt& n2);
	static bool IsPrime(const BigInt& other);
	static BigInt GCD(const BigInt& n1, const BigInt& n2, BigInt& x, BigInt& y);
	static BigInt Abs(const BigInt& b);
	static BigInt ModPow(const BigInt& n1, const BigInt& power, const BigInt& mod);

	static uint8_t ParseToInt(const BigInt& other);
private:
	static BigInt StringToData(const std::string& str) ;
	static BigInt MultByTen(const BigInt& other, const uint8_t power);
	static std::vector<uint8_t> EraseLeadingZeros(const std::vector<uint8_t>& v);
	static void FillSameSize(const BigInt& a, const BigInt& b, vector<uint8_t>& aDigits, vector<uint8_t>& bDigits);
	static std::tuple<uint64_t, BigInt> Divide(const BigInt& a, const BigInt& b);

private:
	std::vector<uint8_t> m_digits;
	int8_t m_sign;
};
