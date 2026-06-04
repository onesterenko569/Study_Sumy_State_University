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

// реалізація методу виведення для будь-яких типів
template <typename T1, typename T2>
void Pair<T1, T2>::print() const
{
	std::cout << first << ", " << second << "\n";
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
	// тестування з типами int та string
	auto p1 = makePair(42, "answer"s);

	std::cout << "Testing with int and std::string:";
	std::cout << "\nPair 1: ";
	p1.print();

	// тестування з дробовими числами double та double
	auto p2 = makePair(5.18, 3.15);

	std::cout << "\nTesting with double and double:";
	std::cout << "\nPair 2: ";
	p2.print();

	// тестування методу swap() для однакових типів int та int
	auto p3 = makePair(10, 20);

	std::cout << "\nTesting swap() with int and int:";
	std::cout << "\nBefore swap: ";
	p3.print();

	p3.swap();

	std::cout << "After swap:  ";
	p3.print();

	// p1.swap(); 

	return 0;
}