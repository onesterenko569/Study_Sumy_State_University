#include <iostream>
#include <vector>

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
	std::vector<int> numbers = { 15, 25, 35 };                 // початковий контейнер для зберігання цілих чисел

	std::cout << "Initial vector elements: ";
	printVector(numbers);                                      // виводимо початковий масив на екран

	int newValue;                                              // змінна для збереження введеного числа
	std::cout << "Enter a number to add to the end: ";
	std::cin >> newValue;

	numbers.push_back(newValue);                               // додаємо новий елемент у кінець контейнера

	std::cout << "Updated vector elements: ";
	printVector(numbers);                                      // виводимо оновлений масив на екран

	return 0;
}
