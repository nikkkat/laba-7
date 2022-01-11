#include <iostream>
using namespace std;

int int_input() {
	int k;
	cin >> k;
	while (cin.get() != '\n') {
		cin.clear();
		cin.ignore(100000, '\n');
		cout << endl << "enter correct input: ";
		cin >> k;
	}
	
	int n = k;
	while (n != 0) {
		if (n % 10 == 9) {
			cout << endl << "enter correct input: ";
			k = int_input();
			break;
		}
		n /= 10;
	}
	return k;
}

int main() {
	setlocale(LC_ALL, "rus");
	cout << "program will remake numbers from the 9th system of counting to the 11th system of counting";
	cout << endl << "enter number in the 9th system of counting:";
	int num1 = int_input();

	int value = 0, k = 0;
	while (num1 != 0) 
	{
		value += abs(num1 % 10) * pow(9, k);
		num1 /= 10;
		k++;
	}

	int val = value;
	int a = 0;
	while (val != 0) 
	{
		a++;
		val /= 11;
	}

	cout << endl << "result: ";
	while (a--) 
	{
		int temp = value;
		for (int i = 0; i < a; i++) 
		{
			temp /= 11;
		}
		if (temp % 11 == 10) 
		{
			cout << "A";
		}
		else 
		{
			cout << temp % 11;
		}
	}
	cout << endl;

	return 0;
}