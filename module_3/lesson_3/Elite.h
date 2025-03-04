#ifndef ELITE_H
#define ELITE_H
#include "Participant.h"
#include <string>

class Elite : public Participant {
private:
	std::string club;
	int yearsAsElite;
public:
	Elite(const std::string name, const std::string gender, const std::string club, const int yearsAsElite);
	void setClub(const std::string club);
	void setYearsAsElite(const int yearsAsElite);
	std::string getClub() const;
	int getYearsAsElite() const;
	bool contains(const std::string str) const override;
	std::string toString() const override;
};

#endif