#include "Sach.h"


Sach::Sach(){

}

Sach::Sach(const char* tensach, int namxb, double heso){
	strcpy_s(this->tensach, tensach);
	this->namxb = namxb;
	this->heso = heso;
}

//set

void Sach::setTenSach(const char* tensach){
	strcpy_s(this->tensach, tensach);
}

void Sach::setNamxb(int namxb){
	this->namxb = namxb;
}

void Sach::setHeSo(double heso){
	this->heso = heso;
}

//get

char* Sach::getTenSach(){
	return tensach;
}

int Sach::getNamxb() const{
	return namxb;
}

double Sach::getHeSo() const{
	return heso;
}

double Sach::GiaBan(){
	return 0;
}

ostream &operator <<(ostream &cout, Sach &sach){
	cout << "Ten sach la: " << sach.tensach << endl;
	cout << "Nam xuat ban: " << sach.namxb << endl;
	cout << "He so: " << sach.heso << endl;
	return cout;
}

istream &operator >>(istream &cin, Sach &sach){
	cout << "Nhap ten sach: "; cin.getline(sach.tensach, 50);
	cout << "Nhap nam xuat ban: "; cin >> sach.namxb;
	cout << "Nhap he so: "; cin >> sach.heso; cin.ignore();
	return cin;
}

Sach::~Sach(){

}
