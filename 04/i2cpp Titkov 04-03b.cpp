/**
*
* Титков Иван
* 3. Определить время года по номеру месяца двумя способами:
* 2) использовать оператор switch
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

	switch (month)	// Конструкция switch-case для перебора значений переменной 'month'.
	{
	case 1:
		cout << "Январь" << endl;
		break;
	case 2:
		cout << "Февраль" << endl;
		break;
	case 3:
		cout << "Март" << endl;
		break;
	case 4:
		cout << "Апрель" << endl;
		break;
	case 5:
		cout << "Май" << endl;
		break;
	case 6:
		cout << "Июнь" << endl;
		break;
	case 7:
		cout << "Июль" << endl;
		break;
	case 8:
		cout << "Август" << endl;
		break;
	case 9:
		cout << "Сентябрь" << endl;
		break;
	case 10:
		cout << "Октябрь" << endl;
		break;
	case 11:
		cout << "Ноябрь" << endl;
		break;
	case 12:
		cout << "Декабрь" << endl;
		break;
	default:
		cout << "Нет такого месяца" << endl;
		break;
	}

	system("pause");
}