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
	std::vector<int> numbers = { 10, 20, 30, 40, 50, 60 };     // початковий контейнер для зберігання цілих чисел

	std::cout << "Initial vector elements: ";
	printVector(numbers);                                      // виводимо початковий масив на екран

	int first;                                                 // змінна для початкового індексу видалення
	int last;                                                  // змінна для кінцевого індексу видалення

	std::cout << "Enter first and last indices to erase: ";
	std::cin >> first >> last;

	// перевірка, чи введені індекси утворюють правильний діапазон у межах вектора
	if (first >= 0 && last <= numbers.size() && first <= last)
	{
		// видаляємо діапазон елементів за допомогою ітераторів
		numbers.erase(numbers.begin() + first, numbers.begin() + last);

		std::cout << "Updated vector elements: ";
		printVector(numbers);                                  // виводимо оновлений масив на екран
	}
	else
	{
		std::cout << "Error! Invalid range\n";                // виводимо повідомлення про помилку
	}

	return 0;
}
