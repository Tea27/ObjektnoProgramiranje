#pragma once
#include "myPoint.hpp"

class Target {
public:
	Point lowerLeftFront;
	Point lowerRightFront;
	Point upperRightFront;
	Point upperLeftFront;

	Point lowerLeftBack;
	Point lowerRightBack;
	Point upperRightBack;
	Point upperLeftBack;

	bool isShot;

	void setTarget(const Point& lowerLeft,const Point& upperRight);
};

int randRange(int lowerBound, int upperBound);