#pragma once

#include <string> // для string

struct GameRecord // структура для зберігання даних однієї гри
{
    std::string playerName;        // ім'я гравця
    std::string playDateBeginning; // дата та час початку гри
    std::string playDateEnd;       // дата та час закінчення гри
    int fieldSize;                 // розмір ігрового поля з яким грав користувач
    int numberMove;                // кількість зроблених гравцем ходів 
    int durationGame;              // тривалість гри у секундах
    bool isCompleted;              // чи пройшов гру до кінця (true) або здався (false)
};

// функція для збереження даних до .txt файлу
void saveRecordToFile();

// зчитування даних з .txt файлу та їх виведення
void showRecordFromFile();
