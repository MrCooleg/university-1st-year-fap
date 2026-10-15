#include <iostream>
#include <locale.h>
#include <cmath>
#include <format>
using namespace std;

static double f1(double x)
{
	return (-0.7 / pow(x, 4)) - pow(x, 3) + cos(2 * x);
}

static void task_1()
{
	double x1, x2, dx; //объявляем x начальное, x конечное и шаг цикла

	//вводим
	cout << "Введите начальное значение x: "; cin >> x1;
	cout << "Введите конечное значение x: "; cin >> x2;
	cout << "Введите шаг цикла: "; cin >> dx;
	
	//выводим таблицу
	cout << "-----------------------------------------------------" << endl;
	cout << "| " << format("{: ^23}", "x") << " | " << format("{: ^23}", "y") << " |" << endl;
	
	while (x1 <= x2)
	{
		cout << "|-------------------------|-------------------------|" << endl;

		//выводим каждую строчку
		cout << "| " << format("{: >23}", x1) << " | ";

		if (x1 != 0)
			cout << format("{: >23}", f1(x1));
		else
			cout << format("{: >23}", "Функция не определена");
		
		cout << " |" << endl;

		//увеличиваем наше значение x1 на шаг цикла
		x1 += dx;
	}
	cout << "-----------------------------------------------------" << endl;
}

static double f2(double x)
{
	return 1.9 - cos(pow(x, 3) - 0.5);
}

static void task_2()
{
	//объявляем переменные
	double x, sum = 0.0;
	int n = 1;

	//вводим
	cout << "Введите значение x: "; cin >> x;

	//считаем
	do
	{
		sum += 1.0 / n;
		n++;
	} while (sum <= f2(x));

	//выводим
	cout << "Наименьшее значение n, при котором 1 + 1/2 + ... + 1/n > " << f2(x) << ": " << n << endl;
}

int main()
{
	setlocale(LC_ALL, "ru_RU");
	
	task_1();
	//task_2();
	
	return 0;
}