#pragma once

#include "GameField.h"       // підключення заголовочного файлу GameField.h

struct GameController        // структура для керування ігровим процесом
{
    GameField field;         // змінна типу GameField, яка містить у собі стан ігрового поля
    int numberMove;          // кількість зроблених гравцем ходів
    bool isGameOver;         // вказує чи завершилася гра
};

// перевірка можливості ходу та переміщення обраної фішки
void makeMove();

// перевірка умови перемоги (чи складені всі фішки по порядку від 1 до N)
bool checkWin();
