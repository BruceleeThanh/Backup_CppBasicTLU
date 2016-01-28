#include"SinhVien.h"

//SinhVien
SinhVien::SinhVien()
{

}

SinhVien::SinhVien(string maSinhVien, string tenSinhVien, string ngaySinh, string noiSinh, string diaChi, string soDienThoai, string maKhoa)
{
	MaSinhVien = maSinhVien;
	TenSinhVien = tenSinhVien;
	NgaySinh = ngaySinh;
	NoiSinh = noiSinh;
	DiaChi = diaChi;
	SoDienThoai = soDienThoai;
	MaKhoaDaHoc.push_back(maKhoa);
}

void SinhVien::setMaSinhVien(string maSinhVien) 
{
	
}

void SinhVien::setTenSinhVien(string tenSinhVien)
{
	TenSinhVien = tenSinhVien;
}

void SinhVien::setNgaySinh(string ngaySinh)
{
	NgaySinh = ngaySinh;
}

void SinhVien::setNoiSinh(string noiSinh)
{
	NoiSinh = noiSinh;
}

void SinhVien::setDiaChi(string diaChi)
{
	DiaChi = diaChi;
}

void SinhVien::setSoDienThoai(string soDienThoai)
{
	SoDienThoai = soDienThoai;
}

void SinhVien::setMaKhoaDaHoc(string maKhoa)
{
	MaKhoaDaHoc.push_back(maKhoa);
}

string SinhVien::getMaSinhVien()
{
	return MaSinhVien;
}

string SinhVien::getTenSinhVien()
{
	return TenSinhVien;
}

string SinhVien::getNgaySinh()
{
	return NgaySinh;
}

string SinhVien::getNoiSinh()
{
	return NoiSinh;
}

string SinhVien::getDiaChi()
{
	return DiaChi;
}

string SinhVien::getSoDienThoai()
{
	return SoDienThoai;
}

vector<string> SinhVien::getMaKhoaDaHoc()
{
	return MaKhoaDaHoc;
}

//void SinhVien::ThemKhoa()//(TT or KT)
//{
//	if (Ma == "TT")
//	{
//
//	}
//	MaKhoa.push_back()
//	
//}

SinhVien::~SinhVien()
{
}


//ListSinhVien

//ListSinhVien::ListSinhVien()
//{
//	string msv, ten, sdt, dc, em, ns, mk;
//	SinhVien temp;
//	ifstream fin("Khoa.txt");
//	if (!fin.is_open())
//	{
//		cout << "Khong the mo file." << endl;
//	}
//	else{
//		while (!fin.eof()){
//			getline(fin, msv);
//			getline(fin, ten);
//			getline(fin, sdt);
//			getline(fin, dc);
//			getline(fin, em);
//		}
//	}
//}
//
//void ListSinhVien::setSV()
//{
//	SinhVien sv;
//	cout << "Ban da chon them." << endl;
//	string msv, ten, sdt, dc, em, ns, mk;
//	cout << "Moi ban them MSV: ";
//	cin.ignore(1);
//	getline(cin, msv);
//	cout << "Moi ban them ten: ";
//	cin.ignore(1);
//	getline(cin, ten);
//	cout << "Moi ban them ngay sinh: ";
//	cin.ignore(1);
//	getline(cin, ns);
//	cout << "Moi ban them so dien thoai: ";
//	cin.ignore(1);
//	getline(cin, sdt);
//	cout << "Moi ban them dia chi: ";
//	cin.ignore(1);
//	getline(cin, dc);
//	cout << "Moi ban them ma khoa: ";
//	getline(cin, mk);
//
//	sv.setMaSinhVien(msv);
//	sv.setTenSinhVien(ten);
//	sv.setNgaySinh(ns);
//	sv.setSoDienThoai(sdt);
//	sv.setDiaChi(dc);
//	sv.setMaKhoaDaHoc(mk);
//
//	List_SV.push_back(sv);
//
//	cout << "\nSinh vien da duoc them." << endl;
//	cout << "-------------------" << endl;
//}
//
//vector<SinhVien> ListSinhVien::getSV(){
//	return List_SV;
//}
//
//void ListSinhVien::SuaThongTinSinhVien()
//{
//	TimKiemSinhVien();
//	int vitriSua;
//	string maSinhVien;
//	cout << "Nhap ma sinh vien can sua: ";
//	getline(cin, maSinhVien);
//	for (int i = 0; i < List_SV.size(); i++)
//	{
//		if (List_SV[i].getMaSinhVien() == maSinhVien)
//		{
//			List_SV[i].HienThiThongTin();
//			vitriSua = i;
//			break;
//		}
//	}
//	char chonSua;
//	string a;
//	do{
//		cout << "1. Sua ma sinh vien.\n";
//		cout << "2. Sua ten.\n";
//		cout << "3. Sua ngay sinh.\n";
//		cout << "4. Sua noi sinh.\n";
//		cout << "5. Sua dia chi.\n";
//		cout << "6. Sua so dien thoai.\n";
//		cout << "7. Sua ma khoa.\n";
//		cout << "8. Sua chuyen nganh.\n";
//		cout << "0. Thoat.\n";
//		cin >> chonSua;
//		cin.ignore();
//		switch (chonSua)
//		{
//		case '1':
//			cout << "Ma sinh vien duoc sua thanh: ";
//			getline(cin, a);
//			List_SV[vitriSua].setMaSinhVien(a);
//			cout << "Thong tin sinh vien sau khi sua:\n";
//			List_SV[vitriSua].HienThiThongTin();
//			break;
//		case '2':
//			cout << "Ten duoc sua thanh: ";
//			getline(cin, a);
//			List_SV[vitriSua].setTenSinhVien(a);
//			cout << "Thong tin sinh vien sau khi sua:\n";
//			List_SV[vitriSua].HienThiThongTin();
//			break;
//		case '3':
//			cout << "Ngay sinh duoc sua thanh: ";
//			getline(cin, a);
//			List_SV[vitriSua].setNgaySinh(a);
//			cout << "Thong tin sinh vien sau khi sua:\n";
//			List_SV[vitriSua].HienThiThongTin();
//			break;
//		case '4':
//			cout << "Noi sinh duoc sua thanh: ";
//			getline(cin, a);
//			List_SV[vitriSua].setNoiSinh(a);
//			cout << "Thong tin sinh vien sau khi sua:\n";
//			List_SV[vitriSua].HienThiThongTin();
//			break;
//		case '5':
//			cout << "Dia chi duoc sua thanh: ";
//			getline(cin, a); 
//			List_SV[vitriSua].setDiaChi(a);
//			cout << "Thong tin sinh vien sau khi sua:\n";
//			List_SV[vitriSua].HienThiThongTin();
//			break;
//		case '6':
//			cout << "So dien thoai duoc sua thanh: ";
//			getline(cin, a);
//			List_SV[vitriSua].setSoDienThoai(a);
//			cout << "Thong tin sinh vien sau khi sua:\n";
//			List_SV[vitriSua].HienThiThongTin();
//			break;
//		case '7':
//			cout << "Ma khoa duoc sua thanh: ";
//			getline(cin, a);
//			List_SV[vitriSua].setMaKhoaDaHoc(a);
//			cout << "Thong tin sinh vien sau khi sua:\n";
//			List_SV[vitriSua].HienThiThongTin();
//			break;
//		/*case '8':
//			cout << "Ten chuyen nganh duoc sua thanh: ";
//			getline(cin, a);
//			List_SV[vitriSua].setTenChuyenNganh(a);
//			cout << "Thong tin sinh vien sau khi sua:\n";
//			List_SV[vitriSua].HienThiThongTin();
//			break;*/
//		case '0':
//			cout << "Cam on ban da su dung.\n";
//			break;
//		default:
//			cout << "Nhap sai. Vui long nhap lai.\n";
//			getchar();
//			system("cls");
//			break;
//		}
//	} while (chonSua != '0');
//}
//
///*void ListSinhVien::XoaThongTinSinhVien()
//{
//	TimKiemSinhVien();
//	string maSinhVien;
//	string a;
//	cout << "Nhap ma sinh vien muon xoa: ";
//	getline(cin, maSinhVien);
//	for (int i = 0; i < SV.size(); i++)
//	{
//		if (SV[i].getMaSinhVien()==maSinhVien)
//		{
//			SV[i].HienThiThongTin();
//			break;
//		}
//	}
//
//	SV.erase(SV.begin() );
//	
//	cout << "Thong tin da duoc xoa.\n";
//}*/ 
//
//void ListSinhVien::TimKiemSinhVien()
//{
//	int dem = 0;
//	string find_SV;
//	cout << "Nhap noi dung can tim: ";
//	getline(cin, find_SV);
//	cout << "Ket qua tim duoc:\n ";
//	for (int i = 0; i < SV.size(); i++)
//	{
//		if (SV[i].getMaSinhVien().find(find_SV, 0) != -1)
//		{
//			SV[i].HienThiThongTin();
//			dem++;
//		}
//		else{
//			if (SV[i].getTenSinhVien().find(find_SV, 0) != -1)
//			{
//				SV[i].HienThiThongTin();
//				dem++;
//			}
//			else{
//				if (SV[i].getNgaySinh().find(find_SV, 0) != -1)
//				{
//					SV[i].HienThiThongTin();
//					dem++;
//				}
//				else{
//					if (SV[i].getNoiSinh().find(find_SV, 0) != -1)
//					{
//						SV[i].HienThiThongTin();
//						dem++;
//					}
//					else{
//						if (SV[i].getDiaChi().find(find_SV, 0) != -1)
//						{
//							SV[i].HienThiThongTin();
//							dem++;
//						}
//						else{
//							if (SV[i].getSoDienThoai().find(find_SV, 0) != -1)
//							{
//								SV[i].HienThiThongTin();
//								dem++;
//							}
//							else{
//								if (SV[i].getKhoaDaHoc().find(find_SV, 0) != -1)
//								{
//									SV[i].HienThiThongTin();
//									dem++;
//								}
//								else
//								{
//									if (SV[i].getTenChuyenNganh().find(find_SV, 0) != -1)
//									{
//										SV[i].HienThiThongTin();
//										dem++;
//									}
//								}
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	if (dem == 0)
//		cout << "Khong tim thay thong tin.\n";
//}
//
//void ListSinhVien::ThemKhoa()
//{
//	Khoa b;
//	string a;
//	cout << "Them ma khoa: ";
//	getline(cin, a);
//	b.setKhoaDaHoc(a);
//	cout << "Them ten khoa: ";
//	getline(cin, a);
//	b.setTenKhoa(a);
//	khoa.push_back(b);
//}
//
//void ListSinhVien::TimKiemKhoa()
//{
//	int dem = 0;
//	string find_khoa;
//	cout << "nhap noi dung can tim: ";
//	getline(cin, find_khoa);
//	cout << "Ket qua tim duoc:\n ";
//	for (int i = 0; i < khoa.size(); i++)
//	{
//		if (khoa[i].getKhoaDaHoc().find(find_khoa, 0) != -1)
//		{
//			khoa[i].In();
//			dem++;
//		}
//		else
//		{
//			if (khoa[i].getTenKhoa().find(find_khoa, 0) != -1)
//			{
//				khoa[i].In();
//				dem++;
//			}
//		}
//	}
//	if (dem == 0)
//		cout << "Khong tim thay.\n";
//}
//
//
//ListSinhVien::~ListSinhVien()
//{
//}