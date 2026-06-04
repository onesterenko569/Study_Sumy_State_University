#include <iostream>
#include <vector>

// головна функція програми
int main()
{
	std::vector<int> numbers = { 10, 20, 30, 40, 50 };         // контейнер для зберігання цілих чисел

	std::cout << "Forward order: ";
	// проходження вектора у прямому порядку за допомогою ітераторів
	for (auto it = numbers.begin(); it != numbers.end(); ++it)
	{
		std::cout << *it << " ";                               // виведення значення за ітератором
	}

	std::cout << "\nReverse order: ";
	// проходження вектора у зворотному порядку за допомогою реверсивних ітераторів
	for (auto it = numbers.rbegin(); it != numbers.rend(); ++it)
	{
		std::cout << *it << " ";                               // виведення значення за ітератором
	}
	std::cout << "\n";

	return 0;
}
