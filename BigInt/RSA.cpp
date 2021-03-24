#include "RSA.h"

std::tuple<BigInt, BigInt, BigInt> RSA::GenerateKeys(const BigInt& a, const BigInt& b)
{
    auto p = a;
    auto q = b;
    auto n = p * q;
    auto t = (p - "1") * (q - "1");
    auto e = CalculateE(t);
    auto d = BigInt::multInv(e, t);
    return std::tuple<BigInt, BigInt, BigInt>(e, n, d);
}

BigInt RSA::Encrypt(const BigInt& msg, std::tuple<BigInt, BigInt> openedKey) const
{

    auto result = BigInt("1");

    auto e = std::get<0>(openedKey);
    auto n = std::get<1>(openedKey);

    for (auto j = BigInt("0"); j < e; j = j + "1")
    {
        result = result * msg;
        result = result % n;
    }

    return result;
}

BigInt RSA::Decrypt(const BigInt& msg, std::tuple<BigInt, BigInt> closedKey) const
{

    auto result = BigInt("1");
    auto d = std::get<0>(closedKey);
    auto n = std::get<1>(closedKey);
    for (auto j = BigInt("0"); j < d; j = j + "1")
    {
        result = result * msg;
        result = result % n;
    }

    return result;
}

BigInt RSA::CalculateE(const BigInt& t) const
{
    auto b = BigInt("2");
    b = b + "1";
    b = b + "1";
    auto test = b < t;
    for (auto e = BigInt("2"); e < t; e = e + "1")
    {
        if (GCD(e, t) == "1")
        {
            return e;
        }
    }
    return BigInt("-1");
}

BigInt RSA::GCD(const BigInt& a, const BigInt& b) const
{
    auto e = a;
    auto t = b;
    while (e > "0")
    {

        auto myTemp = e;
        e = t % e;
        t = myTemp;
    }

    return t;
}
