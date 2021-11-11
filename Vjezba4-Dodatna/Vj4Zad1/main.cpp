/*Učitati string koji predstavlja rečenicu. Napisati funkciju koja iz stringa izbacuje
sve praznine koje se nalaze ispred znakova interpunkcije i dodaje praznine nakon
znaka interpunkcije ako nedostaju.
Primjer: Za rečenicu ”Ja bih ,ako ikako mogu , ovu recenicu napisala ispravno.”,
Ispravna rečenica glasi: ”Ja bih, ako ikako mogu, ovu recenicu napisala ispravno.”.*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool checkSpace(char a, char b)
{
	return ((isspace(a) && isspace(b)));
}

void correctMyString(string str, string& correctedStr) {
	replace(str.begin(), str.end(), '\t', ' ');

	auto ip = unique(str.begin(), str.end(), checkSpace);
	int n = ip - str.begin();

	for (int i = 0; i < n; i++) {
		if (isspace(str[i]) && ispunct(str[i+1])) {
			correctedStr.push_back(str[++i]);
			if (isspace(str[i + 1])) continue;
			correctedStr.push_back(' ');
		}
		else if (ispunct(str[i]) && isalpha(str[i + 1])) {
			correctedStr.push_back(str[i]);
			correctedStr.push_back(' ');
		}
		else{
			correctedStr.push_back(str[i]);
		}
	}

}

int main(){
	cout << "Please enter the sentence that you want to correct" << endl;
	string myStr;
	getline(cin, myStr);
	string correct = "";
	correctMyString(myStr, correct);
	cout << correct;
}


