#pragma once

class Point{

    double x, y, z;

public:
    Point();
    ~Point() {}
    void setCustomCoordinates(const double x,const double y,const double z);
    void setRandomCoordinates(const double& lowerBound, const double& upperBound);
    void getCoordinates(double& x, double& y, double& z) const;
    double pointDistance2D(double x2, double y2) const;
    double pointDistance3D(const Point& second) const;
};

void enterBoundsForRandom(double& a, double& b);