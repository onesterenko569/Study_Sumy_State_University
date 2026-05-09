#include <iostream>
#include <string>
#include <iomanip>

// клас для зберігання інформації про гаманець
class Wallet
{
	friend class Bank;                                     // оголошення дружнього класу

private:
	std::string userID;                                    // змінна для зберігання ID користувача
	double balance;                                        // змінна для зберігання балансу

public:
	// конструктор для ініціалізації полів гаманця
	Wallet(const std::string& ID, const double b) : userID(ID), balance(b) {}
};

// клас для виконання банківських операцій
class Bank
{
private:
	const int maxBalance = 1000000;                        // константа максимального ліміту балансу

public:
	// метод для виведення балансу
	void printBalance(const Wallet& w)
	{
		std::cout << "\nBalance: " << w.balance << " UAH";
	}

	// метод для поповнення балансу гаманця
	bool addBalance(Wallet& w, double amount)
	{
		if (w.balance + amount <= maxBalance)              // перевіряємо чи не перевищить сума ліміт
		{
			w.balance += amount;                           // додаємо кошти на баланс
			return true;
		}

		return false;
	}

	// метод для зняття коштів з гаманця
	bool reduceBalance(Wallet& w, double amount)
	{
		if (w.balance - amount >= 0)                       // перевіряємо чи достатньо коштів для зняття
		{
			w.balance -= amount;                           // знімаємо кошти з балансу
			return true;
		}

		return false;
	}
};

// функція для виведення головного меню програми
void printMenu()
{
	std::cout << "\n\nPROGRAM MENU";
	std::cout << "\n  1 - display information about the current balance";
	std::cout << "\n  2 - put money on the balance";
	std::cout << "\n  3 - take money from the balance";
	std::cout << "\n  0 - end the program";
	std::cout << "\n\nYour choice: ";
}

// функція для безпечного введення цілого числа
int inputInt(int minVal, int maxVal)
{
	int val;
	std::string inputStr;

	while (true)                                           // нескінченний цикл для перевірки введення
	{
		std::getline(std::cin, inputStr);

		try
		{
			size_t pos;
			val = stoi(inputStr, &pos);                    // перетворення на int

			if (pos < inputStr.length())                   // якщо введено зайві символи
			{
				throw (std::invalid_argument(""));
			}

			if (val < minVal)                              // якщо число менше допустимого
			{
				throw std::logic_error("\nError! The minimum allowed value is " + std::to_string(minVal) + "\nTry again: ");
			}

			if (val > maxVal)                              // якщо число більше допустимого
			{
				throw std::logic_error("\nError! The maximum allowed value is " + std::to_string(maxVal) + "\nTry again: ");
			}

			return val;                                    // повертаємо коректне число
		}
		catch (const std::invalid_argument)                // перехоплюємо помилку неправильного формату
		{
			std::cerr << "\nError! You must enter an integer\nTry again: ";
		}
		catch (const std::logic_error& e)                  // перехоплюємо помилку виходу за межі
		{
			std::cerr << e.what();
		}
		catch (const std::out_of_range)                    // перехоплюємо переповнення типу
		{
			std::cerr << "\nError! Int data type size exceeded\nTry again: ";
		}
	}
}

// функція для безпечного введення дробового числа
double inputDouble(double minVal, double maxVal)
{
	double val;
	std::string inputStr;

	while (true)                                           // нескінченний цикл для перевірки введення
	{
		std::getline(std::cin, inputStr);

		try
		{
			size_t pos;
			val = stod(inputStr, &pos);                    // перетворення на double

			if (pos < inputStr.length())                   // якщо введено зайві символи
			{
				throw (std::invalid_argument(""));
			}

			if (val < minVal)                              // якщо число менше допустимого
			{
				throw std::logic_error("\nError! The minimum allowed value is " + std::to_string((int)minVal) + "\nTry again: ");
			}

			if (val > maxVal)                              // якщо число більше допустимого
			{
				throw std::logic_error("\nError! The maximum allowed value is " + std::to_string((int)maxVal) + "\nTry again: ");
			}

			return val;                                    // повертаємо коректне число
		}
		catch (const std::invalid_argument)                // перехоплюємо помилку неправильного формату
		{
			std::cerr << "\nError! You must enter a valid number\nTry again: ";
		}
		catch (const std::logic_error& e)                  // перехоплюємо помилку виходу за межі
		{
			std::cerr << e.what();
		}
		catch (const std::out_of_range)                    // перехоплюємо переповнення типу
		{
			std::cerr << "\nError! Double data type size exceeded\nTry again: ";
		}
	}
}

// головна функція програми
int main()
{
	Wallet wallet("U-001", 10000);                         // створюємо об'єкт гаманця
	Bank bank;                                             // створюємо об'єкт банку

	bool running = true;                                   // прапорець для керування циклом

	while (running)                                        // головний цикл програми
	{
		printMenu();                                       // друкуємо меню

		int userChoice = inputInt(0, 3);                   // безпечно зчитуємо вибір користувача

		switch (userChoice)                                // обробка вибору користувача
		{
		case 1:                                            // інформація про поточний баланс
		{
			bank.printBalance(wallet);
			break;
		}
		case 2:                                            // поповнення балансу
		{
			std::cout << "\nEnter the amount in UAH: ";
			double amount = inputDouble(1, 1000000);

			if (bank.addBalance(wallet, amount))           // перевірка успішності поповнення
			{
				std::cout << "\nBalance successfully topped up!";
			}
			else
			{
				std::cout << "\nBalance limit of UAH 1 000 000 exceeded!";
			}
			break;
		}
		case 3:                                            // зняття грошей з балансу
		{
			std::cout << "\nEnter the amount in UAH: ";
			double amount = inputDouble(1, 1000000);

			if (bank.reduceBalance(wallet, amount))        // перевірка успішності зняття
			{
				std::cout << "\nMoney successfully withdrawn!";
			}
			else
			{
				std::cout << "\nNot enough funds!";
			}
			break;
		}
		default:                                           // вихід з програми
		{
			std::cout << "\nGoodbye!" << std::endl;
			running = false;
		}
		}
	}

	return 0;
}
