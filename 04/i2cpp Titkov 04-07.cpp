﻿/**
*
* Титков Иван
* 7. Вывести на экран все делители натурального числа n.
*
*/

#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	long long int n;		// Анализируемое число.
	bool isPrime = true;	// Триггер, по умолчанию наше число будет простое.

	cout << "Введите значение переменной 'n': "; // ввод операнда a
	cin >> n;
	cout << "Вы ввели значение " << n << endl << endl;

	for (int i = 2; i <= sqrt(n); i++)	// Делим наш операнд на все числа от 2 до корня из операнда,
	{									// можно и больше, чем корень из операнда, но не обязательно.
		if (n % i)	// Если есть остаток от деления, то продолжаем цикл.
		{
			continue;
		}
		else		// Если нет остатка от деления на какое-либо число,
		{			// то выводим на экран найденный делитель.
			cout << "Найден делитель числа 'n': " << i << '.' << endl;
			if (isPrime)				// Если хотябы 1 делитель найден, то число НЕ простое.
			{							// Отмечаем что оно НЕ простое и больше не трогаем триггер.
				isPrime = false;
			}
		}
	}

	if (isPrime)	// Если в процессе работы алгоритма не были найдены делители,
	{				// то выводим сообщение.
		cout << "Делители не надены, число " << n << " является простым." << endl;
	}

	system("pause");
}