#include <stdio.h>
#include <conio.h>
int main()
{
	float x, y; // введення змінних типу float
	float* x_ptr, * y_ptr; // введення покажчиків типу float
	x_ptr = &x; // у значення x_ptr заносимо адресу змінної x
	*x_ptr = 5; // *x_ptr - покажчик на змінну x --> x = 5
	x = 5.5 + *x_ptr; // обрахування змінної x
	y_ptr = x_ptr; // у значення y_ptr заносимо адресу змінної x
	y = *y_ptr / 2 + *x_ptr; // обрахування змінної y
	y_ptr = &y; // у значення y_ptr заносимо адресу змінної y
	printf("The value of x = %f  y = %f\n", x, y); // виведення значень x та y
	printf("The value that x_ptr points to is %f .\n", *x_ptr); // виведення значення x
	printf("The value that y_ptr points to is %f.\n", *y_ptr); // виведення значення y
	puts("====================================================");
	_getch();
}

