#include <stdio.h> // Підключення бібліотеки
int main() // Головна функція програми
{
	float x, y, sum, difference, product, division; // Задання змінних з плаваючою комою
	printf("The value of x \n"); // Вивід тексту на екран
	scanf_s("%f", &x); // Надання можливості вводити змінну x
	printf("The value of y \n"); // Вивід тексту на екран
	scanf_s("%f", &y); // Надання можливості вводити змінну y
	sum = x + y; // Формула для обчислення суми
	printf("The value of the sum %f\n", sum); // Виведення результату суми
	difference = x - y; // Формула для обчислення різниці
	printf("The value of the difference %f\n", difference); // Виведення результату різниці
	product = x * y; // Формула для обчислення добутку
	printf("The value of the product %f\n", product); // Виведення результату добутку
	division = x / y; // Формула для обчислення ділення
	printf("The value of the division %f\n", division); // Виведення результату ділення
	if (y == 0) {
		printf("tu sho durak? Na nol dilut nelza\n");
	}
		return 0;
}