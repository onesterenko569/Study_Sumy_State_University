#pragma once

#include <iostream>

// клас для роботи з банківськими рахунками
class BankAccount
{
private:                                       // закриті дані класу
	double balance;                            // змінна для зберігання балансу рахунку

	static double interestRate;                // статична змінна для зберігання відсоткової ставки

public:                                        // відкриті методи класу
	// конструктор з параметрами
	BankAccount(double initialBalance);

	// статичний метод для встановлення відсоткової ставки для всіх рахунків
	static void setInterestRate(double newRate);

	// метод для нарахування відсотків на поточний баланс
	void applyInterest();

	// константний метод для отримання поточного балансу
	double getBalance() const;
};