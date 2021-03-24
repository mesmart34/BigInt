#pragma once

#include <vector>
#include <string>

#include "BigInt.h"
#include "RSA.h"

class StringEncoder
{
public:
	 StringEncoder() = delete;
	 StringEncoder(RSA rsa) : m_RSA(rsa) {};

	 std::vector<BigInt> Encrypt(const std::string msg, std::tuple<BigInt, BigInt> openedKey) const;
	 std::string Decrypt(std::vector<BigInt> msg, std::tuple<BigInt, BigInt> closedKey) const;
private:
	RSA m_RSA;	
};