#pragma once
#include "Animal.hpp"
#include <vector>
#include <string>
#include <iostream>


class Counter {
private:
	int sumOfLegs;
public:
	Counter();
	void printLegNumber();
	void count(std::vector<Animal*>& animal);
};
