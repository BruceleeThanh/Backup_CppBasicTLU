#include "Account.h"


Account::Account(){

}

Account::Account(const char* id, const char* hoten, const char* password, double sotien){
	strcpy_s(this->id, id);
	strcpy_s(this->hoten, hoten);
	strcpy_s(this->password, password);
	this->sotien = sotien;
}

Account::~Account(){

}

//set

void Account::setID(const char* id){
	strcpy_s(this->id, id);
}

void Account::setHoTen(const char* hoten){
	strcpy_s(this->hoten, hoten);
}

void Account::setPassword(const char* password){
	strcpy_s(this->password, password);
}

void Account::setSoTien(double sotien){
	this->sotien = sotien;
}

//get

char* Account::getID(){
	return id;
}

char* Account::getHoTen(){
	return hoten;
}

char* Account::getPassword(){
	return password;
}

double Account::getSoTien()const{
	return sotien;
}

void Account::operator +=(long long a){
	sotien += a;
}

void Account::operator -=(long long a){
	sotien -= a;
}

ostream &operator <<(ostream &cout, Account &acc){
	cout << endl << "ID (ma tai khoan): " << acc.id << endl;
	cout << "Ho ten: " << acc.hoten << endl;
	cout << "Password: " << acc.password << endl;
	cout << "So tien trong tai khoan: " << acc.sotien << " VND." << endl;
	return cout;
}

istream &operator >>(istream &cin, Account &acc){
	cout << "Nhap ID (ma tai khoan): "; cin.getline(acc.id, 50);
	cout << "Nhap Ho ten: "; cin.getline(acc.hoten, 50);
	cout << "Nhap Password: "; cin.getline(acc.password, 50);
	cout << "Nhap so tien trong tai khoan: "; cin >> acc.sotien; cin.ignore();
	return cin;
}
