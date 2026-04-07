#pragma once

#include "GameField.h"       // підключення заголовочного файлу GameField.h

struct GameController        // структура для керування ігровим процесом
{
    GameField field;         // змінна типу GameField, яка містить у собі ігрове поле
    int numberMove;          // кількість зроблених гравцем ходів

    // функція запуску гри
    void startGame();

    // функція обробки введення користувача
    int inputProcessing();

    // функція основного ігрового циклу
    void gameCycle();
};
