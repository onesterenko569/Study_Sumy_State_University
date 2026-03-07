#pragma once

#include <string>             // ПАИПА?? string
#include "GameField.h" // ??????????? ????????????? ????? GameField.h

// виведення вітання, правила гри та повернення вибору користувача (1 - Нова гра, 2 - Історія, 3 - Вихід)
int showMainMenu();

// введення користувачем його імені
std::string askUserName();

// введення розміру ігрового поля з перевіркою введення (MIN_FIELD_SIZE, MAX_FIELD_SIZE)
int askFieldSize();

// виведення ігрового поля на екран

void printGameField();

// введення номеру фішки яку користувач хоче перетягнути (якщо ввів 0 - завершення гри)
int askTileNumber();

// виведення повідомлення про перемогу
void showWinMessage();

// виведення повідомлення про поразку (ввів 0)
void showGiveUpMessage();