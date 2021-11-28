/*Napisati klasu za poziciju točke u prostoru koja ima tri double podatka: dužinu,
širinu i visinu (x, y, z koordinate). Klasa ima sljedeće funkcije:
◦ Funkciju za postavljanje vrijednosti članova (treba imati pretpostavljene vrijednosti 0).
◦ Funkciju za postavljanje pseudorandom vrijednosti članova (granice intervala
su parametri funkcije).
◦ Funkciju za dohvaćanje vrijednosti članova.
◦ Funkciju koja računa udaljenost do druge točke u 2D ravnini (zanemarujući z
koordinatu).
◦ Funkciju koja računa udaljenost do druge točke u 3D prostoru.
U main funkciji postavite vrijednost za dvije točke u prostoru i ispišite obe udaljenosti*/
#include <iostream>
#include <random>
#include "myPoint.hpp"

using namespace std;
int main()
{
    srand(time(NULL));
    Point first, second;
    double min, max, x1, y1, z1, x2, y2, z2;
    
    enterBoundsForRandom(min, max);
    first.setRandomCoordinates(min, max);
    first.getCoordinates(x1, y1, z1);

    cout << "Enter (x, y, z) for second point:" << endl;
    cout << "Enter x: ";
    cin >> x2;
    cout << "Enter y: ";
    cin >> y2;
    cout << "Enter z: ";
    cin >> z2;
    second.setCustomCoordinates(x2, y2, z2);
    
    double distance2D = first.pointDistance2D(x2, y2);
    double distance3D = first.pointDistance3D(second);

    cout << "2D Points distance: " << distance2D << endl;
    cout << "3D Points distance: " << distance3D << endl;
}


