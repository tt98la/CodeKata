#pragma once
#include "stdafx.h"
#include <string>
#include <map>

using namespace std;

class fizzbuzz
{
public:
	map<int,string> magicNumbers;
	typedef pair<int,string> fizzbuzzPair;

	fizzbuzz(void);
	~fizzbuzz(void);

	void getFizzbuzz(int count, string* pList);
	string GetFizzbuzzValue(int i);
};

