#include <iostream>
#include <random>
#include "myPoint.hpp"
using namespace std;
Point::Point() {
    x = 0;
    y = 0;
    z = 0;
}

void Point::setCustomCoordinates(const double x,const double y,const double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void Point::setRandomCoordinates(const double& lowerBound,const double& upperBound) {
    random_device random_device;
    mt19937 random_engine(random_device());
    uniform_real_distribution<double> unif(lowerBound, upperBound);

    x = unif(random_engine);
    y = unif(random_engine);
    z = unif(random_engine);
}

void Point::getCoordinates(double& x, double& y, double& z) const {
    x = this->x;
    y = this->y;
    z = this->z;
}

double Point::pointDistance2D(double x2, double y2) const {
    return sqrt(pow(x2 - x, 2) + pow(y2 - y, 2));
}

double Point::pointDistance3D(const Point& second) const{
    return sqrt(pow(x - second.x, 2.0) + pow(y - second.y, 2.0) + pow(z - second.z, 2.0));
}

void enterBoundsForRandom(double& a, double& b) {
    cout << "Enter the interval [lower-bound, upper-bound] in which you want to generate the point:" << endl << "enter lower-bound: ";
    cin >> a;
    cout << "enter upper-bound: ";
    cin >> b;

    if (a > b) {
        a += b;
        b = a - b;
        a -= b;
    }
}