/*Koristeći funkcije iz prvog zadatka unijeti dva vektora i formirati novi vektor koji
se sastoji od elemenata iz prvog vektora koji nisu u drugom vektoru.*/

#include <iostream>
#include <vector>
#include "myVector.hpp"

using namespace std;

int main()
{
    int n1, n2, a, b;
    vector <int> vect1, vect2, myVect;

    cout << "Unesite velicinu niza:" << endl;
    cin >> n1;

    cout << "Unesite clanove niza:" << endl;
    vectorAndNumOfElements(vect1, n1);

    cout << "Unesite interval raspona brojeva za novi niz:" << endl;
    cin >> a;
    cin >> b;

    if (a > b) {
        a = a + b;
        b = a - b;
        a = a - b;
    }

    cout << "Unesite clanove niza:" << endl;
    vectorAndInterval(vect2, a, b);
    myVect = isInFirstNotInSecond(vect1, vect2);
    n2 = myVect.size();
    cout << "Clanovi prvog vektora koji nisu u drugom" << endl;
    printVector(myVect, n2);
}
