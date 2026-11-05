#include <iostream>
#include <locale.h>
using namespace std;

static void flip(int* N)
{
    int sum = 0;

    while (*N != 0) {
        int last_digit = *N % 10;
        sum = sum * 10 + last_digit;
        *N /= 10;
    }

    *N = sum;
}

static void flip(int& N)
{
    int sum = 0;

    while (N != 0) {
        int last_digit = N % 10;
        sum = sum * 10 + last_digit;
        N /= 10;
    }

    N = sum;
}

static int flip(int N, bool b)
{
	int sum = 0;

    while (N != 0) {
        int last_digit = N % 10;
        sum = sum * 10 + last_digit;
        N /= 10;
    }

    return sum;
}

static void task_2()
{
    int num1, num2, num3;

    cout << "Введите целое число 1: "; cin >> num1;
    cout << "Метод указателя: " << endl;
    cout << "Исходное число: " << num1 << endl;
    flip(&num1);
    cout << "Конечное число: " << num1 << "\n\n";

    cout << "Введите целое число 2: "; cin >> num2;
    cout << "Метод ссылки: " << endl;
    cout << "Исходное число: " << num2 << endl;
    flip(num2);
    cout << "Конечное число: " << num2 << "\n\n";

    cout << "Введите целое число 3: "; cin >> num3;
    cout << "Метод копии (просто возвращение результата): " << endl;
    cout << "Исходное число: " << num3 << endl;
    int result = flip(num3, true);
    cout << "Конечное число (возврат результата функции): " << result << endl;
    cout << "При этом само число (исходное) не изменилось: " << num3 << "\n";
}

static void F(int N, int& First, int& Last)
{
    Last = N % 10;
    First = flip(N, true) % 10;
}

static void task_3()
{
    int n, first, last;
    cout << "Введите число: "; cin >> n;

    F(n, first, last);

    cout << "Исходное число: " << n << endl;
    cout << "Первая цифра: " << first << endl;
    cout << "Последняя цифра: " << last << endl;
}

int main()
{
    setlocale(LC_ALL, "ru_RU");

    //task_2();
    task_3();

    return 0;
}