#include<iostream>
#include"PhanSo.h"
#include "SoPhuc.h"
using namespace std;
int main()
{
	//ToiGian
	/*int ts, ms;
	cin>>ts>>ms;
	PhanSo x;
	x.setts(ts);
	x.setms(ms);
	x.ToiGian();
	cout<<x.getts()<<endl;
	cout<<x.getms()<<endl;
	system("pause");*/

	//Cong
	/*PhanSo a(5,10),b(2,4),c;
	c=a+b;
	c.ToiGian();
	c.In();*/

	//Tru
	/*PhanSo a(5,10),b(3,4),c;
	c=a-b;
	c.In();*/

	/*PhanSo x(4,5);
	++x;
	x.In();*/

	/*PhanSo x(1, 2);
	x+=x;
	x.In();*/

	/*PhanSo a(1, 2), b(2, 4);
	if (a == b)
		cout << "Dung";
	else
		cout << "Sai";*/

	//cong day so
	/*int n;
	cin >> n;
	PhanSo c;
	for (int i = 1; i <= n; i++)
	{
		c+= PhanSo(1,i);
	}
	c.In();*/

	/*PhanSo x, y(3, 2);
	x = y;
	x.In();*/

	/*PhanSo* x = new PhanSo[5];
	for (int i = 0; i < 5; i++)
	{
		int a, b;
		cin >> a >> b;
		x[i].setts(a);
		x[i].setms(b);
	}
	SapXep(x, 5);
	for (int i = 0; i < 5; i++)
	{
		x[i].In();
		cout << endl;
	}*/

	SoPhuc sp1(1, 2, 2, 3), sp2(3, 4, 7, 9), sp3;
	sp3 = sp1 + sp2;
	sp3.InSoPhuc();
	cout << endl;


	return 0;
}