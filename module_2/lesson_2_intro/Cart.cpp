#include "Cart.h"

Cart::Cart(int cartId, std::string name)
	: cartId(cartId), name(name) {
	this->nrOf = 0;
}

void Cart::AddWallPaper(const std::string pattern, const int price, const int nrOfRolls) {
	wallPaperArr[nrOf] = WallPaper(pattern, price, nrOfRolls);
	nrOf++;
}

int Cart::TotalOrderCost() const {
	int cost = 0;

	for (int i = 0; i < this->nrOf; ++i) {
		cost += this->wallPaperArr[i].GetPrice() * this->wallPaperArr[i].GetNrOfRolls();
	}

	return cost;
}

std::string Cart::ToString() const {
	std::string output = "ID: " + std::to_string(this->cartId) + " Name: " + this->name + "\n";

	for (int i = 0; i < this->nrOf; ++i) {
		output += "Pattern: " + this->wallPaperArr[i].GetPattern() + " Price: " + std::to_string(this->wallPaperArr[i].GetPrice()) + " Quantity: " + std::to_string(this->wallPaperArr[i].GetNrOfRolls()) + "\n";
	}

	output += "Total: " + std::to_string(this->TotalOrderCost()) + "\n";

	return output;
}

bool Cart::RemoveWallPaper(const std::string pattern, const int price) {
	for (int i = 0; i < this->nrOf; ++i) {
		if (wallPaperArr[i].GetPattern() == pattern && wallPaperArr[i].GetPrice() == price) {
			for (int y = i; y < this->nrOf - 1; ++y) {
				wallPaperArr[y] = wallPaperArr[y + 1];
			}

			wallPaperArr[nrOf - 1] = WallPaper();

			nrOf--;

			return 1;
		}
	}

	return 0;
}