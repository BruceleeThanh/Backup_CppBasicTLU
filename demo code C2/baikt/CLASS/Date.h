#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;
class Date{
private:
	int ngay,thang,nam;
public:
	Date(){
		ngay = 0;
		thang = 0;
		nam = 0;
	}
	Date(int ngay, int thang, int nam){
		this->ngay = ngay;
		this->thang = thang;
		this->nam = nam;
	}
	void setNgay(int ngay){
		this->ngay = ngay;
	}
	void setThang(int thang){
		this->thang = thang;
	}
	void setNam(int nam){
		this->nam = nam;
	} 
	int getNgay()const{
		return ngay;
	}
	int getThang()const{
		return thang;
	}
	int getNam()const{
		return nam;
	}
	void display()const{
		cout<<ngay<<"/"<<thang<<"/"<<nam;
	}
	friend ostream &operator <<(ostream &cout,const Date &a);
};
ostream &operator << (ostream &cout,const Date &ml){
	 cout<<ml.getNgay()<<"-"<<ml.getThang()<<"-"<<ml.getNam();
	 return cout;
}
#endif