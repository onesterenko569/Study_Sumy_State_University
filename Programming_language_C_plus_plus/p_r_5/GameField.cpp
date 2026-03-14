#include <iostream>
#include <string>
#include <iomanip>
#include "GameField.h"

// функція ініціалізації поля
void GameField::initialField(int size)
{
    fieldSize = size;                                      // зберігаємо переданий розмір поля у структуру GameField
    gameStatus = game_active;                              // встановлюємо статус гри "Активна"

    gameField = new int* [fieldSize];                      // виділяємо пам'ять під масив вказівників (створюємо рядки матриці)

    for (int i = 0; i < fieldSize; i++)                    // цикл по рядках
    {
        gameField[i] = new int[fieldSize];                 // для кожного рядка виділяємо пам'ять під масив цілих чисел (створюємо стовпці)
    }

    int maxValue = fieldSize * fieldSize - 1;              // вираховуємо максимальне значення фішки

    for (int i = 0; i < fieldSize; i++)                    // цикл по рядках
    {
        for (int j = 0; j < fieldSize; j++)                // цикл по стовпцях
        {
            if (i == fieldSize - 1 && j == fieldSize - 1)  // якщо останній елемент грального поля
            {
                gameField[i][j] = 0;                       // надаємо значення 0

                emptyPoint.emptyRow = i;                   // запам'ятовуємо індекс рядка порожньої клітинки у структуру
                emptyPoint.emptyCol = j;                   // запам'ятовуємо індекс стовпця порожньої клітинки у структуру
            }
            else                                           // якщо не останній елемент грального поля
            {
                gameField[i][j] = maxValue;                // записуємо в неї поточне максимальне значення фішки
                maxValue--;                                // зменшуємо це значення на 1 для наступної клітинки
            }
        }
    }

    if (fieldSize % 2 == 0)                                // якщо розмір грального поля є парним
    {
        gameField[fieldSize - 1][fieldSize - 3] = 1;       // міняємо місцями фішки з номерами 1 і 2
        gameField[fieldSize - 1][fieldSize - 2] = 2;       // міняємо місцями фішки з номерами 1 і 2
    }
}

// функція виведення поля на екран
void GameField::printField()
{
    for (int i = 0; i < fieldSize; i++)              // цикл по рядках
    {
        if (i == 0)                                  // якщо це перший рядок, виводимо верхню межу матриці
        {
            std::cout << " ";
            std::cout << std::string((fieldSize * 6) - 1, '-') << std::endl;
        }
        else                                        // якщо це не перший рядок, виводимо міжрядкову межу матриці
        {
            std::cout << "|";
            std::cout << std::string((fieldSize * 6) - 1, '-');
            std::cout << "|" << std::endl;
        }

        std::cout << "|";                           // виведення крайньої лівої межі рядка

        for (int j = 0; j < fieldSize; j++)         // цикл по стовпцях
        {
            if (gameField[i][j] >= 10)              // якщо номер клітинки двохзначне число, виводимо клітинку з налаштованим форматом
            {
                std::cout << std::setw(4) << gameField[i][j] << std::setw(2) << "|";
            }
            else if (gameField[i][j] == 0)          // якщо пуста клітинка, виводимо знак підкреслення
            {
                std::cout << std::setw(3) << "_" << std::setw(3) << "|";
            }
            else                                    // якщо номер клітинки однозначне число, виводимо клітинку з налаштованим форматом
            {
                std::cout << std::setw(3) << gameField[i][j] << std::setw(3) << "|";
            }
        }

        std::cout << "\n";                          // для початку з нового рядка

        if (i == (fieldSize - 1))                   // якщо це останній рядок, виводимо нижню межу матриці    
        {
            std::cout << " ";
            std::cout << std::string((fieldSize * 6) - 1, '-') << std::endl;
        }
    }
}

// функція перевірки можливості ходу
bool GameField::canMove(int x, int y)
{
    // опис функції
}

// функція виконання ходу
void GameField::makeMove(int pointNumber)
{
    // опис функції
}

// функція перевірки умови виграшу
bool GameField::isWin()
{
    // опис функції
}