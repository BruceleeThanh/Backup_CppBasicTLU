#ifndef sinhvien_h
#define sinhvien_h

#include <iostream>
#include <string.h>
using namespace std;
class SinhVien
{	
private:
	char ht[100];
	int msv;
	int ns;
public:
	SinhVien(){};
	SinhVien(const char *ho_ten, int ma, int nam){
		strcpy(ht, ho_ten);
		msv=ma;
		ns=nam;
	};
	void Display() const{
		cout<<ht<<" - "<<msv<<" - "<<ns<<endl;
	};
	int TinhTuoi(int nam_hien_tai) const{
		return nam_hien_tai - ns;
	};
	

};

#endif