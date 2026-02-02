#include<iostream> // підключення бібліотеки

using namespace std; // для бібліотеки iostream

struct polinom // оголошення структури
{
	float a, b, c; // оголошення змінних типу float
};

void input_polinom(struct polinom* A) // функція для введення a, b, c для поліному другого ступеня
{
	cout << "Vy mayete polinom druhoho stupenya: ax^2 + bx + c" << endl; // виведення тексту
	cout << "a = "; // виведення тексту
	cin >> A->a; // введення a
	cout << "b = "; // виведення тексту
	cin >> A->b; // введення b
	cout << "c = "; // виведення тексту
	cin >> A->c; // введення c
	cout << endl; // для початку з нового рядка
}

void output_polinom(struct polinom A) // функція для виведення поліному
{
	cout << "Vash polinom:" << endl; // виведення тексту
	cout << A.a << "x^2 + " << A.b << "x + " << A.c << endl << endl; // виведення поліному
}

struct polinom pokhidna(struct polinom A) // функція для обчислення похідної поліному
{
	struct polinom B; // оголошення змінної типу struct polinom 
	B.a = 2 * A.a; // обрахунок похідної
	B.b = A.b; // обрахунок похідної
	B.c = 0; // обрахунок похідної
	return B; // повернення результатів обчислення (похідна)
}

void output_pokhidna(struct polinom A) // функція для виведення похідної
{
	cout << "Pokhidna dlya polinoma:" << endl; // виведення тексту
	cout << A.a << "x + " << A.b << endl; // виведення похідної
}

int main() // головна функція програми
{
	struct polinom c1, c2; // оголошення змінних типу struct polinom 
	input_polinom(&c1); // введення поліному
	output_polinom(c1); // виведення поліному
	c2 = pokhidna(c1); // обчислення похідної поліному
	output_pokhidna(c2); // виведення похідної поліному
	return 0; // завершення програми
}