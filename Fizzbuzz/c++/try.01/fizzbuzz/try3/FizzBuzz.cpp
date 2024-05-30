#include "FizzBuzz.h"

FizzBuzz::FizzBuzz(void)
{
	magicNumbers.insert(magicNumberEntry(3,"fizz"));
	magicNumbers.insert(magicNumberEntry(5,"buzz"));
	magicNumbers.insert(magicNumberEntry(6,"moo"));
	magicNumbers.insert(magicNumberEntry(15,"fizzbuzz"));
	magicNumbers.insert(magicNumberEntry(33,"fizzyfizz"));
}


FizzBuzz::~FizzBuzz(void)
{
}

void FizzBuzz::GetFizzBuzzList(int count, string* pList)
{
	for(int i = 1; i <= count; i++)
		pList[i-1] = GetFizzBuzzValue(i);
}

string FizzBuzz::GetFizzBuzzValue(int number)
{
	map<int, string>::reverse_iterator iter = magicNumbers.rbegin();
	for(; iter != magicNumbers.rend(); iter++)
		if(number % iter->first == 0)
			return iter->second;

	return to_string(number);
}
