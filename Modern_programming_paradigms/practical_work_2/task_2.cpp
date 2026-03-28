#include <iostream>
using namespace std;
int main() {
	int number;
	cout << "Enter a number [1..100]: ";
	cin >> number;
	// Цикл продовжується, поки умова НЕ виконується
	while (number < 1 || number > 100) {
		cout << "Error! Number must be between 1 and 100.\n";
		cout << "Try again: ";
		cin >> number;
	}
	cout << "Thank you! You entered a valid number: " << number << endl;
	return 0;
}