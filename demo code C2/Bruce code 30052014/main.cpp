#include "sinhviendiem.h"
#include "dongtien.h"
#include "sinhvien.h"

#include <iostream>
#include <string.h>

using namespace std;
int main(){
	char a[100];
	int m,n;
	float d1,d2,d3,t1,t2;
	
	cout<<"Nhap ho ten sinh vien: ";
	//cin.ignore();
	cin.getline(a,100);
	cout<<"Nhap ma sinh vien: "; cin>>m;
	cout<<"Nhap nam sinh: "; cin>>n;
	SinhVien sv(a,m,n);
	sv.Display();

	cout<<"Nhap so tien dong lan 1: "; cin>>t1;
	cout<<"Nhap so tien dong lan 2: "; cin>>t2;
	DongTien dt(t1,t2);
	cout<<"Tong so tien da dong: "<<dt.TongSoTien()<<endl;

	cout<<"Nhap diem 1: "; cin>>d1;
	cout<<"Nhap diem 2: "; cin>>d2;
	cout<<"Nhap diem 3: "; cin>>d3;
	SinhVienDiem svd(d1,d2,d3);
	cout<<"Tong diem = "<<svd.TongDiem()<<endl;

	//SinhVien sv(a,m,n);

	//SinhVien sv("Nguyen Trung Thanh",22896,1995);
	//sv.Display();

	//SinhVienDiem svd(SinhVien("Nguyen Trung Thanh",22896,1995),10,9,8);
	////svd.getSinhVien().Display();
	//cout<<"Tong diem = "<<svd.TongDiem()<<endl;

	/*SinhVienDiem svd("Nguyen Trung Thanh",22896,1995,10,9,8);
	svd.Display();*/

	//cout<<"Tong ket = "<<svd.TongDiem()<<endl;

	//DongTien dt("Nguyen Trung Thanh",22896,1995,55000,60500);


	return 0;
}
