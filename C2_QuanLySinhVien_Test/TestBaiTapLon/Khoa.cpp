#include"Khoa.h"


//Khoa
Khoa::Khoa()
{

}

Khoa::Khoa(string maKhoa, string tenKhoa){
	MaKhoa = maKhoa;
	TenKhoa = tenKhoa;
}

void Khoa::setMaKhoa(string maKhoa)
{
	MaKhoa = maKhoa;
}

void Khoa::setTenKhoa(string tenKhoa)
{
	TenKhoa = tenKhoa;
}

string Khoa::getMaKhoa()
{
	return MaKhoa;
}

string Khoa::getTenKhoa()
{
	return TenKhoa;
}

Khoa::~Khoa()
{
}


ListKhoa::ListKhoa()
{
	string temp;
	string maKhoa, tenKhoa;
	ifstream fin("Khoa.txt");
	if (!fin.is_open()){
		cout << "Khong the mo file." << endl;
	}
	else{
		while (!fin.eof()){
			getline(fin, maKhoa, '$');
			getline(fin, tenKhoa);
			Khoa khoa(maKhoa, tenKhoa);
			setList_Khoa(khoa);
		}
	}
	fin.close();
}

void ListKhoa::setList_Khoa(Khoa khoa)
{
	List_Khoa.push_back(khoa);
}

vector<Khoa> ListKhoa::getList_Khoa()
{
	return List_Khoa;
}

bool ListKhoa::TimKiemKhoa(){
	string tim;
	bool flag = false;
	cout << "Nhap du lieu can tim: ";
	getline(cin, tim);
	InTieuDeDSKhoa();
	for (int i = 0; i < List_Khoa.size(); i++){
		if (List_Khoa[i].getMaKhoa().find(tim, 0) != -1){
			HienThiKhoa(i);
			flag = true;
		}
		else{
			if (List_Khoa[i].getTenKhoa().find(tim, 0) != -1){
				HienThiKhoa(i);
				flag = true;
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

void ListKhoa::HienThiKhoa(int vitri){
	cout << left << setw(12) << List_Khoa[vitri].getMaKhoa() << List_Khoa[vitri].getTenKhoa() << endl;
	cout << left << setw(12) << "___________|" << "___________________|" << endl;
}

void ListKhoa::InToanBoKhoa(){
	InTieuDeDSKhoa();
	for (int i = 0; i < List_Khoa.size(); i++){
		HienThiKhoa(i);
	}
}

ListKhoa::~ListKhoa(){

}

// Ham tro giup In danh sach

// In cac tieu de cua danh sach Khoa
void InTieuDeDSKhoa(){
	cout << left << setw(12) << "  Ma Khoa" << "   Ten Khoa" << endl;
	cout << left << setw(12) << "___________|" << "___________________|" << endl;
}