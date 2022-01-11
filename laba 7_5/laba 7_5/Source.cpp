#include <iostream>
#include <string>
using namespace std;

int int_input()
{
	int k = 0;
	cin >> k;
	while (k < 1 || k > 3999 || cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "enter correct input: ";
		cin >> k;
	}

	return k;
}

string numbers(int a, string s)
{
	if (a == 1) { s += ("I"); }

	if (a == 2) { s += ("II"); }
	
	if (a == 3) { s += ("III"); }
	
	if (a == 4) { s += ("IV"); }
	
	if (a == 5) { s += ("V"); }
	
	if (a == 6) { s += ("VI"); }
	
	if (a == 7) { s += ("VII"); }
	
	if (a == 8) { s += ("VIII"); }
	
	if (a == 9) { s += ("IX"); }

	return s;
}

int main()
{
	cout << "enter number: ";

	int x = int_input();

	string s = "";

	int n1 = x / 1000;
	while (n1 != 0) 
	{
		s += "M";
		n1--;
	}

	x %= 1000;
	if ((x - 500) >= 400 && (x - 500) <= 499) 
	{
		s += "CM";
		x %= 500;
		x %= 100;
	}
	else if (x >= 500 && x <= 899) 
	{
		s += "D";
		x %= 500;
	}

	int n2 = x / 100;
	if ( n2 == 4) 
	{
		s += "CD";
	}
	else 
	{
		while (n2 != 0) 
		{
			s += "C";
			n2--;
		}
	}

	x %= 100;
	if ((x - 50) >= 40 && (x - 50) <= 49) 
	{
		s += "XC";
		x %= 50;
		x %= 10;
	}
	else if (x >= 50 && x <= 89) 
	{
		s += "L";
		x %= 50;
	}

	int n3 = x / 10;
	if (n3 == 4) 
	{
		s += "XL";
	}
	else 
	{
		while (n3 != 0) 
		{
			s += "X";
			n3--;
		}
	}

	x %= 10;
	s = numbers(x, s);

	cout << endl << "result: " << s << endl;
	
	return 0;
}