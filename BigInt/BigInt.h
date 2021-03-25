#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <tuple>

class BigInt
{
public:
	BigInt(uint64_t value);

	std::vector<uint64_t> GetData() const;
	size_t GetSize() const;
	int16_t GetSign() const;

	bool operator<(const BigInt& other);
	bool operator>(const BigInt& other);

	BigInt operator+(const BigInt& other);
	BigInt operator*(const BigInt& other);
	BigInt operator*(const int d);
	BigInt operator-(const BigInt& other);
	BigInt operator/(const BigInt& other);
	BigInt operator%(const BigInt& other);
	
	BigInt operator-();
	BigInt Mod(BigInt& m);
	bool operator==(const BigInt& other);
	bool operator!=(const BigInt& other);
	static BigInt Abs(const BigInt& other);
	static BigInt multInv(const BigInt& e, const BigInt& t);

	friend std::ostream& operator<<(std::ostream& os, const BigInt& bigint);
	static void EraseLeadingZeros(std::vector<uint64_t>& v);
	static size_t GetMaxSize(const BigInt& a, const BigInt& b);
	static size_t GetMinSize(const BigInt& a, const BigInt& b);

	static void CarryAdd(uint64_t a, uint64_t b, uint64_t& value, uint64_t& carry);
	static void CarrySub(uint64_t a, uint64_t b, uint64_t& value, uint64_t& carry);

	static BigInt SumPositive(const BigInt& a, const BigInt& b);
	static BigInt SubPositive(const BigInt& a, const BigInt& b);

	static int AbsCompare(const BigInt& a, const BigInt& b);

private:
	void StringToData(const std::string& str);
	std::tuple<BigInt, BigInt> Divide(const BigInt& other);

private:
	std::vector<uint64_t> m_data;
	int16_t m_sign;
};
