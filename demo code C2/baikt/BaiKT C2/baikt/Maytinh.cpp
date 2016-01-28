#include "Maytinh.h"
#include "Date.h"
#include <iostream>
using namespace std;
#include <string.h>

MayTinh::MayTinh(){

}
MayTinh::MayTinh(Date namsanxuat, const char* hang){
	this->namsanxuat = namsanxuat;
	strcpy_s(this->hang, hang);
}
void MayTinh::setNamsanxuat(int){
	this->namsanxuat = namsanxuat;
}
int MayTinh::getNamsanxuat()const{
	return namsanxuat.getNam();
}
void MayTinh::setHang(const char* hang){
	strcpy_s(this->hang, hang);
}
char MayTinh::getHang()const{
	return hang[50];
}
void MayTinh::disPlay(){
	namsanxuat.disPlay();
	for (int i = 0; i < strlen(hang); i++) cout << hang[i];
	cout << endl;
}