#include <iostream>
#include <locale.h>
using namespace std;

static void task_1()
{
	//объявляем переменные
	int k;
	double S = 0.0;
	//вводим
	cout << "Введите верхний предел суммирования k: "; cin >> k;

	//рассчитываем сумму по формуле
	for (int i = 1; i <= k; i++)
		S += k * i + 1.0 / (i * i);

	//выводим
	cout << "Сумма: " << S << endl;
}

static void task_2()
{
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= i; j++)
			cout << i << " ";

		cout << endl;

		if (i == 3)
			cout << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "ru_RU");

	task_1();
	//task_2();

	return 0;
}