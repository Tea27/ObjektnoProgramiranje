/*Napisati template funkciju za sortiranje niza. Napisati specijalizaciju
te funkcije za niz char-ova u kojoj nece biti razlike izmedu malih i velikih slova*/
#include <iostream>
#include <string>
using namespace std;

template<typename TYPE>
void sortArr(TYPE arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i] < arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

template<>
void sortArr<char>(char arr[], int n){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (tolower(arr[i]) < tolower(arr[j])) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main()
{
    int arrInt[] = { 17, 9, 12, 5, 22, 1 };
    char arrChar[] = { 'f', 'A', 's', 'a', 'w', 'b', 'h', 'B'};

    int nInt = sizeof arrInt / sizeof arrInt[0];
    int nChar = sizeof arrChar / sizeof arrChar[0];

    sortArr(arrInt, nInt);
    sortArr(arrChar, nChar);

    for (int i = 0; i < nInt; i++) {
        cout << arrInt[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < nChar; i++) {
        cout << arrChar[i] << " ";
    }
}