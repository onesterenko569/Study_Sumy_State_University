#include<stdio.h> // підключення бібліотеки
#define Nx 6 // задання розміру масиву
#define Ny 7 // задання розміру масиву
#define Nz 8 // задання розміру масиву

void input(float arr[], int N, char c); // оголошення функції
float sum(float arr[], int N); // оголошення функції
 
int main()
{
	float x[Nx], y[Ny], z[Nz], sumx, sumy, sumz; // оголошення змінних типу float
	input(x, Nx, 'X'); // введення масиву x
	input(y, Ny, 'Y'); // введення масиву y
	input(z, Nz, 'Z'); // введення масиву z
	sumx = sum(x, Nx); // обчислення суми квадратів елементів масиву x
	sumy = sum(y, Ny); // обчислення суми квадратів елементів масиву y
	sumz = sum(z, Nz); // обчислення суми квадратів елементів масиву z
	printf("Suma kvadrativ elementiv masyvu X[6] = %.2f\n", sumx); // виведення результату обчислень
	printf("Suma kvadrativ elementiv masyvu Y[7] = %.2f\n", sumy); // виведення результату обчислень
	printf("Suma kvadrativ elementiv masyvu Z[8] = %.2f\n", sumz); // виведення результату обчислень
}
void input(float arr[], int N, char c) // функція для введення масиву
{
	printf("Vvedit masyv %c[%d]:\n", c, N); // виведення тексту
	for (int i = 0; i < N; i++) // цикл для введення масиву
	{
		printf("%c[%d] = ", c, i + 1); // виведення тексту
		scanf_s("%f", &arr[i]); // введення масиву
	}
}
float sum(float arr[], int N) // функція для обрахунку суми квадратів елементів масиву
{ 
	float suma = 0; // оголошуємо змінну типу float
	for (int i = 0; i < N; i++) // цикл для обрахунку суми квадратів елементів масиву
	{
		suma += arr[i] * arr[i]; // обрахунок 
	}
	return suma; // повернення результату обрахунку
}