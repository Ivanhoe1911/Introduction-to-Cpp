﻿/**
*
* Титков Иван
* 4. Расположить значения трёх переменных a, b, c, в порядке возрастания их величин.
*
*/

#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	double a, b, c;	// a, b, c - переменные для сортировки.
	double temp;	// Временная переменная для обмена значений переменных.

	cout << "Введите значение a: ";	// Ввод значения 'a'.
	cin >> a;
	cout << "Вы ввели: " << a << endl;

	cout << "Введите значение b: "; // Ввод значения 'b'.
	cin >> b;
	cout << "Вы ввели: " << b << endl;

	cout << "Введите значение c: "; // Ввод значения 'c'.
	cin >> c;
	cout << "Вы ввели: " << c << endl;

	cout << endl << "Неотсортированные значения: " << a << " " << b << " " << c << endl;

	if (a > b)	// Последовательно меняем значения переменных, для сортировки по возрастанию.
	{
		temp = a;
		a = b;
		b = temp;
	}
	if (b > c)
	{
		temp = b;
		b = c;
		c = temp;
	}
	if (a > b)
	{
		temp = a;
		a = b;
		b = temp;
	}

	// Выводим ответ на экран.
	cout << "Отсортированные значения: " << a << " " << b << " " << c << endl;

	system("pause");
}