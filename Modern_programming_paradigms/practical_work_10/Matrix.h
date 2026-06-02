#pragma once

#include <iostream>
#include <stdexcept>

// клас для роботи з матрицями
class Matrix
{
private:                                       // закриті дані класу
	int rows;                                  // кількість рядків матриці
	int cols;                                  // кількість стовпців матриці
	double** data;                             // двовимірний динамічний масив для зберігання елементів матриці

public:                                        // відкриті методи класу
	// конструктор за замовчуванням
	Matrix();

	// конструктор з параметрами
	Matrix(int r, int c);

	// конструктор копіювання
	Matrix(const Matrix& m);

	// деструктор
	~Matrix();

	// метод для ручного введення елементів матриці з клавіатури
	void input();

	// константний метод для виведення матриці на екран
	void print() const;

	// перевантаження оператора множення матриць
	Matrix operator*(const Matrix& m) const;

	// дружня функція для перевантаження оператора виводу
	friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
};