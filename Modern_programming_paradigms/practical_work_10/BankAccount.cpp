#include "BankAccount.h"

// ініціалізація статичної змінної (спільна ставка для всіх рахунків банку)
double BankAccount::interestRate = 0.0;

// реалізація конструктора
BankAccount::BankAccount(double initialBalance) : balance(initialBalance) {}

// реалізація статичного методу зміни ставки
void BankAccount::setInterestRate(double newRate)
{
	interestRate = newRate;
}

// реалізація методу нарахування відсотків
void BankAccount::applyInterest()
{
	// додаємо відсотки до балансу
	balance += balance * interestRate;
}

// реалізація константного методу для повернення балансу
double BankAccount::getBalance() const
{
	return balance;
}