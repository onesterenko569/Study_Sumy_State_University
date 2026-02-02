#include<iostream> // підключення бібліотеки
#define N 100 // задання розміру масивам

using namespace std; // для бібліотеки iostream

void input_number(int *psize, char c) // функція для введення кількості елементів масиву
{
	cout << "Vvedit kilkist elementiv dlya odnovymirnoho masyvu " << c << ": "; // виведення тексту
	cin >> *psize; // введення кількості
}

void input_array(float arr[], int size, char c) // функція для введення масиву
{
	cout << "Vvedit masyv " << c << endl; // виведення тексту
	for (int i = 0; i < size; i++) // цикл для введення масиву
	{

		cout << c << "[" << i + 1 << "] = "; // виведення тексту
		cin >> arr[i]; // введення масиву
	}
	cout << "------------------------------" << endl; // для кращої читабельності
}

void input_interval(float *pmin, float *pmax, char c) // функція для введення інтервалу 
{
	cout << "Vvedit pochatkovyy element intervalu dlya masyvu " << c << ": "; // виведення тексту
	cin >> *pmin; // введення початку інтервалу
	cout << "Vvedit kintsevyy element intervalu dlya masyvu " << c << ": "; // виведення тексту
	cin >> *pmax; // введення кінця інтервалу
}

void output(float arr[], int size, char c) // функція для виведення масиву
{
	cout << "Masyv " << c << ": { "; // виведення тексту
	for (int i = 0; i < size; i++) // цикл для виведення масиву
	{

		cout << arr[i] << " "; // виведення масиву
	}
	cout << "}" << endl; // виведення тексту
}

void analysis(float arr[], int size, float min, float max, float *psum, float *pser_arefm, char c) // функція для обчислення суми та середнього арифметичного для елементів, які знаходяться в обраному інтервалі
{
	int lich = 0; // оголошення змінної типу int
	*psum = 0; // обнуляємо
	*pser_arefm = 0; // обнуляємо
	for (int i = 0; i < size; i++) // цикл для знаходження суми та кількості елементів, що знаходяться у вибраному інтервалі
	{
		if (arr[i] > min && arr[i] < max) // перевірка на інтервал
		{
			*psum += arr[i]; // обчислення суми
			lich++; // лічильник збільшується
		}
	}
	if (lich > 0) // якщо елементи існують у вибраному інтервалі
	{
		*pser_arefm = *psum / lich; // обчислення середнього арифметичного
	}
	else // якщо елементи не існують у вибраному інтервалі
	{
		cout << "Eror: dlya masyvu " << c << " nema elementiv v zadanomu intervali" << endl; // виведення відповідного повідомлення
		*pser_arefm = 0; // надаємо значення 0
	}
}

int main() // головна функція програми
{
	float a[N], b[N], c[N], min_a, min_b, min_c, max_a, max_b, max_c, sum, ser_arefm; // оголошення змінних типу float
	int aN, bN, cN; // оголошення змінних типу int
	input_number(&aN, 'a'); // введення кількості елементів для масиву a
	input_number(&bN, 'b'); // введення кількості елементів для масиву b
	input_number(&cN, 'c'); // введення кількості елементів для масиву c
	cout << "------------------------------" << endl; // для кращої читабельності
	input_array(a, aN, 'a'); // введення масиву a
	input_array(b, bN, 'b'); // введення масиву b
	input_array(c, cN, 'c'); // введення масиву c
	output(a, aN, 'a'); // виведення масиву a
	output(b, bN, 'b'); // виведення масиву b
	output(c, cN, 'c'); // виведення масиву c
	cout << "------------------------------" << endl; // для кращої читабельності
	input_interval(&min_a, &max_a, 'a'); // введення інтервалу для масиву a
	input_interval(&min_b, &max_b, 'b'); // введення інтервалу для масиву b
	input_interval(&min_c, &max_c, 'c'); // введення інтервалу для масиву c
	cout << "------------------------------" << endl; // для кращої читабельності
	analysis(a, aN, min_a, max_a, &sum, &ser_arefm, 'a'); // обчислення суми та середнього арифметичного для масиву a
	cout << "Dlya masyvu a[" << aN << "] suma elementiv, znachennya yakih znakhodyatsya v zadanomu intervali (vid " << min_a << " do " << max_a << ") = " << sum << endl; // виведення результатів
	cout << "Dlya masyvu a[" << aN << "] serednye aryfmetychne elementiv, znachennya yakih znakhodyatsya v zadanomu intervali (vid " << min_a << " do " << max_a << ") = " << ser_arefm << endl; // виведення результатів
	analysis(b, bN, min_b, max_b, &sum, &ser_arefm, 'b'); // обчислення суми та середнього арифметичного для масиву b
	cout << "Dlya masyvu b[" << bN << "] suma elementiv, znachennya yakih znakhodyatsya v zadanomu intervali (vid " << min_b << " do " << max_b << ") = " << sum << endl; // виведення результатів
	cout << "Dlya masyvu b[" << bN << "] serednye aryfmetychne elementiv, znachennya yakih znakhodyatsya v zadanomu intervali (vid " << min_b << " do " << max_b << ") = " << ser_arefm << endl; // виведення результатів
	analysis(c, cN, min_c, max_c, &sum, &ser_arefm, 'c'); // обчислення суми та середнього арифметичного для масиву c
	cout << "Dlya masyvu c[" << cN << "] suma elementiv, znachennya yakih znakhodyatsya v zadanomu intervali (vid " << min_c << " do " << max_c << ") = " << sum << endl; // виведення результатів
	cout << "Dlya masyvu c[" << cN << "] serednye aryfmetychne elementiv, znachennya yakih znakhodyatsya v zadanomu intervali (vid " << min_c << " do " << max_c << ") = " << ser_arefm << endl; // виведення результатів
	return 0; // завершення програми
}
