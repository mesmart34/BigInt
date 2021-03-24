#include "StringEncoder.h"

std::vector<BigInt> StringEncoder::Encrypt(const std::string msg, std::tuple<BigInt, BigInt> openedKey) const
{
	auto sz = msg.size();
	auto result = std::vector<BigInt>();
	result.reserve(sz);
	for (auto i = 0; i < sz; i++) 
	{
		auto index = (int)(std::tolower(msg.at(i))) - 97;
		auto bigInt = BigInt(std::to_string(index));
		result.push_back(m_RSA.Encrypt(bigInt, openedKey));
	}
	return result;
}

std::string StringEncoder::Decrypt(std::vector<BigInt> msg, std::tuple<BigInt, BigInt> closedKey) const
{
	auto sz = msg.size();
	auto result = std::string(sz, ' ');
	for (auto i = 0; i < sz; i++)
	{
		auto encoded = msg.at(i);
		auto bigIntIndex = m_RSA.Decrypt(encoded, closedKey);
		auto index = bigIntIndex.toBin();
		result[i] = index + 97;
	}
	return result;
}