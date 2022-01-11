#include <iostream>
#include <string>
using namespace std;

string sum(string str1, string str2) 
{
	int f = 0;
	string sum;

	if (str1.length() > str2.length()) 
	{

		while (str1.length() != str2.length()) 
		{
			str2.insert(0, 1, '0');
		}
	}
	else if (str1.length() < str2.length()) 
	{

		while (str1.length() != str2.length()) 
		{
			str1.insert(0, 1, '0');
		}
	}

	for (int i = str1.length() - 1; i >= 0; i--)
	{
		int num1;
		if (str1[i] == 'A') { num1 = 10; }
		else if (str1[i] == 'B') { num1 = 11; }
		else { num1 = str1[i] - '0'; }

		int num2;
		if (str2[i] == 'A') { num2 = 10; }
		else if (str2[i] == 'B') { num2 = 11; }
		else { num2 = str2[i] - '0'; }

		int newnum = num1 + num2;

		if (f == 1) { newnum++; }
		
		f = 0;
		
		if (newnum > 12)
		{
			newnum -= 12;
			f++;

			if (newnum == 10) { sum.insert(0, 1, 'A'); }
			else if (newnum == 11) 	{ sum.insert(0, 1, 'B'); }
			else { sum.insert(0, 1, newnum + '0');	}
		}
		else if (newnum >= 10 && newnum <= 11)
		{

			if (newnum == 10) {	sum.insert(0, 1, 'A'); }
			else if (newnum == 11) { sum.insert(0, 1, 'B');	}

		}
		else { sum.insert(0, 1, newnum + '0'); }
	}
	return sum;
}

string sub(string str1, string str2)
{
	string res;
	int count = 0;

	if (str1.length() > str2.length()) 
	{

		while (str1.length() != str2.length()) 
		{
			str2.insert(0, 1, '0');
		}
	}
	else if (str1.length() < str2.length()) 
	{

		while (str1.length() != str2.length())
		{
			str1.insert(0, 1, '0');
		}

		string t = str1;
		str1 = str2;
		str2 = t;
	}

	for (int i = str1.length() - 1; i >= 0; i--)
	{
		int num1;
		if (str1[i] == 'A') { num1 = 10; }
		else if (str1[i] == 'B') { num1 = 11; }
		else { num1 = str1[i] - '0'; }

		int num2;
		if (str2[i] == 'A') { num2 = 10; }
		else if (str2[i] == 'B') { num2 = 11; }
		else { num2 = str2[i] - '0'; }

		if (count == 1)
		{
			num1--;
			count = 0;
		}

		if (num1 < num2)
		{
			count++;
			num1 += 12;
		}

		int newnum = num1 - num2;
		if (newnum >= 10 && newnum <= 11)
		{
			if (newnum == 10) { res.insert(0, 1, 'A'); }
			else if (newnum == 11) { res.insert(0, 1, 'B'); }
		}
		else res.insert(0, 1, newnum + '0');
	}
	return res;
}


int main() {
	string str1, str2;

	cout << "enter first string: ";
	getline(cin, str1);
	cout << "enter second string: ";
	getline(cin,str2);

	cout << endl << "sum = " << sum(str1, str2) << endl << "subtraction = " << sub(str1, str2) << endl;

	return 0;
}