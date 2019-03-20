/**
*
* Титков Иван
* 3. Определить время года по номеру месяца двумя способами:
* 1) использовать оператор if;
*
*/

#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	int month;		// Переменная для хранения номера месяца.

	cout << "Введите номер месяца: ";	// Ввод месяца с клавиатуры.
	cin >> month;
	cout << "Вы ввели номер " << month << endl;

	if (month == 1) // Конструкция if-else для перебора значений переменной 'month'.
		cout << "Январь" << endl;
	else if (month == 2)
		cout << "Февраль" << endl;
	else if (month == 3)
		cout << "Март" << endl;
	else if (month == 4)
		cout << "Апрель" << endl;
	else if (month == 5)
		cout << "Май" << endl;
	else if (month == 6)
		cout << "Июнь" << endl;
	else if (month == 7)
		cout << "Июль" << endl;
	else if (month == 8)
		cout << "Август" << endl;
	else if (month == 9)
		cout << "Сентябрь" << endl;
	else if (month == 10)
		cout << "Октябрь" << endl;
	else if (month == 11)
		cout << "Ноябрь" << endl;
	else if (month == 12)
		cout << "Декабрь" << endl;
	else
		cout << "Нет такого месяца." << endl;

	system("pause");
}