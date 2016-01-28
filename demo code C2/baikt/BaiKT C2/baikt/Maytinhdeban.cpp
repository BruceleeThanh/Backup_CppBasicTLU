#include "Maytinhdeban.h"
#include <iostream>
using namespace std; 

MayTinhDeBan::MayTinhDeBan(){

}
void MayTinhDeBan::setLoaicase(bool loaicase){
	this->loaicase = loaicase;
}
void MayTinhDeBan::getLoaicase()const{
	if (loaicase == false) cout << "May nam";
	else cout << "May dung";
}