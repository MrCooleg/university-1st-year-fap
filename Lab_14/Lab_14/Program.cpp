#include <iostream>
#include <format>
#include <algorithm>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

static void print_matrix(char name, double matrix[][6], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		if (i == (m - 1) / 2)
			cout << "Матрица " << name << ": ";
		else
			cout << "           ";

		cout << '(';

		for (int j = 0; j < n; j++)
		{
			cout << format("{: >8}", format("{:.5f}", matrix[i][j]));

			if (j < n - 1)
				cout << ' ';
		}

		cout << ')';

		cout << endl;
	}

	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "ru_RU");
	int m, n;
	double k;

	do
	{
		cout << "Введите количество строк матрицы m x n (2 <= m <= 5): "; cin >> m;
	} while (m < 2 || m > 5);

	do
	{
		cout << "Введите количество столбцов матрицы m x n (2 <= n <= 6): "; cin >> n;
	} while (n < 2 || n > 6);

	do
	{
		cout << "Введите число k, диапазон случайных значений элементов матрицы — [-k; 2k] (1.5 <= k <= 4.5): "; cin >> k;
	} while (k < 1.5 || k > 4.5);

	cout << endl;

	srand((unsigned)time(NULL));

	double A[5][6];
	double B[5][6];
	double C[5][6];
	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			A[i][j] = (((double)rand() / RAND_MAX) * 3 * k) - k;
			B[i][j] = (((double)rand() / RAND_MAX) * 3 * k) - k;
			C[i][j] = (((double)rand() / RAND_MAX) * 3 * k) - k;
		}
	}

	print_matrix('A', A, m, n);
	print_matrix('B', B, m, n);
	print_matrix('C', C, m, n);

	int count_A = 0, count_B = 0, count_C = 0;

	cout << "Матрица(-ы) с наибольшим количеством положительных элементов в чётных столбцах: ";

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j % 2 == 0 && A[i][j] > 0)
				count_A++;
			if (j % 2 == 0 && B[i][j] > 0)
				count_B++;
			if (j % 2 == 0 && C[i][j] > 0)
				count_C++;
		}
	}

	int max_count = max({ count_A, count_B, count_C });

	bool first = true;

	if (count_A == max_count) {
		cout << 'A';
		first = false;
	}
	if (count_B == max_count) {
		if (!first) cout << ", ";
		cout << 'B';
		first = false;
	}
	if (count_C == max_count) {
		if (!first) cout << ", ";
		cout << 'C';
	}
	cout << endl;

	return 0;
}