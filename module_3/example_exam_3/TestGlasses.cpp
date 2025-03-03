#include <iostream>
#include <string>
#include "Glasses.h"
#include "ReadingGlasses.h"
#include "SunGlasses.h"

using namespace std;

bool testingSubClasses()
{
	cout << "Test sub classes" << endl;
	{
		string make = "Milton";
		string color = "gul";
		SunGlasses sunGlass(make, 400, color);
	
		string descr = sunGlass.description();
		if (descr.find(make) == string::npos)
		{
			cout << "NOT CORRECT 1: expected " << make << " in description" << endl;
			return false;
		}

		if (descr.find(color) == string::npos)
		{
			cout << "NOT CORRECT 2: expected " << color << " in description" << endl;
			return false;
		}

		int finalPrice = sunGlass.calculateFinalPrice();
		if (finalPrice != 600)
		{
			cout << "NOT CORRECT 3: expected final price 600" << endl;
			return false;
		}
	}
	{
		string make = "Borg";
		float strength = 2.5;
		ReadingGlasses readGlass(make, 500, strength);

		string descr = readGlass.description();
		if (descr.find(make) == string::npos)
		{
			cout << "NOT CORRECT 4: expected " << make << " in description" << endl;
			return false;
		}

		if (descr.find(to_string(strength)) == string::npos)
		{
			cout << "NOT CORRECT 5: expected " << strength << " in description" << endl;
			return false;
		}

		int finalPrice = readGlass.calculateFinalPrice();
		if (finalPrice != 500)
		{
			cout << "NOT CORRECT 6: expected final price 500" << endl;
			return false;
		}
	}
	{
		string make = "Borg";
		float strength = 2.5;
		ReadingGlasses readGlass(make, 500, strength, "dubbelslipade");

		string descr = readGlass.description();
		if (descr.find(make) == string::npos)
		{
			cout << "NOT CORRECT 7: expected dubbelslipade in description" << endl;
			return false;
		}
	}
	cout << "OK Test sub classes" << endl;
	return true;
}



int main()
{

	bool ok = testingSubClasses();
	if (!ok)
	{
		cout << "TEST OF SUB CLASSES NOT OK" << endl;
		return 1;
	}


	return 0;
}