#include "User.h"

// ініціалізація статичних полів класу
int User::totalUsers = 0;                      // початкова кількість користувачів
int User::nextID = 1;                          // перший ID буде 1
std::vector<std::string> User::accessLevels = { "User", "Moderator", "Admin" }; // доступні рівні

// реалізація конструктора
User::User(const std::string& userName, int accessIndex) :
	name(userName), userID(nextID++), accessLevelIndex(accessIndex)
{
	totalUsers++;                              // збільшуємо загальну кількість користувачів при створенні об'єкта

	// перевірка чи індекс в межах допустимого
	if (accessLevelIndex < 0 || accessLevelIndex >= accessLevels.size())
	{
		accessLevelIndex = 0;
	}
}

// реалізація деструктора
User::~User()
{
	totalUsers--;                              // зменшуємо кількість при знищенні об'єкта
}

// реалізація статичного методу
int User::getTotalUsers()
{
	return totalUsers;                         // повертаємо кількість користувачів
}

// реалізація константного методу
std::string User::getUserInfo() const
{
	// повертаємо склеєний рядок з усіма даними
	return "ID: " + std::to_string(userID) + "\nName: " + name + "\nAccess: " + accessLevels[accessLevelIndex];
}

// реалізація методу зміни рівня доступу
bool User::changeAccessLevel(int newLevel)
{
	// перевіряємо, чи новий рівень знаходиться в допустимих межах вектора
	if (newLevel >= 0 && newLevel < accessLevels.size())
	{
		accessLevelIndex = newLevel;           // встановлюємо новий рівень
		return true;                           // успішна зміна
	}

	return false;                              // зміна не успішна
}