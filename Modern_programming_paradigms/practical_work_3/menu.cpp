#include <iostream>

using namespace std;

void printMenu() 
{
	cout << "\n==== MENU ====\n";
	cout << "1. Add two numbers\n";
	cout << "2. Subtract two numbers\n";
	cout << "3. Entrance\n";
	cout << "Select an item: ";
}

int main() 
{
	bool running = true;
	while (running) 
	{
		printMenu();
		int choice;
		cin >> choice;
		switch (choice) 
		{
		case 1: 
		{
			int a, b;
			cout << "Enter a and b: ";
			cin >> a >> b;
			cout << "Addition result: " << (a + b) << endl;
			break;
		}
		case 2: 
		{
			int a, b;
			cout << "Enter a and b: ";
			cin >> a >> b;
			cout << "Subtraction result: " << (a - b) << endl;
			break;
		}
		case 3:
		{
			cout << "Completion of the program.\n";
			running = false; // Єдиний «вихід» із циклу
			break;
		}
		default:
		{
			cout << "Wrong choice! Try again." << endl;
		}
		}
	}
	return 0;
}
