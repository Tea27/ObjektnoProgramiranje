#include "Bedbug.hpp"
using namespace std;

Bedbug::Bedbug() {
	type = "Bedbug";
	numberOfLegs = 6;
}

int Bedbug::getLegNumber() {
	return numberOfLegs;
}

string Bedbug::getType() {
	return type;
}

Bedbug::~Bedbug() {
	numberOfLegs = 0;
	type = "";
}