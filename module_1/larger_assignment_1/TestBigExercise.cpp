#include "catch_amalgamated.hpp"
#include "Functions.hpp"
#include <stdlib.h>

bool isSorted(std::string arr[], int size)
{
	for (int i = 0; i < size-1; i++)
	{
		if (arr[i] > arr[i + 1])
			return false;
	}
	return true;
}

void rearange(std::string arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int index1 = rand() % size;
		int index2 = rand() % size;
		std::swap(arr[index1], arr[index2]);
	}
}

bool isEqual(std::string arrOne[], std::string arrTwo[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (arrOne[i] != arrTwo[i])
			return false;
	}
	return true;
}

TEST_CASE("Testing sort")
{
	SECTION("Array with 1 word")
	{
		const int cap = 1;
		std::string arr[cap]{ "one" };
		sort(arr, cap);
		REQUIRE(isSorted(arr, cap));
	}
	SECTION("Array with 2 words")
	{
		const int cap = 2;
		SECTION("Identical words")
		{
			std::string arr[cap]{ "one", "one" };
			sort(arr, cap);
			REQUIRE(isSorted(arr, cap));
		}
		SECTION("Reversed ordered words")
		{
			std::string arr[cap]{ "two", "one" };
			sort(arr, cap);
			REQUIRE(isSorted(arr, cap));
		}
		SECTION("Already ordered words")
		{
			std::string arr[cap]{ "one", "two" };
			sort(arr, cap);
			REQUIRE(isSorted(arr, cap));
		}
	}
	SECTION("Array with 3 words")
	{
		const int cap = 3;
		SECTION("Identical words")
		{
			std::string arr[cap]{ "one", "one" , "one"};
			sort(arr, cap);
			REQUIRE(isSorted(arr, cap));
		}
		SECTION("Reversed ordered words")
		{
			std::string arr[cap]{ "cecil", "betty", "bert" };
			sort(arr, cap);
			REQUIRE(isSorted(arr, cap));
		}
		SECTION("Already ordered words")
		{
			std::string arr[cap]{ "bert", "betty","cecil"};
			sort(arr, cap);
			REQUIRE(isSorted(arr, cap));
		}
		SECTION("Mixed ordered words")
		{
			std::string arr[cap]{ "bert", "cecil","betty" };
			sort(arr, cap);
			REQUIRE(isSorted(arr, cap));
		}
	}
	SECTION("Array with 10 words")
	{
		const int cap = 10;
		SECTION("Smallest word last in array")
		{
			std::string arr[cap]{ "frog" , "fox", "snake", "dog", "cow", "fly", "hourse", "snail", "mouse", "cat" };
			sort(arr, cap);
			REQUIRE(isSorted(arr, cap));
		}
		SECTION("Smallest word first in array")
		{
			std::string arr[cap]{ "cat", "frog" , "fox", "snake", "dog", "cow", "fly", "hourse", "snail", "mouse" };
			sort(arr, cap);
			REQUIRE(isSorted(arr, cap));
		}
		SECTION("Smallest word somewhere inbetween the array")
		{
			std::string arr[cap]{ "mouse", "frog" , "fox", "snake", "cat", "dog", "cow", "fly", "hourse", "snail" };
			sort(arr, cap);
			REQUIRE(isSorted(arr, cap));
		}
		SECTION("Mixed ordered words")
		{
			bool sorted = true;
			for (int i = 0; i < 5; i++)
			{
				std::string arr[cap]{ "mouse", "frog" , "fox", "snake", "cat", "dog", "cow", "fly", "hourse", "snail" };
				rearange(arr, cap);
				sort(arr, cap);
				sorted = sorted && isSorted(arr, cap);
			}
			REQUIRE(sorted);
		}
	}
}

TEST_CASE("Testing getWordPartitionSize")
{
	int nrOfLong = 0;
	int nrOfShort = 0;
	SECTION("split length 0")
	{
		const int cap = 10;
		std::string arr[cap]{ "mouse", "frog" , "fox", "snake", "cat", "dog", "cow", "fly", "hourse", "snail" };
		getWordPartitionSize(arr, cap, 0, nrOfShort, nrOfLong);
		REQUIRE(nrOfShort == 0);
		REQUIRE(nrOfLong == cap);
	}
	SECTION("split length 1")
	{
		const int cap = 10;
		std::string arr[cap]{ "mouse", "frog" , "fox", "snake", "cat", "dog", "cow", "fly", "hourse", "snail" };
		getWordPartitionSize(arr, cap, 1, nrOfShort, nrOfLong);
		REQUIRE(nrOfShort == 0);
		REQUIRE(nrOfLong == cap);
	}
	SECTION("split length 3")
	{
		const int cap = 10;
		std::string arr[cap]{ "mouse", "frog" , "fox", "snake", "cat", "dog", "cow", "fly", "hourse", "snail" };
		getWordPartitionSize(arr, cap, 3, nrOfShort, nrOfLong);
		REQUIRE(nrOfShort == 0);
		REQUIRE(nrOfLong == cap);
	}
	SECTION("split length 5")
	{
		const int cap = 10;
		std::string arr[cap]{ "mouse", "frog" , "fox", "snake", "cat", "dog", "cow", "fly", "hourse", "snail" };
		getWordPartitionSize(arr, cap, 5, nrOfShort, nrOfLong);
		REQUIRE(nrOfShort == 6);
		REQUIRE(nrOfLong == cap - 6);
	}
	SECTION("split length 6")
	{
		const int cap = 10;
		std::string arr[cap]{ "mouse", "frog" , "fox", "snake", "cat", "dog", "cow", "fly", "hourse", "snail" };
		getWordPartitionSize(arr, cap, 6, nrOfShort, nrOfLong);
		REQUIRE(nrOfShort == 9);
		REQUIRE(nrOfLong == cap - 9);
	}
}

TEST_CASE("Testing partition")
{
	int nrOfLong = 0;
	int nrOfShort = 0;
	SECTION("split length 0")
	{
		const int cap = 10;
		std::string arr[cap]{ "mouse", "frog" , "fox", "snake", "cat", "dog", "cow", "fly", "hourse", "snail" };
		std::string* arrShort = nullptr;
		std::string arrLong[cap];

		partition(arr, cap, arrShort, arrLong, 0);
		REQUIRE(isEqual(arr, arrLong, cap));
	}
	SECTION("split length 5")
	{
		const int cap = 10;
		std::string arr[cap]{ "mouse", "frog" , "fox", "snake", "cat", "dog", "cow", "fly", "hourse", "snail" };
		std::string arrShort[6];
		std::string arrLong[4];

		std::string arrCorrectShort[6]{ "frog" , "fox", "cat", "dog", "cow", "fly" };
		std::string arrCorrectLong[4]{ "mouse", "snake", "hourse", "snail" };
		partition(arr, cap, arrShort, arrLong, 5);
		REQUIRE(isEqual(arrCorrectLong, arrLong, 4));
		REQUIRE(isEqual(arrCorrectShort, arrShort, 6));
	}
	SECTION("split length 6")
	{
		const int cap = 10;
		std::string arr[cap]{ "mouse", "frog" , "fox", "snake", "cat", "dog", "cow", "fly", "hourse", "snail" };
		std::string arrShort[9];
		std::string arrLong[1];

		std::string arrCorrectShort[9]{ "mouse", "frog" , "fox", "snake", "cat", "dog", "cow", "fly", "snail" };
		std::string arrCorrectLong[1]{ "hourse" };
		partition(arr, cap, arrShort, arrLong, 6);
		REQUIRE(isEqual(arrCorrectLong, arrLong, 1));
		REQUIRE(isEqual(arrCorrectShort, arrShort, 9));
	}
}

TEST_CASE("Testing wordSorter")
{
	// här skriver du dba egna tester
}