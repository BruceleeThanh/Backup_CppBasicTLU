#include "Lib.h"
#include "LibClass.h"

SinhVien::SinhVien(){

}

void SinhVien::setMSV(string MSV){
	this->MSV = MSV;
}

void SinhVien::setTen(string Ten){
	this->Ten = Ten;
}

void SinhVien::setNgaySinh(string NgaySinh){
	this->NgaySinh = NgaySinh;
}

void SinhVien::setNoiSinh(string NoiSinh){
	this->NoiSinh = NoiSinh;
}

void SinhVien::setDiaChi(string DiaChi){
	this->DiaChi = DiaChi;
}

void SinhVien::setSdt(string Sdt){
	this->Sdt = Sdt;
}

void SinhVien::setMaKhoa(string MaKhoa){
	this->MaKhoa = MaKhoa;
}

string SinhVien::getMSV(){
	return MSV;
}

string SinhVien::getTen(){
	return Ten;
}

string SinhVien::getNgaySinh(){
	return NgaySinh;
}

string SinhVien::getNoiSinh(){
	return NoiSinh;
}

string SinhVien::getDiaChi(){
	return DiaChi;
}

string SinhVien::getSdt(){
	return Sdt;
}

string SinhVien::getMaKhoa(){
	return MaKhoa;
}

double SinhVien::DiemTB(){
	return 0;
}

SinhVien::~SinhVien(){

}