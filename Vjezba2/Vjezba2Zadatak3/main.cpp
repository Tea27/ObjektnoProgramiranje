#include "circleRectangleIntersect.h"
#include <iostream>

using namespace std;

int main()
{
	int n;
	int numOfIntersect = 0;

	circle myCircle{ 1 };

	cout << "Unesite radijus te koordinate centra kruznice C(x, y): " << endl;

	myCircle.newCircle();

	const rectangle* rectArr;
	rectangle myRect;

	cout << "Unesite zeljenu velicinu niza pravokutnika: ";
	cin >> n;

	while (n <= 0)
	{
		cout << "Unesena neispravna velicina! Molim ponovite unos: ";
		cin >> n;
	}

	rectArr = myRect.newRectangleArr(n);

	numOfIntersect = numberOfIntersections(myCircle, rectArr, n);

	delete[] rectArr;

	cout << endl << "Broj pravokutnika koji sijeku kruznicu: " << numOfIntersect;

}

