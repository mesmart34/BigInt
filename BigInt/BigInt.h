#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <tuple>

class BigInt
{
public:
	BigInt(uint64_t value = 0);

	std::vector<uint64_t> GetData() const;
	size_t GetSize() const;
	int16_t GetSign() const;

	bool operator<(const BigInt& other) const;
	bool operator>(const BigInt& other) const;

	BigInt operator<<(const uint64_t offset);
	BigInt operator>>(const uint64_t offset);

	BigInt operator+(const BigInt& other) const;
	BigInt operator*(const BigInt& other) const;
	
	BigInt operator-(const BigInt& other) const;
	BigInt operator/(const BigInt& other) const;
	BigInt operator%(const BigInt& other) const;
	
	BigInt operator-() const;
	
	bool operator==(const BigInt& other) const;
	bool operator!=(const BigInt& other) const;


	BigInt Mod(BigInt& m);
	static BigInt Abs(const BigInt& other);
	static BigInt MultInv(const BigInt& e, const BigInt& t);

	friend std::ostream& operator<<(std::ostream& os, const BigInt& bigint);
	

private:	
	static size_t GetMaxSize(const BigInt& a, const BigInt& b);
	static size_t GetMinSize(const BigInt& a, const BigInt& b);
	static void CarryAdd(uint64_t a, uint64_t b, uint64_t& value, uint64_t& carry);
	static void CarrySub(uint64_t a, uint64_t b, uint64_t& value, uint64_t& carry);
	
	static BigInt SumPositive(const BigInt& a, const BigInt& b);
	static BigInt SubPositive(const BigInt& a, const BigInt& b);
	static int AbsCompare(const BigInt& a, const BigInt& b);
	static void EraseLeadingZeros(std::vector<uint64_t>& v);
private:
	std::vector<uint64_t> m_data;
	int16_t m_sign;
};
