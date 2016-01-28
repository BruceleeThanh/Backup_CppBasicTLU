#include "SachTinHoc.h"


SachTinHoc::SachTinHoc(){

}

SachTinHoc::SachTinHoc(const char* tensach, int namxb, double heso, double gianhap) : Sach(tensach, namxb, gianhap){
	this->gianhap = gianhap;
}

//set

void SachTinHoc::setGiaNhap(double){
	this->gianhap = gianhap;
}

//get

double SachTinHoc::getGiaNhap() const{
	return gianhap;
}

double SachTinHoc::GiaBan(){
	return gianhap*heso;
}



SachTinHoc::~SachTinHoc(){

}
