#ifndef EGGPACKAGE_H
#define EGGPACKAGE_H
#include "Product.h"
#include <string>

class EggPackage : public Product {
private:
	std::string eggSize;
	int numEggs;
public:
	EggPackage(const std::string articleNum = "", const int price = 0, const std::string eggSize = "", const int numEggs = 0);
	void SetEggEize(const std::string eggSize);
	void SetNumEggs(const int numEggs);
	std::string GetEggSize() const;
	int GetNumEggs() const;
	std::string Description() const override;
};

#endif