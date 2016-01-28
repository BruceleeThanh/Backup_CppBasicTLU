#ifndef SinhVienChuyenNganh_h
#define SinhVienChuyenNganh_h

#include "Lib.h"
#include"SinhVienDaiCuong.h"

using namespace std;

class SinhVienChuyenNganh :public SinhVienDaiCuong
{
private:
	vector<string> TenChuyenNganh;
	double DiemKhoaLuanTN;
	vector<Mon>MonChuyenNganh;
public:
	SinhVienChuyenNganh();
	SinhVienChuyenNganh(string maSinhVien, string tenSinhVien, string ngaySinh, string noiSinh, string diaChi, string soDienThoai, string maKhoa, string tenChuyenNganh);
	
	void setTenChuyenNganh(string tenChuyenNganh);
	void setDiemKhoaLuanTN(double diemKhoaLuan);
	
	vector<string> getTenChuyenNganh();
	double getDiemKhoaLuanTN();
	vector<Mon> getMonChuyenNganh();

	void ThemChuyenNganh();
	void SuaChuyenNganh();
	bool TimKiemChuyenNganh();
	void HienThiChuyenNganh(int vitri);

	void ThemMonChuyenNganh();
	void SuaMonChuyenNganh();
	void XoaMonChuyenNganh();
	bool TimKiemMonChuyenNganh();
	void HienThiMonChuyenNganh(int vitri);

	void ThemDiemKhoaLuanTN();
	void SuaDiemKhoaLuanTN();

	virtual double DiemTrungBinh();
	virtual int TongTin();
	virtual int TongTinCho();

	// khoa
	void ThemKhoa();
	void SuaKhoa();
	bool TimKiemKhoa();
	void HienThiKhoa(int vitri);

	~SinhVienChuyenNganh();
};

class ListSVCN
{
protected:
	vector<SinhVienChuyenNganh> List_SVCN;

public:
	ListSVCN();
	//SV
	void setList_SVCN(SinhVienChuyenNganh); // Them Sinh Vien
	vector<SinhVienChuyenNganh> getList_SVCN();

	void ThemSinhVien();
	void SuaThongTinSinhVien();
	void XoaThongTinSinhVien();
	bool TimKiemSinhVien();
	void HienThiSinhVien(int vitri);
	void InToanBoSinhVien();

	void TopDiemTB_Khoa();
	void TopDiemTB_ChuyenNganh();
	void TopDiemTB_ToanTruong();

	~ListSVCN();
};

#endif;