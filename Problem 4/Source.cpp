#include <iostream>
#include <math.h>
using namespace std;
bool soDep(long long x);
bool soDep(long long x)
{
	long long d = 0, a = x;
		while (a > 0)
		{
			d = d * 10 + a % 10;
			a = a / 10;
		}
		if (d == x)
			return 1;
		else
			return 0;
}
int main()
{
	int i = 0, a, b;
	long long c, s[100000], max;
	for (a = 999; a > 99; a--)
	{
		for (b = 999; b > 99; b--)
		{
			c = a*b;
			if (soDep(c) == 1)
			{
				s[i] = c;
				i++;
			}
		}
	}
	max = s[0];
	while (i > 0)
	{
		if (s[i] > max) max = s[i];
		i--;
	}
	cout << "Ket qua la: " << max << endl;

	return 0;
}