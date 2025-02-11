#include "CandyStore.h"
#include "Candy.h"
#include <iostream>
using namespace std; 

// used for testing
const int NR_OF = 3;
const string candyNames[NR_OF]{ "Mars", "Ahlgrens bilar", "Plopp" };
const float candyPrices[NR_OF]{ 15.5f, 23.5f, 17.f };

void prepareCandyStoreObject(CandyStore& candyStore)
{
	for (int i = 0; i < NR_OF; i++)
	{
		candyStore.addCandy(candyNames[i], candyPrices[i]);
	}
}

bool testingBasics()
{
	cout << "Testing basics" << endl;
	CandyStore aStore("Best store");

	if (aStore.getStoreName() != "Best store")
	{
		cout << "NOT CORRECT 1: Store name is not correct, expected Best store" << endl;
		return false;
	}
	if (aStore.getCurrentNrOfCandies() != 0)
	{
		cout << "NOT CORRECT 2: Amount of candies, expected 0" << endl;
		return false;
	}
	cout << "OK: Testing basics" << endl;
	return true;
}

bool testingAddCandy()
{
	cout<<"Testing add candy"<<endl;
	CandyStore aStore;

	prepareCandyStoreObject(aStore);
	
	if (aStore.getCurrentNrOfCandies() != NR_OF)
	{
		cout << "NOT CORRECT 1: Amount of candies, expected 3" << endl;
		return false;
	}
	for (int i = 0; i < aStore.getCurrentNrOfCandies(); i++)
	{
		if (aStore.candyAt(i)->getName() != candyNames[i])
		{
			cout << "NOT CORRECT 2: Not correct name returned " << endl;
			return false;
		}
	}

	for (int i = 0; i < 7; i++)
	{
		if (!aStore.addCandy("??", 66.6f))
		{
			cout << "NOT CORRECT 3: Expected true when adding up to 10 candies" << endl;
			return false;
		}
	}
	if (aStore.addCandy("no candy", 77.7f))
	{
		cout << "NOT CORRECT 4: Expected false when trying to add 11:th candy" << endl;
		return false;
	}
	if (!aStore.addCandy("no candy", 77.7f) && aStore.getCurrentNrOfCandies() != 10)
	{
		cout << "NOT CORRECT 5: When trying to add 11:th candy, expected nr of candies 10" << endl;
		return false;
	}

	cout << "OK: Testing add Candy" << endl;
	return true;
}


bool testingRemoveCandy()
{
	cout << "Testing remove Candy" << endl;
	{
		// creating a new CandyStore-object
		CandyStore aStore;

		prepareCandyStoreObject(aStore);
		int nrOf = aStore.getCurrentNrOfCandies();

		bool ok = aStore.removeCandy(candyNames[0], candyPrices[0]);
		if (!ok)
		{
			cout << "NOT CORRECT 1: When removing Candy at index 0, expecting return true" << endl;
			return false;
		}
		if (ok && aStore.getCurrentNrOfCandies() != nrOf - 1)
		{
			cout << "NOT CORRECT 2: When removing Candy at index 0, expecting nr of candies 2"<< endl;
			return false;
		}
	}
	{
		// creating a new CandyStore-object
		CandyStore aStore;
		
		prepareCandyStoreObject(aStore);
		
		int nrOf = aStore.getCurrentNrOfCandies();
		bool ok = aStore.removeCandy(candyNames[NR_OF - 1], candyPrices[NR_OF - 1]);
		if (!ok)
		{
			cout << "NOT CORRECT 3: When removing Candy at last index, expecting return true" << endl;
			return false;
		}
		if (ok && aStore.getCurrentNrOfCandies() != nrOf - 1)
		{
			cout << "NOT CORRECT 4: When removing Candy at last index, expecting nr of candies 2" << endl;
			return false;
		}
	}

	{
		// creating a new CandyStore-object
		CandyStore aStore;

		prepareCandyStoreObject(aStore);
		int nrOf = aStore.getCurrentNrOfCandies();
		bool ok = aStore.removeCandy(candyNames[1], candyPrices[1]);
		if (!ok)
		{
			cout << "NOT CORRECT 5: When removing Candy in middle, expecting return true" << endl;
			return false;
		}
		if (ok && aStore.getCurrentNrOfCandies() != nrOf - 1)
		{
			cout << "NOT CORRECT 6: When removing Candy at last index, expecting nr of candies 2" << endl;
			return false;
		}
	}

	{
		// creating a new CandyStore-object
		CandyStore aStore;

		aStore.addCandy("Plopp", 15.f);
		bool ok = aStore.removeCandy("Plopp", 15.f);
		if (!ok)
		{
			cout << "NOT CORRECT 7: When removing the last Candy in the Candy store, expecting return true" << endl;
			return false;
		}
		if (ok && aStore.getCurrentNrOfCandies() != 0)
		{
			cout << "NOT CORRECT 8: When removing the last Candy in the Candy store, expecting nr of candies 0" << endl;
			return false;
		}
	}

	cout << "OK: Testing remove Candy" << endl;
	return true;
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	bool ok = true;
	ok = testingBasics();
	if (!ok)
	{
		cout << "NOT OK : testingBasics" << endl;
		return 1;
	}

	ok = testingAddCandy();
	if (!ok)
	{
		cout << "NOT OK : testingAddCandy" << endl;
		return 2;
	}
	
	ok = testingRemoveCandy();
	if (!ok)
	{
		cout << "NOT OK : testingRemoveCandy" << endl;
		return 3;
	}
	
	return 0;
}