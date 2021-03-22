#include "BigInt.h"
#include <iostream>
int main(int argc, char** argv)
{
	auto n1 = BigInt("10000");
	auto n2 = BigInt("-225");
	BigInt result = n1 % n2;
	std::cout << result << std::endl;
	return(0);
}