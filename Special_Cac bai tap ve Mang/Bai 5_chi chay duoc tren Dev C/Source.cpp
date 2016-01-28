#include <iostream>
#include <string>
using namespace std;
string S, S1;
int giaTri[1000], N, i, j;
void sapXep();
void sapXep()
{
	int temp;
	for (i = 0; i < N - 1; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (giaTri[i]>giaTri[j])
			{
				temp = giaTri[i];
				giaTri[i] = giaTri[j];
				giaTri[j] = temp;
			}
		}
	}
}
int main()
{
	cout << "Nhap xau ky tu S: "; cin >> S;
	cout << endl;
	N = S.length();
	for (i = 0; i < N; i++)
	{
		giaTri[i] = S[i];
	}
	sapXep();
	for (i = 0; i < N; i++)
	{
		S1[i] = giaTri[i];
	}
	cout << "Xau ky tu sau khi sap xep la: ";
	for (i = 0; i < N; i++)
	{
		cout << S1[i];
	}
	cout << endl;

	return 0;
}