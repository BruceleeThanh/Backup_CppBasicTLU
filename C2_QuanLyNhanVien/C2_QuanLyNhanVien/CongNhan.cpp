#include"CongNhan.h"
#include<iomanip>



//CongNhan
CongNhan::CongNhan()
{
}

void CongNhan::setSoNgayCong(double sn)
{
	if (sn <= 26 && sn >= 0)
		SoNgayCong = sn;
	else
		cout << "Nhap lai.\n";
}

double CongNhan::getSoNgayCong()
{
	return SoNgayCong;
}

double CongNhan::TinhLuong()
{
	return LuongCoBan * HeSoLuong *(SoNgayCong / 26); 
}

void CongNhan::HienThiThongTin()
{
	cout << ID << setw(5) << HoTen << setw(25) << NgaySinh << setw(10) << LuongCoBan << setw(10) << HeSoLuong << setw(10) << SoNgayCong << setw(10) << TinhLuong() << endl;
}

CongNhan::~CongNhan()
{
}

//ListCongNhan
ListCongNhan::ListCongNhan()
{
}

vector<CongNhan> ListCongNhan::getListCN(){
	return CN;
}


void ListCongNhan::ThemCN(int &id)
{
	id++;
	CongNhan x;
	string ten, ns;
	double lcb, hsl;
	double snc;
	cout << "Nhap ten : ";
	getline(cin, ten);
	cout << "Nhap nam sinh: ";
	getline(cin, ns);
	cout << "Nhap luong co ban: ";
	cin >> lcb;
	cin.ignore();
	cout << "Nhap he so luong: ";
	cin >> hsl;
	cin.ignore();
	cout << "Nhap so ngay cong: ";
	cin >> snc;
	x.setHoTen(ten);
	x.setNgaySinh(ns);
	x.setLuongCoBan(lcb);
	x.setHeSoLuong(hsl);
	x.setSoNgayCong(snc);
	CN.push_back(x);
}

void ListCongNhan::TimKiemCN()
{
	int dem = 0;
	string ten, ns;
	double lcb,hsl,snc;
	char chonTim;
	do{
		cout << "Tim theo:\n ";
		cout << "1. Ten.\n";
		cout << "2. Ngay sinh.\n";
		cout << "3. Luong co ban.\n";
		cout << "4. He so luong.\n";
		cout << "5. So ngay cong.\n";
		cout << "0. Thoat.\n";
		cin >> chonTim;
		cin.ignore();
		switch (chonTim)
		{
		case '1':
			dem = 0;
			cout << "Nhap ten can tim: ";
			getline(cin, ten);
			for (int i = 0; i < CN.size(); i++)
			{
				if (CN[i].getHoTen().find(ten, 0) != -1)
				{
					CN[i].HienThiThongTin();
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
			for (int i = 0; i < CN.size(); i++)
			{
				if (CN[i].getNgaySinh().find(ns, 0) != -1)
				{
					CN[i].HienThiThongTin();
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
			for (int i = 0; i < CN.size(); i++)
			{
				if (CN[i].getLuongCoBan() == lcb)
				{
					CN[i].HienThiThongTin();
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
			for (int i = 0; i < CN.size(); i++)
			{
				if (CN[i].getHeSoLuong() == hsl)
				{
					CN[i].HienThiThongTin();
					dem++;
				}
			}
			if (dem == 0)
				cout << "Not found!.\n";
			break;
		case '5':
			dem = 0;
			cout << "Nhap so ngay cong: ";
			cin >> snc;
			for (int i = 0; i < CN.size(); i++)
			{
				if (CN[i].getSoNgayCong() == snc)
				{
					CN[i].HienThiThongTin();
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

void ListCongNhan::SuaCN()
{
	string a;
	double b;
	int id;
	TimKiemCN();
	cout << "Nhap ID nguoi can sua: ";
	cin >> id;
	CN[id].HienThiThongTin();
	char chonSua;
	do{
		cout << "Sua:\n ";
		cout << "1. Ten.\n";
		cout << "2. Ngay sinh.\n";
		cout << "3. Luong co ban.\n";
		cout << "4. He so luong.\n";
		cout << "5. So ngay cong.\n";
		cout << "0. Thoat.\n";
		cin >> chonSua;
		cin.ignore();
		switch (chonSua)
		{
		case '1':
			cout << "Ten duoc sua thanh: ";
			getline(cin, a);
			CN[id].setHoTen(a);
			cout << "Thong tin sau khi sua:\n ";
			CN[id].HienThiThongTin();
			break;
		case '2':
			cout << "Ngay sinh duoc sua thanh: ";
			getline(cin, a);
			CN[id].setNgaySinh(a);
			cout << "Thong tin sau khi sua:\n ";
			CN[id].HienThiThongTin();
			break;
		case '3':
			cout << "Luong co ban duoc sua thanh: ";
			cin >> b;
			cin.ignore();
			CN[id].setLuongCoBan(b);
			cout << "Thong tin sau khi sua:\n ";
			CN[id].HienThiThongTin();
			break;
		case '4':
			cout << "he so luong duoc sua thanh: ";
			cin >> b;
			cin.ignore();
			CN[id].setHeSoLuong(b);
			cout << "Thong tin sau khi sua:\n ";
			CN[id].HienThiThongTin();
			break;
		case '5':
			cout << "So ngay cong duoc sua thanh: ";
			cin >> b;
			cin.ignore();
			CN[id].setSoNgayCong(b);
			cout << "Thong tin sau khi sua:\n ";
			CN[id].HienThiThongTin();
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

void ListCongNhan::XoaCN()
{
	int id;
	TimKiemCN();
	cout << "Nhap ID nguoi muon xoa: ";
	cin >> id;
	CN[id].HienThiThongTin();
	CN.erase(CN.begin() + (id));
	cout << "Thong tin da duoc xoa.\n";
}

void ListCongNhan::DocFileCN(int &id)
{
	CongNhan temp;
	string filter;
	string ten, ns;
	double lcb, hsl, snc;
	ifstream fin("CongNhan.txt");
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
			fin >> snc;
			getline(fin, filter);
			temp.setID(id++);
			temp.setHoTen(ten);
			temp.setNgaySinh(ns);
			temp.setLuongCoBan(lcb);
			temp.setHeSoLuong(hsl);
			temp.setSoNgayCong(snc);
			CN.push_back(temp);
		}
	}
	fin.close();
}

void ListCongNhan::GhiFileCN()
{
	ofstream fout("CongNhan.txt");
	for (int i = 0; i < CN.size(); i++)
	{
		if (i < CN.size() - 1)
			fout << CN[i].getHoTen() << "$" << CN[i].getNgaySinh() << "$" << CN[i].getLuongCoBan() << "$" << CN[i].getHeSoLuong() << "$" << CN[i].getSoNgayCong() << endl;
		else 
			fout << CN[i].getHoTen() << "$" << CN[i].getNgaySinh() << "$" << CN[i].getLuongCoBan() << "$" << CN[i].getHeSoLuong() << "$" << CN[i].getSoNgayCong();
	}

	fout.close();
}

//void ListCongNhan::MenuCN(int id)
//{
//	char chon;
//	do{
//		cout << "Chuc nang:\n";
//		cout << "1. Them cong nhan.\n";
//		cout << "2. Tim kiem thong tin cong nhan.\n";
//		cout << "3. Sua thong tin cong nhan.\n";
//		cout << "4. Xoa thong tin cong nhan.\n";
//		cout << "0. Thoat.\n";
//		cin >> chon;
//		cin.ignore();
//		switch (chon)
//		{
//		case '1':
//			ThemCN(id);
//			break;
//		case '2':
//			TimKiemCN();
//			break;
//		case '3':
//			SuaCN();
//			break;
//		case '4':
//			XoaCN();
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

void ListCongNhan::CNLuongMax()
{
	double max;
	max= CN[0].TinhLuong();
	for (int i = 0; i < CN.size(); i++)
	{
		if (CN[i].TinhLuong() > max)
		{
			max = CN[i].TinhLuong();
		}
	}
	for (int i = 0; i < CN.size(); i++)
	{
		if (CN[i].TinhLuong() == max)
		{
			CN[i].HienThiThongTin();
		}
	}
}

void ListCongNhan::CNLuongMin()
{
	double min;
	min = CN[0].TinhLuong();
	for (int i = 0; i < CN.size(); i++)
	{
		if (CN[i].TinhLuong() < min)
		{
			min = CN[i].TinhLuong();
		}
	}
	for (int i = 0; i < CN.size(); i++)
	{
		if (CN[i].TinhLuong() == min)
		{
			CN[i].HienThiThongTin();
		}
	}
}

void ListCongNhan::HienThiDanhSachCN()
{
	for (int i = 0; i < CN.size(); i++)
	{
		CN[i].HienThiThongTin();
	}
}

ListCongNhan::~ListCongNhan()
{
}










