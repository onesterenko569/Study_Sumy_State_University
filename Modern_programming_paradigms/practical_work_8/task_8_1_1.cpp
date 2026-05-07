#include <iostream>
#include <cmath>

// функція для додавання двох цілих чисел
int myFunc(int a, int b)
{
	std::cout << "Function int myFunc(int a, int b) is called with a = " << a << " b = " << b;
	std::cout << "\nThis function calculates a + b";

	return a + b;
}

// перевантажена функція для обчислення квадрата дробового числа
int myFunc(float x)
{
	std::cout << "\n\nFunction int myFunc(float x) is called with x = " << x;
	std::cout << "\nThis function calculates x * x";

	return static_cast<int>(std::round(x * x));
}

// перевантажена функція для обчислення математичного виразу з трьома параметрами
int myFunc(double x, double y, double z)
{
	std::cout << "\n\nFunction int myFunc(double x, double y, double z) is called with x = " << x << " y = " << y << " z = " << z;
	std::cout << "\nThis function calculates (x + y) * z";

	return static_cast<int>(std::round((x + y) * z));
}

// головна функція програми
int main()
{
	// виклик функції з двома int аргументами
	int result1 = myFunc(5, 3);
	std::cout << "\nResult: " << result1;

	// виклик функції з одним float аргументом
	int result2 = myFunc(3.7f);
	std::cout << "\nResult: " << result2;

	// виклик функції з трьома double аргументами
	int result3 = myFunc(2.45, 6.12, 2.09);
	std::cout << "\nResult: " << result3 << std::endl;

	return 0;
}
