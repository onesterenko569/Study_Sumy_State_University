#pragma once

#include <iostream>
#include <string>
#include <vector>

// клас для зберігання інформації про користувача
class User
{
private:                                       // закриті дані класу
	std::string name;                          // змінна для зберігання імені користувача
	const int userID;                          // константна змінна для ідентифікатора
	int accessLevelIndex;                      // індекс рівня доступу (0 - User, 1 - Moderator, 2 - Admin)

	static int totalUsers;                     // статична змінна для підрахунку користувачів
	static int nextID;                         // статична змінна для генерації наступного ID
	static std::vector<std::string> accessLevels; // статичний вектор з назвами рівнів доступу

public:                                        // відкриті методи класу
	// конструктор з параметрами
	User(const std::string& userName, int accessIndex = 0);

	// деструктор для зменшення лічильника при видаленні користувача
	~User();

	// статичний метод для отримання загальної кількості користувачів
	static int getTotalUsers();

	// константний метод для формування рядка з інформацією про користувача
	std::string getUserInfo() const;

	// метод для зміни рівня доступу
	bool changeAccessLevel(int newLevel);
};