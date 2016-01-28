#include "Menu.h"

ListKhoa DSKhoa;
ListMon DSMon;
ListSVDC DS_SVDC;
ListSVCN DS_SVCN;

void MenuChuongTrinh()
{
	int chon;
	do
	{
		cout << "Chao mung ban den voi chuong trinh quan ly sinh vien. \nChuong trinh co cac chuc nang sau: " << endl;
		cout << "1. Quan ly mon." << endl;
		cout << "2. Quan ly thong tin sinh vien dai cuong." << endl;
		cout << "3. Quan ly thong tin sinh vien chuyen nganh." << endl;
		cout << "4. In cac khoa trong truong." << endl;
		cout << "0. Thoat" << endl;
		cout << "Moi ban chon: ";
		cin >> chon;
		cin.ignore();
		cout << "--------------" << endl;
		switch (chon)
		{
		case 1:
			MenuMon();
			getchar();
			break;
		case 2:
			MenuSinhVienDaiCuong();
			getchar();
			break;
		case 3:
			MenuSinhVienChuyenNganh();
			getchar();
			break;
		case 4:
			DSKhoa.InToanBoKhoa();
			getchar();
			break;
		case 0:
			cout << "Cam on ban da su dung chuong trinh." << endl;
			break;
		default:
			cout << "Nhap sai. Vui long nhap lai" << endl;
			break;
		}
	} while (chon != 0);
}

void MenuSinhVienDaiCuong()
{
	int chon;
	do
	{
		cout << "=========== Sinh Vien Dai Cuong ===========" << endl;
		cout << "1. Them sinh vien." << endl;
		cout << "2. Sua thong tin sinh vien." << endl;
		cout << "3. Xoa thong tin sinh vien." << endl;
		cout << "4. Tim kiem thong tin sinh vien." << endl;
		cout << "5. Tim sinh vien co diem trung binh cao/thap theo khoa." << endl;
		cout << "6. Tim sinh vien co diem trung binh cao/thap toan truong." << endl;
		cout << "7. In danh sach sinh vien." << endl;
		cout << "8. Quan ly hoc tap sinh vien." << endl;
		cout << "0. Thoat." << endl;
		cout << "Moi ban chon: ";
		cin >> chon;
		cin.ignore();
		cout << "-------------------" << endl;
		switch (chon)
		{
		case 1:
			DS_SVDC.ThemSinhVien();
			break;
		case 2:
			DS_SVDC.SuaThongTinSinhVien();
			break;
		case 3:
			DS_SVDC.XoaThongTinSinhVien();
			break;
		case 4:
			DS_SVDC.TimKiemSinhVien();
			break;
		case 5:
			DS_SVDC.TopDiemTB_Khoa();
			break;
		case 6:
			DS_SVDC.TopDiemTB_ToanTruong();
			break;
		case 7:
			DS_SVDC.InToanBoSinhVien();
			break;
		case 8:
			QuanLyHocTapSVDC();
			break;
		case 0:
			break;
		default:
			cout << "Ban nhap sai. Vui long nhap lai." << endl;
			break;
		}
	} while (chon != 0);
}

void MenuSinhVienChuyenNganh()
{
	int chon;
	do
	{
		cout << "=========== Sinh Vien Chuyen Nganh ===========" << endl;
		cout << "1. Them sinh vien." << endl;
		cout << "2. Sua thong tin sinh vien." << endl;
		cout << "3. Xoa thong tin sinh vien." << endl;
		cout << "4. Tim kiem thong tin sinh vien." << endl;
		cout << "5. Tim sinh vien co diem trung binh cao/thap theo chuyen nganh." << endl;
		cout << "6. Tim sinh vien co diem trung binh cao/thap theo khoa." << endl;
		cout << "7. Tim sinh vien co diem trung binh cao/thap toan truong." << endl;
		cout << "8. In danh sach sinh vien." << endl;
		cout << "9. Quan ly hoc tap sinh vien." << endl;
		cout << "0. Thoat." << endl;
		cout << "Moi ban chon: ";
		cin >> chon;
		cin.ignore();
		cout << "-------------------" << endl;
		switch (chon)
		{
		case 1:
			DS_SVCN.ThemSinhVien();
			break;
		case 2:
			DS_SVCN.SuaThongTinSinhVien();
			break;
		case 3:
			DS_SVCN.XoaThongTinSinhVien();
			break;
		case 4:
			DS_SVCN.TimKiemSinhVien();
			break;
		case 5:
			DS_SVCN.TopDiemTB_ChuyenNganh();
			break;
		case 6:
			DS_SVCN.TopDiemTB_Khoa();
			break;
		case 7:
			DS_SVCN.TopDiemTB_ToanTruong();
			break;
		case 8:
			DS_SVDC.InToanBoSinhVien();
			break;
		case 9:
			QuanLyHocTapSVCN();
			break;
		case 0:
			break;
		default:
			cout << "Ban nhap sai. Vui long nhap lai." << endl;
			break;
		}
	} while (chon != 0);
}

void MenuMon(){
	int chon;
	do
	{
		cout << "=========== Quan ly Mon hoc ===========" << endl;
		cout << "1. Them mon hoc." << endl;
		cout << "2. Tim kiem mon hoc." << endl;
		cout << "3. In danh sach mon hoc." << endl;
		cout << "0. Thoat." << endl;
		cout << "Moi ban chon: ";
		cin >> chon;
		cin.ignore();
		cout << "-------------------" << endl;
		switch (chon)
		{
		case 1:
			DSMon.ThemMon();
			break;
		case 2:
			DSMon.TimKiemMon();
			break;
		case 3:
			DSMon.InToanBoMon();
			break;
		case 0:
			break;
		default:
			cout << "Ban nhap sai. Vui long nhap lai." << endl;
			break;
		}
	} while (chon != 0);
}

void MenuKhoa(){
	int chon;
	do
	{
		cout << "=========== Quan ly Khoa ===========" << endl;
		cout << "1. Tim kiem khoa." << endl;
		cout << "2. In danh sach khoa." << endl;
		cout << "0. Thoat." << endl;
		cout << "Moi ban chon: ";
		cin >> chon;
		cin.ignore();
		cout << "-------------------" << endl;
		switch (chon)
		{
		case 1:
			DSKhoa.TimKiemKhoa();
			break;
		case 2:
			DSKhoa.InToanBoKhoa();
			break;
		case 0:
			break;
		default:
			cout << "Ban nhap sai. Vui long nhap lai." << endl;
			break;
		}
	} while (chon != 0);
}

void QuanLyHocTapSVDC(){
	string suaSinhVien, MSV;
	if (!DS_SVDC.TimKiemSinhVien()){
		return;
	}
	else{
		cout << "Nhap MSV can thao tac: ";
		getline(cin, MSV);
		for (int i = 0; i < DS_SVDC.getList_SVDC().size(); i++){
			if (DS_SVDC.getList_SVDC()[i].getMaSinhVien() == MSV){
				DS_SVDC.HienThiSinhVien(i);
				int chon;
				do
				{
					cout << "=========== Quan ly Mon hoc cua Sinh Vien ===========" << endl;
					cout << "1. Them mon hoc." << endl;
					cout << "2. Tim kiem mon hoc." << endl;
					cout << "3. Xoa mon hoc." << endl;
					cout << "0. Thoat." << endl;
					cout << "Moi ban chon: ";
					cin >> chon;
					cin.ignore();
					cout << "-------------------" << endl;
					switch (chon)
					{
					case 1:
						DSMon.InToanBoMon();
						DS_SVDC.getList_SVDC()[i].ThemMonDaiCuong();
						break;
					case 2:
						DS_SVDC.getList_SVDC()[i].TimKiemMonDaiCuong();
						break;
					case 3:
						DS_SVDC.getList_SVDC()[i].XoaMonDaiCuong();
						break;
					case 0:
						break;
					default:
						cout << "Ban nhap sai. Vui long nhap lai." << endl;
						break;
					}
				} while (chon != 0);
			}
		}
	}
}

void QuanLyHocTapSVCN(){
	string suaSinhVien, MSV;
	if (!DS_SVCN.TimKiemSinhVien()){
		return;
	}
	else{
		cout << "Nhap MSV can thao tac: ";
		getline(cin, MSV);
		for (int i = 0; i < DS_SVCN.getList_SVCN().size(); i++){
			if (DS_SVCN.getList_SVCN()[i].getMaSinhVien() == MSV){
				DS_SVCN.HienThiSinhVien(i);
				int chon;
				do
				{
					cout << "=========== Quan ly hoc tap cua Sinh Vien ===========" << endl;
					cout << "1. Them mon hoc." << endl;
					cout << "2. Tim kiem mon hoc." << endl;
					cout << "3. Xoa mon hoc." << endl;
					cout << "4. In phieu ket qua hoc tap." << endl;
					cout << "0. Thoat." << endl;
					cout << "Moi ban chon: ";
					cin >> chon;
					cin.ignore();
					cout << "-------------------" << endl;
					switch (chon)
					{
					case 1:
						DSMon.InToanBoMon();
						DS_SVCN.getList_SVCN()[i].ThemMonChuyenNganh();
						break;
					case 2:
						DS_SVCN.getList_SVCN()[i].TimKiemMonChuyenNganh();
						break;
					case 3:
						DS_SVCN.getList_SVCN()[i].XoaMonChuyenNganh();
						break;
					case 4:
						InPhieuKetQuaHocTap();
					case 0:
						break;
					default:
						cout << "Ban nhap sai. Vui long nhap lai." << endl;
						break;
					}
				} while (chon != 0);
			}
		}
	}
}

void InPhieuKetQuaHocTap(){
	int vitri;
	string suaSinhVien, MSV;
	if (!DS_SVDC.TimKiemSinhVien()){
		return;
	}
	else{
		cout << "Nhap MSV can thao tac: ";
		getline(cin, MSV);
		cout << setw(20) << "Phieu ket qua hoc tap" << endl;
		for (int i = 0; i < DS_SVDC.getList_SVDC().size(); i++){
			if (DS_SVDC.getList_SVDC()[i].getMaSinhVien() == MSV){
				cout << "MSV: " << DS_SVDC.getList_SVDC()[i].getMaSinhVien() << "\tHo ten: " << DS_SVDC.getList_SVDC()[i].getTenSinhVien() 
					<< "\tNgay sinh: " << DS_SVDC.getList_SVDC()[i].getNgaySinh() << "\tKhoa: " << DS_SVDC.getList_SVDC()[i].getMaKhoaDaHoc()[0] << endl;
				cout << "Danh sach mon dai cuong: " << endl;
				cout << "Ma mon" << setw(20) << "Ten mon" << setw(20) << "So tin chi" << setw(20) << "Diem" << endl;
				for (int i = 0; i < DS_SVDC.getList_SVDC()[i].getMonDaiCuong().size(); i++){
					cout << DS_SVDC.getList_SVDC()[i].getMonDaiCuong()[i].getMaMon() << setw(20) << DS_SVDC.getList_SVDC()[i].getMonDaiCuong()[i].getTenMon() << setw(20) 
						<< DS_SVDC.getList_SVDC()[i].getMonDaiCuong()[i].getSoTin() << setw(20) << DS_SVDC.getList_SVDC()[i].getMonDaiCuong()[i].getDiem() << endl;
				}
				cout << "Tong so mon dai cuong: " << DS_SVDC.getList_SVDC()[i].getMonDaiCuong().size() << "\t\t" << "Diem TBDC: " 
					<< DS_SVDC.getList_SVDC()[i].DiemTrungBinh() << endl;
			}
		}
	}
}

void GhiFiles(){
	ofstream fout("Mon.txt");
	for (int i = 0; i < DSMon.getList_Mon().size(); i++){
		fout << DSMon.getList_Mon()[i].getMaMon() << "$" << DSMon.getList_Mon()[i].getTenMon() << "$" << DSMon.getList_Mon()[i].getMaKhoa() << "$" << DSMon.getList_Mon()[i].getSoTin << "$" << DSMon.getList_Mon()[i].getDCCN() << endl;
	}
	fout.close();

	
}



