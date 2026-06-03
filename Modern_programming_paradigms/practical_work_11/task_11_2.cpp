#include <iostream>

const double PI = 3.14159;                      // константа для зберігання числа Пі

// базовий абстрактний клас для всіх фігур
class Shape
{
public:                                         // відкриті методи класу
	// віртуальний деструктор для правильного очищення пам'яті похідних класів
	virtual ~Shape() {}

	// чистий віртуальний метод для розрахунку площі
	virtual double getArea() const = 0;

	// чистий віртуальний метод для виведення інформації
	virtual void printInfo() const = 0;
};

// похідний клас прямокутник
class Rectangle : public Shape
{
private:                                        // закриті дані класу
	double width;                               // ширина
	double height;                              // висота

public:                                         // відкриті методи класу
	// конструктор з параметрами для ініціалізації прямокутника
	Rectangle(double rWidth, double rHeight) : width(rWidth), height(rHeight) {}

	// перевизначений метод для розрахунку площі прямокутника
	double getArea() const override
	{
		return width * height;                  // обрахунок площі
	}

	// перевизначений метод для виведення інформації про прямокутник
	void printInfo() const override
	{
		std::cout << "\n\nRECTANGLE:";
		std::cout << "\nWidth: " << width;
		std::cout << "\nHeight: " << height;
		std::cout << "\nArea: " << getArea();
	}
};

// клас для зберігання інформації про круг
class Circle : public Shape
{
private:                                        // закриті дані класу
	double radius;                              // радіус

public:                                         // відкриті методи класу
	// конструктор з параметрами для ініціалізації круга
	Circle(double cRadius) : radius(cRadius) {}

	// перевизначений метод для розрахунку площі круга
	double getArea() const override
	{
		return PI * radius * radius;            // обрахунок площі
	}

	// перевизначений метод для виведення інформації про круг
	void printInfo() const override
	{
		std::cout << "\n\nCIRCLE";
		std::cout << "\nRadius: " << radius;
		std::cout << "\nArea: " << getArea();
	}
};

// клас для зберігання інформації про трикутник
class Triangle : public Shape
{
private:                                        // закриті дані класу
	double base;                                // основа трикутника
	double height;                              // висота трикутника

public:                                         // відкриті методи класу
	// конструктор з параметрами для ініціалізації трикутника
	Triangle(double tBase, double tHeight) : base(tBase), height(tHeight) {}

	// перевизначений метод для розрахунку площі трикутника
	double getArea() const override
	{
		return 0.5 * base * height;             // обрахунок площі
	}

	// перевизначений метод для виведення інформації про трикутник
	void printInfo() const override
	{
		std::cout << "\n\nTRIANGLE";
		std::cout << "\nBase: " << base;
		std::cout << "\nHeight: " << height;
		std::cout << "\nArea: " << getArea();
	}
};

// головна функція програми
int main()
{
	const int arrSize = 3;                      // константа для зберігання розміру масиву
	Shape* shapes[arrSize];                     // масив вказівників на базовий клас

	// створюємо об'єкти похідних класів та додаємо їх у масив
	shapes[0] = new Rectangle(5.0, 4.0);
	shapes[1] = new Circle(3.0);
	shapes[2] = new Triangle(4.0, 6.0);

	// проходимо по всьому масиву фігур
	for (int i = 0; i < arrSize; i++)
	{
		shapes[i]->printInfo();                 // виведення інформації з обрахування площі фігур
	}

	std::cout << std::endl;

	// очищення виділеної пам'яті
	for (int i = 0; i < arrSize; i++)
	{
		delete shapes[i];
	}

	return 0;                                   // успішне завершення програми
}
