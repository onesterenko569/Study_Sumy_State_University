#include <iostream>
#include <string>   // підключення бібліотек
#include <cmath>
#include <vector>

#define MAX_NUMBER_ROWS 10 // максимальна кількість рядків
#define MAX_LENGTH_ROW 100 // максимальна кількість елементів у одному рядку

int main()                                 // головна функція програми
{
	std::string inputStr;  int N;          // оголошення змінних типу string

	std::cout << "Vvedit kilkist ryadkiv: ";
	while (true)                           // цикл для введення кількості рядків
	{
		std::getline(std::cin, inputStr);  // зчитуємо весь рядок повністю

		try                                // спробуємо виконати наступний блок коду
		{
			size_t pos;                    // змінна для збереження індексу першого символу у рядку, який не є числом

			N = std::stoi(inputStr, &pos); // перетворюємо у цілий тип

			if (pos < inputStr.length())   // якщо є зайві символи
			{
				throw std::invalid_argument("Zayvi symvoly");
			}
			if (N < 1)                     // якщо кількість рядків менша за 1
			{
				throw std::out_of_range("\nPomylka! Dlya vykonannya prohramy neobkhidnyy minimum 1 ryadok\nSprobuyte znovu: ");
			}
			if (N > MAX_NUMBER_ROWS)      // якщо кількість рядків перевищує макс обмеження
			{
				throw std::out_of_range("\nPomylka! Perevyshcheno maksymalnu kilkist ryadkiv (" + std::to_string(MAX_NUMBER_ROWS) + ")\nSprobuyte znovu: ");
			}

			// після того як усі перевірки успішно пройдено
			std::cout << "\nKilkist ryadkiv uspishno vvedeno!" << std::endl;
			break;
		}

		catch (const std::invalid_argument& e) // якщо введено щось окрім числа
		{
			std::cout << "\nPomylka! Potribno vvesty tsile chyslo\nSprobuyte znovu: ";
		}
		catch (const std::out_of_range& e) // якщо N < 1 або N > 10
		{
			std::cout << e.what();
		}
	}

	std::vector<std::string> arr(N);       // динамічне виділення пам'яті

	for (int i = 0; i < N; i++)            // цикл для введення рядків
	{
		std::cout << "\nVvedit " << i + 1 << " ryadok:" << std::endl;

		while (true)                       // цикл для перевірки правильності введення
		{
			std::getline(std::cin, arr[i]);// вводимо рядок

			if (arr[i].empty())            // якщо користувач нічого не ввів
			{
				std::cout << "\nVvedeno pustyy ryadok! Sprobuyte znovu:" << std::endl;
			}
			else if (arr[i].length() > MAX_LENGTH_ROW) // якщо перевищено максимальну кількість символів
			{
				std::cout << "\nPerevyshcheno limit u " << MAX_LENGTH_ROW << " symvoliv! Sprobuyte znovu:" << std::endl;
			}
			else                           // якщо всі перевірки успішно пройдені
			{
				break;                     // зупинка циклу
			}
		}
	}

	std::cout << "\nRyadky uspishno vvedeno!" << std::endl;

	int sum = 0;                           // змінна для обчислення суми довжин всіх рядків

	for (int i = 0; i < N; i++)            // цикл для обчислення суми довжин всіх рядків
	{
		sum += arr[i].length();
	}

	float averageLength = float(sum) / N;  // знаходження середньої довжини рядків

	// виведення результатів
	std::cout << "\nSerednya dovzhyna ryadkiv: " << averageLength << std::endl;

	float target = averageLength + 2;      // середня довжина + 2 символи
	float minDifference = std::fabs(target - float(arr[0].length())); // початкова мінімальна різниця між target та рядками
	int minIndex = 0;                      // початковий індекс рядка з мінімальною різницею від target

	for (int i = 1; i < N; i++)            // цикл для пошуку рядка, довжина якого найближча до значення (середня довжина + 2 символи) 
	{
		float temp = std::fabs(target - float(arr[i].length())); // обчислення різниці між target та рядком

		if (temp < minDifference)          // якщо обчислена різниця менша за minDifference
		{
			minDifference = temp;          // оновлюємо minDifference
			minIndex = i;                  // зберігаємо індекс рядка
		}
	}

	// виведення результатів
	std::cout << "Dovzhyna " << minIndex + 1 << " ryadka nayblyzhcha do znachennya (serednya dovzhyna + 2 symvoly = " << target << ")" << std::endl;
	std::cout << "Ryadok: " << arr[minIndex] << std::endl;
	std::cout << "Dovzhyna ryadka: " << arr[minIndex].length() << std::endl;

	return 0;
}