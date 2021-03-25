#include <chrono>
#include <iostream>

#include "BigInt.h"
#include "RSA.h"
#include "StringEncoder.h"

int main(int argc, char** argv)
{
	
	auto arr = std::vector<BigInt>();
	auto half = (UINT64_MAX / 2) + 1;
	auto a = BigInt(0);
	auto b = BigInt(half);
	auto start = std::chrono::high_resolution_clock::now();
	for (auto i = 0; i < 100; i++) {
		a = a + b;
		a = a + b;
		a = a + b;
		a = a + a;
		arr.push_back(a);
	}
	auto end = std::chrono::high_resolution_clock::now();
	auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	std::cout << time << std::endl;
	for (size_t i = 0; i < 100; i++)
	{
		for (size_t j = 0; j < 100; j++)
		{
			if (i > j != arr[i] > arr[j])
				throw "err1";
			if (i < j != arr[i] < arr[j])
				throw "err1";
		}
	}

	system("pause");
}