#include <iostream>
#include <string>
#include <iomanip>
#include "GameField.h"

// функція ініціалізації поля
void GameField::initialField(int size)
{
    fieldSize = size;                                      // зберігаємо переданий розмір поля у структуру GameField

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

// перевантаження оператора << для виведення об'єкта GameField
std::ostream& operator<<(std::ostream& out, const GameField& var)
{
    for (int i = 0; i < var.fieldSize; i++)             // цикл по рядках
    {
        if (i == 0)                                     // якщо це перший рядок, виводимо верхню межу матриці
        {
            out << " ";
            out << std::string((var.fieldSize * 6) - 1, '-') << std::endl;
        }
        else                                            // якщо це не перший рядок, виводимо міжрядкову межу матриці
        {
            out << "|";
            out << std::string((var.fieldSize * 6) - 1, '-');
            out << "|" << std::endl;
        }

        out << "|";                                     // виведення крайньої лівої межі рядка

        for (int j = 0; j < var.fieldSize; j++)         // цикл по стовпцях
        {
            if (var.gameField[i][j] >= 10)              // якщо номер клітинки двохзначне число, виводимо клітинку з налаштованим форматом
            {
                out << std::setw(4) << var.gameField[i][j] << std::setw(2) << "|";
            }
            else if (var.gameField[i][j] == 0)          // якщо пуста клітинка, виводимо знак підкреслення
            {
                out << std::setw(3) << "_" << std::setw(3) << "|";
            }
            else                                        // якщо номер клітинки однозначне число, виводимо клітинку з налаштованим форматом
            {
                out << std::setw(3) << var.gameField[i][j] << std::setw(3) << "|";
            }
        }

        out << "\n";                                    // для початку з нового рядка

        if (i == (var.fieldSize - 1))                   // якщо це останній рядок, виводимо нижню межу матриці    
        {
            out << " ";
            out << std::string((var.fieldSize * 6) - 1, '-') << std::endl;
        }
    }

    return out;                                         // повернення потока виводу для можливості ланцюжкового виведення
}

// функція перевірки можливості ходу
bool GameField::canMove(int x, int y)
{
    if (x <= (fieldSize - 1) && y <= (fieldSize - 1) && x >= 0 && y >= 0) // якщо обрано фішку в межах ігрового поля
    {
        if (x == emptyPoint.emptyRow && (y + 1 == emptyPoint.emptyCol || y - 1 == emptyPoint.emptyCol)) // якщо сусідня фішка справа чи зліва є пустою
        {
            return true;  // повертаємо ознаку того, що можемо виконати переміщення
        }
        else if (y == emptyPoint.emptyCol && (x + 1 == emptyPoint.emptyRow || x - 1 == emptyPoint.emptyRow)) // якщо сусідня фішка вгорі чи внизу є пустою
        {
            return true;  // повертаємо ознаку того, що можемо виконати переміщення
        }
        else              // якщо немає пустої фішки вгорі чи внизу чи зліва чи справа
        {
            return false; // повертаємо ознаку того, що не можемо виконати переміщення
        }
    }
    else                  // якщо обрано фішку за межами ігрового поля
    {
        return false;     // повертаємо ознаку того, що не можемо виконати переміщення
    }
}

// перевантаження оператора ^ для виконання ходу
bool GameField::operator^(int pointNumber)
{
    int iFound, jFound;                         // змінні для запам'ятовування координат фішки pointNumber
    bool found = false;                         // прапорець для відображення чи знайдено фішку з номером pointNumber

    for (int i = 0; i < fieldSize; i++)         // цикл по рядках
    {
        for (int j = 0; j < fieldSize; j++)     // цикл по стовпцях
        {
            if (gameField[i][j] == pointNumber) // якщо фішку з номером pointNumber знайдено
            {
                iFound = i;                     // запам'ятовуємо координату рядка
                jFound = j;                     // запам'ятовуємо координату стовпця

                found = true;                   // позначаємо що фішку знайдено
                break;                          // зупиняємо внутрішній цикл
            }
        }

        if (found)                              // якщо фішку знайдено
        {
            break;                              // зупиняємо зовнішній цикл
        }
    }

    if (!found)                                 // якщо фішку не знайдено
    {
        return false;                           // повертаємо ознаку, що хід зробити неможливо
    }

    if (canMove(iFound, jFound))                // якщо хід для pointNumber можлививй
    {
        // міняємо місцями пусту фішку з pointNumber
        gameField[emptyPoint.emptyRow][emptyPoint.emptyCol] = pointNumber;
        gameField[iFound][jFound] = 0;

        // запам'ятовуємо координати пустої фішки
        emptyPoint.emptyRow = iFound;
        emptyPoint.emptyCol = jFound;

        return true;                            // повертаємо ознаку, що хід зроблений 
    }
    else                                        // якщо хід для pointNumber неможлививй
    {
        return false;                           // повертаємо ознаку, що хід зробити неможливо
    }
}

// функція перевірки умови виграшу
bool GameField::isWin()
{
    int val = 1;                                          // змінна для зберігання очікуваного значення фішки

    for (int i = 0; i < fieldSize; i++)                   // цикл по рядках 
    {
        for (int j = 0; j < fieldSize; j++)               // цикл по стовпцях
        {
            if (i == fieldSize - 1 && j == fieldSize - 1) // якщо остання фішка
            {
                if (gameField[i][j] != 0)                 // якщо значення останньої фішки не 0
                {
                    return false;                         // повертаємо ознаку, що гра ще не виграна
                }
            }
            else if (gameField[i][j] != val)              // якщо значення поточної фішки відрізняється від очікуваного
            {
                return false;                             // повертаємо ознаку, що гра ще не виграна
            }

            val++;                                        // збільшуємо очікуване значення для перевірки наступної фішки
        }
    }

    return true;                                          // якщо всі фішки стоять на своїх місцях і остання пуста, повертаємо ознаку виграшу
}