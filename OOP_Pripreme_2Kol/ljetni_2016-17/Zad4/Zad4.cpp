/*Napišite program koji iz datoteke ucitava nenegativne cijele brojeve. Tada se, koristeci standardne
algoritme, ispišu broj dvoznamenkastih brojeva i prvi od njih ako postoji.*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vec;
	int num;
	ifstream file("brojevi.txt");
	if (!file.is_open()) {
		cout << "greska";
		return 1;
	}
	while (file >> num) {
		vec.push_back(num);
	}


	int twoDigitNum = count_if(vec.begin(), vec.end(), [](int i) { return (i > 9 && i < 100); });
	cout << "Broj dvoznamenkastih brojeva: " << twoDigitNum << endl;

	vector <int>::iterator it;
	it = find_if(vec.begin(), vec.end(), [](int i) { return (i > 9 && i < 100);});
	cout << "prvi dvoznamenkasti: " <<  *it << endl;
}
