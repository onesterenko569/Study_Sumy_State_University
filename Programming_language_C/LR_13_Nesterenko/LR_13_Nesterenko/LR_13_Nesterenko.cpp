#include<iostream> // підключення бібліотеки 
#define N 20 // задання константи для масивів
using namespace std; // для бібліотеки iostream

void input_number(int* pn, int *pm, int limitN, int limitM, char c) // функція для введення кількості рядків та стовпців
{
	cout << "Vvedit kilkist ryadkiv dlya matrytsi " << c << " (< " << limitN << "): " << endl; // виведення тексту
	cin >> *pn; // введення кількості рядків
	cout << "Vvedit kilkist stovptsiv dlya matrytsi " << c << " (< " << limitM << "): " << endl; // виведення тексту
	cin >> *pm; // введення кількості стовпців
}

void input_matrix(float arr[N][N], int row, int column, char c) // функція для введення матриць
{
	cout << "Vvedit matrytsyu " << c << endl; // виведення тексту
	for (int i = 0; i < row; i++) // цикл по рядкам
	{
		for (int j = 0; j < column; j++) // цикл по стовпцям
		{
			cout << c << "[" << i + 1 << "][" << j + 1 << "] = "; // виведення тексту для кращої читабельності
			cin >> arr[i][j]; // введення матриці
		}
	}
}

void output_matrix(float arr[N][N], int row, int column, char c) // функція для виведення матриці
{
	cout << "Vy mayete matrytsyu " << c << "[" << row << "][" << column << "]:" << endl; // виведення тексту 
	for (int i = 0; i < row; i++) // цикл по рядкам
	{
		for (int j = 0; j < column; j++) // цикл по стовпцям
		{
			cout << arr[i][j] << "\t"; // виведення матриці
		}
		cout << endl; // для початку з нового рядка
	}
}

void analysis(float arr[N][N], int pN[], int row, int column, char c) // функція для обчислення і запам'ятовування кількості негативних елементів кожного стовпчика 
{ 
	for (int j = 0; j < column; j++) // цикл по стовпцям
	{
		pN[j] = 0; // обнуляємо
		for (int i = 0; i < row; i++) // цикл по рядкам
		{
			if (arr[i][j] < 0) // пошук елементів, які менше нуля
			{
				pN[j]++; // лічильник збільшується
			}
		}
		cout << "U " << j + 1 << " stovptsi matrytsi " << c << " " << pN[j] << " nehatyvnykh elementiv" << endl; // виведення результату пошуку
	}
}

int main() // головна функція програми
{
	int aN, aM, bN, bM, a_N[10], b_N[20]; // оголошення змінних типу int
	float a[N][N], b[N][N]; // оголошення змінних типу float
	input_number(&aN, &aM, 10, 10, 'a'); // введення кількості рядків та стовпців для матриці a
	input_number(&bN, &bM, 15, 20, 'b'); // введення кількості рядків та стовпців для матриці b
	input_matrix(a, aN, aM, 'a'); // введення матриці a
	input_matrix(b, bN, bM, 'b'); // введення матриці b
	output_matrix(a, aN, aM, 'a'); // виведення матриці a
	output_matrix(b, bN, bM, 'b'); // виведення матриці b
	analysis(a, a_N, aN, aM, 'a'); // обчислення і запам'ятовування кількості негативних елементів кожного стовпчика матриці a
	analysis(b, b_N, bN, bM, 'b'); // обчислення і запам'ятовування кількості негативних елементів кожного стовпчика матриці b
	return 0; // завершення програми
}
