#include <iostream>
#include <string>
#include <vector>

// базовий клас для всіх тварин
class Animal
{
protected:
	std::string name;                           // змінна для зберігання імені тварини

public:
	// конструктор з параметрами для ініціалізації базового класу
	Animal(const std::string& aName) : name(aName) {}

	// віртуальний деструктор для правильного очищення пам'яті
	virtual ~Animal() {}

	// віртуальний метод для подачі голосу
	virtual void speak() const
	{
		std::cout << "\nAnimal " << name << " makes some sound";
	}
};

// клас для зберігання інформації про кота
class Cat : public Animal
{
public:
	// конструктор з параметрами
	Cat(const std::string& cName) : Animal(cName) {}

	// перевизначений метод для подачі голосу
	void speak() const override
	{
		std::cout << "\nCat " << name << " says: Meow! Meow!";
	}
};

// клас для зберігання інформації про собаку
class Dog : public Animal
{
public:
	// конструктор з параметрами
	Dog(const std::string& dName) : Animal(dName) {}

	// перевизначений метод для подачі голосу
	void speak() const override
	{
		std::cout << "\nDog " << name << " says: Woof! Woof!";
	}
};

// клас для зберігання інформації про папугу
class Parrot : public Animal
{
public:
	// конструктор з параметрами
	Parrot(const std::string& pName) : Animal(pName) {}

	// перевизначений метод для подачі голосу
	void speak() const override
	{
		std::cout << "\nParrot " << name << " says: Squawk! " << name << " wants a cracker!";
	}
};

// головна функція програми
int main()
{
	std::vector<Animal*> zoo;                   // вектор для зберігання вказівників на базовий клас тварин

	// створюємо об'єкти тварин та додаємо їх у вектор
	zoo.push_back(new Cat("Barsik"));
	zoo.push_back(new Dog("Patron"));
	zoo.push_back(new Parrot("Kesha"));
	zoo.push_back(new Cat("Murka"));

	std::cout << "Animal sounds:";

	// проходимо по всьому вектору тварин
	for (int i = 0; i < zoo.size(); i++)
	{
		zoo[i]->speak();
	}

	std::cout << std::endl;

	// очищення виділеної пам'яті
	for (int i = 0; i < zoo.size(); i++)
	{
		delete zoo[i];
	}

	return 0;                                   // успішне завершення програми
}
