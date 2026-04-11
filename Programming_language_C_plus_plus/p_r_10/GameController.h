#pragma once

#include <fstream>             // підключення бібліотеки для роботи з файлами
#include <chrono>
#include "GameField.h"         // підключення заголовочного файлу GameField.h

struct GameController          // структура для керування ігровим процесом
{
    GameField field;           // змінна типу GameField, яка містить у собі ігрове поле
    int numberMove;            // кількість зроблених гравцем ходів

    std::ofstream gameHistory; // файловий потік для логування дій користувача

    // змінні для секундоміра
    std::chrono::steady_clock::time_point startTime; // час початку гри
    std::chrono::duration<double> totalTime;         // накопичений час гри

    // функція запуску гри
    void startGame();

    // функція обробки введення користувача
    int inputProcessing();

    // функція основного ігрового циклу
    void gameCycle();
};
