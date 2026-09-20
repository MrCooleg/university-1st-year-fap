#include <iostream>
#include <locale.h>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    double x1, y1, x2, y2, x3, y3; //инициализация координат вершин треугольника

    //задание координат
    cout << "Ведите координаты вершины 1:" << endl;
    cout << "x1 = "; cin >> x1;
    cout << "y1 = "; cin >> y1;

    cout << "Ведите координаты вершины 2:" << endl;
    cout << "x2 = "; cin >> x2;
    cout << "y2 = "; cin >> y2;

    while (x2 == x1 && y2 == y1)
    {
        cout << "Одна из сторон треугольника становится равна 0, введите другие координаты вершины 2: " << endl;
        cout << "x2 = "; cin >> x2;
        cout << "y2 = "; cin >> y2;
    }

    cout << "Ведите координаты вершины 3:" << endl;
    cout << "x3 = "; cin >> x3;
    cout << "y3 = "; cin >> y3;

    while ((x3 == x2 && y3 == y2) || (x3 == x1 && y3 == y1))
    {
        cout << "Одна из сторон треугольника становится равна 0, введите другие координаты вершины 3: " << endl;
        cout << "x3 = "; cin >> x3;
        cout << "y3 = "; cin >> y3;
    }

    //расчет сторон треугольника по формуле a = √((x - x0)² + (y - y0)²)
    double a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    double b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    double c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));

    //расчет полупериметра треугольника
    double p = (a + b + c) / 2;

    //расчет площади треугольника по формуле Герона
    double S = sqrt(p * (p - a) * (p - b) * (p - c));

    //вывод
    if (S == 0)
        cout << "Площадь треугольника равна " << S << ", треугольник вырожденный" << endl;
    else
        cout << "Площадь треугольника равна " << S << endl;

    return 0;
}