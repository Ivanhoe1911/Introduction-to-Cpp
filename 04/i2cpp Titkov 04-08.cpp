﻿/**
*
* Титков Иван
* 8. Найти среднее арифметическое цифр натурального числа n, отличных от заданной цифры k.
*
*/

#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	long long int n;	// Переменная 'n'.
	int sum = 0;		// Переменная для хранения суммы цифр переменной 'n'.
	int k;				// Переменная 'k', надо будет суммировать цифры переменной 'n', отличные от ее значения.
	int temp;			// Переменная для хранения промежуточных значений.

	cout << "Введите значение переменной 'n': ";	// Ввод значения переменой 'n'.
	cin >> n;
	cout << "Вы ввели значение " << n << endl << endl;

	cout << "Введите значение переменной 'k': ";	// Ввод значения переменой 'k'.
	cin >> k;
	cout << "Вы ввели значение " << k << endl << endl;

	while (n)			// Повторяем цикл пока переменная 'b' делится на 10 с отстатком.
	{
		temp = n % 10;	// Записываем в 'temp' последнюю цифру текущего значения 'n'
		if (temp != k)	// и если она НЕ равна 'k',
		{
			sum += temp;// то добавляем значение 'temp' к сумме цифр.
		}
		n /= 10;		// Делим 'n' на 10, чтобы на следующей итерации цикла перейти к следующему разряду.
	}

	// Выводим ответ на экран.
	cout << "Сумма цифр (кроме '" << k << "') введенного числа 'n' равняется: " << sum << endl;

	system("pause");
}