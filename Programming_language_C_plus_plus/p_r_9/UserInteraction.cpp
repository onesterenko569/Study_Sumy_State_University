#include "UserInteraction.h"

#include <iostream>    // для виведення/введення тексту
#include <string>      // для string
#include <stdexcept>   // для обробки винятків

// функція для виведення меню програми
void printMenu()
{
    std::cout << "\nHOLOVNE MENYU\n";              // виводимо заголовок меню
    std::cout << "1 - Pochaty hru\n";              // пункт початку гри
    std::cout << "2 - Istoriya ihor\n";            // пункт перегляду історії
    std::cout << "3 - Vykhid\n";                   // пункт виходу з програми
    std::cout << "\nVash vybir: ";                 // просимо користувача зробити вибір
}

// функція для виведення інструкції по грі
void printInstructions()
{
    std::cout << "PRAVYLA GRY\n";                                            // виводимо заголовок блоку правил
    std::cout << "1. Meta gry - vidsortuvaty fishky za zrostannyam\n";       // пояснюємо головну мету гри
    std::cout << "2. Pusta klitynka '_' maye buty v samomu kintsi\n";        // пояснюємо фінальну позицію пустої клітинки
    std::cout << "3. Dlya khodu vvedit nomer fishky, shcho poruch iz '_'\n"; // пояснюємо механіку виконання ходу
    std::cout << "4. Shchob pryzupynyty gru, vvedit Space + Enter\n";        // нагадуємо про можливість виклику меню паузи
}

// функція для введення вибору меню з перевіркою на коректність
int getMenuChoice()
{
    int userChoice;                                     // змінна для збереження вибору користувача
    std::string inputStr;                               // змінна для зберігання введеного рядка

    while (true)                                        // нескінченний цикл перевірки правильності введення
    {
        std::getline(std::cin, inputStr);               // зчитуємо весь введений рядок з консолі

        try                                             // блок для перехоплення можливих помилок
        {
            size_t pos;                                 // змінна для збереження позиції обробленого символу

            userChoice = std::stoi(inputStr, &pos);     // конвертуємо рядок у ціле число

            if (pos < inputStr.length())                // якщо оброблено не весь рядок (введено літери чи зайві символи)
            {
                throw std::invalid_argument("");        // генеруємо виняток
            }
            
            if (userChoice < 1 || userChoice > 3)       // якщо число не входить у допустимий діапазон меню
            {
                throw std::invalid_argument("");        // генеруємо виняток
            }

            return userChoice;                          // повертаємо коректно введене число (1, 2 або 3)
        }
        catch (const std::invalid_argument& e)          // перехоплюємо виняток некоректного введення
        {
            std::cout << "\nPomylka! Potribno vvesty tsile chyslo vid 1 do 3\nSprobuyte znovu: ";
        }
        catch (const std::out_of_range& e)              // перехоплюємо виняток виходу за межі типу int
        {
            std::cout << "\nPomylka! Chyslo zanadto velyke\nSprobuyte znovu: ";
        }
    }
}