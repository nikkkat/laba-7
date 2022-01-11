#include <iostream>
using namespace std;

int int_input()
{
	int k = 0;
	cin >> k;
	while (k < 1 || cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "enter correct input: ";
		cin >> k;
	}

	return k;
}

int main() 
{
	cout << "enter number: ";
	int n = int_input();

	int res[25];
	int i = 0;
	while (n != 0) 
	{
		if (n % 3 == 0) { res[i] = 3; }
		else { res[i] = n % 3; }
		i++;
		n /= 3;
	}

	cout << endl << "result: ";
	for (int j = i - 1; j > -1; j--) {
		cout << res[j];
	}
	cout << endl;

	return 0;
}