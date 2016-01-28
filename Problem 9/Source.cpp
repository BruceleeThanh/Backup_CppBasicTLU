#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double a, b, c, s;
	int dem = 0;
	for (a = 1; a < 500; a++)
	{
		b = a + 1;
		for (b; b < 500; b++)
		{
			c = sqrt(a*a + b*b);
			if (c == (int)c)
			{
				if ((a + b + c) == 1000)
				{
					s = a*b*c;
					cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
					cout << "Ket qua la: " << (long long)s << endl;
					dem++;
					break;
				}
			}
		}
		if (dem != 0) break;
	}


	return 0;
}