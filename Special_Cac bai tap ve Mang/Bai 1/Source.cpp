#include <iostream>
using namespace std;
void timMin(long &min, long N, long daySo[]);
void cacPTNho(long &min, long N, long daySo[]);
void khacNhau(long N, long daySo[]);
void timMin(long &min, long N, long daySo[])
{
	min = daySo[1];
	for (int i = 2; i <= N; i++)
	{
		if (min>daySo[i])
			min = daySo[i];
	}
	cout << endl << "Phan tu nho nhat trong day la: " << min << endl;
}
void cacPTNho(long &min, long N , long daySo[])
{
	long a;
	cout << endl << "Cac chi so cua cac phan tu nho nhat la: ";
	for (int i = 1; i <= N; i++)
	{
		if (min == daySo[i])
		{
			a = i;
			cout << a << " ";
		}
	}
}
void khacNhau(long N, long daySo[])
{
	long dem[100], a = 1, b, c, i = 1, x = 0;
	dem[a] = daySo[i];
	for (i = 2; i <= N; i++)
	{
		for (b = 1; b <= a; b++)
		{
			if (daySo[i] == dem[b])
				x++;
		}
		if (x == 0)
		{
			a++;
			dem[a] = daySo[i];
		}
		x = 0;
	}
	cout << endl << endl << "Cac phan tu khac nhau la: ";
	for (b = 1; b <= a; b++)
		cout << dem[b] << " ";
	for (b = 1; b <= a; b++)
	{
		cout << endl << "Phan tu " << dem[b] << " co chi so la: ";
		for (i = 1; i <= N; i++)
		{
			if (dem[b] == daySo[i])
			{
				c = i;
				cout << c << " ";
			}
		}
	}
}
int main()
{
	long daySo[101], N, i, min;
	cout << "Ban muon nhap day co bao nhieu so: "; cin >> N;
	cout << endl << "Nhap day so: ";
	for (i = 1; i <= N; i++)
	{
		cin >> daySo[i];
	}
	timMin(min, N, daySo);
	cacPTNho(min, N, daySo);
	khacNhau(N, daySo);
	return 0;
}