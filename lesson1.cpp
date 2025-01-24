#include <iostream>

struct Icecream {
	std::string name;
	int grade;
};

Icecream* InputIce(Icecream* iceArray, int numIce) {
	std::cout << "\nInput the names of the " << numIce << " ice creams:\n";

	for (int i = 0; i < numIce; i++) {
		std::string name;

		std::cin >> name;
		iceArray[i] = { name, 0 };
	}

	return iceArray;
}

void AvgIceGrade(Icecream* iceArray, int numIce, int numGrading) {
	for (int i = 0; i < numIce; i++) {
		int totGrade = iceArray[i].grade;
		int avgGrade = totGrade / numGrading;
		iceArray[i].grade = avgGrade;
	}
}

int GradeIce(Icecream* iceArray, int numIce) {
	int numGrading = 0;
	char moreGrading;

	do {
		numGrading += 1;

		std::cout << "\nGrade the icecreams (1-5):\n";
		for (int i = 0; i < numIce; i++) {
			int grade;

			std::cout << iceArray[i].name << ": ";
			std::cin >> grade;
			iceArray[i].grade += grade;
		}

		std::cout << "\nMore gradings (y/n)? ";
		std::cin >> moreGrading;
	} while (moreGrading == 'y');

	return numGrading;
}

void PrintGrades(Icecream* iceArray, int numIce) {
	std::cout << "The average score for each ice cream is:\n";
	for (int i = 0; i < numIce; i++) {
		Icecream icecream = iceArray[i];
		std::cout << icecream.name << ": " << icecream.grade << "\n";
	}
}

Icecream GetTopIce(Icecream* iceArray, int numIce) {
	Icecream topIce;

	for (int i = 0; i < numIce; i++) {
		Icecream icecream = iceArray[i];

		if (!i) {
			topIce = iceArray[i];
		}
		else if (topIce.grade < icecream.grade) {
			topIce = icecream;
		}
	}

	return topIce;
}

Icecream GetBottomIce(Icecream* iceArray, int numIce) {
	Icecream bottomIce;

	for (int i = 0; i < numIce; i++) {
		Icecream icecream = iceArray[i];

		if (!i) {
			bottomIce = iceArray[i];
		}
		else if (bottomIce.grade > icecream.grade) {
			bottomIce = icecream;
		}
	}

	return bottomIce;
}

bool HasIce(Icecream* iceArray, int numIce, std::string iceName) {
	bool hasIce = false;

	for (int i = 0; i < numIce; i++) {
		if (iceArray[i].name == iceName) {
			hasIce = true;
		}
	}

	return hasIce;
}

int main() {
	int numIce;

	std::cout << "How many Icecreams will you judge? ";
	std::cin >> numIce;

	Icecream* iceArray = new Icecream[numIce];

	InputIce(iceArray, numIce);

	int numGrading = GradeIce(iceArray, numIce);

	AvgIceGrade(iceArray, numIce, numGrading);

	std::cout << "\nThe number of gradings is " << numGrading << ".\n";

	PrintGrades(iceArray, numIce);

	Icecream topIce = GetTopIce(iceArray, numIce);

	Icecream bottomIce = GetBottomIce(iceArray, numIce);

	std::cout << "\nThe ice cream with highest grade is " << topIce.name << ".\n";
	std::cout << "The ice cream with lowest grade is " << bottomIce.name << ".\n";

	std::string favIce;

	std::cout << "\nInput the name of your favorite ice cream: ";
	std::cin >> favIce;

	bool hasFavIce = HasIce(iceArray, numIce, favIce);

	if (hasFavIce) {
		std::cout << favIce << " has been graded.";
	}
	else {
		std::cout << "Sorry, " << favIce << " has not been graded.";
	}

	delete[] iceArray;

	return 0;
}