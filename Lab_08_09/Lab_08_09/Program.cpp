#include <iostream>
#include <locale.h>
#include <cmath>
using namespace std;

static double f1(double x)
{
	return 2.1 * pow(x, 2) + 2.1 * sin(x) + 1.7;
}

static double f1_antiderivative(double x)
{
	return 0.7 * pow(x, 3) - 2.1 * cos(x) + 1.7 * x;
}

static double left_rectangle(double left, double right, int k)
{
	double h = abs(right - left) / k, sum = 0;

	for (int i = 0; i < k; i++)
		sum += f1(left + h * i);

	return sum * h;
}

static double right_rectangle(double left, double right, int k)
{
	double h = abs(right - left) / k, sum = 0;

	for (int i = 1; i <= k; i++)
		sum += f1(left + h * i);

	return sum * h;
}

static double trapezoid(double left, double right, int n)
{
	double h = abs(right - left) / n, sum = (f1(left) + f1(left + h * n)) / 2;

	for (int i = 1; i < n; i++)
		sum += f1(left + h * i);

	return sum * h;
}

static double simpsons_formula(double left, double right, int k)
{
	double h = abs(right - left) / (2 * k), sum = 0;

	for (int i = 0; i <= 2 * k; i++)
	{
		int multiplier;

		if (i == 0 || i == 2 * k)
			multiplier = 1;
		else if (i % 2 == 0)
			multiplier = 2;
		else
			multiplier = 4;

		sum += multiplier * f1(left + h * i);
	}

	return sum * h / 3;
}

static void task8_1()
{
	double a, b;
	int k;

	cout << "Введите пределы a и b: "; cin >> a >> b;
	cout << "Введите k: "; cin >> k;

	double exact = f1_antiderivative(b) - f1_antiderivative(a);
	double left = left_rectangle(a, b, k);
	double left10 = left_rectangle(a, b, 10 * k);
	double right = right_rectangle(a, b, k);
	double right10 = right_rectangle(a, b, 10 * k);
	double trapez = trapezoid(a, b, k);
	double trapez10 = trapezoid(a, b, 10 * k);
	double simpson = simpsons_formula(a, b, k);
	double simpson10 = simpsons_formula(a, b, 10 * k);

	cout << "Площадь под графиком f(x) = 2.1x^2 + 2.1cos(x) + 1.7 на отрезке [" << a << "; " << b << "]:" << endl;
	cout << "Точное значение: " << exact << endl;
	cout << "Значение по формуле левого прямоугольника при n = k: " << left << endl;
	cout << "Значение по формуле левого прямоугольника при n = 10k: " << left10 << endl;
	cout << "Значение по формуле правого прямоугольника при n = k: " << right << endl;
	cout << "Значение по формуле правого прямоугольника при n = 10k: " << right10 << endl;
	cout << "Значение по формуле трапеции при n = k: " << trapez << endl;
	cout << "Значение по формуле трапеции при n = 10k: " << trapez10 << endl;
	cout << "Значение по формуле Симпсона при n = k: " << simpson << endl;
	cout << "Значение по формуле Симпсона при n = 10k: " << simpson10 << endl;
}

static void task9_1()
{

}

int main()
{
	setlocale(LC_ALL, "ru_RU");

	task8_1();
	//task9_1();

	return 0;
}