#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

// клас для керування файловою базою даних студентів
class StudentDatabase
{
private:
	std::string filename;                              // змінна для зберігання імені файлу

	// метод для автоматичної генерації наступного ID
	int getNextID() const
	{
		std::ifstream fin(filename);                   // відкриваємо файл для читання

		if (!fin.is_open())                            // якщо файлу ще немає
		{
			return 1;                                  // перший ID буде 1
		}

		int maxID = 0;                                 // змінна для збереження найбільшого ID
		std::string line;                              // змінна для зчитування рядка

		while (std::getline(fin, line))                // читаємо файл рядок за рядком
		{
			if (line.empty())                          // пропускаємо порожні рядки
			{
				continue;
			}

			std::stringstream ss(line);                // перетворюємо рядок на потік
			std::string idStr;                         // тимчасова змінна для ID

			std::getline(ss, idStr, ';');              // читаємо тільки до першої крапки з комою

			try
			{
				int currentID = std::stoi(idStr);      // конвертуємо рядок у число
				if (currentID > maxID)                 // знаходимо найбільший ID
				{
					maxID = currentID;
				}
			}
			catch (...) {}                             // ігноруємо можливі помилки конвертації
		}

		fin.close();                                   // закриваємо файл
		return maxID + 1;                              // повертаємо наступний вільний номер
	}

public:
	// конструктор для ініціалізації бази даних
	StudentDatabase(const std::string& fName) : filename(fName) {}

	// метод для додавання нового студента у файл
	void addStudent(const std::string& name, const std::string& group, double grade)
	{
		// відкриваємо файл у режимі дозапису
		std::ofstream fout(filename, std::ios::app);

		if (!fout.is_open())                           // перевірка на успішне відкриття
		{
			std::cout << "\nError! Cannot open file for writing!";
			return;
		}

		int newID = getNextID();                       // генеруємо новий ID

		// записуємо дані у файл, використовуючи ; як розділювач
		fout << newID << ";" << name << ";" << group << ";" << grade << "\n";

		fout.close();                                  // закриваємо файл
		std::cout << "\nStudent successfully added to the database!";
	}

	// метод для виведення всіх студентів у вигляді форматованої таблиці
	void printAllStudents() const
	{
		std::ifstream fin(filename);                   // відкриваємо файл для читання

		if (!fin.is_open())                            // перевірка наявності файлу
		{
			std::cout << "\nDatabase is empty or file not found!";
			return;
		}

		// малюємо шапку таблиці з використанням маніпуляторів форматування
		std::cout << "\n" << std::string(78, '-');
		std::cout << "\n| " << std::left << std::setw(5) << "ID" << "| "
			<< std::setw(40) << "Full Name" << "| " << std::setw(12)
			<< "Group" << "| " << std::setw(12) << "Avg Grade" << "|";
		std::cout << "\n" << std::string(78, '-');

		std::string line;                              // змінна для зчитування рядка
		int count = 0;                                 // лічильник студентів

		while (std::getline(fin, line))                // читаємо файл до кінця
		{
			if (line.empty())                          // пропускаємо порожні рядки
			{
				continue;
			}

			std::stringstream ss(line);                // перетворюємо рядок на потік
			std::string id, name, group, grade;        // змінні для зберігання частин рядка

			// розбиваємо рядок на змінні до символу ;
			std::getline(ss, id, ';');
			std::getline(ss, name, ';');
			std::getline(ss, group, ';');
			std::getline(ss, grade, ';');

			// виводимо відформатований рядок у консоль
			std::cout << "\n| " << std::left << std::setw(5) << id
				<< "| " << std::setw(40) << name
				<< "| " << std::setw(12) << group
				<< "| " << std::setw(12) << grade << "|";

			count++;
		}
		fin.close();                                   // закриваємо файл

		std::cout << "\n" << std::string(78, '-');
		std::cout << "\nTotal students: " << count;
	}

	// метод для пошуку студентів за назвою групи
	void searchByGroup(const std::string& searchGroup) const
	{
		std::ifstream fin(filename);                   // відкриваємо файл для читання

		if (!fin.is_open())
		{
			std::cout << "\nDatabase is empty or file not found!";
			return;
		}

		std::cout << "\nSearch results for group: " << searchGroup;
		std::cout << "\n" << std::string(78, '-');

		std::string line;
		int count = 0;

		while (std::getline(fin, line))
		{
			if (line.empty())
			{
				continue;
			}

			std::stringstream ss(line);
			std::string id, name, group, grade;

			std::getline(ss, id, ';');
			std::getline(ss, name, ';');
			std::getline(ss, group, ';');
			std::getline(ss, grade, ';');

			if (group == searchGroup)                  // якщо група збігається з шуканою
			{
				std::cout << "\n| " << std::left << std::setw(5) << id
					<< "| " << std::setw(40) << name
					<< "| " << std::setw(12) << group
					<< "| " << std::setw(12) << grade << "|";

				count++;
			}
		}
		fin.close();

		std::cout << "\n" << std::string(78, '-');
		if (count == 0)
		{
			std::cout << "\nNo students found in this group";
		}
	}

	// метод для видалення студента за його ID
	void deleteStudent(int targetID)
	{
		std::ifstream fin(filename);                   // відкриваємо файл для читання

		if (!fin.is_open())
		{
			std::cout << "\nDatabase is empty or file not found!";
			return;
		}

		std::vector<std::string> lines;                // вектор для тимчасового зберігання рядків
		std::string line;
		bool isFound = false;                          // прапорець, чи знайшли ми студента

		while (std::getline(fin, line))                // читаємо всі записи
		{
			if (line.empty())
			{
				continue;
			}

			std::stringstream ss(line);
			std::string idStr;
			std::getline(ss, idStr, ';');              // дістаємо ID

			try
			{
				if (std::stoi(idStr) == targetID)      // якщо це той студент, якого треба видалити
				{
					isFound = true;
					continue;                          // пропускаємо запис
				}
			}
			catch (...) {}

			lines.push_back(line);                     // зберігаємо всі інші записи
		}
		fin.close();                                   // закриваємо файл після читання

		if (!isFound)                                  // якщо студента не було знайдено
		{
			std::cout << "\nError! Student with ID " << targetID << " not found!";
			return;
		}

		// відкриваємо файл для очищення вмісту перед записом
		std::ofstream fout(filename, std::ios::trunc);

		for (int i = 0; i < lines.size(); i++)         // записуємо оновлені дані назад у файл
		{
			fout << lines[i] << "\n";
		}

		fout.close();                                  // закриваємо файл
		std::cout << "\nStudent successfully deleted!";
	}
};

// функція для виведення головного меню програми
void printMenu()
{
	std::cout << "\n\nThe main menu of programs:";
	std::cout << "\n  1 - view all students in table";
	std::cout << "\n  2 - add a new student";
	std::cout << "\n  3 - search students by group";
	std::cout << "\n  4 - delete student by ID";
	std::cout << "\n  0 - exit the program";
	std::cout << "\n\nYour choice: ";
}

// функція для безпечного введення цілого числа
int inputProcessingInt(const int minVal, const int maxVal)
{
	std::string inputStr;
	int val;

	while (true)
	{
		std::getline(std::cin, inputStr);

		try
		{
			size_t pos;
			val = stoi(inputStr, &pos);

			if (pos < inputStr.length())
			{
				throw std::invalid_argument("");
			}
			if (val < minVal)
			{
				throw std::logic_error("\nError! The minimum allowed value is " + std::to_string(minVal) + "\nTry again: ");
			}
			if (val > maxVal)
			{
				throw std::logic_error("\nError! The maximum allowed value is " + std::to_string(maxVal) + "\nTry again: ");
			}

			return val;
		}
		catch (const std::invalid_argument)
		{
			std::cerr << "\nError! You must enter an integer\nTry again: ";
		}
		catch (const std::logic_error& e)
		{
			std::cout << e.what();
		}
		catch (const std::out_of_range)
		{
			std::cout << "\nError! Data type size exceeded\nTry again: ";
		}
	}
}

// функція для безпечного введення дробового числа
double inputProcessingDouble(const double minVal, const double maxVal)
{
	std::string inputStr;
	double val;

	while (true)
	{
		std::getline(std::cin, inputStr);

		try
		{
			size_t pos;
			val = stod(inputStr, &pos);

			if (pos < inputStr.length())
			{
				throw std::invalid_argument("");
			}
			if (val < minVal || val > maxVal)
			{
				throw std::logic_error("\nError! Grade must be between " + std::to_string(minVal) + " and " + std::to_string(maxVal) + "\nTry again: ");
			}

			return val;
		}
		catch (const std::invalid_argument)
		{
			std::cerr << "\nError! You must enter a number\nTry again: ";
		}
		catch (const std::logic_error& e)
		{
			std::cout << e.what();
		}
		catch (const std::out_of_range)
		{
			std::cout << "\nError! Data type size exceeded\nTry again: ";
		}
	}
}

// головна функція програми
int main()
{
	// створення об'єкта бази даних із вказанням назви файлу
	StudentDatabase db("students.txt");

	bool running = true;                               // прапорець для керування головним циклом

	while (running)
	{
		printMenu();                                   // виводимо меню

		int userChoice = inputProcessingInt(0, 4);     // безпечно зчитуємо вибір користувача

		switch (userChoice)
		{
		case 1:                                        // відображення всіх
		{
			db.printAllStudents();
			break;
		}

		case 2:                                        // додавання студента
		{
			std::string name, group;
			double grade;

			std::cout << "\nEnter student's full name: ";
			std::getline(std::cin, name);

			std::cout << "Enter student's group: ";
			std::getline(std::cin, group);

			std::cout << "Enter average grade (0.0 - 100.0): ";
			grade = inputProcessingDouble(0.0, 100.0);

			db.addStudent(name, group, grade);
			break;
		}

		case 3:                                        // пошук за групою
		{
			std::string group;
			std::cout << "\nEnter the group to search: ";
			std::getline(std::cin, group);

			db.searchByGroup(group);

			break;
		}

		case 4:                                        // видалення студента
		{
			std::cout << "\nEnter the ID of the student you want to delete: ";
			int idToDelete = inputProcessingInt(1, 999999);

			db.deleteStudent(idToDelete);

			break;
		}

		case 0:                                        // вихід
		{
			std::cout << "\nData saved safely. Goodbye!" << std::endl;
			running = false;
			break;
		}

		default:
		{
			std::cout << "\nUnknown error!";
			break;
		}
		}
	}

	return 0;                                          // успішне завершення програми
}
