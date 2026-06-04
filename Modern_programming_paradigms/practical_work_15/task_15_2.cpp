#include <iostream>
#include <vector>
#include <string>

// шаблонна функція для виведення елементів вектора будь-якого типу
template <typename T>
void printVector(const std::vector<T>& v)
{
	for (const T& x : v)
	{
		std::cout << x << " ";
	}
	std::cout << "\n";
}

// головна функція програми
int main()
{
	std::vector<int> intVec = { 1, 2, 3 };                     // контейнер для зберігання цілих чисел
	std::vector<double> doubleVec = { 1.5, 2.7, 3.9 };         // контейнер для зберігання дробових чисел
	std::vector<std::string> stringVec = { "apple", "dog" };   // контейнер для зберігання рядків

	std::cout << "Vector of integers: ";
	printVector(intVec);                                       // виводимо масив на екран за допомогою шаблонної функції

	std::cout << "Vector of doubles: ";
	printVector(doubleVec);                                    // виводимо масив на екран за допомогою шаблонної функції

	std::cout << "Vector of strings: ";
	printVector(stringVec);                                    // виводимо масив на екран за допомогою шаблонної функції

	return 0;
}
