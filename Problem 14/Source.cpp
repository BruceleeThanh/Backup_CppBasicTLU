#include <iostream>
using namespace std;
int main()
{
	long long s[120000], dem, a, i, max, j = 0;
	for (i = 900000; i >= 800000; i--)
	{
		dem = 0;
		a = i;
		while (a > 1)
		{
			if ((a % 2) == 0)
			{
				a = a / 2;
				dem++;
			}
			else
			{
				a = a * 3 + 1;
				dem++;
			}
		}
		s[j] = dem;
		j++;
		cout << dem << " - ";
	}
	a = 1;
	max = s[0];
	while (a < j)
	{
		if (s[a] > max) max = s[a];
		a++;
	}
	for (a = 0; a < j; a++)
	{
		if (max == s[a]) cout << "so a: " << a;
	}
	cout << "Ket qua la: " << max << endl;
	return 0;
}