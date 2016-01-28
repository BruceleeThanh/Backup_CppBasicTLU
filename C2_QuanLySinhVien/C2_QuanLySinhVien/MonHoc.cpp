#include "Lib.h"
#include "LibClass.h"

MonHoc::MonHoc(){

}

MonHoc::MonHoc(string mamon, string tenmon, string makhoa, int sotin, string dccn){
	MaMon = mamon;
	TenMon = tenmon;
	MaKhoa = makhoa;
	SoTin = sotin;
	DCCN = dccn;
}


void MonHoc::setMaMon(string mamon){
	MaMon = mamon;
}

void MonHoc::setTenMon(string tenmon){
	TenMon = tenmon;
}

void MonHoc::setSoTin(int sotin){
	SoTin = sotin;
}

void MonHoc::setDCCN(string dccn){
	DCCN = dccn;
}

void MonHoc::setMaKhoa(string makhoa){
	MaKhoa = makhoa;
}

string MonHoc::getMaMon(){
	return MaMon;
}

string MonHoc::getTenMon(){
	return TenMon;
}

int MonHoc::getSoTin(){
	return SoTin;
}

string MonHoc::getDCCN(){
	return DCCN;
}

string MonHoc::getMaKhoa(){
	return MaKhoa;
}

MonHoc::~MonHoc(){

}

//////////////////////////////////////////////////////


ListMonHoc::ListMonHoc(){

}

ListMonHoc::~ListMonHoc(){

}

void ListMonHoc::setDSMonHoc(MonHoc MH){
	DSMonHoc.push_back(MH);
}

vector<MonHoc> ListMonHoc::getDSMonHoc(){
	return DSMonHoc;
}

void ListMonHoc::menuMon(){
	int chon;
	cout << "Nhap 1 de Tim kiem mon hoc.\nNhap 2 de Them mon hoc.\nNhap 3 de Sua mon hoc.\nNhap 4 de Xoa mon hoc.\nNhap 5 de Hien thi danh sach mon hoc.\nNhap 0 de Thoat." << endl;
	do{
		switch (chon)
		{
		case 1:
			cout << " Tim kiem mon hoc." << endl;
			timkiemMon();
			break;
		case 2:
			cout << "Them mon hoc." << endl;
			themMon();
			break;
		case 3:
			cout << "Sua mon hoc." << endl;
			suaMon();
			break;
		case 4:
			cout << "Xoa mon hoc." << endl;
			xoaMon();
			break;
		case 5:
			cout << "Hien thi danh sach mon hoc." << endl;
			hienthiDSMon();
			break;
		case 0:
			cout << "Thoat Menu Mon hoc." << endl;
			break;
		default:
			break;
		}
	} while (chon != 0);
}

void ListMonHoc::xoaMon(){
	string a;
	int vitri;
	timkiemMon();
	cout << "Nhap Ma mon can xoa: ";
	getline(cin, a);
	for (int i = 0; i < DSMonHoc.size(); i++){
		if (DSMonHoc[i].getMaMon == a){
			vitri = i;
			break;
		}
	}
	DSMonHoc.erase(DSMonHoc.begin() + vitri);
}

void ListMonHoc::themMon(){
	MonHoc monhoc;
	string DCCN;
	string a;
	int sotin;
	cout << "Nhap Ma mon: ";
	getline(cin, a);
	monhoc.setMaMon(a);
	cout << "Nhap Ten mon: ";
	getline(cin, a);
	monhoc.setTenMon(a);
	cout << "Nhap Ma khoa: ";
	getline(cin, a);
	monhoc.setMaKhoa(a);
	cout << "Nhap So tin: ";
	cin >> sotin;
	monhoc.setSoTin(sotin);
	cout << "Nhap mon Dai Cuong (nhap DC) hay Chuyen Nganh (nhap CN): ";
	getline(cin, a);
	monhoc.setDCCN(DCCN);
	setDSMonHoc(monhoc);
}

void ListMonHoc::suaMon(){
	string a;
	int chon;
	int sotin_moi;
	int vitri;
	timkiemMon();
	cout << "Nhap Ma mon can sua: ";
	getline(cin, a);
	for (int i = 0; i < DSMonHoc.size(); i++){
		if (DSMonHoc[i].getMaMon == a){
			vitri = i;
			break;
		}
	}
	do{
		cout << "Nhap 1 de sua Ma mon.\nNhap 2 de sua Ten mon.\nNhap 3 de sua Ma khoa cua mon.\nNhap 4 de sua so Tin.\nNhap 5 de sua Dai Cuong hay Chuyen Nganh.\nBan nhap: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			cout << "Nhap Ma mon moi: ";
			getline(cin, a);
			DSMonHoc[vitri].setMaMon(a);
			cout << "Thanh cong." << endl;
			break;
		case 2:
			cout << "Nhap Ten mon moi: ";
			getline(cin, a);
			DSMonHoc[vitri].setTenMon(a);
			cout << "Thanh cong." << endl;
			break;
		case 3:
			cout << "Nhap Ma khoa moi: ";
			getline(cin, a);
			DSMonHoc[vitri].setMaKhoa(a);
			cout << "Thanh cong." << endl;
			break;
		case 4:
			cout << "Nhap so Tin moi: ";
			cin >> sotin_moi;
			DSMonHoc[vitri].setSoTin(sotin_moi);
			cout << "Thanh cong." << endl;
			break;
		case 5:
			cout << "Nhap mon Dai Cuong (nhap DC) hay Chuyen Nganh (nhap CN): ";
			getline(cin, a);
			DSMonHoc[vitri].setDCCN(a);
			cout << "Thanh cong." << endl;
			break;
		case 0:
			cout << "Thoat sua Mon hoc." << endl;
		default:
			break;
		}
	} while (chon != 0);
}

void ListMonHoc::timkiemMon(){
	string a;
	int b;
	int chon;
	cout << "Nhap 1 de Tim kiem chung.\nNhap 2 de Tim kiem theo So tin chi.\nNhap 3 de Tim kiem theo Dai Cuong hoac Chuyen Nganh.\nNhap 0 de Thoat Tim kiem.\nBan nhap: ";
	do{
		cin >> chon;
		switch (chon)
		{
		case 1:
			cout << "Nhap du lieu can tim: ";
			getline(cin, a);
			for (int i = 0; i < DSMonHoc.size(); i++){
				if (DSMonHoc[i].getMaMon().find(a, 0) != -1){
					hienthiMon(i);
				}
				else{
					if (DSMonHoc[i].getTenMon().find(a, 0) != -1){
						hienthiMon(i);
					}
					else{
						if (DSMonHoc[i].getMaKhoa().find(a, 0) != -1){
							hienthiMon(i);
						}
					}
				}
			}
			break;
		case 2:
			cout << "Nhap So tin chi: ";
			cin >> b;
			for (int i = 0; i < DSMonHoc.size(); i++){
				if (DSMonHoc[i].getSoTin == b){
					hienthiMon(i);
				}
			}
			break;
		case 3:
			cout << "Nhap DC de Tim kiem mon Dai cuong.\nNhap CN de Tim kiem mon Chuyen nganh: ";
			getline(cin, a);
			for (int i = 0; i < DSMonHoc.size(); i++){
				if (DSMonHoc[i].getDCCN() == a){
					hienthiMon(i);
				}
			}
			break;
		case 0:
			cout << "Thoat Tim kiem Mon hoc." << endl;
			break;
		default:
			break;
		}
	} while (chon != 0);
}

void ListMonHoc::hienthiMon(int vitri){
	cout << "Ma Mon: " << DSMonHoc[vitri].getMaMon() << endl;
	cout << "Ten Mon: " << DSMonHoc[vitri].getTenMon() << endl;
	cout << "Ma Khoa: " << DSMonHoc[vitri].getMaKhoa() << endl;
	cout << "So tin: " << DSMonHoc[vitri].getSoTin() << endl;
	cout << "DCCN: " << DSMonHoc[vitri].getDCCN() << endl;
	cout << "----------------------" << endl;
}

void ListMonHoc::hienthiDSMon(){
	cout << "Danh sach tat ca cac mon:" << endl;
	for (int i = 0; i < DSMonHoc.size(); i++){
		hienthiMon(i);
	}
}