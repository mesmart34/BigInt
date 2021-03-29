#pragma once

#include <string>
#include <vector>
#include <tuple>
#include <sstream>
#include "BigInt.h"

using namespace std;

class RSA
{
public:
	RSA(const BigInt& p, const BigInt& q);

	static vector<BigInt> Encode(const string& msg, const BigInt& e, const BigInt& n);
	static string Decode(const vector<BigInt> msg, const BigInt& d, const BigInt& n);
	tuple<BigInt, BigInt> GetOpenKeys() const;
	tuple<BigInt, BigInt> GetCloseKeys() const;

private:
	BigInt e, d, n;
};

