#include <ctime>
#include <random>
#include <iostream>
#include "ToDo.h"

using namespace std;

bool testDoubleUp()
{
	cout << "Start test of function doubleUp:\n";
	int number = 10;
	doubleUp(number);
	if (number != 20)
	{
		cout << "Not Correct (1): Expected 20, but got " << number << endl;
		return false;
	}
	number = -55;
	doubleUp(number);
	if (number != -110)
	{
		cout << "Not Correct (2): Expected -110, but got " << number << endl;
		return false;
	}
	cout << "End test of function doubleUp:\n";
	return true;
}

bool testReadStringsFromFile()
{
	cout << "Start test of function readStringsFromFile:\n";
	string strArray[10];
	readStringsFromFile("example1.txt", strArray, 4);
	for (int i = 0; i < 4; i++)
	{
		if (strArray[i] != "line" + to_string(i+1))
		{
			cout << "Not Correct (3): Expected line" + to_string(i+1) + " but got " + strArray[i] << endl;
			return false;
		}
	}
	readStringsFromFile("example2.txt", strArray, 10);
	
	if (strArray[2] != "yellow flower")
	{
		cout << "Not Correct (4): Expected yellow flower but got " + strArray[2] << endl;
		return false;
	}
	if (strArray[5] != "elephant")
	{
		cout << "Not Correct (5): Expected elephant but got " + strArray[5] << endl;
		return false;
	}
	if (strArray[9] != "all my friends")
	{
		cout << "Not Correct (5): Expected all my friends but got " + strArray[9] << endl;
		return false;
	}
	
	cout << "End test of function readStringsFromFile:\n";
	return true;
}

bool testNrOfValuesBiggerThan()
{
	cout << "Start test of function nrOfValuesBiggerThan:\n";
	int arr[] = { 45, 77, 812, 34, -12, -66, 54, 0};
	int result = nrOfValuesBiggerThan(arr, 8, 70);
	if (result != 2)
	{
		cout << "Not Correct (6): Expected 2, but got " + to_string(result) << endl;
		return false;
	}
	result = nrOfValuesBiggerThan(arr, 8, -900);
	if (result != 8)
	{
		cout << "Not Correct (7): Expected 8, but got " + to_string(result) << endl;
		return false;
	}
	result = nrOfValuesBiggerThan(arr, 10);
	if (result != 5)
	{
		cout << "Not Correct (8): Expected 5, but got " + to_string(result) << endl;
		return false;
	}
	result = nrOfValuesBiggerThan(arr, 10, 900);
	if (result != 0)
	{
		cout << "Not Correct (9): Expected 0, but got " + to_string(result) << endl;
		return false;
	}
	
	cout << "End test of function nrOfValuesBiggerThan:\n";
	return true;
}

bool testLowestAndHighest()
{
	cout << "Start test of function lowestAndHighest:\n";
	int numbers[9]{ 55, 33, 11, 66, 88, 99, 22, 77, 44 };
	int lowestIndex = 0;
	int highestIndex = 0;
	lowestAndHighest(numbers, 9, lowestIndex, highestIndex);
	if (lowestIndex != 2)
	{
		cout << "Not Correct (11): Expected lowestIndex to be 2 but got "<< lowestIndex << endl;
		return false;
	}
	if (highestIndex != 5)
	{
		cout << "Not Correct (12): Expected highestIndex to be 5 but got " << highestIndex << endl;
		return false;
	}
	int nrs[6]{ 88, -66, 77, 33, -55, 8 };
	lowestAndHighest(nrs, 6, lowestIndex, highestIndex);
	if (lowestIndex != 1)
	{
		cout << "Not Correct (13): Expected lowestIndex to be 1 but got " << lowestIndex << endl;
		return false;
	}
	if (highestIndex != 0)
	{
		cout << "Not Correct (14): Expected highestIndex to be 0 but got " << highestIndex << endl;
		return false;
	}
	int nums[4] = { 33, 33, 33, 33 };
	lowestAndHighest(nums, 4, lowestIndex, highestIndex);
	if (lowestIndex != 0)
	{
		cout << "Not Correct (15): Expected lowestIndex to be 0 but got " << lowestIndex << endl;
		return false;
	}
	if (highestIndex != 0)
	{
		cout << "Not Correct (16): Expected highestIndex to be 0 but got " << highestIndex << endl;
		return false;
	}
	cout << "End test of function lowestAndHigest:\n";
	return true;
}
int main()
{	
	if (!testDoubleUp())
	{
		cout << endl <<"Test of function doubleUp did NOT pass"<<endl;
		return 1;
	}
	cout << "\n";
	if (!testReadStringsFromFile())
	{
		cout << endl <<"Test of function readStringsFromFile did NOT pass"<<endl;
		return 2;
	}
	cout << "\n";
	if (!testNrOfValuesBiggerThan())
	{
		cout << endl <<"Test of function nrOfValuesBiggerThan did NOT pass"<<endl;
		return 3;
	}
	cout << "\n";
	if (!testLowestAndHighest())
	{
		cout << endl << "Test of function remove did NOT pass" << endl;
		return 4;
	}
	cout << endl << "All test passed! Well done!\nIt's time for a teacher to check your solution" << endl;
	return 0;
}


