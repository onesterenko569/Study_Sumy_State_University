#include <iostream>

int main()
{
	double width = 0.0;
	double height = 0.0;
	std::cout << "Enter the width of the rectangle: ";
	std::cin >> width;
	std::cout << "Enter the height of the rectangle: ";
	std::cin >> height;
	const double area = width * height;
	std::cout << "The area of the rectangle is: " << area << '\n';
	return 0;
}
