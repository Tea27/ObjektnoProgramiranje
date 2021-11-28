#pragma once
#include "myPoint.hpp"

class Weapon {
public:
    Point position;
    unsigned char bulletMagazineCapacity;
    unsigned char bulletsNumInMagazine;

    Weapon(const int bulletMagazineCapacity) {
        this->bulletMagazineCapacity = bulletMagazineCapacity;
        this->bulletsNumInMagazine = bulletMagazineCapacity;
    }

    ~Weapon(){}

    void fireMyWeapon() {
        --bulletsNumInMagazine;
    }

    void reloadMyWeapon() {
        bulletsNumInMagazine = bulletMagazineCapacity;
    }
};

int randRange(int lowerBound, int upperBound)
{
    return rand() % (upperBound - lowerBound) + lowerBound;
}