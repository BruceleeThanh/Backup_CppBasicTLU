#include "Lib.h"
#include "LibClass.h"

Khoa::Khoa(){

}

void Khoa::setMaKhoa(string){

}

void Khoa::setTenKhoa(string){

}

void Khoa::setChuyenNganh(string){

}

string Khoa::getMaKhoa(){

}

string Khoa::getTenKhoa(){

}

vector<string> Khoa::getChuyenNganh(){

}

Khoa::~Khoa(){

}

////////////////////////////////////////////////////

ListKhoa::ListKhoa(){

}

void ListKhoa::setDSKhoa(Khoa K){
	DSKhoa.push_back(K);
}

vector<Khoa> ListKhoa::getDSKhoa(){
	return DSKhoa;
}

void ListKhoa::xoaKhoa(){
	string a;
	int vitri;
	timkiemKhoa();
	cout << "Nhap Ma Khoa can xoa: ";
	getline(cin, a);
	for (int i = 0; i < DSKhoa.size(); i++){
		if (DSKhoa[i].getMaKhoa == a){
			vitri = i;
			break;
		}
	}
	DSKhoa.erase(DSKhoa.begin() + vitri);
}

void ListKhoa::themKhoa(){
	Khoa khoa;
	string DCCN;
	string a;
	int sotin;
	cout << "Nhap Ma khoa: ";
	getline(cin, a);
	khoa.setMaKhoa(a);
	cout << "Nhap Ten khoa: ";
	getline(cin, a);
	khoa.setTenKhoa(a);
	
	setDSKhoa(khoa);
}

void ListKhoa::suaKhoa(){

}

void ListKhoa::timkiemKhoa(){

}

void ListKhoa::hienthiKhoa(int){

}

void ListKhoa::hienthiDSKhoa(){

}

ListKhoa::~ListKhoa(){

}