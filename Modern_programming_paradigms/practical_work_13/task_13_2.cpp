#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <map>
#include <stdexcept>

// клас для аналізу тексту та підрахунку частоти символів
class TextAnalyzer
{
private:
	std::string inputFile;                             // вхідний файл
	std::string outputFile;                            // вихідний файл

	// метод для відображення спецсимволів
	std::string getReadableChar(char c) const
	{
		switch (c)
		{
		case '\n': return "\\n (Newline)";
		case '\t': return "\\t (Tab)";
		case ' ':  return "Space";
		case '\r': return "\\r (Return)";
		default:   return std::string(1, c);
		}
	}

public:
	// конструктор для ініціалізації імен файлів
	TextAnalyzer(const std::string& in, const std::string& out) : inputFile(in), outputFile(out) {}

	// метод для створення вхідного файлу з текстом користувача
	void writeToInputFile() const
	{
		std::ofstream fout(inputFile, std::ios::trunc); // відкриваємо файл для перезапису

		if (!fout.is_open())                            // перевірка на успішне відкриття
		{
			std::cout << "\nError! Cannot open input file for writing!";
			return;
		}

		std::string userInput;
		std::cout << "\nEnter text to analyze (type 'END' on a new line to finish):\n";

		// читаємо текст, поки користувач не введе END
		while (true)
		{
			std::getline(std::cin, userInput);
			if (userInput == "END")
			{
				break;
			}
			fout << userInput << "\n";                  // записуємо рядок у файл
		}

		fout.close();                                   // закриваємо файл
		std::cout << "\nText successfully saved to " << inputFile;
	}

	// метод для аналізу тексту та запису результату у форматований файл
	void analyzeAndSaveReport() const
	{
		std::ifstream fin(inputFile);                   // відкриваємо файл для читання

		if (!fin.is_open())
		{
			std::cout << "\nError! Cannot open input file! Please write some text first";
			return;
		}

		std::map<char, int> frequencyMap;               // словник для зберігання (символ -> кількість)
		char ch;                                        // змінна для поточного символу

		// читаємо файл посимвольно
		while (fin.get(ch))
		{
			frequencyMap[ch]++;                         // збільшуємо лічильник для цього символу
		}
		fin.close();                                    // закриваємо вхідний файл

		if (frequencyMap.empty())                       // якщо файл порожній
		{
			std::cout << "\nThe input file is empty! Nothing to analyze";
			return;
		}

		std::ofstream fout(outputFile, std::ios::trunc);// відкриваємо файл для запису звіту

		if (!fout.is_open())
		{
			std::cout << "\nError! Cannot open output file for writing!";
			return;
		}

		// записуємо форматований звіт у вихідний файл
		fout << std::string(45, '=') << "\n";
		fout << "         SYMBOL FREQUENCY REPORT\n";
		fout << std::string(45, '=') << "\n";

		// малюємо шапку таблиці
		fout << "| " << std::left << std::setw(20) << "Symbol"
			<< "| " << std::setw(18) << "Frequency" << "|\n";
		fout << std::string(45, '-') << "\n";

		int totalSymbols = 0;                        // змінна для підрахунку всіх символів

		// проходимо по всьому словнику частот
		for (auto const& pair : frequencyMap)
		{
			// записуємо відформатований рядок даних у файл
			fout << "| " << std::left << std::setw(20) << getReadableChar(pair.first)
				<< "| " << std::setw(18) << pair.second << "|\n";

			totalSymbols += pair.second;             // додаємо до загальної кількості
		}

		fout << std::string(45, '-') << "\n";
		fout << "Total symbols analyzed: " << totalSymbols << "\n";
		fout << std::string(45, '=') << "\n";

		fout.close();                                   // закриваємо вихідний файл
		std::cout << "\nAnalysis complete! Formatted report saved to " << outputFile;
	}
};

// функція для виведення головного меню програми
void printMenu()
{
	std::cout << "\n\nTEXT ANALYZER MENU:";
	std::cout << "\n  1 - Enter text to analyze (saves to input file)";
	std::cout << "\n  2 - Generate frequency report (saves to output file)";
	std::cout << "\n  0 - Exit the program";
	std::cout << "\n\nYour choice: ";
}

// функція для безпечного введення числа
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

// головна функція програми
int main()
{
	// створення об'єкта аналізатора з вказанням імен файлів
	TextAnalyzer analyzer("input.txt", "output.txt");

	bool running = true;                               // прапорець для керування циклом

	while (running)
	{
		printMenu();                                   // виводимо меню

		int userChoice = inputProcessingInt(0, 2);     // безпечно зчитуємо вибір

		switch (userChoice)
		{
		case 1:                                        // запис тексту у вхідний файл
		{
			analyzer.writeToInputFile();
			break;
		}

		case 2:                                        // аналіз та створення звіту
		{
			analyzer.analyzeAndSaveReport();
			break;
		}

		case 0:                                        // вихід
		{
			std::cout << "\nWork with files completed. Goodbye!" << std::endl;
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
