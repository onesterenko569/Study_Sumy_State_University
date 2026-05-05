#include <iostream>
#include <string>
#include <stdexcept>

// функція для обчислення статистики масиву з використанням посилань
void calculateStatistics(double arr[], int size, double& sumNegatives, double& sumPositive, int& numberZeros, bool& hasNegative, bool& hasPositive)
{
	sumNegatives = 0;                                         // обнуляємо суму від'ємних елементів
	sumPositive = 0;                                          // обнуляємо суму позитивних елементів
	numberZeros = 0;                                          // обнуляємо лічильник нулів
	hasNegative = false;                                      // початкове значення: від'ємних немає
	hasPositive = false;                                      // початкове значення: позитивних немає

	for (int i = 0; i < size; i++)                            // проходимо по всьому масиву
	{
		if (arr[i] < 0)                                       // якщо поточний елемент від'ємний
		{
			sumNegatives += arr[i];                           // додаємо його до суми від'ємних
			hasNegative = true;                               // відмічаємо що від'ємні елементи є
		}
		else if (arr[i] > 0)                                  // якщо поточний елемент позитивний
		{
			sumPositive += arr[i];                            // додаємо його до суми позитивних
			hasPositive = true;                               // відмічаємо що позитивні елементи є
		}
		else                                                  // якщо елемент дорівнює нулю
		{
			numberZeros++;                                    // збільшуємо лічильник нулів
		}
	}
}

// головна функція програми
int main()
{
	int n;                                                    // змінна для збереження розміру масиву
	std::string inputStr;                                     // змінна для зберігання введеного рядка тексту

	std::cout << "Enter the array size: ";

	while (true)                                              // нескінченний цикл для перевірки правильності введення розміру
	{
		std::getline(std::cin, inputStr);                     // зчитуємо весь введений рядок з консолі

		try                                                   // блок для перехоплення можливих помилок
		{
			size_t pos;                                       // змінна для збереження позиції після конвертації

			n = std::stoi(inputStr, &pos);                    // конвертуємо рядок у тип int

			if (pos < inputStr.length())                      // якщо оброблено не весь рядок (є зайві символи)
			{
				throw (std::invalid_argument(""));            // генеруємо виключення неправильного аргументу
			}
			if (n < 1)                                        // якщо введене число менше за 1
			{
				throw (std::logic_error("\nError! Array size must be greater than 0\nTry again: "));
			}
			if (n > 50)                                       // якщо введене число більше за 50
			{
				throw (std::logic_error("\nError! Array size must be less than 50\nTry again: "));
			}

			break;                                            // якщо введення правильне, виходимо з циклу
		}
		catch (const std::invalid_argument)                   // перехоплюємо помилку неправильного формату введення
		{
			std::cout << "\nError! You must enter an integer\nTry again: ";
		}
		catch (const std::logic_error& e)                     // перехоплюємо помилку виходу за допустимі межі
		{
			std::cout << e.what();
		}
		catch (const std::out_of_range)                       // перехоплюємо переповнення типу int
		{
			std::cout << "\nError! Int type size exceeded\nTry again: ";
		}
	}

	double* arr = new double[n];                              // динамічно виділяємо пам'ять під масив

	std::cout << "\nInputting an array of " << n << " elements:\n";

	for (int i = 0; i < n; i++)                               // цикл для введення елементів масиву
	{
		std::cout << "  arr[" << i << "] = ";

		while (true)                                          // нескінченний цикл для перевірки введення кожного елемента
		{
			std::getline(std::cin, inputStr);                 // зчитуємо рядок з консолі

			try
			{
				size_t pos;                                   // змінна для збереження позиції після конвертації

				arr[i] = std::stod(inputStr, &pos);           // конвертуємо рядок у тип double

				if (pos < inputStr.length())                  // якщо оброблено не весь рядок
				{
					throw (std::invalid_argument(""));        // генеруємо виключення неправильного аргументу
				}

				break;                                        // якщо число коректне, виходимо з циклу
			}
			catch (const std::invalid_argument)               // перехоплюємо введення тексту замість числа
			{
				std::cout << "  Error! Please enter a valid number\n  Try again: ";
			}
			catch (const std::out_of_range)                   // перехоплюємо переповнення типу double
			{
				std::cout << "  Error! Double type size exceeded\n  Try again: ";
			}
		}
	}

	int numberZ;                                              // змінна для зберігання кількості нулів
	double sumN, sumP;                                        // змінні для зберігання сум від'ємних та позитивних елементів
	bool hasN, hasP;                                          // прапорці для перевірки наявності від'ємних і позитивних елементів

	calculateStatistics(arr, n, sumN, sumP, numberZ, hasN, hasP); // виклик функції з передачею параметрів за посиланням
	delete[] arr;                                             // звільняємо динамічно виділену пам'ять

	if (hasN)                                                 // якщо масив містить від'ємні елементи
	{
		std::cout << "\nSum of negative elements: " << sumN;
	}
	else                                                      // якщо від'ємних елементів немає
	{
		std::cout << "\nThere are no negative elements in the array";
	}

	if (hasP)                                                 // якщо масив містить позитивні елементи
	{
		std::cout << "\nSum of positive elements: " << sumP;
	}
	else                                                      // якщо позитивних елементів немає
	{
		std::cout << "\nThere are no positive elements in the array";
	}

	if (numberZ == 0)                                         // якщо нульових елементів немає
	{
		std::cout << "\nThere are no null elements in the array" << std::endl;
	}
	else                                                      // якщо нульові елементи є
	{
		std::cout << "\nNumber of zero elements: " << numberZ << std::endl;
	}

	return 0;                                                 // успішне завершення програми
}
