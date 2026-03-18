#include <iostream>   // бібліотека для введення та виведення даних
#include <string>     // бібліотека для роботи з рядками
#include <stdexcept>  // бібліотека для роботи з винятками
#include <cmath>      // математична бібліотека

double inputNumber()  // функція для введення числа з перевіркою чи введене число
{
	std::string inputStr;                      // змінна для збереження тексту, який вводить користувач
	double num;                                // змінна для збереження перетвореного числа

	while (true)                               // цикл який триватиме поки користувач не введе коректне число
	{
		std::getline(std::cin, inputStr);      // введення рядка в inputStr
		    
		try                                    // спробуємо виконати наступний блок коду   
		{  
			size_t pos;                        // змінна для збереження індексу першого символу що не є частиною числа

			num = std::stod(inputStr, &pos);   // перетворюємо рядок на число

			if (pos < inputStr.length())       // якщо окрім числа ще є інші символи
			{
				throw std::invalid_argument("Extra characters"); // кидаємо виняток
			}

			return num;                        // якщо число введено правильно, повертаємо його та завершуємо цикл
		}

		catch (const std::invalid_argument& e) // перехоплення помилки
		{
			std::cout << "\nError! The entered number is not a number\nTry again: "; // виведення повідомлення про помилку
		}
	}
}

int main() // головна функція програми
{
	// введення першого числа
	std::cout << "Enter the first number: ";
	double firstNumber = inputNumber();

	// введення другого числа
	std::cout << "\nEnter the second number: ";
	double secondNumber = inputNumber();

	// обрахування суми чисел та виведення результату
	double sum = firstNumber + secondNumber;
	std::cout << "\nSum of numbers: " << firstNumber << " + " << secondNumber << " = " << sum;

	// обрахування різниці чисел та виведення результату
	double diff = firstNumber - secondNumber;
	std::cout << "\nDifference of numbers: " << firstNumber << " - " << secondNumber << " = " << diff;

	// обрахування добутку чисел та виведення результату
	double prod = firstNumber * secondNumber;
	std::cout << "\nProduct of numbers: " << firstNumber << " * " << secondNumber << " = " << prod;

	// перевірка можливості обрахування ділення чисел та виведення результату якщо ділення можливе
	if (std::abs(secondNumber) < 1e-9)                      // якщо ділення не можливе
	{
		std::cout << "\nDivision error! Second number = 0"; // виведення повідомлення про помилку
	}
	else                                                    // якщо ділення можливе
	{
		double div = firstNumber / secondNumber;            // обрахування результату ділення чисел
		std::cout << "\nDivision of numbers: " << firstNumber << " / " << secondNumber << " = " << div; // виведення результатів
	}

	return 0; // завершення програми
}