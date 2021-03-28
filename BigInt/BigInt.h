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
	bool operator<(const BigInt& other) const;
	bool operator<=(const BigInt& other) const;
	bool operator>(const BigInt& other) const;
	bool operator>=(const BigInt& other) const;
	BigInt operator-() const;
	BigInt operator++();
	BigInt operator--();
	BigInt multByTen(int power);
	bool operator==(const BigInt& biothergint) const;
	bool operator!=(const BigInt& other) const;

	friend std::ostream& operator<<(std::ostream& os, const BigInt& bigint);

private:
	void StringToData(const std::string& str);
	static std::vector<int> EraseLeadingZeros(const std::vector<int>& v);
	static void FillSameSize(const BigInt& a, const BigInt& b, vector<int>& aDigits, vector<int>& bDigits);
	static std::tuple<int, BigInt> Divide(const BigInt& a, const BigInt& b);
	static BigInt Abs(const BigInt& b);

private:
	std::vector<int> m_digits;
	int m_sign;
};
