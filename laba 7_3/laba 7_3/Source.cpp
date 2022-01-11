#include<iostream>
#include<string>

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

string convert(int num)									
{

	string straight;
	int nummod = abs(num);

	while (nummod >= 1)											
	{
		straight.insert(0, 1, nummod % 2 + '0');
		nummod /= 2;
	}

	string back;
	if (num > 0)													 
	{
		straight.insert(0, 1, '0');
		back += straight;
		back.insert(0, 1, '0');
	}

	if (num < 0)													
	{
		straight.insert(0, 1, '0');
		for (int i = 0; i < straight.length(); i++)				
		{
			if (straight[i] == '1')
			{
				straight[i] = '0';
			}

			else
			{
				straight[i] = '1';
			}
		}
		back.push_back('1');
		back += straight;
	}
	else
	{
		back.push_back('0');
	}
	return back;
}


int main()
{
	cout << "program will sum your numbers in the back code.\n";
	int num1, num2;

	cout << "enter first number: ";
	num1 = int_input();
	cout << "enter second number: ";
	num2 = int_input();

	bool f = false;
	if (num1 < 0 && num2 < 0)
	{
		f = true;
		num1 *= -1;
		num2 *= -1;
	}
	string num_1, num_2;
	num_1 = convert(num1);

	num_2 = convert(num2);

	if (num_1.length() > num_2.length())
	{
		while (num_1.length() != num_2.length())
		{
			num_2.insert(2, 1, '0');
		}																	
	}

	if (num_1.length() < num_2.length())
	{
		while (num_1.length() != num_2.length())
		{
			num_1.insert(2, 1, '0');
		}																	
	}

	int count = 0;
	string result;

	for (int i = num_1.length() - 1; i >= 0; i--)					
	{
		if (count == 1)													
		{
			num_1[i]++;
			count = 0;
		}

		if (num_1[i] + num_2[i] - 96 > 1)				
		{
			result.insert(0, 1, '0');
			count++;
		}

		if (num_1[i] + num_2[i] - 96 == 1)
		{
			result.insert(0, 1, '1');
		}

		else
		{
			result.insert(0, 1, '0');
		}
	}

	int new_num = 0;
	bool t = false;

	if (result[0] == '1')
	{
		t = true;
		result.erase(0, 1);
		for (int i = 0; i < result.length(); i++)							
		{
			if (result[i] == '1')
			{
				result[i] = '0';
			}

			else
			{
				result[i] = '1';
			}
		}
	}

	for (int i = result.length() - 1, j = 0; i >= 0; i--, j++)				
	{
		new_num += (result[i] - '0') * pow(2, j);
	}

	if (t || f) new_num *= -1;											
	cout << endl << "result: " << new_num << endl;
}