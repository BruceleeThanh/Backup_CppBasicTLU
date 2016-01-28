#include <iostream>
using namespace std;
#include "PhanSo.h"

PhanSo::PhanSo(){
	tuso = 0;
	mauso = 1;
}

PhanSo::PhanSo(int tuso){
	this->tuso = tuso;
	mauso = 1;
}

PhanSo::PhanSo(int tuso, int mauso){
	this->tuso = tuso;
	this->mauso = mauso;
}

PhanSo::~PhanSo(){

}

void PhanSo::setTuSo(int tuso){
	this->tuso = tuso;
}

int PhanSo::getTuSo() const{
	return tuso;
}

void PhanSo::setMauSo(int mauso){
	this->mauso = mauso;
}

int PhanSo::getMauSo() const{
	return mauso;
}

PhanSo PhanSo::ToiGian(){
	int a = tuso, b = mauso;
	while (b != 0)
	{
		int r = a%b;
		a = b;
		b = r;
	}
	tuso /= a;
	mauso /= a;
	return PhanSo(tuso, mauso);
}

PhanSo PhanSo::operator +(PhanSo ps){
	return PhanSo(tuso*ps.mauso + mauso*ps.tuso, mauso*ps.mauso).ToiGian();
}

PhanSo PhanSo::operator -(PhanSo ps){
	return PhanSo(tuso*ps.mauso - mauso*ps.tuso, mauso*ps.mauso).ToiGian();
}

PhanSo PhanSo::operator *(PhanSo ps){
	return PhanSo(tuso*ps.tuso, mauso*ps.mauso).ToiGian();
}

PhanSo PhanSo::operator /(PhanSo ps){
	return PhanSo(tuso*ps.mauso, mauso*ps.tuso).ToiGian();
}

bool PhanSo::operator ==(PhanSo ps){
	return ((tuso*ps.mauso) == (mauso*ps.tuso));
}

bool PhanSo::operator >(PhanSo ps){
	return ((tuso*ps.mauso) > (mauso*ps.tuso));
}

bool PhanSo::operator >=(PhanSo ps){
	return ((tuso*ps.mauso) >= (mauso*ps.tuso));
}

bool PhanSo::operator <(PhanSo ps){
	return ((tuso*ps.mauso) < (mauso*ps.tuso));
}

bool PhanSo::operator <=(PhanSo ps){
	return ((tuso*ps.mauso) <= (mauso*ps.tuso));
}

PhanSo PhanSo::operator ++ (){
	tuso += mauso;
	ToiGian();
	return  PhanSo(tuso, mauso);
}

PhanSo PhanSo::operator --(){
	tuso -= mauso;
	ToiGian();
	return  PhanSo(tuso, mauso);
}

PhanSo PhanSo::operator +=(PhanSo ps){
	tuso = tuso*ps.mauso + mauso*ps.tuso;
	mauso = mauso*ps.mauso;
	ToiGian();
	return PhanSo(tuso, mauso);
}

PhanSo PhanSo::operator -=(PhanSo ps){
	tuso = tuso*ps.mauso - mauso*ps.tuso;
	mauso = mauso*ps.mauso;
	ToiGian();
	return PhanSo(tuso, mauso);
}

PhanSo PhanSo::operator *=(PhanSo ps){
	tuso = tuso*ps.tuso;
	mauso = mauso*ps.mauso;
	ToiGian();
	return PhanSo(tuso, mauso);
}

PhanSo PhanSo::operator /=(PhanSo ps){
	tuso = tuso*ps.mauso;
	mauso = mauso*ps.tuso;
	ToiGian();
	return PhanSo(tuso, mauso);
}

ostream &operator << (ostream &cout, PhanSo &ps){
	ps.ToiGian();
	if (ps.mauso == 1) cout << ps.tuso << endl;
	else cout << ps.tuso << "/" << ps.mauso << endl;
	return cout;
}

istream &operator >>(istream &cin, PhanSo &ps){
	cout << "Nhap Tu so: "; cin >> ps.tuso;
	cout << "Nhap Mau so: "; cin >> ps.mauso; 
	ps.ToiGian();
	return cin;
}