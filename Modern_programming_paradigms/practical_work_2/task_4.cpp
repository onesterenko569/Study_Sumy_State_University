#include <iostream> // підключення бібліотеки для введення/виведення тексту

// функція введення числа з перевіркою на некоректні символи та від'ємні значення
int inputNumber()
{
	int num;                               // оголошення змінної, яка зберігатиме введене значення користувачем

	while (!(std::cin >> num) || num < 0)  // цикл працює, поки введення некоректне
	{
		if (std::cin.fail())               // якщо помилка сталася через те, що користувач ввів текст замість числа
		{
			std::cout << "\nError! You must enter an integer\nTry again: ";
			std::cin.clear();              // скидання прапорця помилки потоку введення, щоб він міг працювати далі
			std::cin.ignore(10000, '\n');  // очищення буфера введення від сміття
		}
		else                               // якщо введене число від'ємне 
		{
			std::cout << "\nError! You must enter a positive number\nTry again: ";
		}
	}

	std::cin.ignore(10000, '\n');          // очищення буфера від можливих зайвих символів після успішного введення числа
	return num;                            // повертаємо коректне невід'ємне значення

}

// функція для перевірки, чи є число паліндромом
bool isPalindrome(int num)
{
	if (num < 0)            // якщо число від'ємне
	{
		return false;       // повертаємо хибне значення
	}

	int originalNum = num;  // зберігаємо початкове значення числа для фінального порівняння
	int remainder;          // змінна для зберігання останньої цифри числа
	int reversedNum = 0;    // змінна для зберігання перевернутого числа

	while (num > 0)         // цикл працює, поки від початкового числа залишаються цифри
	{
		remainder = num % 10;                         // отримуємо останню цифру числа 
		reversedNum = (reversedNum * 10) + remainder; // зсуваємо перевернуте число вліво і додаємо нову цифру
		num /= 10;                                    // відкидаємо останню цифру з числа
	}

	return originalNum == reversedNum;                // порівнюємо початкове число з перевернутим (true - рівні, false - ні)
}

// головна функція програми
int main()
{
	int num;                    // оголошення змінної для зберігання числа, яке будемо перевіряти

	// введення числа
	std::cout << "Enter the integer you want to check for palindrome: ";
	num = inputNumber();

	if (isPalindrome(num))      // якщо функція isPalindrome повернула true, тобто число паліндром
	{
		std::cout << "\nThe number " << num << " is a palindrome!" << std::endl;
	}
	else                        // якщо функція isPalindrome повернула false, тобто число не паліндром
	{
		std::cout << "\nThe number " << num << " is not a palindrome!" << std::endl;
	}

	return 0;                   // завершення програми
}