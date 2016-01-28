#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	int long long a, X, n, i, Y;
	cout << "Day so tam giac va uoc so cua no." << endl;
	cout << "Nhap dieu kien: ";
	cin >> Y;
	a = 1; 
	X = 0;
	n = 1;
	i = 2;
	n = n + i;
	cout << "1 " << n << " ";
	while (1 > 0)
	{
		while (a <= n)
		{
			if ((n%a) == 0)
			{
				X++;
				a++;
			}
			else
			{
				a++;
			}
		}
		if (X > Y)
		{
			break;
		}
		n = n + (++i);
		X = 0;
		a = 1;
		cout << n << " ";
	}
	cout << endl << "Ket qua la: " << n << endl;




	_getch();
	return 0;
}