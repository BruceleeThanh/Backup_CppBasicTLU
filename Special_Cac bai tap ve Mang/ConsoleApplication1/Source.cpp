#include <iostream>
using namespace std;
void xauCon(long N, long daySo[100000]);
void xauCon(long N, long daySo[100000])
{
	long dem[100000], dem1[100000], x = 0, y = 0, i = 0, j = 0, max, a;
	dem[j] = 0;
	for (i = 0; i < N; i++)
	{
		if (daySo[i] != daySo[i + 1])
		{
			dem[j]++;
			x++;
			y = 0;
		}
		else
		{
			if (y == 0)
			{
				j++;
				x = 0;
				y++;
			}
		}
		if (x == 1)
		{
			dem1[j] = i;
		}
	}
	max = dem[0];
	for (j = 1; j < N; j++)
	{
		if (dem[j]>max)
		{
			max = dem[j];
			a = j;
		}
	}
	cout << "Xau con dai nhat la: ";
	for (x = 1; x <= dem[a];x++)
	{
		cout << daySo[dem1[a]] << " ";
		dem1[a]++;
	}
	cout << "Do dai xau con dai nhat la: " << dem[a] << endl;
}
int main()
{
	long daySo[100000], N, i;
	cout << "Nhap do dai xau ky tu la: "; cin >> N;
	cout << "Nhap xau ky tu: ";
	for (i = 0; i < N; i++)
	{
		cin >> daySo[i];
	}
	xauCon(N, daySo);


	return 0;
}