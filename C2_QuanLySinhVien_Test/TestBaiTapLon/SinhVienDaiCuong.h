#ifndef SinhVienDaiCuong_h
#define SinhVienDaiCuong_h

#include "Lib.h"
#include"SinhVien.h"
#include"Mon.h"

class SinhVienDaiCuong :public SinhVien
{
protected:
	vector<Mon> MonDaiCuong;
public:
	SinhVienDaiCuong();
	SinhVienDaiCuong(string maSinhVien, string tenSinhVien, string ngaySinh, string noiSinh, string diaChi, string soDienThoai, string maKhoa);

	void setMonDaiCuong(Mon mon);
	vector<Mon> getMonDaiCuong();

	void ThemMonDaiCuong();
	void SuaMonDaiCuong();
	void XoaMonDaiCuong();
	bool TimKiemMonDaiCuong();
	void HienThiMonDaiCuong(int vitri);

	virtual double DiemTrungBinh();
	virtual int TongTin();
	virtual int TongTinCho();

	~SinhVienDaiCuong();
};

class ListSVDC
{
protected:
	vector<SinhVienDaiCuong> List_SVDC;
public:
	ListSVDC();

	void setList_SVDC(SinhVienDaiCuong); // Them Sinh Vien
	vector<SinhVienDaiCuong> getList_SVDC();

	void ThemSinhVien();
	void SuaThongTinSinhVien();
	void XoaThongTinSinhVien();
	bool TimKiemSinhVien();
	void HienThiSinhVien(int vitri);
	void InToanBoSinhVien();
	
	void TopDiemTB_Khoa();
	void TopDiemTB_ToanTruong();

	~ListSVDC();
};

#endif;