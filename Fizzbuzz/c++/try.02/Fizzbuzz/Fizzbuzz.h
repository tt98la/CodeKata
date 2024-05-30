#pragma once
#include <string>
#include <vector>
#include <map>

using namespace std;

class Fizzbuzz
{
public:
	const map<int, string> magicNumbers =
	{
		{3, "Fizz"},
		{5, "Buzz"},
		{15, "FizzBuzz"}
	};

	Fizzbuzz();
	~Fizzbuzz();
	vector<string> getList(int numItems);
	string GetValue(int magicNumber);
};

