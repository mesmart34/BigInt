#include "RSA.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <algorithm>

static void WriteToFile(const string& path, vector<string> message)
{
	auto file = ofstream();
	file.open(path);
	for (auto msg : message)
		file << msg;
	file.close();
}

static vector<BigInt> ReadFromFile(const string& path)
{
	auto v = vector<vector<std::string>>();
	auto file = ifstream();
	file.open(path);
	auto line = string();
	while (getline(file, line)) {
		auto iss = istringstream(line);
		auto results = vector<string>(
			istream_iterator<string>{iss},
			istream_iterator<string>());
		v.push_back(results);
	}
	file.close();
	auto encoded = vector<BigInt>();
	for (auto s : v)
	{
		for (auto r : s)
			encoded.push_back(BigInt(r));
	}
	return encoded;
}

static void DecodeFromFileToFile()
{
	cout << "Enter first closed key..." << endl;
	auto b1 = string();
	cin >> b1;
	auto b = BigInt(b1);
	cout << "Enter second closed key..." << endl;
	auto b2 = string();
	cin >> b2;
	auto n = BigInt(b2);
	auto encoded = ReadFromFile("encoded.txt");
	auto decoded = RSA::Decode(encoded, b, n);
	WriteToFile("decoded.txt", {decoded});
	cout << "Output has been written to \"decoded.txt\"" << endl;
}

static void EncodeToFile()
{
	//Entering msg for encoding
	cout << "Enter a message to encode..." << endl;
	auto msg = string();
	getline(cin >> std::ws, msg);

	//Entering primes numbers
	cout << "Enter first prime number..." << endl;
	auto primeString = string();
	getline(cin >> std::ws, primeString);
	auto prime1 = BigInt(primeString);
	cout << "Enter second prime number..." << endl;
	getline(cin >> std::ws, primeString);
	auto prime2 = BigInt(primeString);

	//RSA Init
	auto rsa = RSA(prime1, prime2);
	auto closeKeys = rsa.GetCloseKeys();
	auto openKeys = rsa.GetOpenKeys();

	cout << "Open keys: " << get<0>(openKeys) << ", " << get<1>(openKeys) << endl;
	cout << "Close keys: " << get<0>(closeKeys) << ", " << get<1>(closeKeys) << endl;
	
	//Encoding
	auto encoded = RSA::Encode(msg, get<0>(openKeys), get<1>(openKeys));
	cout << "Encoded message has been written to \'encoded.txt\'" << endl;

	//Writing encoded message to a file
	auto encodedStrings = vector<string>();
	for (auto enc : encoded)
		encodedStrings.push_back(enc.ToString() + " ");

	WriteToFile("encoded.txt", encodedStrings);

}

int main(int argc, char** argv)
{
	auto answer = '0';
	while (answer != '3') {
		cout << "Enter the number" << endl;
		cout << "1. Encode \n2. Decode \n3. Exit" << endl;
		answer = cin.get();
		if (answer == '1') {
			EncodeToFile();
		}
		else if (answer == '2') {
			DecodeFromFileToFile();
		}
	} 
	return(0);
}