#include <iostream>
#include <string>

// шаблонна функція для знаходження максимального значення серед різних типів
template <typename T1, typename T2>
auto maxValue(T1 a, T2 b)
{
	return (a > b) ? a : b;                                    // повертаємо більше значення
}

// головна функція програми
int main()
{
	// тестування для типу int та double
	int val1 = 3;                                              // перше ціле число
	double val2 = 5.39;                                        // друге дробове число

	std::cout << "Testing with int and double:";
	std::cout << "\nValue 1 (int): " << val1 << "\nValue 2 (double): " << val2;
	std::cout << "\nMax value: " << maxValue(val1, val2);

	// тестування для типу double та int
	double val3 = 12.5;                                        // перше дробове число
	int val4 = 40;                                              // друге ціле число

	std::cout << "\n\nTesting with double and int:";
	std::cout << "\nValue 1 (double): " << val3 << "\nValue 2 (int): " << val4;
	std::cout << "\nMax value: " << maxValue(val3, val4);

	// тестування для типу char та int
	char val5 = 'M';                                           // символ
	int val6 = 70;                                             // ціле число

	std::cout << "\n\nTesting with char and int:\n";
	std::cout << "Value 1 (char): '" << val5 << "'\nValue 2 (int): " << val6;
	std::cout << "\nMax value: " << maxValue(val5, val6) << "\n";

	return 0;
}
