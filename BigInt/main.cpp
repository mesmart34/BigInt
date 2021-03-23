#include "BigInt.h"
#include <iostream>
int main(int argc, char** argv)
{
	auto n1 = BigInt("10000");
	auto n2 = BigInt("-225");
	BigInt result = n1 % n2;
	std::cout << result << std::endl;

	auto test1 = 1281 % 325;
	auto test2 = -1281 % 325;
	auto test3 = 1281 % -325;
	auto test4 = -1281 % -325;

	return(0);
}