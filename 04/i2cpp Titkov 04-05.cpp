/**
*
* Титков Иван
* 5. Составить программу-калькулятор для выполнения 4
* действий над переменными a и b: +, -, *, /.
* Использовать оператор switch.
*
*/

#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	double a, b;		// Переменные для операндов.
	char ch;			// Переменная для операции.
	double result = 0;	// Переменная для результата.

	cout << "Введите значение операнда 'a': "; // Ввод операнда 'a'.
	cin >> a;
	cout << "Вы ввели значение " << a << endl;

	cout << "Введите операцию (+, -, *, /): "; // Ввод операции.
	cin >> ch;
	cout << "Вы выбрали операцию " << ch << endl;

	cout << "Введите значение операнда 'b': "; // Ввод операнда 'b'.
	cin >> b;
	cout << "Вы ввели значение " << b << endl << endl;

	switch (ch)		// Конструкция switch-case для выполнения операции.
	{
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a * b;
		break;
	case '/':
		if (b == 0)	// Проверка деления на ноль.
		{
			cout << "Недопустимая операция!" << endl;
			break;
		}
		result = a / b;
		break;
	default:
		cout << "Недопустимая операция!" << endl;
		break;
	}

	cout << "Результат вычисления: " << result << endl;

	system("pause");
}