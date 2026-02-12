// підключення необхідних бібліотек
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

// константа для визначення максимального розміру текстового рядка
#define MAX_LENGTH 100 

// головна функція програми
int main()
{
    std::string row; // інціалізаця змінної типу string

    std::cout << "Vvedit odyn ryadok tekstu:" << std::endl; // виведення тексту

    // цикл введення, який триватиме поки не спрацює break
    while (true)
    {
        std::getline(std::cin, row); // введення текстового рядка

        if (row.empty()) // якщо користувач нічого не ввів
        {
            std::cout << "\nVvedeno pustyy ryadok! Sprobuyte znovu:" << std::endl; // виведення повідомлення про помилку
        }
        else if (row.length() > MAX_LENGTH) // якщо перевищено максимальну кількість символів
        {
            std::cout << "\nPerevyshcheno limit u " << MAX_LENGTH << " symvoliv! Sprobuyte znovu:" << std::endl; // виведення повідомлення про помилку
        }
        else // якщо всі перевірки успішно пройдені
        {
            std::cout << "\nTekstovyy ryadok uspishno vvedeno:\n" << row << "\n" << std::endl; // виведення відповідного повідомлення
            break; // зупинка циклу
        }
    }

    int symbols = row.length(); // рахуємо загальну кількість символів
    int letters = 0;            // лічильник для літер
    int digits = 0;             // лічильник для цифр

    for (int i = 0; i < row.length(); i++) // цикл для підрахунку літер та цифр
    {
        if (isalpha(row[i]))      // якщо літера
        {
            letters++;            // збільшуємо лічильник
        }
        else if (isdigit(row[i])) // якщо цифра
        {
            digits++;             // збільшуємо лічильник
        }
    }

    // виведення результатів
    std::cout << std::left << std::setw(28) << "Zahalna kilkist symvoliv:" << std::right << std::setw(5) << symbols << std::endl;
    std::cout << std::left << std::setw(28) << "Kilkist liter:" << std::right << std::setw(5) << letters << std::endl;
    std::cout << std::left << std::setw(28) << "Kilkist tsyfr:" << std::right << std::setw(5) << digits << std::endl;

    return 0; // завершення програми

}
