#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

static int odd_sum(int array[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i] % 2 == 1)
			sum += array[i];
	}

	return sum;
}

static void task_1()
{
	int m, k;

	do
	{
		cout << "Введите количество элементов массивов (1 <= m <= 7): "; cin >> m;
	} while (m < 1 || m > 7);

	do
	{
		cout << "Введите число k, диапазон случайных значений элементов массивов — [k; 3k] (3 < k < 9): "; cin >> k;
	} while (k <= 3 || k >= 9);

	srand((unsigned)time(NULL));

	int array1[7];
	int array2[7];
	int array3[7];
	int array4[7];

	for (int i = 0; i < m; i++)
	{
		array1[i] = k + rand() % (2 * k + 1);
		array2[i] = k + rand() % (2 * k + 1);
		array3[i] = k + rand() % (2 * k + 1);
		array4[i] = k + rand() % (2 * k + 1);
	}

	int odd_sums[4] = { odd_sum(array1, m), odd_sum(array2, m), odd_sum(array3, m), odd_sum(array4, m) };

	cout << "\nМассив array1: [";

	for (int i = 0; i < m; i++)
	{
		cout << array1[i];

		if (i < m - 1)
			cout << ", ";
	}

	cout << "]\nМассив array2: [";

	for (int i = 0; i < m; i++)
	{
		cout << array2[i];

		if (i < m - 1)
			cout << ", ";
	}

	cout << "]\nМассив array3: [";

	for (int i = 0; i < m; i++)
	{
		cout << array3[i];

		if (i < m - 1)
			cout << ", ";
	}

	cout << "]\nМассив array4: [";

	for (int i = 0; i < m; i++)
	{
		cout << array4[i];

		if (i < m - 1)
			cout << ", ";
	}

	cout << "]\n" << endl;

	for (int i = 0; i < 4; i++)
	{
		if (odd_sums[i] == 0)
			cout << "В массиве array" << i + 1 << " нет нечётных чисел" << endl;
		else
			cout << "Сумма нечётных элементов массива array" << i + 1 << ": " << odd_sums[i] << endl;
	}
}

static void task_2()
{
	int n;
	double p;

	do
	{
		cout << "Введите количество элементов массивов (1 <= n <= 10): "; cin >> n;
	} while (n < 1 || n > 10);

	do
	{
		cout << "Введите число p, диапазон случайных значений элементов массивов — [0.5p; 3.5p] (p >= 2): "; cin >> p;
	} while (p < 2.0);

	srand((unsigned)time(NULL));

	double array[10];

	for (int i = 0; i < n; i++)
	{
		array[i] = 0.5 * p + ((double)rand() / RAND_MAX) * 3.0 * p;
	}

	cout << "\nМассив: [";

	for (int i = 0; i < n; i++)
	{
		cout << array[i];

		if (i < n - 1)
			cout << ", ";
	}

	cout << "]\n" << endl;

	double max = 0.0;

	for (int i = 0; i < n; i++)
	{
		if (max < array[i])
			max = array[i];
	}

	double sum = 0.0; int m = 0;
	for (int i = 0; i < n; i++)
	{
		if (array[i] < max)
		{
			sum += array[i];
			m++;
		}
	}

	if (m == 0)
		cout << "В массиве кроме числа " << max << " больше нет чисел" << endl;
	else
	{
		double average = sum / m;
		cout << "Среднее арифметическое всех чисел, меньших, чем " << max << ": " << average << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "ru_RU");

	task_1();
	//task_2();

	return 0;
}