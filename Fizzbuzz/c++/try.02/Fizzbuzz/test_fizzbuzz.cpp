#include "gtest/gtest.h"
#include "Fizzbuzz.h"

#define LIST_COUNT 100

class TestFizzBuzz : public ::testing::Test
{
public:
	Fizzbuzz fizzbuzz;

	void TestMagicNumber(int magicNumber, string expected)
	{
		vector<string> actual = fizzbuzz.getList(LIST_COUNT);

		for (int i = magicNumber; i <= LIST_COUNT; i += magicNumber)
		{
			if (isNumberDivisibleByAHigherMagicNumber(i, magicNumber))
				continue;

			EXPECT_EQ(expected, actual[i - 1]) << "Failed for i = " << i;
		}
	}

	bool isNumberDivisibleByAHigherMagicNumber(int number, int currentMagicNumber)
	{
		for (auto iter : fizzbuzz.magicNumbers)
			if (iter.first > currentMagicNumber && 0 == number % iter.first)
				return true;

		return false;
	}
};

TEST_F(TestFizzBuzz, 1is1)
{
	vector<string> expected = { "1" };
	
	Fizzbuzz fizzbuzz;
	vector<string> actual = fizzbuzz.getList(1);

	EXPECT_EQ(expected, actual);
}

TEST_F(TestFizzBuzz, 3s_are_Fizz)
{
	TestMagicNumber(3, "Fizz");
}

TEST_F(TestFizzBuzz, 5s_are_Buzz)
{
	TestMagicNumber(5, "Buzz");
}

TEST_F(TestFizzBuzz, 3_and_5_is_FizzBuzz)
{
	TestMagicNumber(15, "FizzBuzz");
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	int iResult = RUN_ALL_TESTS();
	printf("Press any key to continue...");
	(void)getchar();
	return iResult;
}