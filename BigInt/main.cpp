#include "BigInt.h"
#include <iostream>
int main(int argc, char** argv)
{
	auto n1 = BigInt("1000");
	auto n2 = BigInt("2000");
	auto result = (n1 - n2) * 5;
	std::cout << result << std::endl;
	return(0);
}