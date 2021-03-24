#pragma once

#include "BigInt.h"
#include <tuple>

class RSA
{
public:
	RSA() = default;

	std::tuple<BigInt, BigInt, BigInt> GenerateKeys(const BigInt& a, const BigInt& b);
	BigInt Encrypt(const BigInt& msg, std::tuple<BigInt, BigInt> openedKey) const;
	BigInt Decrypt(const BigInt& msg, std::tuple<BigInt, BigInt> closedKey) const;

private:
	BigInt CalculateE(const BigInt& t) const;
	BigInt GCD(const BigInt& a, const BigInt& b) const;

};

