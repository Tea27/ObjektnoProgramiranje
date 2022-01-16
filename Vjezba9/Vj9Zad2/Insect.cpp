#include "Insect.hpp"
using namespace std;

int Insect::getLegNumber() {
	return numberOfLegs;
}
string Insect::getType() {
	return type;
}
Insect::~Insect() {
	numberOfLegs = 0;
	type = "";
}