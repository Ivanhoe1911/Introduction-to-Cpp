/**
*
* Титков Иван
* 3. Вычислить доход по вкладу. Исходными данными для функции являются:
* величина вклада, процентная ставка (годовых) и срок вклада (количество дней).
*
*/

#include <iostream>

using namespace std;

double bank(int d, int r, int t);	// Прототип функции дохода вклада.

int main()
{
	setlocale(LC_ALL, "ru");

	int deposit;	// Сумма вклада.
	int rate;		// Процентная ставка (годовых).
	int term;		// Срок вклада (дни).

	double profit;	// Доход по вкладу. Вычислим его.

	cout << "Введите сумму вклада: ";	// Вводим 'deposit' с клавиатуры.
	cin >> deposit;
	cout << "Вы ввели: " << deposit << endl;

	cout << "Введите процентную ставку (годовых): ";	// Вводим 'rate' с клавиатуры.
	cin >> rate;
	cout << "Вы ввели: " << rate << endl;

	cout << "Введите срок вклада в днях: ";		// Вводим 'term' с клавиатуры.
	cin >> term;
	cout << "Вы ввели: " << term << endl;

	if (deposit <= 0 || rate < 0 || term < 0) // Проверка на отрицательный ввод.
	{
		cout << endl << "Вводите значения большие нуля!" << endl << endl;
		return 1;
	}

	profit = bank(deposit, rate, term); // Вызываем функцию подсчета вклада и возвращаем ее значение.

	// Выводим ответ на экран.
	cout << endl << "Будет получен доход в размере: " << profit << endl << endl;
	system("pause");
}

double bank(int d, int r, int t)	// Функция подсчета дохода вклада.
{
	return (double)d * r / 100 * 365 / t;
}