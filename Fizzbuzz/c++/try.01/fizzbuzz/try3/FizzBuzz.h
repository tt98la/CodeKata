#pragma once
#include <string>
#include <map>

using namespace std;

class FizzBuzz
{
public:
	map<int, string> magicNumbers;
	typedef pair<int, string> magicNumberEntry;

	FizzBuzz(void);
	~FizzBuzz(void);
	void GetFizzBuzzList(int count, string* pList);
	string GetFizzBuzzValue(int number);

};

