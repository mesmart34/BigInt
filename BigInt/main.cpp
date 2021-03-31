#include <chrono>
#include <iostream>

#include "BigInt.h"
#include "RSA.h"

int main(int argc, char** argv)
{
	RSA encoder = RSA(11, 13);
	auto keys = encoder.GetKeys();
	std::cout << "GotKeys" << std::endl;
	std::string data = "egorpidor";
	auto start = std::chrono::high_resolution_clock::now();
	auto encoded = RSA::Encode(data, std::get<0>(keys), std::get<2>(keys));
	auto result = RSA::Decode(encoded, std::get<1>(keys), std::get<2>(keys));
	auto end = std::chrono::high_resolution_clock::now();	
	auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	std::cout << time << std::endl;
	std::cout << result << std::endl;
	system("pause");
}