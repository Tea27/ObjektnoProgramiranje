#include "Hawk.hpp"
using namespace std;
Hawk::Hawk() {
	type = "Hawk";
	numberOfLegs = 2;
}

int Hawk::getLegNumber() {
	return numberOfLegs;
}

string Hawk::getType() {
	return type;
}

Hawk::~Hawk() {
	numberOfLegs = 0;
	type = "";
}

