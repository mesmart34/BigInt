#include <iostream>

#include "BigInt.h"
#include "RSA.h"
#include "StringEncoder.h"

int main(int argc, char** argv)
{
	auto rsa = RSA();
	auto strEnc = StringEncoder(rsa);
	auto keys = rsa.GenerateKeys("31", "37");

	auto e = std::get<0>(keys);
	auto n = std::get<1>(keys);
	auto d = std::get<2>(keys);

	auto enc = strEnc.Encrypt("hi", std::tuple<BigInt, BigInt>(e, n));
	auto dec = strEnc.Decrypt(enc, std::tuple<BigInt, BigInt>(d, n));

	std::cout << dec << std::endl;

	system("pause");
	return(0);
}