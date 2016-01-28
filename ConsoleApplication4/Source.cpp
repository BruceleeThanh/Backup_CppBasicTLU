#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	int n;
	cout << "Nhap mot so nguyen bat ky: ";
	cin >> n;
	cout << "Day so la:" << endl;
	cout << n << " ";
	while (n != 1)
	{
		if (((double)n / 2) == (int)(n / 2))
		{
			n = n / 2;
			cout << n << " ";
		}
		else
		{
			n = n * 3 + 1;
			cout << n << " ";
		}
	}

	cout << endl;
	cout << "_____________________________________________" << endl;
	cout << endl << "Thanks for watching" << endl << "Design by Brucelee Thanh" << endl;

	_getch();
	return 0;
}