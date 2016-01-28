#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
int main()
{
	/*double b, n, i;
	int long long Tong;
	cout << "        Tinh tong cac so nguyen to nho hon so ma ban nhap." << endl;
	cout << "Hay nhap so: ";
	cin >> n;
	i = 2;
	Tong = 2;
	cout << "Tong cac so nguyen to la: ";
	while (n > 1)
	{
		while (i < n)
		{
			b = n / i;
			if (b == (int)b)
				break;
			else
			{
				i++;
				if (i == n)
				{
					Tong = Tong + n;
					cout << n << " + ";
				}
			}
		}
		n--;
		i = 2;
	}

		cout << "2 = " << Tong << endl;


	cout << "_____________________________________________" << endl;
	cout << endl << "Thanks for watching" << endl << "Design by Brucelee Thanh" << endl;
	_getch();*/

	/*double b, n;
	int long long sum;
	bool check;
	cout << "        Tinh tong cac so nguyen to nho hon so ma ban nhap." << endl;
	cout << "Hay nhap so: ";
	cin >> n;
	sum = 5;
	cout << "Tong cac so nguyen to la: ";
	for (int i = 5; i <= n; i+=2){
		check = true;
		for (int j = 2; j <= sqrt((double)i); j++){
			if (i%j == 0){
				check = false;
				break;
			}
		}
		if (check){
			sum += i;
		}
	}
	cout << sum << endl;*/

	int n = 3;
	int snt = 1, count = 2;
	while (count < 10001){
		snt = 1;
		n += 2;
		for (int i = 2; i <= sqrt(n) && (snt); i++)
			snt = (n%i);
		if (snt)
		{
			count++;
		}
	}
	cout << n << endl;


	return 0;
}