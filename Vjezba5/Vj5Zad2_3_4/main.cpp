#include <iostream>
#include <random>
#include "myTarget.hpp"
#include "myWeapon.hpp"

#define LOW 1
#define HIGH 20

using namespace std;

int main()
{
	srand(time(NULL));
	double wX, wY, wZ;
	Point firstRandom, secondRandom;
	int numOfTargets, weaponCapacity, min1, max1;

	cout << "Enter the number of targets you want to shoot" << endl;
	cin >> numOfTargets;

	Target* targetArray = new Target[numOfTargets];
	double x1, y1, z1, x2, y2, z2;
	for (int i = 0; i < numOfTargets; i++) {
		firstRandom.setRandomCoordinates(LOW, HIGH);
		secondRandom.setRandomCoordinates(LOW, HIGH);

		firstRandom.getCoordinates(x1, y1, z1);
		secondRandom.getCoordinates(x2, y2, z2);

		if (z2 < z1) {
			swap(z1, z2);
			firstRandom.setCustomCoordinates(x1, y1, z1);
			secondRandom.setCustomCoordinates(x2, y2, z2);
		}

		targetArray[i].setTarget(firstRandom, secondRandom);
	}

	weaponCapacity = randRange(LOW, HIGH);
	Weapon myWeapon(weaponCapacity);
	cout << "You have " << weaponCapacity << " bullets" << endl;

	myWeapon.position.setRandomCoordinates(LOW, HIGH);
	myWeapon.position.getCoordinates(wX, wY, wZ);
	for (int i = 0; i < numOfTargets; i++) {
		myWeapon.fireMyWeapon();

		if (!myWeapon.bulletsNumInMagazine) {
			break;
		}
	
		if (wZ > z1 && wZ < z2) {
			targetArray[i].isShot = true;
			cout << "Target number " << i + 1 << " has been shot" << endl << endl;
		}
		else {
			targetArray[i].isShot = false;
			cout << "You miss" << endl << endl;
		}
	}

	delete [] targetArray;
}
