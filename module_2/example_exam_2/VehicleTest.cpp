#include "Vehicle.h"
#include <iostream>
using namespace std;

// used for testing
const int NR_OF_VEHICLES = 4;
const string owners[NR_OF_VEHICLES]{ "Pia", "Lasse", "Kaj", "Pia"};
const string regPlates[NR_OF_VEHICLES]{ "AAA111", "BBB222", "CCC333", "CCC444"};
const int loadWeights[NR_OF_VEHICLES]{ 100, 400, 100, 300};

void prepareVehicleObjects(Vehicle vehicles[])
{
	for (int i = 0; i < NR_OF_VEHICLES; i++)
	{
		vehicles[i].setOwner(owners[i]);
		vehicles[i].setRegPlate(regPlates[i]);
		vehicles[i].setLoadWeight(loadWeights[i]);
	}
}

bool testingBasics()
{
	cout << "Testing basics" << endl;
	
	Vehicle bVehicle("ABC123","Lasse", 423);
	
	if (bVehicle.getRegPlate() != "ABC123")
	{
		cout << "NOT CORRECT 1: regPlate, expected ABC123 but got "<< bVehicle.getRegPlate() << endl;
		return false;
	}

	string vehicleString = bVehicle.description();
	if (vehicleString.find("Lasse") == string::npos)
	{
		cout << "NOT CORRECT 2: result from description(), expected Lasse as part of the string" << endl;
		return false;

	}
	if (vehicleString.find("423") == string::npos)
	{
		cout << "NOT CORRECT 3: result from description(), expected 423 as part of the string" << endl;
		return false;

	}

	Vehicle aVehicle;
	aVehicle.setOwner("Lisa");
	aVehicle.setRegPlate("QQQ444");
	aVehicle.setLoadWeight(500);
	if (aVehicle.getRegPlate() != "QQQ444")
	{
		cout << "NOT CORRECT 5: regPlate, expected QQQ444 but got, " << aVehicle.getRegPlate() << endl;
		return false;
	}

	vehicleString = aVehicle.description();
	if (vehicleString.find("Lisa") == string::npos)
	{
		cout << "NOT CORRECT 5: result from description(), expected Lisa as part of the string" << endl;
		return false;

	}
	if (vehicleString.find("500") == string::npos)
	{
		cout << "NOT CORRECT 6: result from description(), expected 500 as part of the string" << endl;
		return false;

	}
	aVehicle.setRegPlate("X1234"); // X1234 is not of length 6 
	vehicleString = aVehicle.description();
	if (vehicleString.find("X1234") != string::npos)
	{
		cout << "NOT CORRECT 7: result from description(), not expected X1234 as part of the string" << endl;
		return false;
	}


	cout << "OK: Testing basics" << endl;
	return true;
}

bool testingEqualsOperator()
{
	cout << endl << "Testing == " << endl;
	
	Vehicle vehicles[NR_OF_VEHICLES];
	Vehicle aVehicle("AAA111", "Pia", 100);

	prepareVehicleObjects(vehicles);
	if (!(vehicles[0] == aVehicle))
	{
		cout << "NOT CORRECT 1: comparing == when two identical objects, expected true" << endl;
		return false;
	}
	if (vehicles[0] == vehicles[3])
	{
		cout << "NOT CORRECT 2: comparing == when two different objects according to regPlate, expected false" << endl;
		return false;
	}
	if (vehicles[1] == vehicles[3])
	{
		cout << "NOT CORRECT 3: comparing == when two different objects according to owner and regPlate, expected false" << endl;
		return false;

	}
	cout << "OK Testing == " << endl;
	return true;
}

bool testingLessThanOperator()
{
	cout << endl << "Testing < " << endl;

	Vehicle vehicles[NR_OF_VEHICLES];

	prepareVehicleObjects(vehicles);

	if (! (vehicles[0] < vehicles[1]))
	{
		cout << "NOT CORRECT 1: expected vehicles[0] < vehicles[1] to be true" << endl;
		return false;
	}
	if (vehicles[3] < vehicles[0])
	{
		cout << "NOT CORRECT 2: expected vehicles[3] < vehicles[0] to be false" << endl;
		return false;
	}
	if (vehicles[0] < vehicles[2])
	{
		cout << "NOT CORRECT 3: expected vehicles[0] < vehicles[2] to be false" << endl;
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