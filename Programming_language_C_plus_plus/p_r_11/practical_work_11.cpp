#include <iostream>           // підключення бібліотеки для роботи з консоллю
#include <string>             // підключення бібліотеки для роботи з текстом
#include <limits>             // підключення бібліотеки для отримання максимальних/мінімальних значень типів даних
#include <stdexcept>          // підключення бібліотеки для роботи із винятками
#include <type_traits>        // підключення бібліотеки для перевірки типів даних
#include <iomanip>            // підключення бібліотеки для форматованого виведення на екран

// шаблонна функція для безпечного введення числа з перевіркою меж та типу
template <typename T>
T inputNum(const std::string& text, T minNum = std::numeric_limits<T>::lowest(), T maxNum = std::numeric_limits<T>::max())
{
	T num;                                          // змінна для збереження введеного числа
	std::string inputStr;                           // змінна для зберігання введеного рядка тексту

	std::cout << text;                              // виведення повідомлення про введення

	while (true)                                    // нескінченний цикл для перевірки правильності введення
	{
		getline(std::cin, inputStr);                // зчитуємо весь введений рядок з консолі

		try                                         // блок для перехоплення можливих помилок під час перетворення
		{
			size_t pos;                             // змінна для збереження індексу першого символу у рядку, який не є числом

			if constexpr (std::is_same_v<T, int>)   // якщо поточний шаблонний тип це int
			{
				num = std::stoi(inputStr, &pos);    // конвертуємо рядок у тип int та записуємо позицію зупинки
			}
			else                                    // якщо поточний шаблонний тип це double
			{
				num = std::stod(inputStr, &pos);    // конвертуємо рядок у тип double та записуємо позицію зупинки
			}

			if (pos < inputStr.length())            // якщо оброблено не весь рядок (введено літери чи зайві символи)
			{
				throw std::invalid_argument("Zayvi symvoly");
			}
			if (num < minNum)                       // якщо введене число менше за мінімально допустиму межу
			{
				throw std::logic_error("\nPomylka! Dozvolene minimalne znachennya: " + std::to_string(minNum) + "\nSprobuyte znovu: ");
			}
			if (num > maxNum)                       // якщо введене число більше за максимально допустиму межу
			{
				throw std::logic_error("\nPomylka! Dozvolene maksymalne znachennya: " + std::to_string(maxNum) + "\nSprobuyte znovu: ");
			}

			return num;                             // повертаємо коректно введене число та виходимо з функції
		}
		catch (const std::invalid_argument&)        // перехоплюємо виняток некоректного введення
		{
			if constexpr (std::is_same_v<T, int>)   // якщо очікувався тип int
			{
				std::cout << "\nPomylka! Potribno vvesty chyslo typu int\nSprobuyte znovu: ";
			}
			else                                    // якщо очікувався тип double
			{
				std::cout << "\nPomylka! Potribno vvesty chyslo typu double\nSprobuyte znovu: ";
			}
		}
		catch (const std::logic_error& e)           // перехоплюємо виняток виходу за встановлені межі
		{
			std::cout << e.what();                  // виводимо повідомлення згенероване під час кидання винятку
		}
		catch (const std::out_of_range&)            // перехоплюємо виняток переповнення типу даних
		{
			if constexpr (std::is_same_v<T, int>)   // якщо працюємо з int
			{
				std::cout << "\nPomylka! Perevyshcheno rozmir typu int\nSprobuyte znovu: ";
			}
			else                                    // якщо працюємо з double
			{
				std::cout << "\nPomylka! Perevyshcheno rozmir typu double\nSprobuyte znovu: ";
			}
		}
	}
}

// шаблонна функція для обчислення середнього арифметичного елементів масиву
template <typename T>
double arithmeticMean(int size, T arr[])
{
	double sum = 0;                      // змінна для накопичення суми елементів масиву

	for (int i = 0; i < size; i++)       // цикл для проходження по всіх елементах масиву
	{
		sum += arr[i];                   // додаємо значення поточного елемента до загальної суми
	}

	return sum / size;                   // повертаємо результат ділення суми на кількість елементів
}

// головна функція програми
int main()
{
	// введення розміру першого масиву типу int з обмеженням від 1 до 50
	int size1 = inputNum<int>("Vvedit rozmir dlya masyvu typu int: ", 1, 50);

	int* arr1 = new int[size1];                            // динамічно виділяємо пам'ять під масив цілих чисел

	// введення елементів масиву типу int
	std::cout << "\nVvedit masyv typu int z " << size1 << " elementiv:\n";
	for (int i = 0; i < size1; i++)
	{
		std::string text = "  arr1[" + std::to_string(i + 1) + "] = ";
		arr1[i] = inputNum<int>(text);
	}

	double result1 = arithmeticMean(size1, arr1);          // обчислюємо середнє арифметичне для масиву int

	// виведення результатів
	std::cout << "\nSerednye aryfmetychne elementiv pershoho masyvu = " << std::fixed << std::setprecision(2) << result1 << std::endl;

	delete[] arr1;                                         // звільняємо динамічну пам'ять, виділену під перший масив

	// введення розміру другого масиву типу double з обмеженням від 1 до 50
	int size2 = inputNum<int>("\nVvedit rozmir dlya masyvu typu double: ", 1, 50);

	double* arr2 = new double[size2];                      // динамічно виділяємо пам'ять під масив дійсних чисел

	// введення елементів масиву типу double
	std::cout << "\nVvedit masyv typu double z " << size2 << " elementiv:\n";
	for (int i = 0; i < size2; i++)
	{
		std::string text = "  arr2[" + std::to_string(i + 1) + "] = ";
		arr2[i] = inputNum<double>(text);
	}

	double result2 = arithmeticMean(size2, arr2);          // обчислюємо середнє арифметичне для масиву double

	// виведення результатів
	std::cout << "\nSerednye aryfmetychne elementiv druhoho masyvu = " << std::fixed << std::setprecision(2) << result2 << std::endl;

	delete[] arr2;                                         // звільняємо динамічну пам'ять, виділену під другий масив

	return 0;                                              // завершення програми
}
