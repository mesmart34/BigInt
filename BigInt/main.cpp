#include "BigInt.h"

int main(int argc, char** argv)
{
	auto bigint1 = BigInt("12");
	auto bigint2 = BigInt("34");
	auto sum = bigint1 + bigint2;
	auto expected = BigInt(std::vector<int>{4, 6}, 1);
	return(0);
}