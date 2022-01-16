#pragma once
#include "Spider.hpp"

class BrownRecluse : public Spider {
	int numberOfLegs;
	std::string type;

public:
	BrownRecluse();
	int getLegNumber();
	std::string getType();
	~BrownRecluse();
};