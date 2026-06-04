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

// шаблонна функція для пошуку елемента за значенням
template <typename T>
int findElement(const std::vector<T>& v, const T& target)
{
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] == target)
		{
			return i;                                              // повертаємо індекс, якщо елемент знайдено
		}
	}
	return -1;                                                     // повертаємо -1, якщо елемент не знайдено
}

// головна функція програми
int main()
{
	std::vector<int> numbers = { 12, 45, 78, 23, 56, 89 };         // початковий контейнер для зберігання цілих чисел

	std::cout << "Vector elements: ";
	printVector(numbers);                                          // виводимо масив на екран

	int targetValue;                                               // змінна для значення, яке потрібно знайти
	std::cout << "Enter a value to search for: ";
	std::cin >> targetValue;

	// викликаємо функцію пошуку та зберігаємо результат
	int index = findElement(numbers, targetValue);

	// перевіряємо результат пошуку та виводимо відповідне повідомлення
	if (index != -1)
	{
		std::cout << "Value " << targetValue << " found at index: " << index << "\n";
	}
	else
	{
		std::cout << "Value " << targetValue << " not found in the vector\n";
	}

	return 0;
}
