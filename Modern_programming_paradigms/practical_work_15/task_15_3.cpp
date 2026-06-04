#include <iostream>
#include <vector>

// головна функція програми
int main()
{
	std::vector<int> numbers = { 15, 25, 35 };                 // контейнер для зберігання цілих чисел

	if (numbers.empty())                                       // перевірка, чи порожній контейнер
	{
		std::cout << "Container is empty\n";                   // виведення повідомлення про порожній контейнер
	}
	else
	{
		std::cout << "Size: " << numbers.size() << "\n";       // кількість елементів
		std::cout << "Capacity: " << numbers.capacity() << "\n";   // поточна місткість
		std::cout << "First element: " << numbers.front() << "\n"; // перший елемент
		std::cout << "Last element: " << numbers.back() << "\n";   // останній елемент
	}

	return 0;
}
