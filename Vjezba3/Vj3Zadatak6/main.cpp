/*Napišite funkciju koja stringove, koje korisnik unosi, sprema u vektor stingova,
svaki string preokrene te sortira vektor po preokrenutim stringovima*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void reverseSortStr(vector<string>& str) {
    string s1;
    int i = 0, n;
    cout << "Unesite rijeci\n";
    while (cin >> s1) {
        n = s1.size();
        for (int i = 0; i < n / 2; i++) {
            swap(s1[i], s1[n - i - 1]);
        }
        str.push_back(s1);
    }
    sort(str.begin(), str.end());
}

void printVector(vector<string> vect) {
    for (int i = 0; i < vect.size(); i++) {
        cout << vect[i] << " ";
    }
}

int main()
{
    vector<string> str;
    reverseSortStr(str);
    printVector(str);
}
