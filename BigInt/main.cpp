#include <chrono>
#include <iostream>

#include "BigInt.h"
#include "RSA.h"
#include "StringEncoder.h"

int main(int argc, char** argv)
{
	
	auto arr = std::vector<BigInt>();
	auto half = (UINT64_MAX / 2) + 1;
	auto a = BigInt(1);
	auto b = BigInt(half);
	auto start = std::chrono::high_resolution_clock::now();
	
	std::cout << a << std::endl;
	a = a << 100;
	std::cout << a << std::endl;

	auto end = std::chrono::high_resolution_clock::now();	
	auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	std::cout << time << std::endl;
	system("pause");
}