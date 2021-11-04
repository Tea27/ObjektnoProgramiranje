/*Napisati funkciju u za uklanjanje elementa iz vektora sa što manje operacija. Poredak elemenata u vektoru nije bitan.*/
#include <iostream>
#include <vector>
#include "headerForVector.hpp"

using namespace std;

int main()
{
    int n, i;
    vector<int> myVector;

    cout << "Unesite broj elemenata u vektoru: ";
    cin >> n;

    cout << "Unesite elemente u vektor:" << endl;
    pushInElements(myVector, n);

    cout << "Unesite indeks element koji zelite ukloniti iz vektora: ";
    cin >> i;

    removeElement(myVector, i);

    cout << "Trenutni vektor sadrzi elemente:" << endl;
    printVector(myVector);
}
