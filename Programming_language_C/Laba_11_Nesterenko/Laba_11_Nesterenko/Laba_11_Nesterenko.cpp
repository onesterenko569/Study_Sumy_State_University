#include<iostream> // підключення бібліотеки 
#define max 20 // задання обмеження

using namespace std; // для бібліотеки iostream

int inputMN(int &row, int &column, int limit, char c) // функція для введення розмірів масивів
{
	cout << "Vvedit kilkist ryadkiv dlya masyvu " << c << " (<=" << limit << "): "; // виведення тексту
	cin >> row; // занесення розміру
	if (row > limit || row < 1) // перевірка на правильність введення користувачем розміру масиву
	{
		return -1; // повернення -1
	}
	cout << "Vvedit kilkist stovptsiv dlya masyvu " << c << " (<=" << limit << "): "; // виведення тексту
	cin >> column; // занесення розміру
	if (column > limit || column < 1) // перевірка на правильність введення користувачем розміру масиву
	{
		return -1; // повернення -1
	}
	cout << "------------------------------" << endl; // для зручності при введенні 
	return 0; // повернення 0
}

void input_matrix(float arr[max][max], int row, int column, char c) // фунція для введення матриць
{
	for (int i = 0; i < row; i++) // цикл по рядкам
	{
		for (int j = 0; j < column; j++) // цикл по стовпцям
		{
			cout << c << "[" << i + 1 << "][" << j + 1 << "] = "; // виведення тексту
			cin >> arr[i][j]; // введення матриці
		}
	}
	cout << "------------------------------" << endl; // для зручності при введенні
}

void output_matrix(float arr[max][max], int row, int column, char c) // функція для виведення матриці
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
	cout << "------------------------------" << endl; // для зручності
}

void suma(float arr[max][max], int row, int column, char c) // функція для обчислення суми додатних елементів, що містяться нижче за головну діагональ 
{
	float sum = 0; // оголошення змінної
	for (int i = 1; i < row; i++) // цикл по рядках (починаємо з 2 рядка, бо в першому рядку немає елементів, що нижче за головну діагональ)
	{
		for (int j = 0; j < column && j < i; j++) // цикл по стовпцях (елементи стовпців нижчі за головну діагональ)
		{
			if (arr[i][j] > 0) // перевірка на знак елемента
			{
				sum += arr[i][j]; // обчислення суми
			}
		}
	}
	if (sum > 0) // перевірка чи були додатні елементи нижчі за головну діагональ
	{
		cout << "Suma dodatnykh elementiv, shcho mistyatsya nyzhche za holovnu diahonal dlya matrytsi " << c << "[" << row << "][" << column << "] = " << sum << endl; // виведення результатів
	}
	else // якщо додатних елементів нижчих за головну діагональ не існує
	{
		cout << "U matrytsi " << c << " nemaye dodatnykh elementiv, shcho nyzhche za holovnu diahonal" << endl; // виведення відповідного повідомлення
	}
}

int main() // головна функція програми
{
	int m1, n1, m2, n2; // оголошення змінних типу int
	float a[max][max], b[max][max]; // оголошення змінних типу float
	if (inputMN(m1, n1, 15, 'a') == -1) // одночасне введення розміру масива та перевірка на правильність введення
	{
		cout << "Vy nepravylno vvely kilkist ryadkiv ta stovptsiv"; // виведення повідомлення про помилку
		return -1; // завершення програми з помилкою
	}
	if (inputMN(m2, n2, 20, 'b') == -1) // одночасне введення розміру масива та перевірка на правильність введення
	{
		cout << "Vy nepravylno vvely kilkist ryadkiv ta stovptsiv"; // виведення повідомлення про помилку
		return -1; // завершення програми з помилкою
	}
	input_matrix(a, m1, n1, 'a'); // виклик функції для введення матриці a
	input_matrix(b, m2, n2, 'b'); // виклик функції для введення матриці b
	output_matrix(a, m1, n1, 'a'); // виведення матриці a
	output_matrix(b, m2, n2, 'b'); // виведення матриці b
	suma(a, m1, n1, 'a'); // обчислення суми додатних елементів, що містяться нижче за головну діагональ та виведення результату
	suma(b, m2, n2, 'b'); // обчислення суми додатних елементів, що містяться нижче за головну діагональ та виведення результату
	return 0; // завершення програми
}
