#include <iostream>
using namespace std;
int main()
{
	long long n, k, dem = 0, a = 1, b;
	cout << "Nhap phan so: 1/"; cin >> n;
	cout << "Nhap so cac chu so sau dau phay thap phan: "; cin >> k;
	cout << "Ket qua la: 1/" << n << " = 0.";
	while (dem < k)
	{
		a = 10 * a;
		cout << a / n;
		b = a%n;
		dem++;
		a = b;
	}
	cout << endl;



	return 0;
}