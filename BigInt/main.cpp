#include <iostream>

#include "BigInt.h"
#include "RSA.h"
#include "StringEncoder.h"

int main(int argc, char** argv)
{
	auto a = BigInt(UINT64_MAX / 2);
	auto b = BigInt(UINT64_MAX / 2);
	for (auto i = 0; i < 100; i++) {
		std::cout << a << std::endl;
		a = a + b;		
	}
	system("pause");
}