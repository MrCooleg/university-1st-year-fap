#include <iostream>
#include <locale.h>
#include <cmath>
#include <format>
using namespace std;

static double f(double x)
{
	return 2.1 * pow(x, 2) + 2.1 * sin(x) + 1.7;
}

static double f_antiderivative(double x)
{
	return 0.7 * pow(x, 3) - 2.1 * cos(x) + 1.7 * x;
}

static double area(double left, double right, int n, bool leftmode)
{
	double h = abs(right - left) / n, sum = 0;

	for (int i = 0; i < n; i++)
		sum += f(left + h * i);

	return sum * h;
}

static double area(double left, double right, int n, char rightmode)
{
	double h = abs(right - left) / n, sum = 0;

	for (int i = 1; i <= n; i++)
		sum += f(left + h * i);

	return sum * h;
}

static double area(double left, double right, int n)
{
	double h = abs(right - left) / n, sum = (f(left) + f(left + h * n)) / 2;

	for (int i = 1; i < n; i++)
		sum += f(left + h * i);

	return sum * h;
}

static double area(double left, double right, int n, double simpson)
{
	double h = abs(right - left) / (2 * n), sum = 0;

	for (int i = 0; i <= 2 * n; i++)
	{
		int multiplier;

		if (i == 0 || i == 2 * n)
			multiplier = 1;
		else if (i % 2 == 0)
			multiplier = 2;
		else
			multiplier = 4;

		sum += multiplier * f(left + h * i);
	}

	return sum * h / 3;
}

static void task8()
{
	double a, b;
	int k;

	cout << "Введите пределы a и b: "; cin >> a >> b;
	cout << "Введите k: "; cin >> k;

	double exact = f_antiderivative(b) - f_antiderivative(a);
	double left = area(a, b, k, true);
	double left10 = area(a, b, 10 * k, true);
	double right = area(a, b, k, ' ');
	double right10 = area(a, b, 10 * k, ' ');
	double trapez = area(a, b, k);
	double trapez10 = area(a, b, 10 * k);
	double simpson = area(a, b, k, 0.0);
	double simpson10 = area(a, b, 10 * k, 0.0);

	cout << "Площадь под графиком f(x) = 2.1x^2 + 2.1cos(x) + 1.7 на отрезке [" << a << "; " << b << "]:" << endl;
	cout << "Точное значение: " << exact << endl;
	cout << format("{: <4}", "") << format("{: ^92}", "Формула") << endl;
	cout << format("{: <4}", "n") << format("{: <23}", "левого прямоугольника") << format("{: <23}", "правого прямоугольника") << format("{: <23}", "трапеции") << format("{: <23}", "Симпсона") << endl << endl;
	cout << format("{: <4}", "k") << format("{: <23}", format("{:.4f}", left)) << format("{: <23}", format("{:.4f}", right))
		<< format("{: <23}", format("{:.4f}", trapez)) << format("{: <23}", format("{:.4f}", simpson)) << endl;
	cout << format("{: <4}", "10k") << format("{: <23}", format("{:.4f}", left10)) << format("{: <23}", format("{:.4f}", right10))
		<< format("{: <23}", format("{:.4f}", trapez10)) << format("{: <23}", format("{:.4f}", simpson10)) << endl;
}

int main()
{
	setlocale(LC_ALL, "ru_RU");

	task8();

	return 0;
}