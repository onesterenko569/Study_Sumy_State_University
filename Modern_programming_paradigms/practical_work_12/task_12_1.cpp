#include <iostream>
#include <string>

// базовий абстрактний клас для всіх видів транспорту
class Transport
{
protected:
	std::string model;                          // модель транспорту

public:
	// конструктор з параметрами для ініціалізації базового класу
	Transport(const std::string& tModel) : model(tModel) {}

	// віртуальний деструктор для правильного очищення пам'яті похідних класів
	virtual ~Transport() {}

	// чиста віртуальна функція для розрахунку чистого прибутку
	virtual double NetProfit() const = 0;

	// віртуальний метод для виведення загальної інформації про транспорт
	virtual void printInfo() const
	{
		std::cout << "Model: " << model;
	}
};

// клас для зберігання інформації про вантажний транспорт
class CargoTransport : public Transport
{
private:
	double cargoWeight;                         // вага вантажу в тоннах
	double pricePerTon;                         // ціна за тонну вантажу

public:                                         // відкриті методи класу
	// конструктор з параметрами
	CargoTransport(const std::string& cModel, double weight, double price) : Transport(cModel), cargoWeight(weight), pricePerTon(price) {}

	// перевизначений метод для розрахунку чистого прибутку вантажівки
	double NetProfit() const override
	{
		return cargoWeight * pricePerTon;       // розрахування прибутку
	}

	// перевизначений метод для виведення інформації про вантажівку
	void printInfo() const override
	{
		std::cout << "\nCARGO TRANSPORT:\n";
		Transport::printInfo();
		std::cout << "\nCargo weight: " << cargoWeight << " tons";
		std::cout << "\nPrice per ton: " << pricePerTon << " dollars";
		std::cout << "\nNet profit: " << NetProfit() << " dollars";
	}
};

// клас для зберігання інформації про пасажирський транспорт
class PassengerTransport : public Transport
{
private:
	int passengerCount;                         // кількість пасажирів
	double ticketPrice;                         // вартість одного квитка

public:
	// конструктор з параметрами
	PassengerTransport(const std::string& pModel, int count, double price) : Transport(pModel), passengerCount(count), ticketPrice(price) {}

	// перевизначений метод для розрахунку чистого прибутку автобуса
	double NetProfit() const override
	{
		return passengerCount * ticketPrice;    // розрахування прибутку
	}

	// перевизначений метод для виведення інформації про пасажирський транспорт
	void printInfo() const override
	{
		std::cout << "\nPASSENGER TRANSPORT:\n";
		Transport::printInfo();
		std::cout << "\nPassenger count: " << passengerCount;
		std::cout << "\nTicket price: " << ticketPrice << " dollars";
		std::cout << "\nNet profit: " << NetProfit() << " dollars";
	}
};

// головна функція програми
int main()
{
	const int tCount = 3;                       // константа для зберігання розміру масиву
	Transport* t[tCount];                       // масив вказівників на базовий абстрактний клас

	// створюємо об'єкти похідних класів та додаємо їх у масив
	t[0] = new CargoTransport("Volvo FH16", 20.5, 50.0);
	t[1] = new PassengerTransport("Mercedes-Benz Sprinter", 18, 15.5);
	t[2] = new CargoTransport("MAN TGX", 15.0, 45.0);

	// проходимо по всьому масиву транспорту
	for (int i = 0; i < tCount; i++)
	{
		t[i]->printInfo();                      // виклик методу виведення інформації
		std::cout << "\n";
	}

	// очищення виділеної пам'яті
	for (int i = 0; i < tCount; i++)
	{
		delete t[i];                            // видаляємо об'єкт за вказівником
	}

	return 0;                                   // успішне завершення програми
}
