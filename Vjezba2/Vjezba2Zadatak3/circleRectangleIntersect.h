#ifndef CIRCLE_RECTANGLE_INTERSECT
#define CIRCLE_RECTANGLE_INTERSECT

#include <cstddef>
#include <iostream>  

struct point {
	int x, y;
};

struct circle {
	int radius;
	point center;

	void newCircle()
	{
		std::cin >> radius;
		std::cin >> center.x;
		std::cin >> center.y;
	}

};
struct rectangle {
	point lowerLeft;
	point upperLeft;
	point lowerRight;
	point upperRight;

	rectangle* newRectangleArr(int n)
	{
		rectangle* rectArr = new rectangle[n];

		for (int i = 0; i < n; i++)
		{
			std::cout << "Unesite koordinate donje lijeve tocke A(x, y) pravokutnika(" << i + 1 << "):" << std::endl << "x: ";
			std::cin >> rectArr[i].lowerLeft.x;
			std::cout << "y: ";
			std::cin >> rectArr[i].lowerLeft.y;

			std::cout << "Unesite koordinate gornje desne tocke C(x, y) pravokutnika(" << i + 1 << "):" << std::endl << "x: ";
			std::cin >> rectArr[i].upperRight.x;
			std::cout << "y: ";
			std::cin >> rectArr[i].upperRight.y;

			rectArr[i].upperLeft.x = rectArr[i].lowerLeft.x;
			rectArr[i].upperLeft.y = rectArr[i].upperRight.y;

			rectArr[i].lowerRight.x = rectArr[i].upperRight.x;
			rectArr[i].lowerRight.y = rectArr[i].lowerLeft.y;
		}

		return rectArr;
	}
};

bool checkPoints(int xC, int yC, int r, int xyR1, int xyR2, int xyR)
{

	int x = 0;
	int y = 0;

	for (xyR1; xyR1 <= xyR2; xyR1++)
	{
		y = xyR - yC;
		x = xyR1 - xC;

		if ((x * x + y * y) == (r * r))
		{
			return true;
		}
	}
	return false;
}

int numberOfIntersections(const circle& myCircle, const rectangle* (&rectArr), int n)
{
	int numOfIntersect = 0;

	int xC = myCircle.center.x;
	int yC = myCircle.center.y;
	int rC = myCircle.radius;

	for (int i = 0; i < n; i++)
	{
		if (checkPoints(xC, yC, rC, rectArr[i].lowerLeft.x, rectArr[i].lowerRight.x, rectArr[i].lowerLeft.y))
		{
			numOfIntersect++;
		}
		if (checkPoints(xC, yC, rC, rectArr[i].upperLeft.x, rectArr[i].upperRight.x, rectArr[i].upperLeft.y))
		{
			numOfIntersect++;
		}
		if (checkPoints(xC, yC, rC, rectArr[i].lowerLeft.y, rectArr[i].upperLeft.y, rectArr[i].lowerLeft.x))
		{
			numOfIntersect++;
		}
		if (checkPoints(xC, yC, rC, rectArr[i].lowerRight.y, rectArr[i].upperRight.y, rectArr[i].lowerRight.x))
		{
			numOfIntersect++;
		}
	}

	return numOfIntersect;
}

#endif