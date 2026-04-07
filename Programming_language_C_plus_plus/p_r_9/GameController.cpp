#include <iostream>
#include <string>
#include <stdexcept>
#include "GameController.h"

// функція запуску гри
void GameController::startGame()
{
    std::string inputStr;                                  // оголошення змінної типу string для введення тексту

    std::cout << "\nVvedit rozmir hralnoho polya: ";

    while (true)                                           // нескінченний цикл для перевірки правильності введення
    {
        std::getline(std::cin, inputStr);                  // зчитуємо весь введений рядок з консолі

        try                                                // блок для перехоплення можливих помилок
        {
            size_t pos;                                    // змінна для збереження індексу першого символу у рядку, який не є числом

            field.fieldSize = std::stoi(inputStr, &pos);   // конвертуємо рядок у ціле число та записуємо у структуру поля
            
            if (pos < inputStr.length())                   // якщо введено літери або зайві символи
            {
                throw std::invalid_argument(""); // генеруємо виняток про некоректне введення
            }
            if (field.fieldSize < MIN_FIELD_SIZE)          // якщо введений розмір менший за мінімально допустимий
            {
                throw std::out_of_range("\nPomylka! Minimalnyy rozmir hralnoho polya - " + std::to_string(MIN_FIELD_SIZE) + "\nSprobuyte znovu: "); // генеруємо виняток про вихід за нижню межу
            }
            if (field.fieldSize > MAX_FIELD_SIZE)          // якщо введений розмір більший за максимально допустимий
            {
                throw std::out_of_range("\nPomylka! Maksymalnyy rozmir hralnoho polya - " + std::to_string(MAX_FIELD_SIZE) + "\nSprobuyte znovu: "); // генеруємо виняток про вихід за верхню межу
            }
            
            std::cout << "\nRozmir hralnoho polya uspishno vvedeno!\nStvorene pole:\n\n"; // повідомляємо про успішне введення
            break;                                         // зупиняємо цикл, оскільки розмір введено правильно
        }
        catch (const std::invalid_argument& e)             // перехоплюємо виняток некоректного введення
        {
            std::cout << "\nPomylka! Potribno vvesty tsile chyslo\nSprobuyte znovu: "; // виводимо повідомлення про помилку на екран
        }
        catch (const std::out_of_range& e)                 // перехоплюємо виняток виходу за межі
        {
            std::cout << e.what();                         // виводимо повідомлення про помилку на екран
        }
    }

    field.initialField(field.fieldSize);                   // ініціалізуємо гральне поле введеним розміром
    field.gameStatus = GameField::game_active;             // встановлюємо статус гри "Активна"

    numberMove = 0;                                        // обнуляємо лічильник кількості ходів

    gameCycle();                                           // запускаємо основний ігровий цикл

    for (int i = 0; i < field.fieldSize; i++)              // цикл по рядках грального поля
    {
        delete[] field.gameField[i];                       // звільняємо пам'ять, виділену під стовпці
    }

    delete[] field.gameField;                              // звільняємо пам'ять, виділену під масив вказівників
}

// функція обробки введення користувача
int GameController::inputProcessing() 
{
    int chipNumber;                                        // змінна для збереження номера обраної фішки
    std::string inputStr;                                  // змінна для зберігання введеного рядка

    std::cout << "\nVvedit nomer fishky (abo Space + Enter dlya pauzy): ";

    while (true)                                           // нескінченний цикл перевірки правильності введення
    {
        // введення номеру фішки або Space + Enter для паузи
        std::getline(std::cin, inputStr);

        if (!inputStr.empty() && inputStr[0] == ' ')       // якщо рядок не порожній і його перший символ це пробіл
        {
            std::string pauseStr;                          // змінна для збереження вибору в меню паузи

            // виведення тексту меню
            std::cout << "\nHRU ZUPYNENO";
            std::cout << "\n0 - zavershyty gru";
            std::cout << "\n1 - prodovzhyty gru";
            std::cout << "\n\nVash vybir: ";

            while (true)                                   // нескінченний цикл для перевірки вибору в паузі
            {
                std::getline(std::cin, pauseStr);          // зчитуємо вибір користувача

                if (pauseStr == "0")                       // якщо користувач обрав завершення гри
                {
                    return 0;                              // повертаємо 0
                }
                else if (pauseStr == "1")                  // якщо користувач обрав продовження гри
                {
                    std::cout << "\nHru prodovzheno!\n\nVvedit nomer fishky (abo Space + Enter dlya pauzy): "; // виводимо повідомлення про продовження
                    break;                                 // виходимо з внутрішнього циклу паузи
                }
                else                                       // якщо введено некоректний символ
                {
                    std::cout << "\nPomylka! Potribno vvesty 0 abo 1\nSprobuyte znovu: "; // виводимо повідомлення про помилку
                }
            }

            continue;                                      // розпочинаємо нову ітерацію запиту ходу
        }

        try                                                // блок для перехоплення можливих винятків при конвертації
        {
            size_t pos;                                    // змінна для збереження позиції обробленого символу
            
            chipNumber = std::stoi(inputStr, &pos);        // конвертуємо рядок у ціле число

            if (chipNumber == 0)                           // якщо введено 0
            {
                throw std::invalid_argument("");           // генеруємо виняток про некоректний аргумент
            }

            if (pos < inputStr.length())                   // якщо оброблено не весь рядок (введено літери чи зайві символи)
            {
                throw std::invalid_argument("Pomylka vvedennya"); // генеруємо виняток про некоректний аргумент
            }

            return chipNumber;                             // повертаємо коректно введений номер фішки
        }
        catch (const std::invalid_argument& e)             // перехоплюємо виняток некоректного введення
        {
            std::cout << "\nPomylka! Potribno vvesty tsile chyslo okrim 0\nSprobuyte znovu: ";
        }
        catch (const std::out_of_range& e)                 // перехоплюємо виняток виходу за межі типу int
        {
            std::cout << "\nPomylka! Chyslo zanadto velyke\nSprobuyte znovu: ";
        }
    }
}

// функція основного ігрового циклу
void GameController::gameCycle()
{
    while (field.gameStatus == GameField::game_active)     // цикл працює поки статус гри "Активна"
    {
        std::cout << field;                                // виводимо поточний стан грального поля на екран

        int chipNumber = inputProcessing();                // отримуємо номер фішки для ходу від користувача

        if (chipNumber == 0)                               // якщо функція обробки повернула 0
        {
            std::cout << "\nHru zaversheno!\n";            // виводимо повідомлення про завершення гри
            field.gameStatus = GameField::game_interrupted;// змінюємо статус ігрового поля на "Перервана"
            break;                                         // виходимо з ігрового циклу
        }

        try                                                // блок виконання ходу та перевірки помилок
        {
            field^ chipNumber;                             // намагаємося виконати хід
        
            numberMove++;                                  // збільшуємо лічильник ходів

            std::cout << "\nKhid uspishno vykonano!\n\n";

            if (field.isWin())                             // якщо поточний стан поля переможний
            {
                field.gameStatus = GameField::game_won;    // змінюємо статус ігрового поля на "Виграна"
                std::cout << field;                        // виводимо фінальний стан поля на екран
                std::cout << "\nVitayemo! Hru vyhrano";    // виводимо повідомлення про перемогу
                std::cout << "\nKilkist zroblenykh khodiv - " << numberMove << std::endl; // виводимо загальну кількість зроблених ходів
                break;                                     // виходимо з ігрового циклу
            }
        }
        catch (const std::exception& e)                   // ловимо стандартну помилку (invalid_argument або logic_error)
        {
            std::cout << e.what();                        // виводимо текст спійманої помилки на екран
        }
    }
}