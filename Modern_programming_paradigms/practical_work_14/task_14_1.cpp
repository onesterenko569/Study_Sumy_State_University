#include <iostream>
#include <string>

// шаблонна функція для знаходження максимального з двох значень
template <typename T>
T maxValue(T a, T b)
{
	return (a > b) ? a : b;                                    // повертаємо більше значення
}

// головна функція програми
int main()
{
	// тестування для типу int
	int int1 = 3;                                              // перше ціле число
	int int2 = 12;                                             // друге ціле число

	std::cout << "Testing with int:";
	std::cout << "\nValue 1: " << int1 << "\nValue 2: " << int2;
	std::cout << "\nMax value: " << maxValue(int1, int2);

	// тестування для типу double
	double dbl1 = 1.83;                                        // перше дробове число
	double dbl2 = 5.39;                                        // друге дробове число

	std::cout << "\n\nTesting with double:";
	std::cout << "\nValue 1: " << dbl1 << "\nValue 2: " << dbl2;
	std::cout << "\nMax value: " << maxValue(dbl1, dbl2);

	// тестування для типу char
	char ch1 = 'A';                                            // перший символ
	char ch2 = 'C';                                            // другий символ

	std::cout << "\n\nTesting with char:\n";
	std::cout << "Value 1: '" << ch1 << "'\nValue 2: '" << ch2 << "'";
	std::cout << "\nMax value: '" << maxValue(ch1, ch2) << "'";

	// тестування для типу std::string
	std::string str1 = "cat";                                  // перший рядок
	std::string str2 = "dog";                                  // другий рядок

	std::cout << "\n\nTesting with std::string:";
	std::cout << "\nValue 1: \"" << str1 << "\"\nValue 2: \"" << str2 << "\"";
	std::cout << "\nMax value: \"" << maxValue(str1, str2) << "\"\n";

	return 0;
}