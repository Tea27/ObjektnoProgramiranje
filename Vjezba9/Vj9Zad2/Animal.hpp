#pragma once
#include <string>
#include <iostream>
class Animal {

public:
	virtual int getLegNumber() = 0;
	virtual std::string getType() = 0;
	virtual ~Animal() = 0;
};


