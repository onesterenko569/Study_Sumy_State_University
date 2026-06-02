#include "Matrix.h"

// реалізація конструктора за замовчуванням
Matrix::Matrix() : rows(0), cols(0), data(nullptr) {}

// реалізація конструктора з параметрами
Matrix::Matrix(int r, int c) : rows(r), cols(c)
{
	data = new double* [rows];                 // виділяємо пам'ять для рядків
	for (int i = 0; i < rows; i++)
	{
		data[i] = new double[cols];            // виділяємо пам'ять для стовпців
		for (int j = 0; j < cols; j++)
		{
			data[i][j] = 0.0;                  // ініціалізуємо елементи нулями
		}
	}
}

// реалізація конструктора копіювання
Matrix::Matrix(const Matrix& m) : rows(m.rows), cols(m.cols)
{
	if (m.data == nullptr)                 // якщо матриця, яку копіюємо, порожня
	{
		data = nullptr;
		return;
	}

	data = new double* [rows];             // виділяємо пам'ять для рядків
	for (int i = 0; i < rows; i++)
	{
		data[i] = new double[cols];        // виділяємо пам'ять для стовпців
		for (int j = 0; j < cols; j++)
		{
			data[i][j] = m.data[i][j];     // копіюємо значення
		}
	}
}

// реалізація деструктора
Matrix::~Matrix()
{
	if (data != nullptr)                       // якщо пам'ять була виділена
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] data[i];                  // спочатку видаляємо кожен рядок
		}
		delete[] data;                         // потім видаляємо сам масив вказівників
	}
}

// реалізація методу для введення даних
void Matrix::input()
{
	if (data == nullptr)               // перевірка на порожню матрицю
	{
		return;
	}

	std::cout << "\nEnter matrix elements (" << rows << "; " << cols << "):\n";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << "Element [" << i << "][" << j << "] = ";
			std::cin >> data[i][j];
		}
	}
}

// реалізація методу виводу
void Matrix::print() const
{
	std::cout << *this;
}

// реалізація перевантаження оператора множення
Matrix Matrix::operator*(const Matrix& m) const
{
	// кількість стовпців першої матриці має дорівнювати кількості рядків другої
	if (this->cols != m.rows)
	{
		throw std::invalid_argument("\n\nError! Matrices cannot be multiplied (wrong dimensions)\n");
	}

	// створюємо нову матрицю-результат розміром (рядки першої, стовпці другої)
	Matrix result(this->rows, m.cols);

	// множення матриць
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < m.cols; j++)
		{
			for (int k = 0; k < this->cols; k++)
			{
				result.data[i][j] += this->data[i][k] * m.data[k][j];
			}
		}
	}

	return result;
}

// реалізація перевантаження оператора виводу
std::ostream& operator<<(std::ostream& os, const Matrix& m)
{
	if (m.data == nullptr)
	{
		os << "\nMatrix is empty";
		return os;
	}

	for (int i = 0; i < m.rows; i++)
	{
		for (int j = 0; j < m.cols; j++)
		{
			os << m.data[i][j] << "\t";
		}
		os << "\n";
	}
	return os;
}