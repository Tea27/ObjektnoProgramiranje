//Napisati rekurzivnu funkciju za traženje najvećeg i najmanjeg broja u nizu.

#include <iostream>

using namespace std;

void recursiveMin(int arr[], int n, int* mini, int* maxi)
{
	if (n < 0)
	{
		return;
	}
	else
	{
		if (arr[n] < *mini)
		{
			*mini = arr[n];
		}
		if (arr[n] > *maxi)
		{
			*maxi = arr[n];
		}
		return recursiveMin(arr, --n, mini, maxi);
	}
}

int main()
{
	int mini, maxi, n;

	cout << "Unesite zeljenu velicinu niza: ";
	cin >> n;

	int* arr = new int[n];

	cout << "Unesite elemente niza: " << endl;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	mini = maxi = arr[n - 1];

	recursiveMin(arr, n - 1, &mini, &maxi);

	delete[] arr;

	cout << "Najmanji broj u nizu je: " << mini << endl;
	cout << "Najveci broj u nizu je: " << maxi << endl;
	return 0;
}
