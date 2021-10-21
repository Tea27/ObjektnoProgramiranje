#include <ctime>
#include <iostream>
#include <iomanip>

using namespace std;

struct matrix
{
	int rows, cols;
	float** mat;
};

void userInMat(matrix* userIn, int n, int m)
{

	userIn->rows = n;
	userIn->cols = m;

	userIn->mat = new float* [n];
	for (int i = 0; i < n; i++)
		userIn->mat[i] = new float[m];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "[" << (i + 1) << "] [" << (j + 1) << "] = ";
			cin >> userIn->mat[i][j];
		}
	}
}

void randomMatrix(matrix* randMat, int n, int m)
{
	float randomNum;
	float a, b;

	srand((unsigned)time(0));

	randMat->rows = n;
	randMat->cols = m;

	randMat->mat = new float* [n];
	for (int i = 0; i < n; i++)
		randMat->mat[i] = new float[m];

	cout << "Unesite interval [a, b] u kojem zelite generirati nasumicne brojeve za matricu:\n" << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;

	if (a > b)
	{
		a += b;
		b = a - b;
		a -= b;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			randomNum = a + (rand() / (RAND_MAX / (b - a)));
			randMat->mat[i][j] = randomNum;
		}
	}

}

int addOrSubtract(matrix userIn, matrix randNum, matrix* added, matrix* sbtr)
{

	if ((userIn.cols == randNum.cols) && (userIn.rows == randNum.rows))
	{
		int n = randNum.rows;
		int m = randNum.cols;

		added->rows = sbtr->rows = n;
		added->cols = sbtr->cols = m;

		added->mat = new float* [n];
		for (int i = 0; i < n; i++)
			added->mat[i] = new float[m];

		sbtr->mat = new float* [n];
		for (int i = 0; i < n; i++)
			sbtr->mat[i] = new float[m];

		for (int i = 0; i < userIn.cols; i++)
		{
			for (int j = 0; j < userIn.rows; j++)
			{
				added->mat[i][j] = userIn.mat[i][j] + randNum.mat[i][j];
				sbtr->mat[i][j] = userIn.mat[i][j] - randNum.mat[i][j];
			}
		}
		return 1;
	}
	else
	{
		cout << endl << "Matrice nisu jednakih dimenzija. Ne mogu se zbrajati/oduzimati." << endl;
		return 0;
	}
}

int multiplyMat(matrix m1, matrix m2, matrix* multiMat)
{

	if (m1.cols == m2.rows)
	{
		multiMat->rows = m1.rows;
		multiMat->cols = m2.cols;

		multiMat->mat = new float* [m1.rows];
		for (int i = 0; i < m1.rows; i++)
			multiMat->mat[i] = new float[m2.cols];

		for (int i = 0; i < m1.rows; ++i)
			for (int j = 0; j < m2.cols; ++j)
			{
				multiMat->mat[i][j] = 0;
			}

		for (int i = 0; i < m1.rows; ++i)
		{
			for (int j = 0; j < m2.cols; ++j)
			{
				//multiMat->mat[i][j] = 0;
				for (int k = 0; k < m2.rows; ++k)
				{
					multiMat->mat[i][j] += (m1.mat[i][k] * m2.mat[k][j]);
				}
			}
		}

		return 1;
	}
	else
	{
		cout << endl << "Error! Stupci prve matrice nisu jednaki retcima druge matrice. Matrice se ne mogu mnoziti!" << endl;
		return 0;
	}
}

void transposeMat(matrix m1, matrix* transpMat)
{
	int n = m1.cols;
	int m = m1.rows;

	transpMat->rows = n;
	transpMat->cols = m;

	transpMat->mat = new float* [n];
	for (int i = 0; i < n; i++)
		transpMat->mat[i] = new float[m];


	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			transpMat->mat[j][i] = m1.mat[i][j];
		}
	}

}

void printMe(matrix matPr)
{
	int i, j;
	for (i = 0; i < matPr.rows; i++)
	{
		for (j = 0; j < matPr.cols; j++)
		{
			cout << setprecision(4) << fixed << right << setw(10) << matPr.mat[i][j] << "  ";
		}
		cout << "\n";
	}
}

void deleteMe(matrix* matDe)
{
	for (int i = 0; i < matDe->rows; i++)
		delete[] matDe->mat[i];
	delete[] matDe->mat;
}


int main()
{
	matrix userIn, randNum, addedMat, subtrMat, multiMat, transpMat;
	int n1, m1, n2, m2, fl1, fl2;

	cout << "Unesite velicinu (n x m) prve matrice: " << endl << "n = ";
	cin >> n1;
	cout << "m = ";
	cin >> m1;

	userInMat(&userIn, n1, m1);

	cout << "Unesite velicinu (n x m) druge matrice: " << endl << "n = ";
	cin >> n2;
	cout << "m = ";
	cin >> m2;

	randomMatrix(&randNum, n2, m2);

	fl1 = addOrSubtract(userIn, randNum, &addedMat, &subtrMat);

	fl2 = multiplyMat(userIn, randNum, &multiMat);

	transposeMat(userIn, &transpMat);

	cout << endl << "Unesena matrica:" << endl;
	printMe(userIn);

	cout << endl << "Nasumicno generirana matrica:" << endl;
	printMe(randNum);

	if (fl1)
	{
		cout << endl << "Matrice nakon oduzimanja:" << endl;
		printMe(subtrMat);

		cout << endl << "Matrice nakon zbrajanja:" << endl;
		printMe(addedMat);
	}

	if (fl2)
	{
		cout << endl << "Matrice nakon mnozenja:" << endl;
		printMe(multiMat);
	}

	cout << endl << "Transponirana matrica:" << endl;
	printMe(transpMat);

	deleteMe(&userIn);
	deleteMe(&randNum);
	deleteMe(&subtrMat);
	deleteMe(&addedMat);
	deleteMe(&multiMat);

	return 0;
}
