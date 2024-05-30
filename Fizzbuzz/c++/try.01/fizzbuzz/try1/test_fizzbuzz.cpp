#include "fizzbuzz.h"
#include "gtest\gtest.h"

#define LIST_SIZE 1000

void testMultiple(const int iMultiple, const string expected, const int iListLength);
bool isNumberOnlyDivisableByMultiple(const int number, const int iCurrentMultiple);

class TestFizzBuzz : public ::testing::Test
{
public:
	fizzbuzz fizzbuzzTest;
	vector<string> actualList;

	void SetUp(void)
	{
		actualList = fizzbuzzTest.GetList(LIST_SIZE);
	}

	void testMultiple(const int iMultiple, const string expected)
	{
		bool bChecked = false;

		for(int i = iMultiple; i <= LIST_SIZE; i += iMultiple)
		{
			if(isNumberOnlyDivisableByMultiple(i, iMultiple))
			{
				EXPECT_EQ(expected, actualList[i-1]) << "Unexpected value for " << i;
				bChecked = true;
			}
		}

		ASSERT_TRUE(bChecked);
	}

	bool isNumberOnlyDivisableByMultiple(const int number, const int iCurrentMultiple)
	{
		fizzbuzz_map::reverse_iterator iter;

		iter = fizzbuzzTest.specialNumbers.rbegin();
		for(; iter != fizzbuzzTest.specialNumbers.rend() && iter->first > iCurrentMultiple; iter++)
		{
			if(number % iter->first == 0)
				return false;
		}
		return true;
	}
};

TEST_F(TestFizzBuzz, firstValue)
{
	fizzbuzz fizzbuzzTest;
	string expectedList[] = {"1"};
	vector<string> actualList = fizzbuzzTest.GetList(1);
	
	ASSERT_EQ(expectedList[0], actualList[0]);
}

TEST_F(TestFizzBuzz, sequence)
{
	int iMax = 15;
	fizzbuzz fizzbuzzTest;
	string expectedList[] = {"1","2","fizz","4","buzz","fizz","7","8","fizz","buzz","11","fizz","13","14","fizzbuzz"};
	vector<string> actualList = fizzbuzzTest.GetList(iMax);
	
	for(int i = 0; i < iMax; i++)
	{
		ASSERT_EQ(expectedList[i], actualList[i]);
	}
}

TEST_F(TestFizzBuzz, divisableBy3EqualsFizz)
{
	testMultiple(3, "fizz");
}

TEST_F(TestFizzBuzz, divisableBy5EqualsBuzz)
{
	testMultiple(5, "buzz");
}

TEST_F(TestFizzBuzz, divisableBy15EqualsFizzBuzz)
{
	testMultiple(15, "fizzbuzz");
}

TEST_F(TestFizzBuzz, divisableBy33EqualsFizzyFizz)
{
	testMultiple(33, "fizzyfizz");
}

TEST_F(TestFizzBuzz, divisableBy55EqualsBuzzyBuzz)
{
	testMultiple(55, "buzzybuzz");
}

TEST_F(TestFizzBuzz, divisableBy99EqualsWhoopDeeDoo)
{
	testMultiple(99, "whoopdeedoo");
}


int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	int iResult = RUN_ALL_TESTS();
	printf("Press any key to continue...");
	(void)getchar();
	return iResult;
}