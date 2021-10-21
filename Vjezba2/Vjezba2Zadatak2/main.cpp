/* Napisati funkciju koja vraća referencu na neki element niza.Koristeći povratnu vrijednost funkcije kao lvalue
uvećajte i - ti element niza za jedan. */

#include <iostream>

using namespace std;

void inputArr(int* arr, int n)
{

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

int& returnArrElement(int* arr, int selected)
{

	return (arr[selected]);
}

void printArr(int* arr, int n)
{

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	int n;

	cout << "Unesite zeljenu velicinu niza: ";
	cin >> n;

	int* arr = new int[n];

	cout << "Unesite elemente niza: " << endl;
	inputArr(arr, n);

	int selected;

	cout << endl << "Unesite redni broj elementa kojeg zelite uvecati za 1: ";
	cin >> selected;

	while ((selected > n) || (selected < 0))
	{
		cout << endl << "Unesena vrijednost nije unutar niza!" << endl << "Unesite redni broj elementa kojeg zelite uvecati za 1: ";
		cin >> selected;
	}

	selected--;

	returnArrElement(arr, selected) += 1;

	printArr(arr, n);

	delete[] arr;

	return 0;
}
