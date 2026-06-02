#include <iostream>
#include "User.h"
#include "Matrix.h"
#include "Income.h"
#include "BankAccount.h"

int main()
{
	std::cout << "TASK 1 (CLASS USER)";

	std::cout << "\n\nTotal users at start: " << User::getTotalUsers();

	// створення першого об'єкта (глобальний для main)
	std::cout << "\n\nCreating 1 user (global to main):";
	User admin("Petro", 2);
	std::cout << "\n\n" << admin.getUserInfo();

	std::cout << "\n\nTotal users after creating 1 user: " << User::getTotalUsers();

	{
		// локальна область видимості
		std::cout << "\n\nCreating 2 more users in the local scope:\n\n";

		User student1("Bohdan", 0);
		User student2("Artem", 1);

		std::cout << student1.getUserInfo();
		std::cout << "\n\n" << student2.getUserInfo();
		std::cout << "\n\nTotal users: " << User::getTotalUsers();
	}

	std::cout << "\n\nTotal users after scope exit: " << User::getTotalUsers();

	// тестування перевірки рівня доступу
	if (!admin.changeAccessLevel(5)) // спроба поставити неіснуючий рівень
	{
		std::cout << "\n\nError! Index out of bounds";
	}

	std::cout << "\n\nTASK 2 (CLASS MATRIX)";

	try
	{
		std::cout << "\n\nCreating Matrix A (2x2):\n";
		Matrix matA(2, 2);
		matA.input();

		std::cout << "\nCreating Matrix B (2x3):\n";
		Matrix matB(2, 3);
		matB.input();

		std::cout << "\nMatrix A:\n" << matA; // перевірка operator<<
		std::cout << "\nMatrix B:\n";
		matB.print(); // перевірка методу print()

		std::cout << "\nMultiplying A * B:\n";
		Matrix matC = matA * matB; // перевірка operator*
		std::cout << matC;
	}
	catch (const std::exception& e) // перехоплення помилок
	{
		std::cout << e.what();
	}

	std::cout << "\n\nTASK 3 (CLASS INCOME)";

	// створюємо фінансові звіти за два місяці
	std::cout << "\n\nIncome generation for April and May:";
	Income april(15000.50, 5000.00);
	Income may(18000.00, 6200.75);

	std::cout << "\n\nApril:\n" << april;
	std::cout << "\n\nMay:\n" << may;

	// тестуємо оператор +
	std::cout << "\n\nTesting operator+ (total for 2 months):\n";
	Income total = april + may;
	std::cout << total;

	// тестуємо оператор -
	std::cout << "\n\nTesting operator- (difference between May and April):\n";
	Income diff = may - april;
	std::cout << diff;

	// тестуємо оператор +=
	std::cout << "\n\nTesting operator+= (adding May to April):\n";
	april += may;
	std::cout << april;

	// тестуємо оператор -=
	std::cout << "\n\nTesting operator-= (subtracting May back from April):\n";
	april -= may;
	std::cout << april;

	std::cout << "\n\nTASK 4 (CLASS BANKACCOUNT)";

	// встановлюємо початкову відсоткову ставку
	BankAccount::setInterestRate(0.05);
	std::cout << "\n\nSetting global interest rate to 5% (0.05)";

	// створюємо кілька рахунків
	BankAccount acc1(1000.0);
	BankAccount acc2(5000.0);

	std::cout << "\n\nInitial balances:\n";
	std::cout << "Account 1: " << acc1.getBalance();
	std::cout << "\nAccount 2: " << acc2.getBalance();

	// застосовуємо відсотки
	acc1.applyInterest();
	acc2.applyInterest();

	std::cout << "\n\nBalances after applying 5% interest:\n";
	std::cout << "Account 1: " << acc1.getBalance();
	std::cout << "\nAccount 2: " << acc2.getBalance();

	// змінюємо ставку
	BankAccount::setInterestRate(0.10);
	std::cout << "\n\nSetting global interest rate to 10% (0.10)";

	// застосовуємо нову ставку
	acc1.applyInterest();
	acc2.applyInterest();

	std::cout << "\n\nBalances after applying new 10% interest:\n";
	std::cout << "Account 1: " << acc1.getBalance() << "\n";
	std::cout << "Account 2: " << acc2.getBalance() << "\n";

	return 0;
}