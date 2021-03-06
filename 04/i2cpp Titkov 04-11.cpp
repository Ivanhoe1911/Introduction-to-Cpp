﻿/**
*
* Титков Иван
* 11. Вводится последовательность из n натуральных чисел. Найти среди них максимальное число.
*
*/

#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	int n;				// Переменная 'n'.
	int temp;			// Переменная для хранения промежуточных значений.
	int max = INT_MIN;	// Переменная для хранения максимального числа, делаем ее минимально возможной
						// чтобы корректно обработать отрицательные значения.

	cout << "Сколько чисел будете вводить?: ";	// Ввод значения переменой 'n'.
	cin >> n;
	cout << "Вы ввели значение " << n << endl << endl;

	while (n-- && n >= 0)	// Повторяем цикл 'n' раз, а также не начинаем его если n < 0.
	{
		cout << "Введите число: ";	// Записывает в переменную 'temp' текущее число.
		cin >> temp;
		cout << "Вы ввели: " << temp << endl;

		if (max < temp)				// Если это число является максимальным на данный момент,
		{							// то выводим соответствующее сообщение
			cout << "Вы ввели максимальное число на данный момент." << endl;
			max = temp;				// и записывает это число в переменную 'max'.
		}
	}

	// Выводим окончательный ответ на экран.
	cout << endl << "Максимальное число из всех введенных: " << max << endl;

	system("pause");
}