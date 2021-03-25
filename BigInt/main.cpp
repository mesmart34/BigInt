#include <iostream>

#include "BigInt.h"
#include "RSA.h"
#include "StringEncoder.h"

int main(int argc, char** argv)
{
	auto half = (UINT64_MAX / 2) + 1;
	std::cout << half << std::endl;
 	auto a = BigInt(half);
	auto b = BigInt(half);
	for (auto i = 0; i < 100; i++) {
		std::cout << a << std::endl;
		a = a + b;		
	}
	system("pause");
}