/*Napisati funkciju koja broji koliko pojavljivanja danog podstringa ima u stringu koristeći funkcije standardne biblioteke.*/
#include <iostream>
#include <string>
using namespace std;

int cntStrInStr(string str, string subStr) {
    int cnt = 0;
    size_t nPos = str.find(subStr); // first occurrence
    while (nPos != string::npos)
    {
        cnt++;
        nPos = str.find(subStr, nPos + 1);
    }
    return cnt;
}
int main()
{
	int cnt;
	string str = "this is my string that has multiple strings and has a word string";
	string findMe = "string";

    cnt = cntStrInStr(str, findMe);
    cout << "Broj Ponavljanja: " << cnt << endl;
}
