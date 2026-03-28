#include <iostream>
using namespace std;
int main() {
	int N;
	int sum = 0;
	cout << "Enter a number N: ";
	cin >> N;
	for (int i = 1; i <= N; i++) {
		sum += i; // Додаємо i до суми
	}
	cout << "The sum of the numbers from 1 to " << N << " is equal to " << sum <<
		endl;

	return 0;
}