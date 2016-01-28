#include "phanso.h"
#include <iostream>
using namespace std;

PhanSo::PhanSo(int a, int b){
	tuso = a; mauso = b;
}

PhanSo::PhanSo(int a){
	tuso = a; mauso = 1;
}

PhanSo::PhanSo(){
	tuso = 0; mauso = 1;
}

void PhanSo::setTuso(int tuso){
	this->tuso = tuso;
}

void PhanSo::setMauso(int mauso){
	this->mauso = mauso;
}

double PhanSo::getPhanso() const{
	return (double)tuso / mauso;
}

PhanSo PhanSo::operator +(PhanSo ps){
	int tu, mau;
	tu = tuso*ps.mauso + mauso*ps.tuso;
	mau = mauso*ps.mauso;
	return PhanSo(tu, mau);
}

PhanSo PhanSo::operator*(PhanSo ps){
	return PhanSo(tuso*ps.tuso, mauso*ps.mauso);
}

PhanSo PhanSo::operator-(PhanSo ps){
	return PhanSo(tuso*ps.mauso - mauso*ps.tuso, mauso*ps.mauso);
}

PhanSo PhanSo::operator/(PhanSo ps){
	return PhanSo(tuso*ps.mauso, mauso*ps.tuso);
}

void PhanSo::operator++(){
	tuso = tuso + mauso;
}

void PhanSo::operator--(){
	tuso = tuso - mauso;
}