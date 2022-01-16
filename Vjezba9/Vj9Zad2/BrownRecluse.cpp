#include "BrownRecluse.hpp"

using namespace std;

BrownRecluse::BrownRecluse() {
	type = "Brown Recluse";
	numberOfLegs = 8;
}

int BrownRecluse::getLegNumber() {
	return numberOfLegs;
}

string BrownRecluse::getType() {
	return type;
}

BrownRecluse::~BrownRecluse() {
	numberOfLegs = 0;
	type = "";
}