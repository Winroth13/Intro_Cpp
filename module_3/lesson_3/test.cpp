#include "Register.h"
#include <iostream>
#include <string>

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Register reg1 = Register();

	reg1.addParticipant("Hans", "Male", 20);
	reg1.addParticipant("Maja", "Female", "Homerunners", 4);

	std::cout << "Reg1: " + std::to_string(reg1.numParticipants()) + "\n";

	Register reg2(reg1);

	std::cout << "Copied to Reg2: " + std::to_string(reg2.numParticipants()) + "\n";

	reg1.addParticipant("Harry", "Male", 40);

	std::cout << "Added one to Reg 1.\n";

	std::cout << "Reg1: " + std::to_string(reg1.numParticipants()) + "\n";
	std::cout << "Reg2: " + std::to_string(reg2.numParticipants()) + "\n";

	reg1 = reg2;

	std::cout << "Reg1 = Reg2.\n";

	std::cout << "Reg1: " + std::to_string(reg1.numParticipants()) + "\n";
	std::cout << "Reg2: " + std::to_string(reg2.numParticipants()) + "\n";

	std::cout << "Find hans.\n";

	std::cout << reg1.getByName("Hans")->toString();
}