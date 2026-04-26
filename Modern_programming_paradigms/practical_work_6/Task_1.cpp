#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

// клас для зберігання інформації про книгу
class Book
{
private:                                       // закриті дані класу 
	int yearPublication;                       // змінна для зберігання року видання
	std::string title;                         // змінна для зберігання назви книги
	std::string author;                        // змінна для зберігання автора книги
	std::string bookID;                        // змінна для зберігання ID книги

	std::string currentReaderID;               // змінна для зберігання ID читача, який взяв книгу

public:                                        // відкриті методи класу
	// конструктор з параметрами для ініціалізації полів книги через список ініціалізації
	Book(int year, const std::string& name, const std::string& writer, const std::string& bookNum) :
		yearPublication(year), title(name), author(writer), bookID(bookNum), currentReaderID("") {}

	// метод для зміни року видання
	void setYearPublication(int newYear)
	{
		yearPublication = newYear;
	}

	// метод для отримання року видання
	int getYearPublication()
	{
		return yearPublication;
	}

	// метод для формування рядка з повною інформацією про книгу
	std::string getBookInfo() const
	{
		std::string reader;                    // змінна для збереження статусу книги

		if (currentReaderID.empty())           // якщо ID читача порожній
		{
			reader = "the book is free";       // книга вільна
		}
		else                                   // інакше записуємо ID читача
		{
			reader = currentReaderID;
		}

		// повертаємо склеєний рядок з усіма даними
		return "\n\nID: " + bookID + "\nTitle: " + title + "\nAuthor: " + author + "\nYear of publication: " + std::to_string(yearPublication) + "\nReader ID: " + reader;
	}

	// метод для отримання ID книги
	std::string getBookID() const
	{
		return bookID;
	}

	// метод для перевірки статусу доступності книги
	bool isAvailable() const
	{
		return currentReaderID.empty();
	}

	// метод для прив'язки читача до книги (видача)
	void addReader(const std::string& readerID)
	{
		currentReaderID = readerID;
	}

	// метод для відкріплення читача від книги (повернення)
	bool clearReader(const std::string readerID)
	{
		if (currentReaderID == readerID)       // перевіряємо, чи саме цей читач брав книгу
		{
			currentReaderID = "";              // очищаємо ID читача
			return true;                       // успішне відкріплення
		}

		return false;                          // якщо книга належить іншому читачу
	}
};

// клас для зберігання інформації про читача
class Reader
{
private:                                       // закриті дані класу
	std::string name;                          // змінна для зберігання імені читача
	std::string surname;                       // змінна для зберігання прізвища читача
	std::string readerID;                      // змінна для зберігання номера читацького квитка

	std::vector<std::string> takenBookID;      // вектор для зберігання ID всіх взятих цим читачем книг

public:                                        // відкриті методи класу
	// конструктор для ініціалізації читача
	Reader(const std::string& readerName, const std::string& readerSurname, const std::string& readerNum) :
		name(readerName), surname(readerSurname), readerID(readerNum) {}

	// метод для отримання ID читача
	std::string getReaderID() const
	{
		return readerID;
	}

	// метод для отримання кількості взятих книг
	int getCountBooks() const
	{
		return takenBookID.size();
	}

	// метод для додавання ID книги до списку взятих
	void setBook(const std::string& bookID)
	{
		takenBookID.push_back(bookID);
	}

	// метод для видалення ID книги зі списку (при поверненні)
	bool returnBook(const std::string& bookID)
	{
		for (int i = 0; i < takenBookID.size(); i++)        // проходимо по всьому вектору взятих книг
		{
			if (takenBookID[i] == bookID)                   // якщо знайшли потрібний ID
			{
				takenBookID.erase(takenBookID.begin() + i); // видаляємо елемент з вектора
				return true;                                // успішне видалення
			}
		}
		return false;                                       // якщо такої книги у читача немає
	}

	// метод для формування рядка з інформацією про читача та його книги
	std::string getReaderInfo() const
	{
		std::string booksList = "";                         // рядок для зберігання списку книг

		if (takenBookID.empty())                            // якщо взятих книг немає
		{
			booksList = "\nthe reader has no books yet";  
		}
		else                                                // якщо є взяті книги
		{
			for (int i = 0; i < takenBookID.size(); i++)    // проходимо по вектору
			{
				booksList += "\n  - Book ID: " + takenBookID[i]; // додаємо кожен ID до списку
			}
		}

		// повертаємо склеєний рядок з інформацією
		return "\n\nID: " + readerID + "\nName: " + name + "\nSurname: " + surname + "\nBooks taken: " + booksList;
	}
};

// головний клас, що виконує роль бази даних бібліотеки
class Library
{
private:                                                        // закриті дані класу
	std::string name;                                           // змінна для зберігання назви бібліотеки
	std::string address;                                        // змінна для зберігання адреси
	std::string workingHours;                                   // змінна для зберігання графіка роботи
	std::string phone;                                          // змінна для зберігання номеру телефону
	std::string email;                                          // змінна для зберігання електронної пошти

	std::vector<Book> books;                                    // вектор для зберігання об'єктів усіх книг бібліотеки
	std::vector<Reader> readers;                                // вектор для зберігання об'єктів усіх читачів

public:                                                         // відкриті методи класу
	// конструктор для ініціалізації базової інформації про бібліотеку
	Library(const std::string& lName, const std::string& laddres, const std::string& hour, const std::string& lphone, const std::string& lemail) :
		name(lName), address(laddres), workingHours(hour), phone(lphone), email(lemail) {}

	// метод для виведення інформації про бібліотеку
	void printLibraryInfo() const
	{
		std::cout << "\nLIBRARY INFORMATION:\n";
		std::cout << "\nName: " << name << "\nAddress: " << address << "\n\nWork schedule:\n" << workingHours << "\n\nPhone: " << phone << "\nEmail: " << email;
		std::cout << "\n\nNumber of books: " << books.size();
		std::cout << "\nNumber of readers: " << readers.size();
	}

	// метод для додавання нової книги
	void addBook(const Book& newBook)
	{
		books.push_back(newBook);
		std::cout << "\nThe book has been successfully added to the library!";
	}

	// метод для реєстрації нового читача
	void registerReader(const Reader& newReader)
	{
		readers.push_back(newReader);
		std::cout << "\nReader successfully authorized!";
	}

	// метод для видачі книги читачеві
	void issueBook(const std::string& bookID, const std::string& readerID)
	{
		int foundBookIndex = -1;                                 // індекс знайденої книги
		int foundReaderIndex = -1;                               // індекс знайденого читача

		// пошук книги за ID
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].getBookID() == bookID)
			{
				foundBookIndex = i;
				break;
			}
		}

		// пошук читача за ID
		for (int i = 0; i < readers.size(); i++)
		{
			if (readers[i].getReaderID() == readerID)
			{
				foundReaderIndex = i;
				break;
			}
		}

		if (foundBookIndex == -1)                                // якщо книгу не знайдено
		{
			std::cout << "\nBook with ID " << bookID << " not found!";
			return;
		}

		if (foundReaderIndex == -1)                              // якщо читача не знайдено
		{
			std::cout << "\nReader with ID " << readerID << " not found!";
			return;
		}

		if (!books[foundBookIndex].isAvailable())                // якщо книга зайнята
		{
			std::cout << "\nSorry, this book is already taken by another reader";
			return;
		}

		if (readers[foundReaderIndex].getCountBooks() == 5)      // перевірка на ліміт книг
		{
			std::cout << "\nSorry, but you are allowed to give 5 books per reader";
			return;
		}

		books[foundBookIndex].addReader(readerID);               // записуємо ID читача у книгу
		readers[foundReaderIndex].setBook(bookID);               // додаємо ID книги до читача

		std::cout << "\nSuccess! The book has been issued to the reader";
	}

	// метод для повернення книги в бібліотеку
	void returnBook(const std::string& bookID, const std::string& readerID)
	{
		int foundBookIndex = -1;                                 // індекс знайденої книги
		int foundReaderIndex = -1;                               // індекс знайденого читача

		// пошук книги за ID
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].getBookID() == bookID)
			{
				foundBookIndex = i;
				break;
			}
		}

		// пошук читача за ID
		for (int i = 0; i < readers.size(); i++)
		{
			if (readers[i].getReaderID() == readerID)
			{
				foundReaderIndex = i;
				break;
			}
		}

		if (foundBookIndex == -1)                                // якщо книгу не знайдено
		{
			std::cout << "\nBook with ID " << bookID << " not found!";
			return;
		}

		if (foundReaderIndex == -1)                              // якщо читача не знайдено
		{
			std::cout << "\nReader with ID " << readerID << " not found!";
			return;
		}

		if (books[foundBookIndex].clearReader(readerID))        // якщо вдалося відкріпити читача від книги
		{
			if (readers[foundReaderIndex].returnBook(bookID))   // якщо книгу успішно повернуто від читача
			{
				std::cout << "\nThe book has been successfully submitted!";
			}
			else                                                // якщо в читача не виявилося цієї книги
			{
				std::cout << "\nError! Reader with ID " << readerID << " does not have a book with ID " << bookID;
			}
		}
		else                                                    // якщо книга належить іншому читачеві
		{
			std::cout << "\nError! The book with ID " << bookID << " is not owned by the reader with ID " << readerID;
		}
	}

	// метод для виведення списку всіх книг
	void printBooks() const
	{
		std::cout << "\nInformation about all books:";
		
		if (books.empty())                                 // якщо вектор порожній
		{
			std::cout << "\nThe library has no books yet!";
			return;
		}
		
		for (int i = 0; i < books.size(); i++)             // проходимо по всіх книгах
		{
			std::cout << books[i].getBookInfo();           // виводимо інформацію про кожну книгу
			std::cout << "\n\n----------------------";
		}
	}

	// метод для виведення списку всіх читачів
	void printReaders() const
	{
		std::cout << "\nInformation about all readers:";

		if (readers.empty())                               // якщо вектор порожній
		{
			std::cout << "\nThe library has no readers yet!";
			return;
		}

		for (int i = 0; i < readers.size(); i++)          // проходимо по всіх читачах 
		{
			std::cout << readers[i].getReaderInfo();      // виводимо інформацію про кожного
			std::cout << "\n\n----------------------";
		}
	}

	// метод для зміни року видання конкретної книги
	void changeYearPublication(const std::string& bookID, const int newYear)
	{
		int foundBookIndex = -1;                      // індекс знайденої книги

		// пошук книги за ID
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].getBookID() == bookID)
			{
				foundBookIndex = i;
				break;
			}
		}

		if (foundBookIndex == -1)                     // якщо книгу не знайдено
		{
			std::cout << "\nBook with ID " << bookID << " not found!";
			return;
		}

		// викликаємо метод зміни року публікації для знайденої книги
		books[foundBookIndex].setYearPublication(newYear);

		std::cout << "\nPublication year successfully changed!";
	}
};

// функція для виведення головного меню програми
void printMenu()
{
	std::cout << "\n\nThe main menu of programs:";
	std::cout << "\n  1 - view library information";
	std::cout << "\n  2 - add a new book to the library";
	std::cout << "\n  3 - register a new reader";
	std::cout << "\n  4 - issue a book to a reader";
	std::cout << "\n  5 - return a book to the library";
	std::cout << "\n  6 - show all books in the library";
	std::cout << "\n  7 - show all readers";
	std::cout << "\n  8 - change the year of publication of a book";
	std::cout << "\n  0 - exit the program";
	std::cout << "\n\nYour choice: ";
}

// функція для безпечного введення числа з перевіркою меж та типу
int inputProcessing(const int minVal, const int maxVal)
{
	std::string inputStr;                          // змінна для зберігання введеного рядка тексту
	int val;                                       // змінна для збереження введеного числа

	while (true)                                   // нескінченний цикл для перевірки правильності введення
	{
		std::getline(std::cin, inputStr);          // зчитуємо весь введений рядок з консолі

		try                                        // блок для перехоплення можливих помилок
		{
			size_t pos;                            // змінна для збереження індексу першого символу, який не є числом

			val = stoi(inputStr, &pos);            // конвертуємо рядок у тип int та записуємо позицію зупинки

			if (pos < inputStr.length())           // якщо оброблено не весь рядок (є зайві символи)
			{
				throw std::invalid_argument("");
			}
			if (val < minVal)                      // якщо число менше допустимого
			{
				throw std::logic_error("\nError! The minimum allowed value is " + std::to_string(minVal) + "\nTry again: ");
			}
			if (val > maxVal)                      // якщо число більше допустимого
			{
				throw std::logic_error("\nError! The maximum allowed value is " + std::to_string(maxVal) + "\nTry again: ");
			}

			return val;                            // повертаємо коректне число
		}
		catch (const std::invalid_argument)        // перехоплюємо помилку неправильного формату введення
		{
			std::cerr << "\nError! You must enter an integer\nTry again: ";
		}
		catch (const std::logic_error& e)          // перехоплюємо помилку виходу за межі
		{
			std::cout << e.what();
		}
		catch (const std::out_of_range)            // перехоплюємо переповнення типу int
		{
			std::cout << "\nError! int data type size exceeded\nTry again: ";
		}
	}
}

// головна функція програми
int main()
{
	// створення об'єкта бібліотеки та ініціалізація стартовими параметрами
	Library library("Sumy City Central Library", "15 Soborna Street, Sumy, Ukraine",
		"   Mon-Fri: 9:00 AM - 7:00 PM;\n   Sat: 10:00 AM - 5:00 PM;\n   Sun: Closed",
		"+380 542 123 456", "info@sumylibrary.ua");

	bool running = true;                                      // прапорець для керування головним циклом програми

	while (running)                                           // головний цикл, що працює доки користувач не натисне 0
	{
		printMenu();                                          // виводимо меню

		int userChoice = inputProcessing(0, 8);               // безпечно зчитуємо вибір користувача

		switch (userChoice)                                   // обробка вибору користувача
		{
		case 1:                                               // пункт меню: інформація про бібліотеку
		{
			library.printLibraryInfo();                       // виклик відповідного методу бібліотеки
			break;
		}

		case 2:                                               // пункт меню: додавання книги
		{
			int year;                                         // змінна для року
			std::string title, author, bookID;                // змінні для текстових даних

			// введення назви книги
			std::cout << "\nEnter title: ";
			std::getline(std::cin, title);

			// введення автора
			std::cout << "Enter author: ";
			std::getline(std::cin, author);

			// введення року публікації
			std::cout << "Enter publication year (1440 - 2026): ";
			year = inputProcessing(1440, 2026);

			// введення ID книги
			std::cout << "Enter book ID: ";
			std::getline(std::cin, bookID);

			Book tempBook(year, title, author, bookID);       // створюємо тимчасовий об'єкт книги
			library.addBook(tempBook);                        // передаємо об'єкт у базу бібліотеки

			break;
		}

		case 3:                                               // пункт меню: реєстрація читача
		{
			std::string name, surname, readerID;              // змінні для даних читача

			// введення ім'я читача
			std::cout << "\nEnter name: ";
			std::getline(std::cin, name);

			// введення прізвища читача
			std::cout << "Enter surname: ";
			std::getline(std::cin, surname);

			// введення ID читача
			std::cout << "Enter reader ID: ";
			std::getline(std::cin, readerID);

			Reader tempReader(name, surname, readerID);       // створюємо тимчасовий об'єкт читача
			library.registerReader(tempReader);               // передаємо його в базу бібліотеки

			break;
		}

		case 4:                                               // пункт меню: видача книги
		{
			std::string bID, rID;                             // змінні для пошуку

			// введення ID книги
			std::cout << "\nEnter the book ID: ";
			std::getline(std::cin, bID);

			// введення ID читача
			std::cout << "Enter the reader ID: ";
			std::getline(std::cin, rID);

			library.issueBook(bID, rID);                      // викликаємо метод бібліотеки для зв'язування

			break;
		}

		case 5:                                               // пункт меню: повернення книги
		{
			std::string bID, rID;                             // змінні для пошуку

			// введення ID книги
			std::cout << "\nEnter the ID of the book we are returning: ";
			std::getline(std::cin, bID);

			// введення ID читача
			std::cout << "Enter the ID of the reader from whom we are taking the book: ";
			std::getline(std::cin, rID);

			library.returnBook(bID, rID);                     // викликаємо метод бібліотеки для роз'єднання

			break;
		}

		case 6:                                               // пункт меню: показати всі книги
		{
			library.printBooks();                             // виклик методу бібліотеки
			break;
		}

		case 7:                                               // пункт меню: показати всіх читачів
		{
			library.printReaders();                           // виклик методу бібліотеки
			break;
		}

		case 8:                                               // пункт меню: змінити рік видання
		{
			std::string bookID;

			// введення ID книги
			std::cout << "\nEnter the ID of the book you want to change the publication year for: ";
			std::getline(std::cin, bookID);

			// введення нового року публікації книги
			std::cout << "Enter the new year of publication of the book: ";
			int newYear = inputProcessing(1440, 2026);

			library.changeYearPublication(bookID, newYear);   // викликаємо метод оновлення

			break;
		}

		case 0:                                               // пункт меню: вихід
		{
			std::cout << "\nWhen you read, you live several lives" << std::endl;
			running = false;                                  // змінюємо прапорець, щоб розірвати цикл while
			break;
		}

		default:                                              // якщо щось пішло не так
		{
			std::cout << "\nUnknown error!";
			break;
		}
		}
	}

	return 0;                                                 // успішне завершення програми
}
