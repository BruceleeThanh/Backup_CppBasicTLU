#include <iostream>
using namespace std;
long sapXep(long N, long daySo[100]);
long sapXep(long N, long daySo[100])
{
	long i, j, temp;
	for (i = 1; i <= N; i++)
	{
		for (j = i + 1; j <= N; j++)
		{
			if (daySo[i]>daySo[j])
			{
				temp = daySo[i];
				daySo[i] = daySo[j];
				daySo[j] = temp;
			}
		}
	}
	return daySo[100];
}
int main()
{
	long daySoA[100], daySoB[100], N, i, j, x = 0;
	cout << "Nhap so cac phan tu trong 2 day la: "; cin >> N;
	cout << "Nhap day so A: ";
	for (i = 1; i <= N; i++)
	{
		cin >> daySoA[i];
	}
	cout << "Nhap day so B: ";
	for (j = 1; j <= N; j++)
	{
		cin >> daySoB[j];
	}
	sapXep(N, daySoA);
	sapXep(N, daySoB);
	for (i = 1; i <= N; i++)
	{
		if (daySoA[i] != daySoB[i]) x++;
	}
	if (x == 0) cout << "Hai day co so hang nhu nhau, chi khac nhau ve thu tu sap xep." << endl;
	else cout << "Hai day co cac so hang khac nhau." << endl;


	return 0;
}
