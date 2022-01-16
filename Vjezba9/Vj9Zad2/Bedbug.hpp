#pragma once
#include "Insect.hpp"

class Bedbug : public Insect {
	int numberOfLegs;
	std::string type;

public:
	Bedbug();
	int getLegNumber();
	std::string getType();
	~Bedbug();
};
