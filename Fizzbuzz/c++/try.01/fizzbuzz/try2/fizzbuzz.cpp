#include "fizzbuzz.h"


fizzbuzz::fizzbuzz(void)
{
	magicNumbers.insert(fizzbuzzPair(3,"fizz"));
	magicNumbers.insert(fizzbuzzPair(5,"buzz"));
	magicNumbers.insert(fizzbuzzPair(15,"fizzbuzz"));
	magicNumbers.insert(fizzbuzzPair(33,"fizzyfizz"));
}


fizzbuzz::~fizzbuzz(void)
{
}

void fizzbuzz::getFizzbuzz(int count, string* pList)
{
	for(int i = 1; i <= count; i++)
		pList[i-1] = GetFizzbuzzValue(i);
}

string fizzbuzz::GetFizzbuzzValue(int i)
{
	map<int,string>::reverse_iterator iter = magicNumbers.rbegin();
	for(; iter != magicNumbers.rend(); iter++)
		if(i % iter->first == 0)
			return iter->second;

	return to_string(i);
}

