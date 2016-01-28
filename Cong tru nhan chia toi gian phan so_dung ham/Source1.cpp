#include <iostream>
int main()
{
	int a, b, c;
	cout << "nhap a: "; cin >> a;
	cout << "nhap b: "; cin >> b;
	while (b != 0)
	{
		c = a%b;
		a = b;
		b = c;
	}
	cout << a;

	return 0;
}