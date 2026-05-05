#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>
#include <iomanip>

// функція для безпечного введення цілого числа з перевіркою меж
int inputSize(int minVal, int maxVal)
{
	int size;                                                 // змінна для збереження введеного числа
	std::string inputStr;                                     // змінна для зберігання введеного рядка тексту

	while (true)                                              // нескінченний цикл для перевірки правильності введення
	{
		std::getline(std::cin, inputStr);                     // зчитуємо весь введений рядок з консолі

		try                                                   // блок для перехоплення можливих помилок
		{
			size_t pos;                                       // змінна для збереження позиції після конвертації

			size = std::stoi(inputStr, &pos);                 // конвертуємо рядок у тип int

			if (pos < inputStr.length())                      // якщо оброблено не весь рядок (є зайві символи)
			{
				throw (std::invalid_argument(""));            // генеруємо виключення неправильного формату
			}
			if (size < minVal)                                // якщо введене число менше за мінімально допустиме
			{
				throw (std::logic_error("\nError! Array size must be greater than " + std::to_string(minVal) + "\nTry again: "));
			}
			if (size > maxVal)                                // якщо введене число більше за максимально допустиме
			{
				throw (std::logic_error("\nError! Array size must be less than " + std::to_string(maxVal) + " \nTry again : "));
			}

			return size;                                      // повертаємо коректний розмір
		}
		catch (const std::invalid_argument)                   // перехоплюємо помилку неправильного формату введення
		{
			std::cout << "\nError! You must enter an integer\nTry again: ";
		}
		catch (const std::logic_error& e)                     // перехоплюємо помилку виходу за допустимі межі
		{
			std::cout << e.what();
		}
		catch (const std::out_of_range)                       // перехоплюємо переповнення типу int
		{
			std::cout << "\nError! Int type size exceeded\nTry again: ";
		}
	}
}

// функція для безпечного введення дійсного числа (елементів масиву)
double inputDouble()
{
	double val;                                               // змінна для збереження введеного числа
	std::string inputStr;                                     // змінна для зберігання введеного рядка тексту

	while (true)                                              // нескінченний цикл для перевірки введення
	{
		std::getline(std::cin, inputStr);                     // зчитуємо рядок з консолі

		try
		{
			size_t pos;                                       // змінна для збереження позиції після конвертації

			val = std::stod(inputStr, &pos);                  // конвертуємо рядок у тип double

			if (pos < inputStr.length())                      // якщо оброблено не весь рядок
			{
				throw (std::invalid_argument(""));            // генеруємо виключення неправильного формату
			}

			return val;                                       // повертаємо коректне число
		}
		catch (const std::invalid_argument)                   // перехоплюємо введення тексту замість числа
		{
			std::cout << "  Error! You must enter a valid number\n  Try again: ";
		}
		catch (const std::out_of_range)                       // перехоплюємо переповнення типу double
		{
			std::cout << "  Error! Double type size exceeded\n  Try again: ";
		}
	}
}

// функція для обробки масиву x та обчислення параметрів A, B, C
void calculationABC(double arr[], int size, double& A, double& B, double& C)
{
	double s = 0, p = 1;                                      // змінні для суми (s) та добутку (p) елементів масиву
	double sumA = 0, sumB = 0, sumC = 0;                      // тимчасові змінні для накопичення сум із тригонометричними функціями

	for (int i = 0; i < size; i++)                            // проходимо по всьому масиву
	{
		s += arr[i];                                          // накопичуємо суму елементів
		p *= arr[i];                                          // накопичуємо добуток елементів

		sumA += arr[i] * std::sin(arr[i]);                    // обчислюємо суму для A
		sumB += arr[i] * std::cos(arr[i]);                    // обчислюємо суму для B
		sumC += arr[i] * std::tan(arr[i]);                    // обчислюємо суму для C
	}

	A = p * sumA;                                             // розрахунок A
	B = s * sumB;                                             // розрахунок B
	C = (p + s) * sumC;                                       // розрахунок C
}

// функція для обробки масиву y та обчислення параметрів D, E, F
void calculationDEF(double arr[], int size, double& D, double& E, double& F)
{
	D = 0;                                                    // обнуляємо параметр D
	E = 0;                                                    // обнуляємо параметр E
	F = 0;                                                    // обнуляємо параметр F

	for (int i = 0; i < size; i++)                            // проходимо по всьому масиву
	{
		D += arr[i] * std::tan(arr[i]);                       // розрахунок D
		E += arr[i] * std::exp(arr[i]);                       // розрахунок E
		F += arr[i] * std::cos(arr[i]);                       // розрахунок F
	}
}

// головна функція програми
int main()
{
	std::cout << "Enter the number of elements for the array x: ";
	int n = inputSize(1, 50);                                 // безпечне введення розміру масиву x

	std::cout << "\nEnter the number of elements for the array y: ";
	int m = inputSize(1, 50);                                 // безпечне введення розміру масиву y

	double* x = new double[n];                                // динамічно виділяємо пам'ять під масив x

	std::cout << "\nInput array x:\n";
	for (int i = 0; i < n; i++)                               // цикл введення елементів масиву x
	{
		std::cout << "  x[" << i << "] = ";
		x[i] = inputDouble();
	}

	double* y = new double[m];                                // динамічно виділяємо пам'ять під масив y

	std::cout << "\nInput array y:\n";
	for (int i = 0; i < m; i++)                               // цикл введення елементів масиву y
	{
		std::cout << "  y[" << i << "] = ";
		y[i] = inputDouble();
	}

	double A, B, C;                                           // змінні для зберігання результатів першої частини формули
	calculationABC(x, n, A, B, C);                            // виклик функції з передачею параметрів за посиланням

	double D, E, F;                                           // змінні для зберігання результатів другої частини формули
	calculationDEF(y, m, D, E, F);                            // виклик функції з передачею параметрів за посиланням

	delete[] x;                                               // звільняємо динамічно виділену пам'ять для x
	delete[] y;                                               // звільняємо динамічно виділену пам'ять для y

	double denom = D + E * std::sin(F);                       // обчислюємо знаменник фінальної формули

	if (std::abs(denom) < 1e-9)                               // перевірка на ділення на нуль
	{
		std::cout << "\nError! Division by zero" << std::endl;
	}
	else                                                      // якщо знаменник не нуль, обчислюємо результат
	{
		double psi = (A * std::sin(B) + B * std::cos(C)) / denom;

		std::cout << "\nResults:";
		std::cout << std::fixed << std::setprecision(3);
		std::cout << "\nA = " << A << "\nB = " << B << "\nC = " << C;
		std::cout << "\nD = " << D << "\nE = " << E << "\nF = " << F << "\n";
		std::cout << "\npsi = " << psi << std::endl;          // виведення фінального результату
	}

	return 0;                                                 // успішне завершення програми
}
