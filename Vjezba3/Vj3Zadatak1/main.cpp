/*Napisati funkcije za unos i ispis vektora brojeva. Prototipove funkcija staviti u
.hpp datoteke, a implementaciju u .cpp datoteke.
Za unos vektora napisati dvije funkcije:
• funkcija čiji su parametri referenca na vektor i broj elemenata vektora,
• funkcija čiji su parametri referenca na vektor i granice intervala u kojem
trebaju biti elementi vektora. Elementi vektora se unose u funkciji, sve dok
se ne unese broj koji nije u danom intervalu.*/

#include <iostream>
#include <vector>
#include "myVector.hpp"
using namespace std;

int main()
{
    int n1, n2, a, b;
    vector <int> vect1, vect2;

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
    
    n2 = vect2.size();

    cout << "Prvi niz: ";
    printVector(vect1, n1);
    cout << endl << "Drugi niz: ";
    printVector(vect2, n2);

}

