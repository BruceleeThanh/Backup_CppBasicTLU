#include"CanBoQuanLy.h"


//CanBoQuanLy
CanBoQuanLy::CanBoQuanLy()
{
}

vector<CanBoQuanLy> ListCanBoQuanLy::getListCB(){
	return CB;
}

void CanBoQuanLy::setPhuCap(double pc)
{
	PhuCap = pc;
}

double CanBoQuanLy::getPhuCap()
{
	return PhuCap;
}

double CanBoQuanLy::TinhLuong()
{
	return (LuongCoBan*HeSoLuong) + PhuCap;
}

void CanBoQuanLy::HienThiThongTin()
{
	cout <<ID<<setw(10)<< HoTen << setw(25) << NgaySinh << setw(10) << LuongCoBan << setw(10) << HeSoLuong << setw(10) << PhuCap << setw(10) << TinhLuong() << endl;
}

CanBoQuanLy::~CanBoQuanLy()
{
}

//ListCanBoQuanLy
ListCanBoQuanLy::ListCanBoQuanLy()
{
}

void ListCanBoQuanLy::ThemCB(int &id)
{
	id++;
	CanBoQuanLy a;
	string b;
	double c;
	cout << "Them ten: ";
	getline(cin, b);
	a.setHoTen(b);
	cout << "Them ngay sinh: ";
	getline(cin, b);
	a.setNgaySinh(b);
	cout << "Them luong co ban: ";
	cin >> c;
	a.setLuongCoBan(c);
	cout << "Them he so luong: ";
	cin >> c;
	a.setHeSoLuong(c);
	cout << "Them phu cap: ";
	cin >> c;
	a.setPhuCap(c);
	CB.push_back(a);
}

void ListCanBoQuanLy::SuaCB()
{
	TimKiemCB();
	string a;
	double b;
	int id;
	cout << "Nhap id nguoi can sua: ";
	cin >> id;
	CB[id].HienThiThongTin();
	char chonSua;
	do{
		cout << "Sua:\n ";
		cout << "1. Ten.\n";
		cout << "2. Ngay sinh.\n";
		cout << "3. Luong co ban.\n";
		cout << "4. He so luong.\n";
		cout << "5. Phu cap.\n";
		cout << "0. Thoat.\n";
		cin >> chonSua;
		cin.ignore();
		switch (chonSua)
		{
		case '1':
			cout << "Ten duoc sua thanh: ";
			getline(cin, a);
			CB[id].setHoTen(a);
			cout << "Thong tin sau khi sua:\n ";
			CB[id].HienThiThongTin();
			break;
		case '2':
			cout << "Ngay sinh duoc sua thanh: ";
			getline(cin, a);
			CB[id].setNgaySinh(a);
			cout << "Thong tin sau khi sua:\n ";
			CB[id].HienThiThongTin();
			break;
		case '3':
			cout << "Luong co ban duoc sua thanh: ";
			cin >> b;
			cin.ignore();
			CB[id].setLuongCoBan(b);
			cout << "Thong tin sau khi sua:\n ";
			CB[id].HienThiThongTin();
			break;
		case '4':
			cout << "he so luong duoc sua thanh: ";
			cin >> b;
			cin.ignore();
			CB[id].setHeSoLuong(b);
			cout << "Thong tin sau khi sua:\n ";
			CB[id].HienThiThongTin();
			break;
		case '5':
			cout << "Phu cap duoc sua thanh: ";
			cin >> b;
			cin.ignore();
			CB[id].setPhuCap(b);
			cout << "Thong tin sau khi sua:\n ";
			CB[id].HienThiThongTin();
			break;
		case '0':
			cout << "Thoat sua.\n";
			break;
		default:
			cout << "Nhap sai. Vui long nhap lai.\n";
			getchar();
			system("cls");
			break;
		}
	} while (chonSua != '0');

}

void ListCanBoQuanLy::XoaCB()
{
	int id;
	TimKiemCB();
	cout << "Nhap ID nguoi muon xoa: ";
	cin >> id;
	CB[id].HienThiThongTin();
	CB.erase(CB.begin() + (id));
	cout << "Thong tin da duoc xoa.\n";
}

void ListCanBoQuanLy::TimKiemCB()
{
	int dem = 0;
	string ten, ns;
	double lcb, hsl, pc;
	char chonTim;
	do{
		cout << "Tim theo:\n ";
		cout << "1. Ten.\n";
		cout << "2. Ngay sinh.\n";
		cout << "3. Luong co ban.\n";
		cout << "4. He so luong.\n";
		cout << "5. Phu cap.\n";
		cout << "0. Thoat.\n";
		cin >> chonTim;
		cin.ignore();
		switch (chonTim)
		{
		case '1':
			dem = 0;
			cout << "Nhap ten can tim: ";
			getline(cin, ten);
			for (int i = 0; i < CB.size(); i++)
			{
				if (CB[i].getHoTen().find(ten, 0) != -1)
				{
					CB[i].HienThiThongTin();
					dem++;
				}
			}
			if (dem == 0)
				cout << "Not found!.\n";
			break;
		case '2':
			dem = 0;
			cout << "Nhap ngay sinh can tim: ";
			getline(cin, ns);
			for (int i = 0; i <CB.size(); i++)
			{
				if (CB[i].getNgaySinh().find(ns, 0) != -1)
				{
					CB[i].HienThiThongTin();
					dem++;
				}
			}
			if (dem == 0)
				cout << "Not found!.\n";
			break;
		case '3':
			dem = 0;
			cout << "Nhap luong co ban: ";
			cin >> lcb;
			for (int i = 0; i < CB.size(); i++)
			{
				if (CB[i].getLuongCoBan() == lcb)
				{
					CB[i].HienThiThongTin();
					dem++;
				}
			}
			if (dem == 0)
				cout << "Not found!.\n";
			break;
		case '4':
			dem = 0;
			cout << "Nhap he so luong: ";
			cin >> hsl;
			for (int i = 0; i < CB.size(); i++)
			{
				if (CB[i].getHeSoLuong() == hsl)
				{
					CB[i].HienThiThongTin();
					dem++;
				}
			}
			if (dem == 0)
				cout << "Not found!.\n";
			break;
		case '5':
			dem = 0;
			cout << "Nhap phu cap: ";
			cin >> pc;
			for (int i = 0; i < CB.size(); i++)
			{
				if (CB[i].getPhuCap() == pc)
				{
					CB[i].HienThiThongTin();
					dem++;
				}
			}
			if (dem == 0)
				cout << "Not found!.\n";
			break;
		case '0':
			cout << "Cam on da su dung chuong trinh.\n";
			break;
		default:
			cout << "Nhap sai. Vui long nhap lai.\n";
			getchar();
			system("cls");
			break;
		}
	} while (chonTim != '0');
}

void ListCanBoQuanLy::DocFileCB(int &id)
{
	CanBoQuanLy temp;
	string filter;
	string ten, ns;
	double lcb, hsl, pc;
	ifstream fin("CanBoQuanLy.txt");
	if (!fin.is_open())
	{
		cout << "Khong the mo file.\n";
	}
	else
	{
		while (!fin.eof())
		{
			getline(fin, ten, '$');
			getline(fin, ns, '$');
			fin >> lcb;
			getline(fin, filter, '$');
			fin >> hsl;
			getline(fin, filter, '$');
			fin >> pc;
			getline(fin, filter);
			temp.setID(id++);
			temp.setHoTen(ten);
			temp.setNgaySinh(ns);
			temp.setLuongCoBan(lcb);
			temp.setHeSoLuong(hsl);
			temp.setPhuCap(pc);
			CB.push_back(temp);
		}
	}
	fin.close();
}

void ListCanBoQuanLy::GhiFileCB()
{
	ofstream fout("CanBoQuanLy.txt");
	for (int i = 0; i < CB.size(); i++)
	{
		if (i < CB.size() - 1)
			fout << CB[i].getHoTen() << "$" << CB[i].getNgaySinh() << "$" << CB[i].getLuongCoBan() << "$" << CB[i].getHeSoLuong() << "$" << CB[i].getPhuCap() << endl;
		else
			fout << CB[i].getHoTen() << "$" << CB[i].getNgaySinh() << "$" << CB[i].getLuongCoBan() << "$" << CB[i].getHeSoLuong() << "$" << CB[i].getPhuCap();
	}

	fout.close();
}

//void ListCanBoQuanLy::MenuCB(int id)
//{
//	char chon;
//	do{
//		cout << "Chuc nang:\n";
//		cout << "1. Them can bo.\n";
//		cout << "2. Tim kiem thong tin can bo.\n";
//		cout << "3. Sua thong tin can bo.\n";
//		cout << "4. Xoa thong tin can bo.\n";
//		cout << "0. Thoat.\n";
//		cin >> chon;
//		cin.ignore();
//		switch (chon)
//		{
//		case '1':
//			ThemCB(id);
//			break;
//		case '2':
//			TimKiemCB();
//			break;
//		case '3':
//			SuaCB();
//			break;
//		case '4':
//			XoaCB();
//			break;
//		case '0':
//			cout << "Cam on ban da su dung.\n";
//			break;
//		default:
//			cout << "Nhap sai. Vui long nhap lai.\n";
//			getchar();
//			system("cls");
//			break;
//		}
//	} while (chon != '0');
//}

void ListCanBoQuanLy::CBLuongMax()
{
	double max;
	max = CB[0].TinhLuong();
	for (int i = 0; i < CB.size(); i++)
	{
		if (CB[i].TinhLuong() > max)
		{
			max = CB[i].TinhLuong();
		}
	}
	for (int i = 0; i < CB.size(); i++)
	{
		if (CB[i].TinhLuong() == max)
		{
			CB[i].HienThiThongTin();
		}
	}
}

void ListCanBoQuanLy::CBLuongMin()
{
	double min;
	min = CB[0].TinhLuong();
	for (int i = 0; i < CB.size(); i++)
	{
		if (CB[i].TinhLuong() < min)
		{
			min = CB[i].TinhLuong();
		}
	}
	for (int i = 0; i < CB.size(); i++)
	{
		if (CB[i].TinhLuong() == min)
		{
			CB[i].HienThiThongTin();
		}
	}
}

void ListCanBoQuanLy::HienhiDanhSachCB()
{
	for (int i = 0; i < CB.size(); i++)
	{
		CB[i].HienThiThongTin();
	}
}

ListCanBoQuanLy::~ListCanBoQuanLy(){
}