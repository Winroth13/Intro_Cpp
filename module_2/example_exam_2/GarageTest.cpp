#include "Garage.h"
#include "Vehicle.h"
#include <iostream>
using namespace std; 

// used for testing
const int NR_OF_VEHICLES = 5;
const string regPlates[NR_OF_VEHICLES]{ "AAA111", "BBB222", "CCC333", "CCC444" , "DDD555"};
const string owners[NR_OF_VEHICLES]{ "Pia", "Lasse", "Kaj", "Sven", "Rune" };
const int loadWeights[NR_OF_VEHICLES]{ 100, 400, 200, 500, 300};
void prepareGarageObject(Garage& garage)
{
	for (int i = 0; i < NR_OF_VEHICLES; i++)
	{
		garage.addVehicleAt(regPlates[i], owners[i], loadWeights[i], i);
	}
}

bool testingBasics()
{
	cout << "Testing basics" << endl;
	Garage aGarage("Garage group 1");

	if (aGarage.getName() != "Garage group 1")
	{
		cout << "NOT CORRECT 1: Name of group is not correct, expected Garage group 1" << endl;
		return false;
	}
	if (aGarage.getCurrentNrOfVehicles() != 0)
	{
		cout << "NOT CORRECT 2: Amount of vehicles, expected 0" << endl;
		return false;
	}
	cout << "OK: Testing basics" << endl;
	return true;
}

bool testingAddVehicle()
{
	cout << endl << "Testing add vehicle" << endl;
	Garage aGarage;

	prepareGarageObject(aGarage);
	
	if (aGarage.getCurrentNrOfVehicles() != NR_OF_VEHICLES)
	{
		cout << "NOT CORRECT 1: Amount of vehicles, expected 5" << endl;
		return false;
	}
	for (int i = 0; i < aGarage.getCurrentNrOfVehicles(); i++)
		{
			if (aGarage.vehicleAt(i)->getRegPlate() != regPlates[i])
			{
				cout << "NOT CORRECT 2: Not correct regPlate returned" << endl;
				return false;
			}
	} 

	if (aGarage.addVehicleAt("wer112", "??", 100,2))
	{
		cout << "NOT CORRECT 3: Expected false when adding at index that is occupied" << endl;
		return false;
	}
	if (!aGarage.addVehicleAt("wer112", "??", 100, 2) && aGarage.getCurrentNrOfVehicles() < NR_OF_VEHICLES)
	{
		cout << "NOT CORRECT 4: Expected "<<NR_OF_VEHICLES<<" vehicles" << endl;
		return false;
	}

	if (!aGarage.addVehicleAt("UTR543", "wer112", 100, 9))
	{
		cout << "NOT CORRECT 5: Expected true when adding at index that is free" << endl;
		return false;
	}

	if (aGarage.addVehicleAt("UTR543", "wer112", 100, 9) && aGarage.getCurrentNrOfVehicles() != NR_OF_VEHICLES + 1)
	{
		cout << "NOT CORRECT 5: Expected " << NR_OF_VEHICLES + 1 << " vehicles" << endl;
		return false;
	}
	cout << "OK: Testing add Vehicle" << endl;
	return true;
}

bool testingFindVehicle()
{
	cout << endl << "Testing find Vehicle" << endl;
	Garage aGarage;

	prepareGarageObject(aGarage);

	if (aGarage.findVehicle(regPlates[2]) != 2)
	{
		cout << "NOT CORRECT 1: When searching for a vehicle that is in garage, expecting return 2 but got "<< aGarage.findVehicle(regPlates[2]) << endl;
		return false;
	}
	if (aGarage.findVehicle(regPlates[4]) != 4)
	{
		cout << "NOT CORRECT 2: When searching for a vehicle that is in garage, expecting return 4 but got "<< aGarage.findVehicle(regPlates[4]) << endl;
		return false;
	}
	if (aGarage.findVehicle("ACS342") != -1)
	{
		cout << "NOT CORRECT 3: When searching for a vehicle that is not in garage, expecting return -1 but got "<< aGarage.findVehicle(regPlates[2]) << endl;
		return false;
	}

	cout << "OK: Testing find Vehicle" << endl;
	return true;
}

bool testingRemoveVehicle()
{
	cout << endl << "Testing remove Vehicle" << endl;
	{
		Garage aGarage;

		prepareGarageObject(aGarage);
		int nrOf = aGarage.getCurrentNrOfVehicles();

		bool ok = aGarage.removeVehicleAt(0);
		if (!ok)
		{
			cout << "NOT CORRECT 1: When removing vehicle, expecting return true" << endl;
			return false;
		}
		if (ok && aGarage.getCurrentNrOfVehicles() != nrOf - 1)
		{
			cout << "NOT CORRECT 2: When removing vehicle, expecting "<< nrOf - 1<< " vehicles " << endl;
			return false;
		}
		if (aGarage.vehicleAt(0) != nullptr)
		{
			cout << "NOT CORRECT 3: When removing vehicle, expecting nullptr at removed index" << endl;
			return false;
		}
	}
	{
		Garage aGarage;
		prepareGarageObject(aGarage);
		int nrOf = aGarage.getCurrentNrOfVehicles();
		bool ok = aGarage.removeVehicleAt(6);
		if (ok)
		{
			cout << "NOT CORRECT 4: When removing vehicle , expecting return false" << endl;
			return false;
		}
		if (ok && aGarage.getCurrentNrOfVehicles() != nrOf)
		{
			cout << "NOT CORRECT 5: When removing vehicle, expecting "<<nrOf<<" vehicles" << endl;
			return false;
		}
	}
	{
		Garage aGarage;
		prepareGarageObject(aGarage);
		int nrOf = aGarage.getCurrentNrOfVehicles();
		bool ok = true;
		for (int i = 0; i < nrOf; i++)
		{
			ok = ok && aGarage.removeVehicleAt(i);
		}
		if (!ok)
		{
			cout << "NOT CORRECT 6: When removing all vehicles , expecting return true" << endl;
			return false;
		}
		if (ok && aGarage.getCurrentNrOfVehicles() != 0)
		{
			cout << "NOT CORRECT 7: When removing all vehicles, expecting 0 vehicles" << endl;
			return false;
		}
	}
	
	cout << "OK: Testing remove vehicle" << endl;
	return true;
}

bool testingMixOfAddAndRemoveVehicles()
{
	cout << endl << "Testing mix of add and remove vehicles" << endl;
	Garage aGarage;

	prepareGarageObject(aGarage);
	bool ok = aGarage.removeVehicleAt(0);
	ok = ok && aGarage.removeVehicleAt(3);
		
	ok = ok && aGarage.addVehicleAt(regPlates[0], owners[0], loadWeights[0], 3);
	if (!ok)
	{
		cout << "NOT CORRECT 1: When removing and adding at previous removed index, expecting return true" << endl;
		return false;
	}
	if (ok && aGarage.getCurrentNrOfVehicles() != NR_OF_VEHICLES -1 )
	{
		cout << "NOT CORRECT 2: When removing and adding at previous removed index, expecting "<<NR_OF_VEHICLES-1<<" vehicles" << endl;
		return false;
	}
	
	cout << "OK: Testing mix of add and remove vehicles" << endl;
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

	ok = testingAddVehicle();
	if (!ok)
	{
		cout << "NOT OK : testingAddVehicle" << endl;
		return 2;
	}
	ok = testingFindVehicle();
	if (!ok)
	{
		cout << "NOT OK : testingFindVehicle" << endl;
		return 3;
	}
	
	ok = testingRemoveVehicle();
	if (!ok)
	{
		cout << "NOT OK : testingRemoveVehicle" << endl;
		return 4;
	}
	
	ok = testingMixOfAddAndRemoveVehicles();
	if (!ok)
	{
		cout << "NOT OK : testingMixOfAddAndRemoveVehicles" << endl;
		return 5;
	}
	return 0;
}