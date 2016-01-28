#ifndef sinhviendiem_h
#define sinhviendeim_h

#include "sinhvien.h"
class SinhVienDiem : public SinhVien
{
private:
	float d1;
	float d2;
	float d3;
public:
	SinhVienDiem(){};
	SinhVienDiem(float _d1, float _d2, float _d3){
		d1=_d1;
		d2=_d2;
		d3=_d3;
	};
	SinhVienDiem(char ho_ten[],int ma,int nam, float _d1,float _d2,float _d3):SinhVien(ho_ten,ma,nam){
		d1=_d1;
		d2=_d2;
		d3=_d3;
	};
	float TongDiem() const{
		return d1+d2+d3;
	};
	void Display() const{
		//cout<<ht<<" - "<<msv<<" - "<<ns<<" - "<<TongDiem()<<endl;
		//SinhVien::Display();
		cout<<" - "<<TongDiem()<<endl;
	};

	/*SinhVienDiem(SinhVien s, float _d1, float _d2, float _d3){
		sv=sv;
		d1=_d1;
		d2=_d2;
		d3=_d3;
	};
	float TongDiem() const{
		return d1+d2+d3;
	};
	SinhVien getSinhVien() const{
		return sv;
	};*/


};

#endif