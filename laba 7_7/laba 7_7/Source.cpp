#include <iostream>
using namespace std;

int main()
{
	cout << "enter number: ";
	int m;
	cin >> m;

	int i = 0;
	while( i < m )
	{
		i += 5;
	}

	int j = 0;
	while (j < m)
	{
		j += 29;
	}

	int k = 0;
	while (k < m)
	{
		k += 223;
	}
	
	cout << endl << "result:" << endl;
	if (i == m) { cout << endl << "yes for 5"; }
	else { cout << endl << "no for 5"; }
	
	if (j == m) { cout << endl << "yes for 29"; }
	else { cout << endl << "no for 29"; }

	if (k == m) { cout << endl << "yes for 223" << endl; }
	else { cout << endl << "no for 223" << endl; }


	return 0;
}