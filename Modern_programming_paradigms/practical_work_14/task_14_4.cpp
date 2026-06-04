#include <iostream>
#include <string>
#include <type_traits>
#include <utility>

using namespace std::string_literals;

// шаблонний клас для зберігання пари значень
template <typename T1, typename T2>
class Pair
{
private:
	T1 first;                                                  // перше значення
	T2 second;                                                 // друге значення

public:
	// конструктор з параметрами для ініціалізації
	Pair(T1 f, T2 s) : first(f), second(s) {}

	// константний метод для отримання першого елемента
	const T1& getFirst() const
	{
		return first;
	}

	// константний метод для отримання другого елемента
	const T2& getSecond() const
	{
		return second;
	}

	// метод для обміну значень місцями
	void swap()
	{
		// перевірка на етапі компіляції щоб типи були однаковими
		static_assert(std::is_same_v<T1, T2>, "Error! swap() is available only when T1 and T2 are the same type");

		std::swap(first, second);
	}

	// метод для виведення пари
	void print() const;
};

// загальна реалізація методу виведення для будь-яких типів
template <typename T1, typename T2>
void Pair<T1, T2>::print() const
{
	std::cout << first << ", " << second << "\n";
}

// явна спеціалізація методу print() для типу Pair<std::string, std::string>
template <>
void Pair<std::string, std::string>::print() const
{
	std::cout << "\"" << first << "\": \"" << second << "\"\n";
}

// явна спеціалізація методу print() для типу Pair<int, int>
template <>
void Pair<int, int>::print() const
{
	std::cout << first << " + " << second << " = " << (first + second) << "\n";
	std::cout << first << " * " << second << " = " << (first * second) << "\n";
}

// шаблонна функція-фабрика для зручного створення об'єктів Pair без явного вказування типів
template <typename T1, typename T2>
Pair<T1, T2> makePair(T1 a, T2 b)
{
	return Pair<T1, T2>(a, b);
}

// головна функція програми
int main()
{
	// тестування явної спеціалізації для std::string та std::string
	auto words = makePair("hello"s, "world"s);

	std::cout << "Testing explicit specialization for std::string:\n";
	std::cout << "Pair 1: ";
	words.print();

	// тестування явної спеціалізації для int та int
	auto nums = makePair(4, 7);                                // пара цілих чисел

	std::cout << "\nTesting explicit specialization for int:\n";
	std::cout << "Pair 2:\n";
	nums.print();

	// тестування загального шаблону для інших типів
	auto values = makePair(5.37, 3.15);                        // пара дробових чисел

	std::cout << "\nTesting general template for double:\n";
	std::cout << "Pair 3: ";
	values.print();

	return 0;
}
