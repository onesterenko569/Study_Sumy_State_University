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
	int n;                                                     // кількість елементів
	std::cout << "\n\nEnter the number of elements (N): ";
	std::cin >> n;

	std::vector<int> numbers;                                  // контейнер для зберігання цілих чисел

	std::cout << "Enter " << n << " integers:\n";
	for (int i = 0; i < n; ++i)
	{
		int val;                                               // змінна для тимчасового збереження введеного числа
		std::cout << "Element " << (i + 1) << ": ";
		std::cin >> val;
		numbers.push_back(val);                                // додаємо число у кінець вектора
	}

	std::cout << "\nVector elements: ";
	printVector(numbers);                                      // виводимо масив на екран за допомогою шаблонної функції

	return 0;
}
