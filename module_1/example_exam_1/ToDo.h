#ifndef TO_DO_H
#define TO_DO_H
#include <string>
using namespace std;

void doubleUp(int& number);

void readStringsFromFile(string fileName, string strArr[], int numLines);

int nrOfValuesBiggerThan(int arr[], int nrOf, int compareNum = 0);

void lowestAndHighest(int arr[], int nrOf, int& indexOfLowest, int& indexOfHighest);

#endif
