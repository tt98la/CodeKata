#include "fizzbuzz.h"


fizzbuzz::fizzbuzz(void)
{
	specialNumbers.insert(fizzbuzz_pair(3, "fizz"));
	specialNumbers.insert(pair<int, char*>(5, "buzz"));
	specialNumbers.insert(fizzbuzz_map::value_type(15, "fizzbuzz"));
	specialNumbers.insert(fizzbuzz_map::value_type(33, "fizzyfizz"));
	specialNumbers.insert(fizzbuzz_map::value_type(55, "buzzybuzz"));
	specialNumbers.insert(fizzbuzz_map::value_type(99, "whoopdeedoo"));
}


fizzbuzz::~fizzbuzz(void)
{
	specialNumbers.clear();
}

vector<string> fizzbuzz::GetList(int count)
{
	vector<string> fizzbuzzList(count);
	
	for(int i = 1; i <= count; i++)
	{
		fizzbuzzList[i-1] = GetSpecialValue(i);
	}
	return fizzbuzzList;
}

string fizzbuzz::GetSpecialValue(int number)
{
	int fizzbuzzNumber = GetSpecialNumber(number);
	
	if (fizzbuzzNumber > 0)
		return specialNumbers.at(fizzbuzzNumber);
	else
		return to_string(number);
}

int fizzbuzz::GetSpecialNumber(int number)
{
	int fizzbuzzNumber = 0;
	
	for(auto specialNumber: specialNumbers)
		if ((number % specialNumber.first == 0))
			fizzbuzzNumber = specialNumber.first;

	return fizzbuzzNumber;
}
