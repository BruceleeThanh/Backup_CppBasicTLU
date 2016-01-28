#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
int main()
{
	double n, i, i1, b, c, X;
	
	cout << "Nhap so: ";
	cin >> n;
	i = (n + 1) / 2;
	i1 = 2;
	X = 0;
	while (i > 1)
	{
		b = n / i;
		if (b == (int)b)
		{
			while (i1 < i)
			{
				c = i / i1;
				if (c == (int)c)
					break;
				else
				{
					i1++;
					if (i1 == i)
					{
						X = i;
						break;
					}
				}
			}
		}
			i--;
			i1 = 2;
			if (X != 0)
				break;
	}

	cout << "Ket qua la: " << X << endl;



	cout << "_____________________________________________" << endl;
	cout << endl << "Thanks for watching" << endl << "Design by Brucelee Thanh" << endl;
	_getch();
	return 0;
}