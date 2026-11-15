#include <iostream>
#include <locale.h>
#include <cmath>
#include <iomanip>
using namespace std;

static double f(double x)
{
	return -0.5 * pow(x, 5) + 7.8 * x + 7.2;
}

int main()
{
	setlocale(LC_ALL, "ru_RU");
	double a, b, x = 0.0;
	int i = 1;

	cout << "Введите границы отрезка: "; cin >> a >> b;

	while (true)
	{
		if (a >= b || b - a > 1.0)
		{
			if (a > b)
			{
				double y = b;
				b = a;
				a = y;

				continue;
			}

			cout << "Длина отрезка должна быть больше 0 и не больше 1, введите другие границы отрезка: "; cin >> a >> b;
		}
		else if (f(a) * f(b) >= 0.0)
		{
			cout << "На концах отрезка функция должна иметь разные по знаку значения, введите другие границы отрезка: "; cin >> a >> b;
		}
		else
			break;
	}

	cout << fixed << setprecision(5);

	while (b - a >= 0.005)
	{
		x = (a + b) / 2;

		cout << "Шаг " << i << ": x = " << x << endl;

		if (abs(f(x)) < 1e-9) {
			break;
		}
		else if (f(a) * f(x) < 0) {
			b = x;
		}
		else {
			a = x;
		}

		i++;
	}

	cout << "\nПриближенный x = " << x << endl;

	return 0;
}