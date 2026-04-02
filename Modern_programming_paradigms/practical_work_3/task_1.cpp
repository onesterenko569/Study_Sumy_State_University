#include <iostream>  // підключення бібліотеки для введення/виведення інформації
#include <limits>    // підключення бібліотеки для роботи з лімітами типів

// функція для введення числа з перевіркою чи введено число коректно
int inputNumber()
{
	int num; 

	std::cout << "Enter a number: ";

	// цикл повторюватиме введення числа, поки не буде коректного введення
	while (!(std::cin >> num))
	{
		std::cout << "\nError! You must enter an integer\nTry again: ";
		std::cin.clear();                                                    // скидання прапорця помилки потоку cin
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // очищення буфера вводу від сміття
	}

	return num; // повертаємо коректно введене число
}

// функція для визначення знаку числа
int signOfNumber(int x)
{
	int result;

	if (x < 0)       // якщо значення числа від'ємне
	{
		result = -1;
	}
	else if (x > 0)  // якщо значення числа додатнє
	{
		result = 1;
	}
	else             // якщо число дорівнює 0
	{
		result = 0;
	}

	return result;   // повертаємо результат аналізу числа
}

// головна функція програми
int main()
{
	int num, result;

	num = inputNumber();        // введення числа користувачем з клавіатури
	result = signOfNumber(num); // визначення знаку числа

	// оператор множинного вибору для виведення тексту залежно від значення result
	switch (result)
	{
	case -1: // якщо функція signOfNumber повернула -1
	{
		std::cout << "\nThe signOfNumber() function returned -1 (negative number)" << std::endl;
		break;
	}
	case 0:  // якщо функція signOfNumber повернула 0
	{
		std::cout << "\nThe signOfNumber() function returned 0 (the number is zero)" << std::endl;
		break;
	}
	default: // якщо функція signOfNumber повернула 1
	{
		std::cout << "\nThe signOfNumber() function returned 1 (a positive number)" << std::endl;
		break;
	}
	}

	return 0; // завершення програми
}