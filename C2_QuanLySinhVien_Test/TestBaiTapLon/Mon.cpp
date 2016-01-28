#include"Mon.h"

//Mon
Mon::Mon()
{

}

Mon::Mon(string maMon, string tenMon, string maKhoa, int soTin, bool DCCN){
	MaMon = maMon;
	TenMon = tenMon;
	MaKhoa = maKhoa;
	SoTin = soTin;
	this->DCCN = DCCN;
}

void Mon::setMaMon(string maMon)
{
	MaMon = maMon;
}

void Mon::setTenMon(string tenMon)
{
	TenMon = tenMon;
}

void Mon::setSoTin(int soTin)
{
	SoTin = soTin;
}

void Mon::setMaKhoa(string maKhoa)
{
	MaKhoa = maKhoa;
}

void Mon::setDiem(double diem)
{
	Diem = diem;
}

void Mon::setDCCN(bool DCCN){
	this->DCCN = DCCN;
}

string Mon::getMaMon()
{
	return MaMon;
}

string Mon::getTenMon()
{
	return TenMon;
}

int Mon::getSoTin()
{
	return SoTin;
}

string Mon::getMaKhoa()
{
	return MaKhoa;
}

bool Mon::getDCCN(){
	return DCCN;
}

double Mon::getDiem()
{
	return Diem;
}

Mon::~Mon()
{
}

//ListMon
ListMon::ListMon(){
	string temp;
	string maMon, tenMon, maKhoa;
	int soTin;
	bool DCCN;
	ifstream fin("Mon.txt");
	if (!fin.is_open()){
		cout << "Khong the mo file." << endl;
	}
	else{
		while (!fin.eof()){
			getline(fin, maMon, '$');
			getline(fin, tenMon, '$');
			getline(fin, maKhoa, '$');
			fin >> soTin;
			getline(fin, temp, '$');
			fin >> DCCN;
			getline(fin, temp);
			Mon mon(maMon, tenMon, maKhoa, soTin, DCCN);
			setList_Mon(mon);
		}
	}
	fin.close();
}

void ListMon::setList_Mon(Mon mon){
	List_Mon.push_back(mon);
}

vector<Mon> ListMon::getList_Mon(){
	return List_Mon;
}

void ListMon::ThemMon()
{
	string maMon, tenMon, maKhoa;
	bool DCCN;
	int soTin;
	cout << "Nhap ma mon: ";
	getline(cin, maMon);
	cout << "Nhap ten mon: ";
	getline(cin, tenMon);
	cout << "Nhap ma khoa: ";
	getline(cin, maKhoa);
	cout << "Nhap so tin: ";
	cin >> soTin;
	cout << "Nhap dai cuong (nhan 0) hay chuyen nganh (nhan 1): ";
	cin >> DCCN;
	Mon x(maMon, tenMon, maKhoa, soTin, DCCN);
	List_Mon.push_back(x);
}

bool ListMon::TimKiemMon(){
	string tim;
	bool flag = false;
	cout << "Nhap du lieu can tim: ";
	getline(cin, tim);
	InTieuDeDSMon();
	for (int i = 0; i < List_Mon.size(); i++){
		if (List_Mon[i].getMaMon() .find(tim, 0) != -1){
			HienThiMon(i);
			flag = true;
		}
		else{
			if (List_Mon[i].getTenMon() .find(tim, 0) != -1){
				HienThiMon(i);
				flag = true;
			}
			else{
				if (List_Mon[i].getMaKhoa() .find(tim, 0) != -1){
					HienThiMon(i);
					flag = true;
				}
			}
		}
	}
	if (!flag){
		cout << "Khong tim thay." << endl;
		return false;
	}
	else{
		return true;
	}
}

void ListMon::HienThiMon(int vitri){
	cout << left << setw(12) << List_Mon[vitri].getMaMon() << left << setw(31) << List_Mon[vitri].getTenMon() << left << setw(9) << List_Mon[vitri].getMaKhoa() << List_Mon[vitri].getSoTin();
	if (List_Mon[vitri].getDCCN()){
		cout << "\t     Chuyen nganh" << endl;
	}
	else{
		cout << "\t     Dai cuong" << endl;
	}
	cout << "___________|_____________________________|________|________|___________________|" << endl;
}

void ListMon::InToanBoMon(){
	InTieuDeDSMon();
	for (int i = 0; i < List_Mon.size(); i++){
		HienThiMon(i);
	}
}

ListMon::~ListMon(){

}

// Ham tro giup In danh sach

// In cac tieu de cua danh sach Khoa
void InTieuDeDSMon(){
	cout << "  Ma Mon              Ten Mon             Ma Khoa   So Tin       Loai mon"<< endl;
	cout << "___________|_____________________________|________|________|___________________|" << endl;
}