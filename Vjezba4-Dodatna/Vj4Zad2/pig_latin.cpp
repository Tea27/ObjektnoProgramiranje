#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "pig_latin.hpp"

using namespace std;

string getOneRandomSentence(vector<string> vec, int n) {
	int randNum = rand() % n;
	return vec[randNum];
}

void inputSentencesVector(vector<string>& vector, int n) {
	cout << "Input sentences into vector" << endl;
	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		vector.push_back(s);
	}
}

bool isVowel(char ch) {
	string vowels = "aeiouAEIOU";
	for (int i = 0; i < 11; i++) {
		if (ch == vowels[i]) {
			return true;
		}
	}
	return false;
}

string consonantsOnTheEnd(string str) {
	int i = 0;
	while (!isVowel(str[i])) {
		i++;
	}
	return str.substr(i) + str.substr(0, i) + "ay";
}

string pigLatinTongue(string str) {
	stringstream s(str); // Used for breaking words
	string word; // to store individual words
	string pigLatin;
	while (s >> word) {
		int n = word.size();
		if (isVowel(word[0])) {
			if (ispunct(word[n - 1])) {
				pigLatin += word.substr(0, n - 1) + "hay" + word[n - 1] + " ";
			}
			else {
				pigLatin += word + "hay" + " ";
			}
		}
		if (!isVowel(word[0])) {
			if (ispunct(word[n - 1])) {
				pigLatin += consonantsOnTheEnd(word.substr(0, n - 1)) + word[n - 1] + " ";
			}
			else {
				pigLatin += consonantsOnTheEnd(word) + " ";
			}
		}
	}
	return pigLatin;
}
