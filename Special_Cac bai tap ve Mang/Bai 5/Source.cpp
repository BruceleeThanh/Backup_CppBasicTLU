#include <iostream>
using namespace std;
void SapXep(long giaTri[], long n)
{
	int temp, i ,j;
	for (i = 0; i < n - 1; i++)
	for (j = i + 1; j < n; j++)
	{
		if (giaTri[i] > giaTri[j])
		{
			temp = giaTri[i];
			giaTri[i] = giaTri[j];
			giaTri[j] = temp;
		}
	}
}
int main()
{
	char S[100000], S1[100000];
	long N, giaTri[100000], i;
	cout << "Nhap so ky tu ban muon nhap trong xau: "; cin >> N;
	cout << "Nhap xau ky tu: ";
	for (i = 0; i < N; i++)
	{
		cin >> S[i];
	}
	for (i = 0; i < N; i++)
	{
		giaTri[i] = S[i];
	}
	SapXep(giaTri, N);
	for (i = 0; i<N; i++)
	{
		S1[i] = giaTri[i];
	}
	cout << "Xau ky tu duoc sap xep la: ";
	for (i = 0; i<N; i++)
	{
		cout << S1[i];
	}
	cout << endl;


	return 0;
}