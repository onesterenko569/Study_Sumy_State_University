#include <iostream>
#include <iomanip>
#include <chrono>
#include <limits>

// звичайна функція із математичними обчисленнями
double normalFunction(double a, double b)
{
	return (((a * a - 2 * a * b + b * b) * 2.67) - 3796.34) / 6.72;
}

// inline функція із математичними обчисленнями
inline double inlineFunction(double a, double b)
{
	return (((a * a - 2 * a * b + b * b) * 2.67) - 3796.34) / 6.72;
}

// головна функція програми
int main()
{
	// задаємо максимальну кількість ітерацій, яку може вмістити тип int
	constexpr int iter = std::numeric_limits<int>::max();

	// змінні для зберігання обрахованої суми
	double sum1 = 0;
	double sum2 = 0;

	// фіксуємо час початку тесту
	auto startTime1 = std::chrono::high_resolution_clock::now();

	// обчислення за допомогою звичайної функції
	for (int i = 0; i < iter; i++)
	{
		sum1 += normalFunction(2.12, 3.34);
	}

	// фіксуємо час завершення тесту
	auto endTime1 = std::chrono::high_resolution_clock::now();

	// розраховуємо тривалість у мілісекундах
	std::chrono::duration<double, std::milli> time1 = endTime1 - startTime1;

	// налаштовуємо 3 знаки після коми
	std::cout << std::fixed << std::setprecision(3);

	// виведення результатів
	std::cout << "The result of the regular function:";
	std::cout << "\n  Time = " << time1.count() << " ms";
	std::cout << "\n  Sum = " << sum1;

	// фіксуємо час початку тесту
	auto startTime2 = std::chrono::high_resolution_clock::now();

	// обчислення за допомогою inline функції
	for (int i = 0; i < iter; i++)
	{
		sum2 += inlineFunction(2.12, 3.34);
	}

	// фіксуємо час завершення тесту
	auto endTime2 = std::chrono::high_resolution_clock::now();

	// розраховуємо тривалість у мілісекундах
	std::chrono::duration<double, std::milli> time2 = endTime2 - startTime2;

	// виведення результатів
	std::cout << "\n\nThe result of the inline function:";
	std::cout << "\n  Time = " << time2.count() << " ms";
	std::cout << "\n  Sum = " << sum2 << std::endl;

	return 0;
}
