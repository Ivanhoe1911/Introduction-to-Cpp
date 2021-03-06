﻿/**
*
* Титков Иван
* 20.*Определить натуральное число из диапазона [n, m],
* в двоичном представлении которого больше всего единиц.
*
*/

#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	int n;					// Натуральное число 'n' диапазона.
	int m;					// Натуральное число 'm' диапазона.
	int temp;				// Временная переменная, текущее обрабатываемое число.
	int nMax;				// Переменная для хранения искомого числа (с максимальной суммой единиц).
	long long int binMax;	// Двоичное представление искомого числа.
	int sumMax = 0;			// Максимальная сумма единиц искомого числа в двоичном формате.
	long long int bin = 0;	// Двоичное представление текущего числа.
	int sum = 0;			// Сумма единиц в текущем двоичном числе.


	cout << "Введите число 'n' диапазона [n, m]: ";	// Вводим 'n' с клавиатуры.
	cin >> n;
	cout << "Вы ввели: " << n << endl;

	cout << "Введите число 'm'диапазона [n, m]: ";	// Вводим 'n' с клавиатуры.
	cin >> m;
	cout << "Вы ввели: " << m << endl;

	while (n <= m)			// Повторяем цикл, пока не переберем все числа дианазона.
	{
		temp = n;			// Начинаем с минимального числа.
		// Алгоритм конвертации путем сохранения остатка от деления на 2.
		for (int i = 0; temp; i++)			// Продожаем цикл пока есть что делить на 2.
		{
			bin += temp % 2 * pow(10, i);	// В 'bin' заносим в правильном порядке благодаря pow().
			sum += temp % 2;				// Одновременно с этим суммируем единицы числа.
			temp /= 2;						// Делим на 2 для следующей итерации.
		}

		// Выводим ответ на экран.
		cout << endl << "Результат конвертации числа " << n << ": " << bin << ". Сумма единиц = " << sum;

		// Поиск и сохранение числа с максимальной суммой единиц в двоичном предсавлении.
		if (sum > sumMax)
		{
			nMax = n;
			sumMax = sum;
			binMax = bin;
		}
		bin = 0; sum = 0;		// Обнуляем переменные, успользуемые в итерациях.
		n++;					// Переходим к следующему числу диапазона [n, m].
	}

	// Выводим ответ на экран.
	cout << endl << endl << "В двоичном представлении числа " << nMax
		<< " (" << binMax << ") больше всего единиц: " << sumMax << endl << endl;

	system("pause");
}