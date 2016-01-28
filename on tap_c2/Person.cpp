#include "Person.h"


Person::Person(){

}

Person::Person(const char* hoten, int ngay, int thang, int nam, const char* quequan){
	strcpy_s(this->hoten, hoten);
	this->ngay = ngay;
	this->thang = thang;
	this->nam = nam;
	strcpy_s(this->quequan, quequan);
}

Person::~Person(){

}

void Person::setSinhNhat(int ngay, int thang, int nam){
	this->ngay = ngay;
	this->thang = thang;
	this->nam = nam;
}

int Person::getNgay() const{
	return ngay;
}

int Person::getThang() const{
	return thang;
}

int Person::getNam() const{
	return nam;
}

void Person::setHoTen(const char* hoten){
	strcpy_s(this->hoten, hoten);
}

char* Person::getHoTen(){
	return hoten;
}

void Person::setQueQuan(const char* quequan){
	strcpy_s(this->quequan, quequan);
}

char* Person::getQueQuan(){
	return quequan;
}