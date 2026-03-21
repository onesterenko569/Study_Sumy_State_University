#include <iostream>
#include "UserInteraction.h"
#include "GameRecord.h"
#include "GameField.h"
#include "GameController.h"

int main()
{
    while (true)                                      // поки true
    {
        int userChoice = 1;                           // користувач вводить свій вибір (1 - Гра, 2 - Історія, 3 - Вихід)

        if (userChoice == 1)                          // якщо ввів 1
        {
            // std::string name = askUserName();      // введення ім'я користувача
            // int size = askFieldSize();             // введення розміру ігрового поля

            GameField field;                          // створюємо об'єкт ігрового поля
            int size = 4;                             // задаємо розмір ігрового поля

            field.initialField(size);                 // ініціалізуємо його розміром size

            // виведення початкового ініціалізованого поля
            std::cout << "Pochatkove pole:\n";
            field.printField();

            // беремо координати фішки вгорі від пустої клітинки та тестуємо canMove
            int x = 2;
            int y = 3;

            std::cout << "Perevirka canMove dlya koordynat (" << x + 1 << "; " << y + 1 << "):\n";

            if (field.canMove(x, y))                  // якщо можемо виконати хід  
            {
                std::cout << "Khid mozhlyvyy!\n";
            }
            else                                      // якщо не можемо виконати хід 
            {
                std::cout << "Khid nemozhlyvyy!\n";
            }

            // дізнаємося яка саме фішка стоїть за цими координатами щоб зробити хід
            int chipNumber = field.gameField[x][y];

            std::cout << "\nVykonannya khodu fishkoyu nomer " << chipNumber << " (perevirka makeMove):\n";

            if (field.makeMove(chipNumber))           // якщо хід виконано 
            {
                std::cout << "Khid uspishno vykonano! Novyy stan polya:\n";
                field.printField();                   // виведення поля
            }
            else                                      // якщо хід не виконано 
            {
                std::cout << "Pomylka! Khid ne vykonano\n";
            }

            std::cout << "Perevirka umovy vyhrashu (perevirka isWin):\n";
            if (field.isWin())                        // якщо гру виграно
            {
                std::cout << "Hru vyhrano!\n";
            }
            else                                      // якщо гру не виграно
            {
                std::cout << "Hru ne vyhrano!\n";
            }

            break;                                    // зупинка циклу
        }
        else if (userChoice == 2)             // якщо ввів 2
        {
            showRecordFromFile();             // виведення історії на екран
        }
        else if (userChoice == 3)             // якщо ввів 3
        { 
            return 0;                         // вихід з циклу
        }
        else                                  // якщо введено щось окрім 1, 2 та 3
        {
            std::cout << "Pomylka! Nepravylnyy vvid" << std::endl;
            continue;                         // розпочинаємо наступну ітерацію циклу
        }
    }

    return 0;
}