#ifndef dongtien_h
#define dongtien_h
#include "sinhvien.h"
using namespace std;

class DongTien:public SinhVien
{
private:
	float t1;
	float t2;
public:
	DongTien(){};
	DongTien(float _t1,float _t2){
		t1=_t1;
		t2=_t2;
	};
	DongTien(char ho_ten[],int ma,int nam,float _t1,float _t2):SinhVien(ho_ten,ma,nam){
		t1=_t1;
		t2=_t2;
	};
	float TongSoTien() const{
		return t1+t2;
	};
	void Display()const{
		SinhVien::Display();
		cout<<"Tong so tien = "<<TongSoTien()<<endl;
	};
};


#endif