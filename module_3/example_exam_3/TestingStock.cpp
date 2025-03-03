#include <iostream>
#include <string>
#include "Stock.h"
#include "Glasses.h"
#include "SunGlasses.h"
#include "ReadingGlasses.h"

using namespace std;
bool testInitialContent()
{
	cout << "Test initial content" << endl;
	Stock aStock;

	if (aStock.totalStockValue() != 0)
	{
		cout << "NOT CORRECT 1: expected stock value 0 but got " << aStock.totalStockValue() << endl;
		return false;
	}

	if (aStock.nrOfReadingGlassesWithStrengthAbove(1.2f) != 0)
	{
		cout << "NOT CORRECT 2: expected 0 reading glasses but got " << aStock.nrOfReadingGlassesWithStrengthAbove(1.2f) << endl;
		return false;
	}

	if (aStock.nrOfSunGlasses("gul") != 0)
	{
		cout << "NOT CORRECT 3: expected 0 sun glasses but got " << aStock.nrOfSunGlasses("gul") << endl;
		return false;
	}
	cout << "OK: Test initial content" << endl;
	return true;
}

bool testAddingGlasses()
{
	cout << endl << "Test adding glasses" << endl;
	Stock aStock;

	if (!aStock.add("Borg", 1500))
	{
		cout << "NOT CORRECT 1: expected true but got false" << endl;
		return false;
	}

	aStock.add("Chanel", 1600, "lila");

	if (aStock.nrOfGlasses() != 2)
	{
		cout << "NOT CORRECT 2: expected 2 but got " << aStock.nrOfGlasses() << endl;
		return false;
	}

	if (aStock.nrOfSunGlasses("lila") != 1)
	{
		cout << "NOT CORRECT 3: expected 1 but got " << aStock.nrOfSunGlasses("lila") << endl;
		return false;
	}

	if (aStock.totalStockValue() != 3300)
	{
		cout << "NOT CORRECT 4: expected 3300 but got " << aStock.totalStockValue() << endl;
		return false;
	}

	if (!aStock.add("Viito", 400, 1.0f))
	{
		cout << "NOT CORRECT 5: expected true but got false" << endl;
		return false;
	}

	if (aStock.nrOfReadingGlassesWithStrengthAbove(0.5f) != 1)
	{
		cout << "NOT CORRECT 6: expected 1 but got " << aStock.nrOfReadingGlassesWithStrengthAbove(0.5f) << endl;
		return false;
	}
	aStock.add("Viito", 400, 3.0f);
	aStock.add("Borg", 600, "gul");
	aStock.add("Gogo", 900, 2.3f, "dubbelslipade");

	if (aStock.nrOfReadingGlassesWithStrengthAbove(0.5f) != 3)
	{
		cout << "NOT CORRECT 7: expected 3 but got " << aStock.nrOfReadingGlassesWithStrengthAbove(0.5f) << endl;
		return false;
	}

	if (aStock.nrOfReadingGlassesWithStrengthAbove(1.2f) != 2)
	{
		cout << "NOT CORRECT 8: expected 2 but got " << aStock.nrOfReadingGlassesWithStrengthAbove(1.2f) << endl;
		return false;
	}

	if (aStock.nrOfReadingGlassesWithStrengthAbove(4.0f) != 0)
	{
		cout << "NOT CORRECT 9: expected 3 but got " << aStock.nrOfReadingGlassesWithStrengthAbove(4.0f) << endl;
		return false;
	}
	if (!aStock.add("Viito", 400, 1.0f))
	{
		cout << "NOT CORRECT 10: expected true but got false" << endl;
		return false;
	}

	for (int i = 0; i < 13; i++)
	{
		if (!aStock.add("?", 0, 0.f, "dubbelslipade"))
		{
			cout << "NOT CORRECT 11: expected true but got false" << endl;
			return false;
		}
	}
	if (aStock.add("?", 0, 0.f, "gul"))
	{
		cout << "NOT CORRECT 12: expected false but got true" << endl;
		return false;
	}

	cout << "OK Test adding glasses" << endl << endl;
	return true;
}

bool testingCopyConstructor()
{
	cout << "Test copy constructor" << endl;
	{
		Stock aStock;
		Stock bStock = aStock;
		if (bStock.nrOfGlasses() != 0)
		{
			cout << "NOT CORRECT 1: expected 0 but got " << bStock.nrOfGlasses() << endl;
			return false;
		}
	}
	{
		Stock aStock;
		aStock.add("Viito", 400, 3.0f);
		aStock.add("Borg", 600, "gul");
		aStock.add("Gogo", 900, 2.3f, "dubbelslipade");
		Stock bStock = aStock;

		if (bStock.nrOfGlasses() != 3)
		{
			cout << "NOT CORRECT 3: expected 3 but got " << bStock.nrOfGlasses() << endl;
			return false;
		}
		if (bStock.nrOfSunGlasses("gul") != 1)
		{
			cout << "NOT CORRECT 4: expected 1 but got " << bStock.nrOfSunGlasses("gul") << endl;
			return false;
		}
		for (int i = 0; i < 3; i++)
			if (aStock.getAccessToGlassesAt(i) == bStock.getAccessToGlassesAt(i))
			{
				cout << "NOT CORRECT 5: expected different adresses but got same adress " << endl;
				return false;
			}
	}
	cout << "OK Test copy constructor" << endl << endl;
	return true;
}

bool testingAssignmentOperator()
{
	cout << "Test assignment operator" << endl;
	{
		Stock aStock;
		Stock bStock;

		bStock = aStock;
		if (bStock.nrOfGlasses() != 0)
		{
			cout << "NOT CORRECT 1: expected 0 but got " << bStock.nrOfGlasses() << endl;
			return false;
		}
	}
	{
		Stock aStock;
		aStock.add("Marko", 1000, "orange");
		aStock.add("Marko", 1000, "gul");
		Stock bStock;
		bStock = aStock;

		if (bStock.nrOfGlasses() != 2)
		{
			cout << "NOT CORRECT 2: expected 2 but got " << bStock.nrOfGlasses() << endl;
			return false;
		}
		if (bStock.nrOfSunGlasses("orange") != 1)
		{
			cout << "NOT CORRECT 3: expected 1 but got " << bStock.nrOfSunGlasses("orange") << endl;
			return false;
		}

		if (aStock.getAccessToGlassesAt(0) == bStock.getAccessToGlassesAt(0) ||
			aStock.getAccessToGlassesAt(0) == bStock.getAccessToGlassesAt(1) ||
			aStock.getAccessToGlassesAt(1) == bStock.getAccessToGlassesAt(0) ||
			aStock.getAccessToGlassesAt(1) == bStock.getAccessToGlassesAt(1))
		{
			cout << "NOT CORRECT 4: expected different adresses but got same adress " << endl;
			return false;
		}
	}
	{
		Stock aStock;
		aStock.add("Marko", 1000, "orange");
		aStock.add("Gogo", 900, 2.3f, "dubbelslipade");
		Stock bStock;

		aStock = bStock;

		if (aStock.nrOfGlasses() != 0)
		{
			cout << "NOT CORRECT 5: expected 0 but got " << aStock.nrOfGlasses() << endl;
			return false;
		}
		if (bStock.nrOfGlasses() != 0)
		{
			cout << "NOT CORRECT 6: expected 0 but got " << bStock.nrOfGlasses() << endl;
			return false;
		}
	}
	{
		Stock aStock;
		aStock.add("Marko", 1000, "orange");
		aStock.add("Gogo", 900, 2.3f, "dubbelslipade");
		Stock bStock;
		bStock.add("Viito", 400, 3.0f);
		bStock.add("Borg", 600, "gul");
		bStock.add("Gogo", 900, 1.7f);
		bStock.add("Marko", 1200, 0.5);

		aStock = bStock;

		if (aStock.nrOfGlasses() != 4)
		{
			cout << "NOT CORRECT 7: expected 4 but got " << bStock.nrOfGlasses() << endl;
			return false;
		}
		if (aStock.nrOfSunGlasses("gul") != 1)
		{
			cout << "NOT CORRECT 8: expected 1 but got " << bStock.nrOfSunGlasses("gul") << endl;
			return false;
		}

		if (aStock.getAccessToGlassesAt(1) == bStock.getAccessToGlassesAt(1) ||
			aStock.getAccessToGlassesAt(3) == bStock.getAccessToGlassesAt(3))
		{
			cout << "NOT CORRECT 9: expected different addresses but got same " << endl;
			return false;
		}
	}
	{
		Stock aStock;
		aStock.add("Viito", 400, 3.0f);
		aStock.add("Borg", 600, "gul");
		Glasses* beforePtr1 = aStock.getAccessToGlassesAt(0);
		Glasses* beforePtr2 = aStock.getAccessToGlassesAt(1);
		aStock = aStock;
		Glasses* afterPtr1 = aStock.getAccessToGlassesAt(0);
		Glasses* afterPtr2 = aStock.getAccessToGlassesAt(1);
		if (beforePtr1 != afterPtr1)
		{
			cout << "NOT CORRECT 10: expected same address to array but got different " << endl;
			return false;
		}
		if (beforePtr2 != afterPtr2)
		{
			cout << "NOT CORRECT 11: expected same address to array but got different " << endl;
			return false;
		}
	}

	cout << "OK Test assignment operator" << endl;
	return true;
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	if (!testInitialContent())
	{
		cout << "NOT OK TEST OF INITIAL CONTENT" << endl;
		return 1;
	}
	if (!testAddingGlasses())
	{
		cout << "NOT OK TEST OF ADDING PRODUCTS" << endl;
		return 2;
	}
	if (!testingCopyConstructor())
	{
		cout << "NOT OK TEST OF COPY CONSTRUCTOR" << endl;
		return 3;
	}
	if (!testingAssignmentOperator())
	{
		cout << "NOT OK TEST OF ASSIGNMENT OPERATOR" << endl;
		return 4;
	}
	return 0;
}