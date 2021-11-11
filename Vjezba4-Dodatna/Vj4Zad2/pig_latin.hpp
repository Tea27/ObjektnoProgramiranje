#pragma once
#include <string>
#include <vector>

std::string getOneRandomSentence(std::vector<std::string> vec, int n);

void inputSentencesVector(std::vector<std::string>& vector, int n);

bool isVowel(char ch);

std::string consonantsOnTheEnd(std::string str);

std::string pigLatinTongue(std::string str);