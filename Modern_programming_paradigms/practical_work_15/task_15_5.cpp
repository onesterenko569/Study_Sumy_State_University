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
	std::vector<int> numbers = { 10, 20, 30 };                 // початковий контейнер для зберігання цілих чисел

	std::cout << "Initial vector elements: ";
	printVector(numbers);                                      // виводимо початковий масив на екран

	int pos;                                                   // змінна для збереження введеної позиції
	int val;                                                   // змінна для збереження введеного значення

	std::cout << "Enter position and value to insert: ";
	std::cin >> pos >> val;

	// перевірка, чи введена позиція є коректною
	if (pos >= 0 && pos <= numbers.size())
	{
		numbers.insert(numbers.begin() + pos, val);            // вставка елемента

		std::cout << "Updated vector elements: ";
		printVector(numbers);                                  // виводимо оновлений масив на екран
	}
	else
	{
		std::cout << "Error! Invalid position\n";             // виводимо повідомлення про помилку
	}

	return 0;
}
