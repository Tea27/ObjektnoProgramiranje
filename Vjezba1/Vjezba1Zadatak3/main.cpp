//Napisati iterativnu funkciju za traženje najvećeg i najmanjeg broja u nizu.

#include <iostream>

using namespace std;

void minAndMax(int arr[], int n, int* mini, int* maxi)
{
	int i;
	*mini = *maxi = arr[0];

	for (i = 0; i < n; i++)
	{
		if (arr[i] < *mini)
		{
			*mini = arr[i];
		}
		else if (arr[i] > *maxi)
		{
			*maxi = arr[i];
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

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	minAndMax(arr, n, &mini, &maxi);

	delete[] arr;

	cout << "Najmanji clan niza je: " << mini << endl << endl;
	cout << "Najveci clan niza je: " << maxi << endl;

	return 0;
}
