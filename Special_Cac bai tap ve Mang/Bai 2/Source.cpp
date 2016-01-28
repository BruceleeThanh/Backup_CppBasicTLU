#include <iostream>
using namespace std;
int main()
{
	long daySo[99], i, j, N, temp;
	cout << "Ban muon nhap day co bao nhieu so: "; cin >> N;
	cout << endl << "Nhap day so: ";
	for (i = 0; i < N; i++)
	{
		cin >> daySo[i];
	}
	for (i = 0; i < N; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (daySo[i] > daySo[j])
			{
				temp = daySo[i];
				daySo[i] = daySo[j];
				daySo[j] = temp;
			}
		}
	}
	cout << "Day so duoc sap xep la: ";
	for (i = 0; i < N; i++)
		cout << daySo[i] << " ";

	return 0;
}