#include "Income.h"

// реалізація конструктора за замовчуванням
Income::Income() : revenue(0.0), expense(0.0) {}

// реалізація конструктора з параметрами
Income::Income(double rev, double exp) : revenue(rev), expense(exp) {}

// реалізація оператора додавання
Income Income::operator+(const Income& inc) const
{
	// створюємо і повертаємо новий об'єкт, додаючи відповідні поля
	return Income(this->revenue + inc.revenue, this->expense + inc.expense);
}

// реалізація оператора віднімання
Income Income::operator-(const Income& inc) const
{
	// створюємо і повертаємо новий об'єкт, віднімаючи відповідні поля
	return Income(this->revenue - inc.revenue, this->expense - inc.expense);
}

// реалізація оператора +=
Income& Income::operator+=(const Income& inc)
{
	this->revenue += inc.revenue;            // додаємо доходи до поточного об'єкта
	this->expense += inc.expense;            // додаємо витрати до поточного об'єкта

	return *this;                            // повертаємо змінений об'єкт
}

// реалізація оператора -=
Income& Income::operator-=(const Income& inc)
{
	this->revenue -= inc.revenue;            // віднімаємо доходи від поточного об'єкта
	this->expense -= inc.expense;            // віднімаємо витрати від поточного об'єкта

	return *this;                            // повертаємо змінений об'єкт
}

// реалізація оператора виводу
std::ostream& operator<<(std::ostream& os, const Income& inc)
{
	double profit = inc.revenue - inc.expense; // рахуємо чистий прибуток

	// формуємо рядок для консолі
	os << "Revenue: " << inc.revenue << "\nExpense: " << inc.expense << "\nProfit: " << profit;

	return os;                                 // повертаємо потік для можливості ланцюжкового виводу
}