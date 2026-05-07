#include <iostream>
#include <cmath>

// функція для додавання двох чисел
int sum(int x, float y)
{
	std::cout << "\n\nFunction int sum(int x, float y) is called with x = " << x << " y = " << y;
	std::cout << "\nThis function calculates x + y";

	return static_cast<int>(std::round(x + y));
}

// перевантажена функція додавання двох чисел
int sum(int x, double y)
{
	std::cout << "\n\nFunction int sum(int x, double y) is called with x = " << x << " y = " << y;
	std::cout << "\nThis function calculates x + y";

	return static_cast<int>(std::round(x + y));
}

// головна функція програми
int main()
{
	// виклик першої функції додавання
	int result1 = sum(5, 3.14f);
	std::cout << "\nResult: " << result1;

	// виклик другої перевантаженої функції
	int result2 = sum(4, 7.23);
	std::cout << "\nResult: " << result2;

	// неоднозначність
	int result3 = sum(3, 4);
	std::cout << "\nResult: " << result3 << std::endl;

	return 0;
}
