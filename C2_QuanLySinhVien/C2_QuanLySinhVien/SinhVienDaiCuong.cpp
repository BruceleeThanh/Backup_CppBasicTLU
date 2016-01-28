#include "Lib.h"
#include "LibClass.h"

SinhVienDaiCuong::SinhVienDaiCuong(){

}

void SinhVienDaiCuong::setMonDC(KetQua){

}

vector<KetQua> SinhVienDaiCuong::getMonDC(){
	

double SinhVienDaiCuong::DiemTB(vector<MonHoc> MH){
	double Diem = 0;
	
}

int SinhVienDaiCuong::TongTinDat(vector<MonHoc> MH){
	int Tin = 0;
	for (int i = 0; i < MonDC.size(); i++){
		for (int j = 0; j < MH.size(); j++){
			if (MonDC[i].MaMon == MH[j].getMaMon()){
				if (MonDC[i].Diem >= 4){
					Tin += MH[j].getSoTin();
				}
			}
		}
	}
	return Tin;
}

int SinhVienDaiCuong::TongTinCho(vector<MonHoc> MH){
	int Tin = 0;
	for (int i = 0; i < MonDC.size(); i++){
		for (int j = 0; j < MH.size(); j++){
			if (MonDC[i].MaMon == MH[j].getMaMon()){
				if (MonDC[i].Diem < 4){
					Tin += MH[j].getSoTin();
				}
			}
		}
	}
	return Tin;
}

SinhVienDaiCuong::~SinhVienDaiCuong(){

}