//Napisati funkciju koja računa najveći i najmanji broj u nizu od n prirodnih
//brojeva. Funkcija vraća tražene brojeve pomoću referenci.

#include <iostream>

using namespace std;

void inputArr(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

void getMiniMaxi(int* arr, int n, int& mini, int& maxi)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < mini)
		{
			mini = arr[i];
		}
		else if (arr[i] > maxi)
		{
			maxi = arr[i];
		}
	}
}

int main()
{
	int mini, maxi, n;


	cout << "Unesite zeljenu velicinu niza: ";
	cin >> n;

	int* arr = new int[n];

	cout << "Unesite elemente niza: " << endl;
	inputArr(arr, n);

	mini = maxi = arr[0];

	getMiniMaxi(arr, n, mini, maxi);

	cout << "Najmanji clan niza je: " << mini << endl << endl;
	cout << "Najveci clan niza je: " << maxi << endl;

	delete[] arr;

	return 0;
}
