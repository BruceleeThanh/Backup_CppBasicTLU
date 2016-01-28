#include <iostream>
#include "header1.h"
#include "hinhtron.h"
using namespace std;
/*int main()
{
	float x,y;
	HinhChuNhat hcn1,hcn2;
	cout<<"Nhap hcn1: ";
	cin>>x>>y;
	hcn1.setA(x);
	hcn1.setB(y);
	cout<<"2 canh la: "<<hcn1.getA()<<" "<<hcn1.getB();
	cout<<"Chu vi: "<<hcn1.getChuVi()<<" Dien tich: "<<hcn1.getDienTich();


	return 0;
}*/
int main()
{
	float r[100];
	int n;
	cout<<"Nhap so cac ban kinh: "; cin>>n;
	cout<<"Nhap ban kinh hinh tron: "<<endl; 
	HinhTron ht1;
	for(int i=0;i<n;i++)
	{
		cout<<"Ban kinh "<<i+1<<" : ";
		cin>>r[i];
	}
	for(int i=0;i<n;i++)
	{
		ht1.setR(r[i]);
		cout<<endl<<"Chu vi hinh tron "<<i+1<<" la: "<<ht1.getChuVi()<<endl<<"Dien tich hinh tron "<<i+1<<" la: "<<ht1.getDienTich()<<endl;
	}
	cout<<endl;

	return 0;
}