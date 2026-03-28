#include <iostream>
#include <cmath> // Для sqrt()
using namespace std;
// Функція перевіряє, чи є число простим
// Параметр: n - ціле число
// Повертає: true якщо просте, false якщо ні
bool isPrime(int n) {
	if (n <= 1) return false;
	if (n <= 3) return true; // 2, 3 - прості

	// Перевіряємо дільники до sqrt(n)
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}
int main() {
	int number;
	cout << "Enter a number: ";
	cin >> number;
	if (isPrime(number))
		cout << number << " - is a prime number.\n";
	else
		cout << number << " - is not a prime number.\n";

	return 0;
}