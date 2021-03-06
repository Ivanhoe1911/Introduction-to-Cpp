﻿/**
*
* Титков Иван
* 11.	*Вводится последовательность из n натуральных чисел. Определить количество единиц в двоичном представлении каждого числа с помощью
* а) арифметических операций,
* б) битовых операций.
*
*/

#include <iostream>

using namespace std;

// Прототип функции для конвертации в двоичный формат.
int toBin(int var);

// Прототип функции для подсчета суммы единиц двоичного представления числа (арифметический).
int count1math(int var);

// Прототип функции для подсчета суммы единиц двоичного представления числа (битовый сдвиг).
int count1shift(int var);

int main()
{
	setlocale(LC_ALL, "ru");

	int n;				// Натуральное число 'n'.

	cout << "Введите натуральное число 'n': ";	// Вводим 'n' с клавиатуры.
	cin >> n;
	cout << "Вы ввели: " << n << endl;

	if (n <= 0)			// Проверка на отрицательный ввод.
	{
		cout << endl << "Вводите натуральное число (целое, большее нуля)!" << endl << endl;
		return 1;
	}

	// Выводим ответ на экран.
	cout << endl << "Число в двоичном представлении: " << toBin(n) << endl;
	cout << "Сумма единиц (арифметическая операция): " << count1math(n) << endl;
	cout << "Сумма единиц (битовый сдвиг): " << count1shift(n) << endl;

	system("pause");
}

// Функция для конвертации в двоичный формат.
int toBin(int var)
{
	int converted = 0;						// Переменная для хранения результата.
	for (int i = 0; var; i++, var /= 2)		// Продожаем цикл пока есть что делить на 2,
	{										// делим на 2 для следующей итерации и ведем счетчик разрядов.
		converted += var % 2 * pow(10, i);	// В переменную 'bin' заносим уже в правильном порядке
	}										// путем записи сразу в старший разряд с момощью "pow()".
	return converted;						// Возвращаем результат.
}

// Функция для подсчета суммы единиц двоичного представления числа (арифметический).
int count1math(int var)
{
	int sum = 0;		// Счетчик единиц.
	do
	{
		sum += var % 2;	// Суммируем остатки от деления на 2
	} while (var /= 2);	// пока число не доделится до нуля.
	return sum;
}

// Функция для подсчета суммы единиц двоичного представления числа (битовый сдвиг).
int count1shift(int var)
{
	int sum = 0;		// Счетчик единиц.
	do
	{
		if (((var >> 1) * 2) != var)// Если до сдвига число не равно числу после сдвига умноженному на 2,
		{
			sum++;					// значит последним битом была единица, увеличиваем счетчик.
		}
	} while (var >>= 1);			// Пока число не станет равным нулю, будем сдвигать биты вправо на итерациях.
	return sum;
}