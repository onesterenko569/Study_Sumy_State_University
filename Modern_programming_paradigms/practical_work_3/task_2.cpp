#include <iostream>  // підключення бібліотеки для введення/виведення інформації
#include <limits>    // підключення бібліотеки для роботи з лімітами типів

#define MAX_SIZE 100 // максимальна кількість елементів масиву

// функція для введення кількості елементів масиву з перевіркою
int inputSize(int maxSize)
{
	int size;

	std::cout << "Enter the number of array elements: ";

	// цикл повторюватиме введення, поки не буде введено коректне число від 1 до maxSize
	while (!(std::cin >> size) || size <= 0 || size > maxSize)
	{
		if (std::cin.fail())  // якщо введено не ціле число
		{
			std::cout << "\nError! You must enter an integer\nTry again: ";
			std::cin.clear();                                                   // скидання прапорця помилки потоку cin
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // очищення буфера вводу від сміття
		}
		else if (size <= 0)   // якщо введено не додатнє число
		{
			std::cout << "\nError! Array size must be greater than 0\nTry again: ";
		}
		else                  // якщо введено число, що перевищує обмеження MAX_SIZE
		{
			std::cout << "\nError! Maximum array size is 100\nTry again: ";
		}
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // очищення буфера вводу від сміття
	return size;                                                        // повернення коректного значення
}

// функція для введення масиву
void inputArray(double arr[], int size)
{
	std::cout << "\nEnter an array of " << size << " elements:" << std::endl;

	// цикл для введення кожного елементу з перевіркою
	for (int i = 0; i < size; i++)
	{
		std::cout << "arr[" << i << "] = ";

		// якщо введено не дійсне число
		while (!(std::cin >> arr[i]))
		{
			std::cout << "Error! Please enter a valid number: ";
			std::cin.clear();                                                   // скидання прапорця помилки потоку cin
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // очищення буфера вводу від сміття
		}
	}
}

// функція для виведення меню програми
void printMenu()
{
	std::cout << "\n\nChoose the array sorting method:" << std::endl;
	std::cout << "1. Sort an array using the bubble sort method" << std::endl;
	std::cout << "2. Sort an array using the selection method" << std::endl;
	std::cout << "3. Exit" << std::endl;
	std::cout << "\nEnter your choice: ";
}

// функція для сортування масиву методом бульбашки 
void bubbleSort(double arr[], int size)
{
	for (int i = 0; i < size - 1; i++)         // зовнішній цикл для кількості проходів по масиву
	{
		for (int j = 0; j < size - i - 1; j++) // внутрішній цикл для порівняння сусідніх елементів
		{
			if (arr[j] > arr[j + 1])           // якщо лівий елемент більший за правий
			{
				// міняємо елементи місцями
				double tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

// функція для сортування масиву методом вибору
void selectionSort(double arr[], int size)
{
	for (int i = 0; i < size - 1; i++)     // зовнішній цикл по всьому масиву
	{
		int minIndex = i;                  // припускаємо, що поточний елемент є найменшим

		for (int j = i + 1; j < size; j++) // внутрішній цикл для пошуку найменшого елемента в залишку масиву
		{
			if (arr[j] < arr[minIndex])    // якщо знайшли елемент, менший за поточний мінімум
			{
				minIndex = j;              // запам'ятовуємо його індекс
			}
		}

		if (minIndex != i)                 // якщо початковий мінімальний елемент не є мінімальним
		{
			// міняємо елементи місцями
			double tmp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = tmp;
		}
	}
}

// функція для виведення всіх елементів масиву
void printArray(double arr[], int size)
{
	for (int i = 0; i < size; i++)      // цикл по всіх елементах масиву
	{
		if (i == size - 1)              // якщо дійшли до останнього елемента масиву
		{
			std::cout << arr[i] << ".";
		}
		else                            // якщо не останній елемент масиву
		{
			std::cout << arr[i] << ", ";
		}
	}
}

// головна функція програми
int main()
{
	// оголошення необхідних змінних
	int arrSize;
	bool running = true;

	arrSize = inputSize(MAX_SIZE);     // введення розміру для масиву
	double* arr = new double[arrSize]; // виділення пам'яті під масив

	inputArray(arr, arrSize);          // введення масиву

	// виведення масиву
	std::cout << "\nInitial array:" << std::endl;
	printArray(arr, arrSize);

	// головний цикл програми, повторюється поки running == true
	while (running)
	{
		printMenu();                   // друк меню

		int choice;                    // змінна для збереження обраного пункту меню
		while (!(std::cin >> choice))  // перевірка чи введено коректне число для меню
		{
			std::cout << "\nError! Enter an integer: ";
			std::cin.clear();          // скидання прапорця помилки потоку cin
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // очищення буфера вводу від сміття
		}

		switch (choice)                               // оператор множинного вибору для обробки пунктів меню
		{
		case 1:                                   // якщо обрано сортування бульбашкою
		{
			std::cout << "\nBubble sort\n";

			std::cout << "  Array to sort: ";
			printArray(arr, arrSize);             // виводимо оригінальний масив перед сортуванням

			double* tmpArr = new double[arrSize]; // створюємо тимчасовий динамічний масив
			for (int i = 0; i < arrSize; i++)     // цикл для копіювання елементів з оригінального до тимчасового масиву
			{
				tmpArr[i] = arr[i];
			}

			bubbleSort(tmpArr, arrSize);          // сортуємо тимчасовий масив

			std::cout << "\n  Array after sorting: ";
			printArray(tmpArr, arrSize);          // виводимо відсортований масив

			delete[] tmpArr;                      // звільняємо пам'ять тимчасового масиву
			break;                                // завершення гілки case 1
		}
		case 2:                                   // якщо обрано сортування вибором
		{
			std::cout << "\nSelection sort\n";

			std::cout << "  Array to sort: ";
			printArray(arr, arrSize);             // виводимо оригінальний масив перед сортуванням

			double* tmpArr = new double[arrSize]; // створюємо тимчасовий динамічний масив
			for (int i = 0; i < arrSize; i++)     // цикл для копіювання елементів з оригінального до тимчасового масиву
			{
				tmpArr[i] = arr[i];
			}

			selectionSort(tmpArr, arrSize);       // сортуємо тимчасовий масив

			std::cout << "\n  Array after sorting: ";
			printArray(tmpArr, arrSize);          // виводимо відсортований масив

			delete[] tmpArr;                      // звільняємо пам'ять тимчасового масиву
			break;                                // завершення гілки case 2
		}
		case 3:                                   // якщо обрано вихід
		{
			running = false;                      // змінюємо прапорець, щоб зупинити головний цикл
			break;                                // завершення гілки case 3
		}
		default:                                  // якщо введено число, якого немає в меню
		{
			std::cout << "\nWrong choice! Try again";
			break;                                // завершення гілки default
		}
		}
	}

	delete[] arr;                                     // звільняємо пам'ять, виділену під головний масив перед виходом
	return 0;                                         // завершення роботи програми
}
