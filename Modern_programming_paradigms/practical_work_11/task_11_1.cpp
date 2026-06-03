#include <iostream>

// базовий клас
class Transport
{
protected:                                      // дані класу щоб похідні класи мали доступ до них
	double speed;                               // змінна для зберігання швидкості транспорту
	double weight;                              // змінна для зберігання ваги транспорту

public:                                         // відкриті методи класу
	// конструктор з параметрами для ініціалізації полів транспорту через список ініціалізації
	Transport(double tSpeed, double tWeight) : speed(tSpeed), weight(tWeight) {}

	// віртуальний деструктор для правильного очищення пам'яті похідних класів
	virtual ~Transport() {}

	// віртуальний метод для виведення загальної інформації про транспорт
	virtual void printInfo() const
	{
		std::cout << "\nSpeed: " << speed << " km/h\nWeight: " << weight << " kg";
	}
};

// клас для зберігання інформації про легковий автомобіль
class Car : public Transport
{
private:                                        // закриті дані класу
	int passengerCount;                         // змінна для зберігання кількості пасажирів

public:                                         // відкриті методи класу
	// конструктор з параметрами для ініціалізації автомобіля
	Car(double cSpeed, double cWeight, int pCount) : Transport(cSpeed, cWeight), passengerCount(pCount) {}

	// перевизначений метод для виведення інформації про автомобіль
	void printInfo() const override
	{
		std::cout << "\n\nCAR INFO:";
		Transport::printInfo();                               // викликаємо базовий метод для виведення швидкості та ваги
		std::cout << "\nPassenger count: " << passengerCount; // виводимо власне поле класу
	}
};

// клас для зберігання інформації про вантажівку
class Truck : public Transport
{
private:                                        // закриті дані класу
	double loadCapacity;                        // змінна для зберігання вантажопідйомності

public:                                         // відкриті методи класу
	// конструктор з параметрами для ініціалізації вантажівки
	Truck(double tSpeed, double tWeight, double lCapacity) : Transport(tSpeed, tWeight), loadCapacity(lCapacity) {}

	// перевизначений метод для виведення інформації про вантажівку
	void printInfo() const override
	{
		std::cout << "\n\nTRUCK INFO";
		Transport::printInfo();                                    // викликаємо базовий метод
		std::cout << "\nLoad capacity: " << loadCapacity << " kg"; // виводимо власне поле класу
	}
};

// головна функція програми
int main()
{
	int const tSize = 3;                    // константа для зберігання розміру масиву
	Transport* t[tSize];                    // масив вказівників на базовий клас

	// створюємо об'єкти та додаємо їх у масив
	t[0] = new Car(180.5, 1500.0, 4);
	t[1] = new Truck(90.0, 8500.0, 20000.0);
	t[2] = new Car(220.0, 1200.0, 2);

	// проходимо по всьому масиву транспорту
	for (int i = 0; i < tSize; i++)
	{
		t[i]->printInfo();                  // виклик методу виведення інформації
	}

	std::cout << std::endl;

	// очищення виділеної пам'яті
	for (int i = 0; i < tSize; i++)
	{
		delete t[i];                        // видаляємо об'єкт за вказівником
	}

	return 0;                               // успішне завершення програми
}
