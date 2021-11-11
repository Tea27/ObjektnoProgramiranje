/*Napisati funkciju koji prevodi engleske rečenice na pig latin jezik. Pravila su sljedeća:
(a) ako riječ počinje samoglasnikom dopisuje se hay na kraj riječi,
(b) inače, svi suglasnici s početka riječi prebacuju se na kraj te se na kraju riječi dopisuje ay.
Rečenice treba spremiti u vector, a zatim prevesti slučajno odabranu rečenicu iz vektora.
Primjer: ”What time is it?” prevodi se kao ”atwhay imetay ishay ithay?”*/

#include <iostream>
#include <string>
#include <vector>
#include "pig_latin.hpp"
using namespace std;

int main()
{
	srand(time(NULL));
	vector<string> myStringVec;
	string str;
	int numOfSentences;

	cout << "Input the number of the sentences: ";
	cin >> numOfSentences;
	numOfSentences++;

	inputSentencesVector(myStringVec, numOfSentences);
	str = getOneRandomSentence(myStringVec, numOfSentences);

	string pl = pigLatinTongue(str);
	cout << endl <<"One random sentence from your vector in pig latin:" << endl << pl;
}
