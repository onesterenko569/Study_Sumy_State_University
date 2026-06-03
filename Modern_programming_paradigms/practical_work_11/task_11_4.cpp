#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Logger
{
public:
	virtual void log(const std::string& message) = 0;

	virtual std::string getType() const
	{
		return "Base Logger";
	}

	virtual ~Logger()
	{
		std::cout << "[Logger] Destructor called\n";
	}
};

class ConsoleLogger : public Logger
{
public:
	void log(const std::string& message) override
	{
		std::cout << "[Console] " << message << std::endl;
	}

	std::string getType() const override
	{
		return "Console Logger";
	}

	~ConsoleLogger()
	{
		std::cout << "[ConsoleLogger] Destructor called\n";
	}
};

class FileLogger : public Logger
{
private:
	std::ofstream file;

public:
	FileLogger()
	{
		file.open("log.txt", std::ios::app);
	}

	void log(const std::string& message) override
	{
		if (file.is_open())
		{
			file << "[File] " << message << std::endl;
		}
	}

	std::string getType() const override
	{
		return "File Logger";
	}

	~FileLogger()
	{
		std::cout << "[FileLogger] Destructor called\n";
		file.close();
	}
};

class MemoryLogger : public Logger
{
private:
	std::vector<std::string> messages;

public:
	void log(const std::string& message) override
	{
		messages.push_back(message);
	}

	std::string getType() const override
	{
		return "Memory Logger";
	}

	const std::vector<std::string>& getMessages() const
	{
		return messages;
	}

	~MemoryLogger()
	{
		std::cout << "[MemoryLogger] Destructor called\n";
	}
};

int main()
{
	std::vector<Logger*> loggers;

	loggers.push_back(new ConsoleLogger());
	loggers.push_back(new FileLogger());
	loggers.push_back(new MemoryLogger());

	for (Logger* logger : loggers)
	{
		std::cout << "Logger Type: " << logger->getType() << std::endl;
		logger->log("Test message");
	}

	for (Logger* logger : loggers)
	{
		delete logger;
	}

	/*
	Що відбудеться, якщо видалити об'єкт без віртуального деструктора у базовому класі?

	Якби у класі Logger деструктор не був позначений словом virtual,
	то під час команди delete logger; компілятор викликав би тільки ~Logger().
	Для об'єкта FileLogger не спрацював би його власний ~FileLogger().
	А оскільки там прописана команда file.close();, файл log.txt залишився б
	відкритим у системі
	*/

	return 0;
}
