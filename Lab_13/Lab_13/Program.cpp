#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;

	do
	{
		cout << "Введите количество строк в массиве (1 <= n <= 12): "; cin >> n;
	} while (n < 1 || n > 12);

	cin.ignore(1000, '\n');
	char str_arr[12][51];

	for (int i = 0; i < n; i++)
	{
		cout << "Введите строку " << i << ", длина которой не больше 50 символов:" << endl;
		cin.getline(str_arr[i], 51);
	}

	for (int i = 0; i < n; i++)
	{
		int count[] = {0, 0, 0};

		for (int j = 0; j < sizeof(str_arr[i]); j++)
		{
			if (str_arr[i][j] == '#')
				count[0]++;
			else if (str_arr[i][j] == '!')
				count[1]++;
			else if (str_arr[i][j] == '@')
				count[2]++;
		}

		if ((count[0] > 0 && count[0] <= 4) || (count[1] > 0 && count[1] <= 4) || (count[2] > 0 && count[2] <= 4))
			cout << "Строка " << i << ": " << str_arr[i] << endl;
	}

	return 0;
}