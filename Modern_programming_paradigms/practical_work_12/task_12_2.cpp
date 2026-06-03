#include <iostream>
#include <string>

// базовий абстрактний клас для всіх видів документів
class Document
{
protected:
	std::string docNumber;                                      // номер документа
	std::string date;                                           // дата оформлення документа

public:
	// конструктор з параметрами для ініціалізації базового класу
	Document(const std::string& dNumber, const std::string& dDate) : docNumber(dNumber), date(dDate) {}

	// віртуальний деструктор для правильного очищення пам'яті похідних класів
	virtual ~Document() {}

	// чиста віртуальна функція для розрахунку загальної суми документа
	virtual double getTotalAmount() const = 0;

	// віртуальний метод для виведення загальної інформації про документ
	virtual void printInfo() const
	{
		std::cout << "Document number: " << docNumber;
		std::cout << "\nDate: " << date;
	}
};

// клас для зберігання інформації про квитанцію
class Receipt : public Document
{
private:
	std::string serviceName;                                    // назва послуги
	double amount;                                              // сума до оплати

public:                                                         // відкриті методи класу
	// конструктор з параметрами
	Receipt(const std::string& rNumber, const std::string& rDate, const std::string& service, double sum) : Document(rNumber, rDate), serviceName(service), amount(sum) {}

	// перевизначений метод для отримання загальної суми квитанції
	double getTotalAmount() const override
	{
		return amount;                                          // повертаємо значення
	}

	// перевизначений метод для виведення інформації про квитанцію
	void printInfo() const override
	{
		std::cout << "\nRECEIPT:\n";
		Document::printInfo();
		std::cout << "\nService: " << serviceName;
		std::cout << "\nTotal amount: " << getTotalAmount() << " UAH";
	}
};

// клас для зберігання інформації про накладну
class Invoice : public Document
{
private:
	std::string productName;                                    // назва товару
	int productCount;                                           // кількість товару
	double pricePerUnit;                                        // ціна за одиницю товару

public:                                                         // відкриті методи класу
	// конструктор з параметрами
	Invoice(const std::string& iNumber, const std::string& iDate, const std::string& product, int count, double price) : Document(iNumber, iDate), productName(product), productCount(count), pricePerUnit(price) {}

	// перевизначений метод для отримання загальної суми накладної
	double getTotalAmount() const override
	{
		return productCount * pricePerUnit;                      // розрахування суми
	}

	// перевизначений метод для виведення інформації про накладну
	void printInfo() const override
	{
		std::cout << "\nINVOICE:\n";
		Document::printInfo();
		std::cout << "\nProduct: " << productName;
		std::cout << "\nQuantity: " << productCount;
		std::cout << "\nPrice per unit: " << pricePerUnit << " UAH";
		std::cout << "\nTotal amount: " << getTotalAmount() << " UAH";
	}
};

// клас для зберігання інформації про чек
class Check : public Document
{
private:
	std::string storeName;                                      // назва магазину
	double purchaseSum;                                         // сума покупки без податку
	double taxRate;                                             // податкова ставка у відсотках

public:                                                         // відкриті методи класу
	// конструктор з параметрами
	Check(const std::string& cNumber, const std::string& cDate, const std::string& store, double sum, double tax) : Document(cNumber, cDate), storeName(store), purchaseSum(sum), taxRate(tax) {}

	// перевизначений метод для отримання загальної суми чека з урахуванням податку
	double getTotalAmount() const override
	{
		return purchaseSum + (purchaseSum * taxRate / 100.0);   // розрахування суми
	}

	// перевизначений метод для виведення інформації про чек
	void printInfo() const override
	{
		std::cout << "\nCHECK:\n";
		Document::printInfo();
		std::cout << "\nStore: " << storeName;
		std::cout << "\nPurchase sum: " << purchaseSum << " UAH";
		std::cout << "\nTax rate: " << taxRate << " %";
		std::cout << "\nTotal amount: " << getTotalAmount() << " UAH";
	}
};

// головна функція програми
int main()
{
	const int dCount = 3;                                       // константа для зберігання розміру масиву
	Document* d[dCount];                                        // масив вказівників на базовий абстрактний клас

	// створюємо об'єкти похідних класів та додаємо їх у масив
	d[0] = new Receipt("REC-001", "20.05.2026", "Internet Bill", 350.0);
	d[1] = new Invoice("INV-104", "21.05.2026", "Office Laptops", 5, 25000.0);
	d[2] = new Check("CHK-992", "22.05.2026", "Supermarket", 1200.50, 20.0);

	// проходимо по всьому масиву документів
	for (int i = 0; i < dCount; i++)
	{
		d[i]->printInfo();                                      // виклик методу виведення інформації
		std::cout << "\n";
	}

	// очищення виділеної пам'яті
	for (int i = 0; i < dCount; i++)
	{
		delete d[i];                                            // видаляємо об'єкт за вказівником
	}

	return 0;                                                   // успішне завершення програми
}