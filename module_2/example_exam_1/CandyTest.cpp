#include "Candy.h"
#include <iostream>
using namespace std;

// used for testing
const int NR_OF_CANDIES = 5;
const string names[NR_OF_CANDIES]{ "Mars", "Ahlgrens bilar", "Plopp", "Mars", "Plopp"};
const float prices[NR_OF_CANDIES]{ 15.5f, 23.5f, 17.f, 15.5f, 18.5f };

void prepareCandyObjects(Candy candies[])
{
	for (int i = 0; i < NR_OF_CANDIES; i++)
	{
		candies[i].setName(names[i]);
		candies[i].setPrice(prices[i]);
	}
}

bool testingBasics()
{
	cout << "Testing basics" << endl;

	Candy bCandy("Plopp", 12.5f);

	if (bCandy.getName() != "Plopp")
	{
		cout << "NOT CORRECT 1:  name, expected Plopp" << endl;
		return false;
	}
	string candyString = bCandy.toString();
	if (candyString.find("12.5") == string::npos)
	{
		cout << "NOT CORRECT 2: result from toString(), expected 12 as part of the string" << endl;
		return false;
	}
	Candy aCandy;
	aCandy.setName("Anton berg");
	aCandy.setPrice(123.f);
	if (aCandy.getName() != "Anton berg")
	{
		cout << "NOT CORRECT 3: name, expected Anton berg" << endl;
		return false;
	}

	candyString = aCandy.toString();
	if (candyString.find("Anton berg") == string::npos)
	{
		cout << "NOT CORRECT 4: result from toString(), expected Anton berg as part of the string" << endl;
		return false;

	}
	if (candyString.find("123.") == string::npos)
	{
		cout << "NOT CORRECT 5: result from toString(), expected 123 as part of the string" << endl;
		return false;

	}
	cout << "OK: Testing basics" << endl;
	return true;
}

bool testingEqualsOperator()
{
	cout << "Testing == " << endl;
	Candy candies[NR_OF_CANDIES];

	prepareCandyObjects(candies);
	if (!(candies[0] == candies[3]))
	{
		cout << "NOT CORRECT 1: comparing == when two identical objects, expected true" << endl;
		return false;
	}
	if (candies[0] == candies[1])
	{
		cout << "NOT CORRECT 2: comparing == when two different objects according to names, expected false" << endl;
		return false;
	}
	if (candies[2] == candies[4])
	{
		cout << "NOT CORRECT 3: comparing == when two different objects according to price, expected false" << endl;
		return false;
	}

	cout << "OK Testing == " << endl;
	return true;
}

bool testingLessThanOperator()
{
	cout << "Testing < " << endl;
	Candy candies[NR_OF_CANDIES];

	prepareCandyObjects(candies);
	if (candies[1] < candies[0]) 
	{
		cout << "NOT CORRECT 1: comparing < expected false" << endl;
		return false;
	}
	if (candies[0] < candies[3]) 
	{
		cout << "NOT CORRECT 2: comparing < expected false" << endl;
		return false;
	}
	if (!(candies[2] < candies[4]))
	{
		cout << "NOT CORRECT 3: comparing < expected true" << endl;
		return false;
	}
	cout << "OK: Testing < " << endl;
	return true;
}

int main()
{
	bool ok = true;
	ok = testingBasics();
	if (!ok)
	{
		cout << "NOT OK : testingBasics" << endl;
		return 1;
	}

	ok = testingEqualsOperator();
	if (!ok)
	{
		cout << "NOT OK : testingEqualsOperator" << endl;
		return 2;
	}
	
	ok = testingLessThanOperator();
	if (!ok)
	{
		cout << "NOT OK : testingLessThanOperator" << endl;
		return 3;
	}
	
	return 0;
}