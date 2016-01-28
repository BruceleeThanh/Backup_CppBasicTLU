#include "Date.h"
#include <iostream>
using namespace std;

Date::Date(){

}
Date::Date(int ngay, int thang, int nam){
	this->ngay = ngay;
	this->thang = thang;
	this->nam = nam;
}
void Date::setNgay(int ngay){
	this->ngay = ngay;
}
int Date::getNgay()const{
	return ngay;
}
void Date::setThang(int thang){
	this->thang = thang;
}
int Date::getThang()const{
	return thang;
}
void Date::setNam(int nam){
	this->nam = nam;
}
int Date::getNam()const{
	return nam;
}
void Date::disPlay(){
	cout << ngay << "/" << thang << "/" << nam << endl;
}
