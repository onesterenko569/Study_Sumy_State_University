#include <iostream>
#include "UserInteraction.h"
#include "GameRecord.h"
#include "GameField.h"
#include "GameController.h"

int main()
{
    while (true)                              // поки True
    {
        int userChoice = showMainMenu();      // користувач вводить свій вибір (1 - Гра, 2 - Історія, 3 - Вихід)

        if (userChoice == 1)                  // якщо ввів 1
        {
            std::string name = askUserName(); // введення ім'я користувача
            int size = askFieldSize();        // введення розміру ігрового поля
            // запуск гри
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