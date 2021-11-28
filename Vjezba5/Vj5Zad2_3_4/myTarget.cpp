#include "myPoint.hpp"
#include "myTarget.hpp"
#include <random>

void Target::setTarget(const Point& lowerLeft,const Point& upperRight) {
	double x1, y1, z1, x2, y2, z2;

	lowerLeft.getCoordinates(x1, y1, z1);
	lowerLeftFront.setCustomCoordinates(x1, y1, z1);

	upperRight.getCoordinates(x2, y2, z2);
	upperRightBack.setCustomCoordinates(x2, y2, z2);

	lowerRightFront.setCustomCoordinates(x2, x1, z1);
	upperRightFront.setCustomCoordinates(x2, y1, z2);
	upperLeftFront.setCustomCoordinates(x1, y1, z2);

	lowerLeftBack.setCustomCoordinates(x1, y2, z1);
	lowerRightBack.setCustomCoordinates(x2, y2, z1);
	upperLeftBack.setCustomCoordinates(x1, y2, z2);
}
