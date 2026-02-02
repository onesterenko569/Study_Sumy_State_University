#include<iostream> // підключення бібліотеки
#include<math.h> // підключення бібліотеки

#define Nx 7 // задання розміру масиву x
#define Ny 10 // задання розміру масиву y
 
using namespace std; // для бібліотеки iostream

void input_array(double arr[], int size, char c) // функція для введення масиву
{
	cout << "Vy mayete masyv " << c << "[" << size << "]" << endl << "Zopovnit yoho" << endl; // виведення тексту
	for (int i = 0; i < size; i++) // цикл для введення масиву
	{
		cout << c << "[" << i + 1 << "] = "; // виведення тексту
		cin >> arr[i]; // введення масиву
	}
	cout << "----------------------------------" << endl; // для кращої читабельності
}

void output_array(double arr[], int size, char c) // функція для виведення масиву
{
	cout << "Vash masyv " << c << "[" << size << "]:" << endl; // виведення тексту
	for (int i = 0; i < size; i++) // цикл для виведення масиву
	{
		cout << arr[i] << "\t"; // виведення масиву
	}
	cout << endl; // для початку з нового рядка
}

double search_least(double arr[], int size, int *pindex, double (*pfn)(double)) // пошук наймешого значення функції
{
	*pindex = 0; // обнуляємо
	double pmin = pfn(arr[0]); // обраховуємо значення функції при нульовому елемету масиву
	for (int i = 1; i < size; i++) // цикл для пошуку мінімального значення функції
	{
		if (pfn(arr[i]) < pmin) // умова для пошуку
		{
			pmin = pfn(arr[i]); // запам'ятовуємо значення
			*pindex = i; // зберігає індекс
		}
	}
	return pmin; // повертаємо мінімаьне значення функції
}

double Z(double y) // функція для обрахунку функції z
{
	return exp(y); // обрахунок та повернення результату обрахунку
}

double Y(double x) // функція для обрахунку функції y
{
	return (x + pow(x, 7)); // обрахунок та повернення результату обрахунку
}

int main() // головна функція програми
{
	int in_x, in_y; // оголошення змінних типу int
	double x[Nx], y[Ny], min_Z, min_Y; // оголошення змінних типу double
	input_array(x, Nx, 'x'); // введення масиву x
	input_array(y, Ny, 'y'); // введення масиву y
	output_array(x, Nx, 'x'); // виведення масиву x
	output_array(y, Ny, 'y'); // виведення масиву y
	cout << "----------------------------------" << endl; // для кращої читабельності
	min_Z = search_least(y, Ny, &in_y, Z); // обрахунок найменшого значення для функці Z
	min_Y = search_least(x, Nx, &in_x, Y); // обрахунок найменшого значення для функці Y
	cout << "Naymenshe znachennya dlya funktsiyi Z:" << endl << "Indeks: " << in_y + 1 << endl << "Znachennya: " << min_Z << endl; // виведення результату
	cout << "----------------------------------" << endl; // для кращої читабельності
	cout << "Naymenshe znachennya dlya funktsiyi Y:" << endl << "Indeks: " << in_x + 1 << endl << "Znachennya: " << min_Y << endl; // виведення результату
	cout << "----------------------------------" << endl; // для кращої читабельності
	return 0; // завершення програми
}