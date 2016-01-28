#ifndef SinhVien_h
#define SinhVien_h
#include "Lib.h"
#include "Khoa.h"


class SinhVien
{
protected:
	string MaSinhVien;
	string TenSinhVien;
	string NgaySinh;
	string NoiSinh;
	string DiaChi;
	string SoDienThoai;
	vector<string> MaKhoaDaHoc;
public:
	SinhVien();
	SinhVien(string maSinhVien, string tenSinhVien, string ngaySinh, string noiSinh, string diaChi, string soDienThoai, string maKhoa);
	void setMaSinhVien(string maSinhVien);
	void setTenSinhVien(string tenSinhVien);
	void setNgaySinh(string ngaySinh);
	void setNoiSinh(string noiSinh);
	void setDiaChi(string diaChi);
	void setSoDienThoai(string soDienThoai);
	void setMaKhoaDaHoc(string maKhoa);

	string getMaSinhVien();
	string getTenSinhVien();
	string getNgaySinh();
	string getNoiSinh();
	string getDiaChi();
	string getSoDienThoai();
	vector<string> getMaKhoaDaHoc();

	virtual double DiemTrungBinh() = 0;
	virtual int TongTin() = 0;
	virtual int TongTinCho() = 0;

	~SinhVien();
};

//class ListSinhVien
//{
//protected:
//	vector<SinhVien> List_SV;
//	
//public:
//	ListSinhVien();
//	//SV
//	void setSV(); // Them Sinh Vien
//	vector<SinhVien> getSV();
//
//	void SuaThongTinSinhVien();
//	void XoaThongTinSinhVien();
//	void TimKiemSinhVien();
//	//khoa
//	void ThemKhoa();
//	void SuaKhoa();
//	void XoaKhoa();
//	void TimKiemKhoa();
//	~ListSinhVien();
//};

#endif