#include <iostream>  // підключення бібліотеки для введення/виведення тексту

#define MAX_SIZE 100 // визначення константи для максимального розміру масиву

// функція для введення розміру масиву з перевіркою на некоректні дані та обмеженням розміру
int inputSize(int maxSize)
{
    int n;                                 // оголошення змінної, яка зберігатиме введений користувачем розмір масиву

    // цикл працює, поки введено текст, або число <менше/дорівнює <= нулю, або число більше за максимум
    while (!(std::cin >> n) || n <= 0 || n > maxSize)
    {
        if (std::cin.fail())               // якщо помилка сталася через те, що користувач ввів текст замість числа
        {
            std::cout << "\nError! You must enter an integer\nTry again: "; // виведення повідомлення про помилку
            std::cin.clear();                                               // скидання прапорця помилки потоку введення
            std::cin.ignore(10000, '\n');                                   // очищення буфера введення від сміття
        }
        else if (n <= 0)                   // якщо введене число менше або дорівнює нулю
        {
            std::cout << "\nError! Array size must be greater than 0\nTry again: ";
        }
        else                               // якщо введене число більше за maxSize
        {
            std::cout << "\nError! Maximum array size is 100\nTry again: ";
        }
    }

    std::cin.ignore(10000, '\n');          // очищення буфера введення від сміття
    return n;                              // повертаємо коректне невід'ємне значення розміру масиву
}

// функція введення елементу масиву з перевіркою на некоректні символи
int inputNumber()
{
    int num;                   // оголошення змінної, яка зберігатиме введене значення елементу

    while (!(std::cin >> num)) // цикл працює, поки введення некоректне
    {
        std::cout << "Error! You must enter an integer\nTry again: ";  // виведення повідомлення про помилку
        std::cin.clear();                                              // скидання прапорця помилки потоку введення
        std::cin.ignore(10000, '\n');                                  // очищення буфера введення від сміття
    }

    return num;                // повертаємо коректно введене ціле число
}

// функція для заповнення масиву з клавіатури
void inputArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)             // цикл для проходу по всіх елементах масиву
    {
        std::cout << "arr[" << i << "] = "; // виведення тексту
        arr[i] = inputNumber();             // виклик функції безпечного введення числа та запис результату у масив
    }
}

// функція для обчислення суми парних елементів масиву
int sumEvenElements(int arr[], int n)
{
    int sum = 0;                // оголошення змінної, яка зберігатиме суму парних елементів масиву

    for (int i = 0; i < n; i++) // цикл по кожному елементу масиву
    {
        if (arr[i] % 2 == 0)    // якщо елемент парний
        {
            sum += arr[i];      // рахуємо суму
        }
    }

    return sum;                 // повертаємо обраховану суму парних елементів масиву
}

// функція для обчислення середнього арифметичного непарних елементів
bool arithMean(int arr[], int n, double& arithmeticMean)
{
    int count = 0, sum = 0;                   // оголошуємо змінні необхідні для обрахунку середнього арифметичного

    for (int i = 0; i < n; i++)               // цикл по кожному елементу масиву
    {
        if (arr[i] % 2 != 0)                  // якщо елемент непарний
        {
            sum += arr[i];                    // рахуємо суму таких елементів
            count++;                          // рахуємо кількість таких елементів
        }
    }

    if (count > 0)                            // якщо кількість непарних елементів більша за 0
    {
        arithmeticMean = (double)sum / count; // рахуємо середнє арифметичне
        return true;                          // повертаємо true (непарні елементи знайдено)
    }
    else                                      // якщо непарні елементи не знайдено
    {
        return false;                         // повертаємо false (непарні елементи не знайдено)
    }
}

// головна функція програми
int main()
{
    // оголошення змінних
    int arrSize, arr[MAX_SIZE], sum; 
    double arithmeticMean;

    // введення розміру масиву
    std::cout << "Enter the array size: ";
    arrSize = inputSize(MAX_SIZE);

    // введення елементів масиву
    std::cout << "\nEnter an array of " << arrSize << " elements:" << std::endl;
    inputArray(arr, arrSize);

    // обчислення суми парних елементів масиву та виведення результату
    sum = sumEvenElements(arr, arrSize);
    std::cout << "\nSum of even elements of the array = " << sum << std::endl;

    if (arithMean(arr, arrSize, arithmeticMean)) // якщо arithMean() повернула true (непарні елементи знайдено)
    {
        std::cout << "\nArithmetic mean of odd array elements = " << arithmeticMean << std::endl; // виводимо результат
    }
    else                                         // якщо arithMean() повернула false (непарні елементи не знайдено)
    {
        std::cout << "There are no odd elements in the array" << std::endl; // виводимо відповідне повідомлення
    }

    return 0; // завершення програми
}
