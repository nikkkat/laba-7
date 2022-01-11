#include <iostream>
#include <string>
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

string str(int a)
{									
	string a1;
	while (a > 0)
	{
		a1.insert(0, 1, a % 10 + '0');
		a = a / 10;
	}
	return a1;
}

string two(int a)
{										
	string a1;
	int i = 0;
	while (a != 0) 
	{
		if (a % 2 == 0)
		{
			a1.insert(0, 1, '0');
			a /= 2;
		}
		else 
		{
			a1.insert(0, 1, '1');
			a /= 2;
		}
		i++;
	}

	return a1;
}

bool prov(string s) 
{											
	for (int i = 0; i < s.length(); i++) 
	{
		if (s[i] != '1' && s[i] != '0') 
		{
			return false;
		}
	}
	return true;
}

bool comparing(string s1, string s2) 
{												
	bool count = 1;
	for (int i = 0; i < s1.length(); i++) 
	{
		count = 1;
		for (int j = 0; j < s2.length(); j++) 
		{
			if (s1[i + j] != s2[j]) 
			{
				count = 0;
				break;
			}
		}
		if (count) 
		{
			return count;
		}
	}
	return count;
}

int main() 
{						
	cout << "enter n: ";
	int n = int_input();

	int a = 1, i = 0;
	while (i < n) 
	{
		string s1 = str(a);
		if (prov(s1) && comparing(two(a), s1))
		{ i++; }
		a++;
	}
	a--;

	cout << endl << "the smallest two-decimal number: " << a << endl;

	return 0;
}