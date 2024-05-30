#include "gtest\gtest.h"
#include "FizzBuzz.h"

#define LIST_COUNT 100

class TestFizzBuzz : public ::testing::Test
{
public:
	FizzBuzz testObj;
	string actualList[LIST_COUNT];

	void SetUp(void)
	{
		testObj.GetFizzBuzzList(LIST_COUNT, actualList);
	}

	void TestMultiple(int iMultiple, string sExpected)
	{
		bool bTested = false;

		for(int i = iMultiple; i <= LIST_COUNT; i += iMultiple)
		{
			if(IsNumberDivisableByAnotherMultiple(i, iMultiple))
				continue;

			EXPECT_EQ(sExpected, actualList[i-1]) << "Mismatch for " << i;
			bTested = true;
		}

		ASSERT_TRUE(bTested);
	}

	bool IsNumberDivisableByAnotherMultiple(int iNumber, int iCurrentMultiple)
	{
		map<int, string>::reverse_iterator iter = testObj.magicNumbers.rbegin();
		for(; iter != testObj.magicNumbers.rend(); iter++)
			if(iter->first > iCurrentMultiple && 
				iNumber % iter->first == 0)
					return true;

		return false;
	}
};

TEST_F(TestFizzBuzz, sequence)
{
	FizzBuzz testObj;
	string expectedList[] = {"1","2","fizz","4","buzz","moo","7","8","fizz","buzz","11","moo","13","14","fizzbuzz"};
	string actualList[15];
	testObj.GetFizzBuzzList(15, actualList);
	
	for(int i = 0; i < 15; i++)
		EXPECT_EQ(expectedList[i], actualList[i]) << "Mismatch for " << i+1;
}

TEST_F(TestFizzBuzz, DisvisableBy3EqualsFizz)
{
	TestMultiple(3, "fizz");
}

TEST_F(TestFizzBuzz, DisvisableBy5EqualsBuzz)
{
	TestMultiple(5, "buzz");
}

TEST_F(TestFizzBuzz, DisvisableBy6EqualsMoo)
{
	TestMultiple(6, "moo");
}

TEST_F(TestFizzBuzz, DisvisableBy15EqualsBuzz)
{
	TestMultiple(15, "fizzbuzz");
}

TEST_F(TestFizzBuzz, DisvisableBy33EqualsFizzyFizz)
{
	TestMultiple(33, "fizzyfizz");
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}