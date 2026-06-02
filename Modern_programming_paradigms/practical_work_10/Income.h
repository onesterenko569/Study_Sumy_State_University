#pragma once

#include <iostream>

// клас для роботи з фінансами
class Income
{
private:                                       // закриті дані класу
	double revenue;                            // змінна для зберігання суми доходів
	double expense;                            // змінна для зберігання суми витрат

public:                                        // відкриті методи класу
	// конструктор за замовчуванням
	Income();

	// конструктор з параметрами
	Income(double rev, double exp);

	// перевантаження оператора додавання
	Income operator+(const Income& inc) const;

	// перевантаження оператора віднімання
	Income operator-(const Income& inc) const;

	// перевантаження оператора +=
	Income& operator+=(const Income& inc);

	// перевантаження оператора -=
	Income& operator-=(const Income& inc);

	// дружня функція для перевантаження оператора виводу
	friend std::ostream& operator<<(std::ostream& os, const Income& inc);
};