#ifndef SINHVIEN_H
#define SINHVIEN_H
#include "Lib.h"

class SinhVien{

protected:
	string MSV;
	string Ten;
	string NgaySinh;
	string NoiSinh;
	string DiaChi;
	string Sdt;
	string MaKhoa;
public:
	SinhVien();
	void setMSV(string);
	void setTen(string);
	void setNgaySinh(string);
	void setNoiSinh(string);
	void setDiaChi(string);
	void setSdt(string);
	void setMaKhoa(string);
	string getMSV();
	string getTen();
	string getNgaySinh();
	string getNoiSinh();
	string getDiaChi();
	string getSdt();
	string getMaKhoa();
	virtual double DiemTB();
	~SinhVien();


};





#endif