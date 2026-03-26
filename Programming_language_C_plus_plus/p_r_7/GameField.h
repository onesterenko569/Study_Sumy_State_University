#pragma once

#include <iostream>

#define MIN_FIELD_SIZE 3      // мінімальний розмір ігрового поля
#define MAX_FIELD_SIZE 9      // максимальний розмір ігрового поля

struct GameField              // структура для зберігання стану ігрового поля
{
    int fieldSize;            // розмір грального поля
    int** gameField;          // двовимірний масив для зберігання ігрового поля

    struct EmptyPoint         // структура для зберігання індексу рядка і стовпчика порожньої клітинки
    {
        int emptyRow;         // індекс рядка порожньої клітинки
        int emptyCol;         // індекс колонки порожньої клітинки
    } emptyPoint;

    enum GameStatus           // набір констант для збереження стану гри
    {
        game_active,          // гра активна
        game_won,             // гра виграна
        game_interrupted      // гра перервана користувачем
    } gameStatus;

    // функція ініціалізації поля
    void initialField(int size);

    // функція перевірки можливості ходу
    bool canMove(int x, int y);

    // перевантаження оператора ^ для виконання ходу
    bool operator^(int pointNumber);

    // функція перевірки умови виграшу
    bool isWin();
};

// перевантаження оператора << для виведення об'єкта GameField
std::ostream& operator<<(std::ostream& out, const GameField& var);