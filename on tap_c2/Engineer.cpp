#include "Engineer.h"


Engineer::Engineer(){

}

Engineer::Engineer(const char* hoten, int ngay, int thang, int nam, const char* quequan, const char* nganhhoc, int namtotnghiep):Person(hoten,ngay,thang,nam,quequan){
	strcpy_s(this->nganhhoc, nganhhoc);
	this->namtotnghiep = namtotnghiep;
}

Engineer::~Engineer(){

}

void Engineer::setNganhHoc(const char* nganhhoc){
	strcpy_s(this->nganhhoc, nganhhoc);
}

char* Engineer::getNganhHoc(){
	return nganhhoc;
}

void Engineer::setNamTotNghiep(int namtotnghiep){
	this->namtotnghiep = namtotnghiep;
}

int Engineer::getNamTotNghiep() const{
	return namtotnghiep;
}

ostream &operator <<(ostream &cout, Engineer &en){
	cout << "Ho ten: " << en.hoten << endl;
	cout << "Sinh nhat " << en.ngay << "/" << en.thang << "/" << en.nam << endl;
	cout << "Que quan: " << en.quequan << endl;
	cout << "Nganh hoc: " << en.nganhhoc << endl;
	cout << "Nam tot nghiep " << en.namtotnghiep << endl;
	return cout;
}

istream &operator >>(istream &cin, Engineer &en){
	cout << endl << "Nhap ho ten: "; cin.getline(en.hoten, 50);
	cout << "Nhap ngay thang nam sinh: "; cin >> en.ngay >> en.thang >> en.nam; cin.ignore();
	cout << "Nhap que quan: "; cin.getline(en.quequan, 50);
	cout << "Nhap nganh hoc: "; cin.getline(en.nganhhoc, 50);
	cout << "Nhap nam tot nghiep: "; cin >> en.namtotnghiep; cin.ignore();
	return cin;
}
