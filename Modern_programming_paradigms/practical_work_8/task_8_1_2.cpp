#include <iostream>
#include <cmath>

// функція для додавання двох чисел
int myFunc(int x, float y)
{
	std::cout << "\n\nFunction int myFunc(int x, float y) is called with x = " << x << " y = " << y;
	std::cout << "\nThis function calculates x + y";

	return static_cast<int>(std::round(x + y));
}

// перевантажена функція для множення двох чисел
int myFunc(float x, int y)
{
	std::cout << "\n\nFunction int myFunc(float x, int y) is called with x = " << x << " y = " << y;
	std::cout << "\nThis function calculates x * y";

	return static_cast<int>(std::round(x * y));
}

// головна функція програми
int main()
{
	// виклик функції додавання
	int result1 = myFunc(5, 3.14f);
	std::cout << "\nResult: " << result1;

	// виклик функції множення
	int result2 = myFunc(4.12f, 7);
	std::cout << "\nResult: " << result2;

	// неоднозначність
	int result3 = myFunc(5, 5);
	std::cout << "\nResult: " << result3;

	return 0;
}
