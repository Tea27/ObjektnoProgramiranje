#pragma once
#include "Bird.hpp"

class Hawk : public Bird {
	int numberOfLegs;
	std::string type;

public:
	Hawk();
	int getLegNumber();
	std::string getType();
	~Hawk();
};