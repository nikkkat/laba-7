#include <iostream>;
using namespace std;

bool interesting(int x) 
{
	int sum1 = 0;
	int sum2 = 0;
	int k = x + 1;

	while (x > 0) 
	{
		sum1 += x % 10;
		x /= 10;
	}
	while (k > 0) 
	{
		sum2 += k % 10;
		k /= 10;
	}
	if (sum2 < sum1) { return true; }
	else { return false; }
}

int main()
{
	int n, t;
	cout << "enter number of inputs: ";
	cin >> t;
	while (t > 0) 
	{
		cout << endl << "enter number n: ";
		cin >> n;

		int count = 0;
		for (int i = 1; i <= n; i++) 
		{
			if (interesting(i)) { count++; }
		}
		cout << "amount:" << count << endl;

		t--;
	}
	return 0;
}