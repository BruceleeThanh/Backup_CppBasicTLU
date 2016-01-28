#ifndef SINHVIENDAICUONG_H
#define SINHVIENDAICUONG_H
#include "Lib.h"

class SinhVienDaiCuong : public SinhVien
{
private:
	struct KetQua
	{
		string MaMon;
		double Diem;
	};
protected:
	vector<KetQua> MonDC;
	int TongTinDat;
	int TongTinCho;

public:
	void setMonDC(KetQua);
	vector<KetQua> getMonDC();
	virtual double DiemTB(vector<MonHoc>);
	virtual int TongTinDat(vector<MonHoc>);
	virtual int TongTinCho(vector<MonHoc>);
	

};



#endif