#include <iostream>
#include <locale.h>
using namespace std;

static void task_2()
{
	char letter; //объявляем переменную буквы, вводимой пользователем

	//просим пользователя ввести букву
	cout << "Введите любую букву из набора {A, S, D, F, B, R}: "; cin >> letter;

	//проверяем введённую букву на принадлежность списку и на корректность ввода и выводим результат
	switch (toupper(letter))
	{
		case 'A':
			cout << "Apple";
			break;
		case 'S':
			cout << "Snake";
			break;
		case 'D':
			cout << "Dog";
			break;
		case 'F':
			cout << "Fish";
			break;
		case 'B':
			cout << "Butterfly";
			break;
		case 'R':
			cout << "Rock";
			break;
		default:
			cout << "Введённый символ не находится в списке допустимых";
	}

	cout << endl;
}

static void task_6()
{
	char letter; //объявляем переменную буквы, вводимой пользователем

	//просим пользователя ввести букву
	cout << "Введите любую букву из набора {P, U, R, L, M}: "; cin >> letter;

	//проверяем введённую букву на принадлежность списку и на корректность ввода и выводим результат
	switch (toupper(letter))
	{
		case 'P':
			cout << "Poland";
			break;
		case 'U':
			cout << "Ukraine";
			break;
		case 'R':
			cout << "Russia";
			break;
		case 'L':
			cout << "Lithuania";
			break;
		case 'M':
			cout << "Mongolia";
			break;
		default:
			cout << "Введённый символ не находится в списке допустимых";
	}

	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "ru_RU");

	task_2();
	//task_6();

	return 0;
}