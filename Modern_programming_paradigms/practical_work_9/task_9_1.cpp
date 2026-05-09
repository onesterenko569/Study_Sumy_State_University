#include <iostream>
#include <string>

class User;                                                 // попереднє оголошення класу

class Library                                               // клас для зберігання інформації про бібліотеку
{
	friend void issueBook(Library& lib, User& usr);         // оголошення дружньої функції

private:
	std::string name;                                       // змінна для зберігання назви бібліотеки
	int numberBooks;                                        // змінна для зберігання кількості доступних книг
	bool isSystemOnline;                                    // прапорець для статусу роботи електронної бази

public:
	// конструктор для ініціалізації полів бібліотеки
	Library(const std::string& n, const int numB, const bool isOnline) :
		name(n), numberBooks(numB), isSystemOnline(isOnline) {}
};

class User                                                  // клас для зберігання інформації про користувача
{
	friend void issueBook(Library& lib, User& usr);         // оголошення дружньої функції

private:
	std::string name;                                       // змінна для зберігання імені користувача
	int desiredNumberBooks;                                 // змінна для зберігання бажаної кількості книг
	bool hasUnreturnedBooks;                                // прапорець для перевірки наявності неповернутих книг

public:
	// конструктор для ініціалізації полів користувача
	User(const std::string& n, const int numB, const bool hasUB) :
		name(n), desiredNumberBooks(numB), hasUnreturnedBooks(hasUB) {}
};

// функція для перевірки та видачі книг
void issueBook(Library& lib, User& usr)
{
	if (!lib.isSystemOnline)                           // якщо електронна база бібліотеки не працює
	{
		std::cout << "\nError! The library's electronic database \"" << lib.name << "\" is temporarily unavailable";
	}
	else if (usr.hasUnreturnedBooks)                   // якщо у користувача є неповернуті книги
	{
		std::cout << "\nError! A reader named " << usr.name << " has unreturned books";
	}
	else if (usr.desiredNumberBooks > lib.numberBooks) // якщо користувач просить більше книг, ніж є в наявності
	{
		std::cout << "\nError! There are not enough books in the library";
	}
	else if (usr.desiredNumberBooks > 5)               // якщо користувач перевищує ліміт у 5 книг
	{
		std::cout << "\nError! User can take no more than 5 books";
	}
	else                                               // якщо жодна з умов відмови не спрацювала
	{
		lib.numberBooks -= usr.desiredNumberBooks;
		std::cout << "\nBooks have been successfully issued";
	}
}

// головна функція програми
int main()
{
	// створення об'єктів класу Library
	Library sumduLib("SumDU Library", 10, true);
	Library offlineLib("Sumy Central Library", 50, false);

	// створення об'єктів класу User
	User artem("Artem", 3, false);
	User julia("Julia", 2, true);
	User volodymyr("Volodymyr", 6, false);
	User peter("Peter", 15, false);

	// видача книг 1 читачу
	std::cout << "Issuance of books to Artem";
	issueBook(sumduLib, artem);

	// видача книг 2 читачу
	std::cout << "\n\nIssuance of books to Julia";
	issueBook(sumduLib, julia);

	// видача книг 3 читачу
	std::cout << "\n\nIssuance of books to Volodymyr";
	issueBook(sumduLib, volodymyr);

	// видача книг 4 читачу
	std::cout << "\n\nIssuance of books to Peter";
	issueBook(sumduLib, peter);

	// видача книг 1 читачу
	std::cout << "\n\nIssuance of books to Artem";
	issueBook(offlineLib, artem);

	std::cout << std::endl;
	return 0;
}
