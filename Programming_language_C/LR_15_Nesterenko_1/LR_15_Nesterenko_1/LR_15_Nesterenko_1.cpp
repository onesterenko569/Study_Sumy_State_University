#include<iostream> // підключення бібліотеки 
#include<math.h> // підключення бібліотеки 
#define N 100 // задання розміру для масиву

using namespace std; // для бібліотеки iostream

void input_number(int *size, char c) // функція для введення кількості елементів масивів
{
	cout << "Vvedit kilkist elementiv dlya masyvu " << c << ": "; // виведення тексту
	cin >> *size; // введення кількості елементів масивів
}

void input_array(double arr[], int size, char c) // функція для введення елементів масиву
{
	cout << "Vvedit masyv " << c << "[" << size << "]:" << endl; // виведення тексту
	for (int i = 0; i < size; i++) // цикл для введення масиву
	{
		cout << c << "[" << i + 1 << "] = "; // виведення тексту
		cin >> arr[i]; // введення масиву
	}
	cout << "---------------------------" << endl; // для кращої читабельності
}

void output_array(double arr[], int size, char c) // функція для виведення масиву
{
	cout << "Vy mayete masyv " << c << ":" << endl; // виведення тексту
	for (int i = 0; i < size; i++) // цикл для виведення масиву
	{
		cout << arr[i] << "\t"; // виведення масиву
	}
	cout << endl; // для початку з нового рядка
}

double sum(double arr[], int size, double f1(double), double f2(double)) // функція для обчислення A, B, C, D
{
	double s = 0; // оголошення змінної
	for (int i = 0; i < size; i++) // цикл для обчислення A, B, C, D
	{
		s += (arr[i]) * (f1(arr[i])) + (arr[i]) * (arr[i]) * (f2(arr[i])); // обчислення A, B, C, D
	}
	return s; // повернення результату обчислень
}

int main() // головна функція програми
{
	double x[N], y[N], z[N], q[N], A, B, C, D; // оголошення змінних типу double
	int Nx, Ny, Nz, Nq; // оголошення змінних типу int
	input_number(&Nx, 'x'); // введення кількості елементів масиву x
	input_number(&Ny, 'y'); // введення кількості елементів масиву y
	input_number(&Nz, 'z'); // введення кількості елементів масиву z
	input_number(&Nq, 'q'); // введення кількості елементів масиву q
	cout << "---------------------------" << endl; // для кращої читабельності
	input_array(x, Nx, 'x'); // введення елементів масиву x
	input_array(y, Ny, 'y'); // введення елементів масиву y
	input_array(z, Nz, 'z'); // введення елементів масиву z
	input_array(q, Nq, 'q'); // введення елементів масиву q
	output_array(x, Nx, 'x'); // виведення масиву x
	output_array(y, Ny, 'y'); // виведення масиву y
	output_array(z, Nz, 'z'); // виведення масиву z
	output_array(q, Nq, 'q'); // виведення масиву q
	cout << "---------------------------" << endl; // для кращої читабельності
	A = sum(x, Nx, sin, cos); // обчислення A
	B = sum(y, Ny, cos, sin); // обчислення B
	C = sum(z, Nz, sin, sin); // обчислення C
	D = sum(q, Nq, cos, cos); // обчислення D
	cout << "A = " << A << endl; // виведення A
	cout << "B = " << B << endl; // виведення B
	cout << "C = " << C << endl; // виведення C
	cout << "D = " << D << endl; // виведення D
	return 0; // завершення програми
}