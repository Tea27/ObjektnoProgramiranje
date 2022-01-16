#include "Counter.hpp"
using namespace std;

Counter::Counter() {
	sumOfLegs = 0;
}

void Counter::printLegNumber() {
	cout << "Sum of animal legs: " << sumOfLegs << endl;
}

void Counter::count(vector<Animal*>& animal) {
	for (Animal* el : animal) {

		cout << "Animal added: " << el->getType() << endl;
		sumOfLegs += el->getLegNumber();
	}
	printLegNumber();
}