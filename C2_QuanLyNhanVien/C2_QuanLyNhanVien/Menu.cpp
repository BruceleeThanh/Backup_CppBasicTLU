#include"Menu.h"

void Menu(ListCongNhan &CN, ListCanBoQuanLy &CB)
{
	
	int idCN = 0;
	int idCB = 0;
	CN.DocFileCN(idCN);
	CB.DocFileCB(idCB);
	char chon;
	do{
		cout << "Ban muon lam viec voi :\n";
		cout << "1. Cong Nhan.\n";
		cout << "2. Can bo quan ly.\n";
		cout << "3. Danh sach sap xep theo luong.\n";
		cout << "0. Thoat.\n";
		cin >> chon;
		cin.ignore();
		system("cls");
		switch (chon)
		{
		case '1':
			MenuCN(CN);
			break;
		case '2':
			MenuCB(CB);
			break;
		case '3':
			cout << "Danh sach sap xep theo luong." << endl;
			sapxepTheoLuong(CN,CB);
			break;
		case '0':
			cout << "Cam on ban da su dung.\n";
			CN.GhiFileCN();
			CB.GhiFileCB();
			break;
		default:
			cout << "Nhap sai. Vui long nhap lai.\n";
			getchar();
			system("cls");
			break;
		}
	} while (chon != '0');
}

void MenuCN(ListCongNhan &CN)
{
	int id;
	char chonCN;
	do{
		cout << "1. Them thong tin cong nhan.\n";
		cout << "2. Sua thong tin cong nhan.\n";
		cout << "3 Xoa thong tin cong nhan.\n";
		cout << "4. Tim kiem thong tin cong nhan.\n";
		cout << "5. Cong nhan co luong cao nhat.\n";
		cout << "6. Cong nhan co luong thap nhat.\n";
		cout << "7. Hien thi danh sach cong nhan.\n";
		cout << "0. Thoat.\n";
		cin >> chonCN;
		cin.ignore();
		system("cls");
		switch (chonCN)
		{
		case '1':
			CN.ThemCN(id);
			system("cls");
			break;
		case '2':
			CN.SuaCN();
			system("cls");
			break;
		case '3':
			CN.XoaCN();
			system("cls");
			break;
		case '4':
			CN.TimKiemCN();
			system("cls");
			break;
		case '5':
			CN.CNLuongMax();
			//system("cls");
			break;
		case '6':
			CN.CNLuongMin(); 
			//system("cls");
			break;
		case '7':
			CN.HienThiDanhSachCN();
			//system("cls");
			break;
		case '0':
			cout << "Cam on ban da su dung.\n";
			system("cls");
			break;
		default:
			cout << "Nhap sai. Vui long nhap lai.\n";
			getchar();
			system("cls");
			break;
		}
	} while (chonCN != '0');
}

void MenuCB(ListCanBoQuanLy &CB)
{
	int id;
	char chonCB;
	do{
		cout << "1. Them thong tin cong nhan.\n";
		cout << "2. Sua thong tin cong nhan.\n";
		cout << "3 Xoa thong tin cong nhan.\n";
		cout << "4. Tim kiem thong tin cong nhan.\n";
		cout << "5. Cong nhan co luong cao nhat.\n";
		cout << "6. Cong nhan co luong thap nhat.\n";
		cout << "7 Hien thi danh sach cong nhan.\n";
		cout << "0. Thoat.\n";
		cin >> chonCB;
		cin.ignore();
		system("cls");
		switch (chonCB)
		{
		case '1':
			CB.ThemCB(id);
			system("cls");
			break;
		case '2':
			CB.SuaCB();
			system("cls");
			break;
		case '3':
			CB.XoaCB();
			system("cls");
			break;
		case '4':
			CB.TimKiemCB();
			system("cls");
			break;
		case '5':
			CB.CBLuongMax();
			//system("cls");
			break;
		case '6':
			CB.CBLuongMin();
			//system("cls");
			break;
		case '7':
			CB.HienhiDanhSachCB();
			//system("cls");
			break;
		case '0':
			cout << "Cam on ban da su dung.\n";
			system("cls");
			break;
		default:
			cout << "Nhap sai. Vui long nhap lai.\n";
			getchar();
			system("cls");
			break;
		}
	} while (chonCB != '0');
}

void sapxepTheoLuong(ListCongNhan CN, ListCanBoQuanLy CB){
	double luong_temp[1000];
	double luong[1000];
	int dem = 0;
	int slCN, slCB; // so luong CN, so luong CB
	slCN = CN.getListCN().size();
	slCB = CB.getListCB().size();
	for (int i = 0; i < slCN + slCB; i++){
		if (i < slCN){
			luong_temp[i] = CN.getListCN()[i].TinhLuong();
		}
		else
		{
			luong_temp[i] = CB.getListCB()[i - slCN].TinhLuong();
		}
	}
	luong[0] = luong_temp[0];
	dem++;
	for (int i = 0; i < slCN + slCB; i++){
		for (int j = 0; j < dem; j++){
			if (luong_temp[i]==luong[j]){
				break;
			}
			else{
				if (j == dem - 1){
					luong[dem] = luong_temp[i];
					dem++;
					break;
				}
			}
		}
	}
	for (int i = 0; i < dem - 1; i++){
		for (int j = i + 1; j < dem; j++){
			if (luong[i] > luong[j]){
				double temp = luong[i];
				luong[i] = luong[j];
				luong[j] = temp;
			}
		}
	}
	for (int i = 0; i < dem; i++){
		for (int j = 0; j < slCN; j++){
			if (luong[i] == CN.getListCN()[j].TinhLuong()){
				CN.getListCN()[j].HienThiThongTin();
			}
		}
		for (int j = 0; j < slCB; j++){
			if (luong[i] == CB.getListCB()[j].TinhLuong()){
				CB.getListCB()[j].HienThiThongTin();
			}
		}
	}
}