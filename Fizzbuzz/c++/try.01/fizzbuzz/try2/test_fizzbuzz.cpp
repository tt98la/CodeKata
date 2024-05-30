#include "gtest\gtest.h"
#include "stdafx.h"
#include <string>
#include <map>
#include "fizzbuzz.h"

using namespace std;
#define LIST_MAX 100

class TestFizzbuzz : public ::testing::Test
{
public:
	fizzbuzz testfizzbuzz_obj;
	string actualList[LIST_MAX];
	
	void SetUp(void)
	{
		testfizzbuzz_obj.getFizzbuzz(LIST_MAX, actualList);
	}

	void TestMultiple(int iMultiple, string expected)
	{
		bool bTested = false;
		
		for(int i = iMultiple; i <= LIST_MAX; i += iMultiple)
		{
			if(IsNumberDivisableByOtherMultiple(i, iMultiple))
				continue;

			EXPECT_EQ(expected, actualList[i-1]) << "Mismatch for " << i;
			bTested = true;
		}

		ASSERT_TRUE(bTested);
	}

	bool IsNumberDivisableByOtherMultiple(int iNumber, int iCurrentMultiple)
	{
		map<int,string>::reverse_iterator iter;
		iter = testfizzbuzz_obj.magicNumbers.rbegin();
		for(; iter != testfizzbuzz_obj.magicNumbers.rend(); iter++)
		{
			if(iter->first > iCurrentMultiple && 
				iNumber % iter->first == 0)
					return true;
		}

		return false;
	}
};

TEST_F(TestFizzbuzz, sequence)
{
	string expectedList[] = {"1","2","fizz","4","buzz","fizz","7","8","fizz","buzz","11","fizz","13","14","fizzbuzz"};
	string actualList[15];

	testfizzbuzz_obj.getFizzbuzz(15, actualList);

	for(int i = 0; i < 15; i++)
		EXPECT_EQ(expectedList[i], actualList[i]) << "Mismatch for " << i+1;
}

TEST_F(TestFizzbuzz, DivisableBy3EqualsFizz)
{
	TestMultiple(3, "fizz");
}

TEST_F(TestFizzbuzz, DivisableBy5EqualsBuzz)
{
	TestMultiple(5, "buzz");
}

TEST_F(TestFizzbuzz, DivisableBy15EqualsBuzz)
{
	TestMultiple(15, "fizzbuzz");
}

TEST_F(TestFizzbuzz, DivisableBy33EqualsFizzyFizz)
{
	TestMultiple(33, "fizzyfizz");
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
