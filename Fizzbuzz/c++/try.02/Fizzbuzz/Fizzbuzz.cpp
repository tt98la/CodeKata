// Fizzbuzz.cpp : Defines the entry point for the console application.
//

#include "Fizzbuzz.h"

Fizzbuzz::Fizzbuzz()
{
}


Fizzbuzz::~Fizzbuzz()
{
}


vector<string> Fizzbuzz::getList(int numItems)
{
	vector<string> sRetValue(numItems);

	for (int i = 1; i <= numItems; i++)
		sRetValue[i-1] = GetValue(i);
	
	return sRetValue;
}

string Fizzbuzz::GetValue(int magicNumber)
{
	string sRetValue = to_string(magicNumber);

	for (auto iter : magicNumbers)
		if (0 == magicNumber % iter.first)
			sRetValue = iter.second;

	return sRetValue;
}
