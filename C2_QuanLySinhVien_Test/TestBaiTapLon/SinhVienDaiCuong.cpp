#include"SinhVienDaiCuong.h"

SinhVienDaiCuong::SinhVienDaiCuong(){

}

SinhVienDaiCuong::SinhVienDaiCuong(string maSinhVien, string tenSinhVien, string ngaySinh, string noiSinh, string diaChi, string soDienThoai, string maKhoa) :
SinhVien(maSinhVien, tenSinhVien, ngaySinh, noiSinh, diaChi, soDienThoai, maKhoa){

}

void SinhVienDaiCuong::setMonDaiCuong(Mon mon){
	MonDaiCuong.push_back(mon);
}

vector<Mon> SinhVienDaiCuong::getMonDaiCuong(){
	return MonDaiCuong;
}

void SinhVienDaiCuong::ThemMonDaiCuong(){
	Mon temp;
	string maMon, tenMon;
	int soTin;
	double diem;
	cout << "Nhap ma mon: ";
	getline(cin, maMon);
	cout << "Nhap ten mon: ";
	getline(cin, tenMon);
	cout << "Nhap so tin: ";
	cin >> soTin;
	cout << "Nhap diem tong ket (neu chua co diem thi nhap diem = -1)";
	cin >> diem;
	temp.setMaMon(maMon);
	temp.setTenMon(tenMon);
	temp.setSoTin(soTin);
	temp.setDiem(diem);
	MonDaiCuong.push_back(temp);
}

void SinhVienDaiCuong::SuaMonDaiCuong(){
	string maMon, suaMaMon;
	double suaDiem;
	cout << "Tim mon can sua:" << endl;
	if (!TimKiemMonDaiCuong()){
		return;
	}
	else{
		cout << "Nhap ma mon can sua: ";
		getline(cin, maMon);
		for (int i = 0; i < MonDaiCuong.size(); i++){
			if (MonDaiCuong[i].getMaMon() == maMon){
				HienThiMonDaiCuong(i);
				char chon;
				do
				{
					cout << "Sua mon: " << endl;
					cout << "1. Thay doi mon." << endl;
					cout << "2. Thay doi diem." << endl;
					cout << "0. Thoat" << endl;
					cout << "Moi ban chon: ";
					cin >> chon;
					cout << "--------------" << endl;
					switch (chon)
					{
					case '1':
						cout << "Nhap ma mon moi: ";
						getline(cin, suaMaMon);
						MonDaiCuong[i].setMaMon(suaMaMon);
						cout << "Sua thanh cong." << endl;
						break;
					case '2':
						cout << "Nhap diem moi: ";
						cin >> suaDiem;
						MonDaiCuong[i].setDiem(suaDiem);
						cout << "Sua thanh cong." << endl;
						break;
					case '0':
						cout << "Thoat sua mon." << endl;
						break;
					default:
						cout << "Nhap sai. Vui long nhap lai" << endl;
						break;
					}
				} while (chon != '0');
				break;
			}
		}
	}
}

void SinhVienDaiCuong::XoaMonDaiCuong(){
	string maMon, suaMaMon;
	double suaDiem;
	cout << "Tim mon can xoa:" << endl;
	if (!TimKiemMonDaiCuong()){
		return;
	}
	else{
		cout << "Nhap ma mon can xoa: ";
		getline(cin, maMon);
		for (int i = 0; i < MonDaiCuong.size(); i++){
			if (MonDaiCuong[i].getMaMon() == maMon){
				HienThiMonDaiCuong(i);
				MonDaiCuong.erase(MonDaiCuong.begin() + i - 1);
			}
		}
	}
}

bool SinhVienDaiCuong::TimKiemMonDaiCuong(){
	string tim;
	bool flag = false;
	cout << "Nhap du lieu can tim: ";
	getline(cin, tim);
	for (int i = 0; i < MonDaiCuong.size(); i++){
		if (MonDaiCuong[i].getMaMon().find(tim,0) != -1){
			HienThiMonDaiCuong(i);
			flag = true;
		}
		else{
			if (MonDaiCuong[i].getTenMon().find(tim,0) != -1){
				HienThiMonDaiCuong(i);
				flag = true;
			}
			else{
				if (MonDaiCuong[i].getMaKhoa().find(tim,0) != -1){
					HienThiMonDaiCuong(i);
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

void SinhVienDaiCuong::HienThiMonDaiCuong(int vitri){
	cout << "Ma mon: " << MonDaiCuong[vitri].getMaMon() << endl;
	cout << "Ten mon: " << MonDaiCuong[vitri].getTenMon() << endl;
	cout << "Ma khoa: " << MonDaiCuong[vitri].getMaKhoa() << endl;
	cout << "So tin: " << MonDaiCuong[vitri].getSoTin() << endl;
	if (MonDaiCuong[vitri].getDiem() == -1){
		cout << "Chua co diem tong ket." << endl;
	}
	else{
		cout << "Diem: " << MonDaiCuong[vitri].getDiem() << endl;
	}
}

double SinhVienDaiCuong::DiemTrungBinh(){
	double tongDiem = 0;
	for (int i = 0; i < MonDaiCuong.size(); i++){
		if (MonDaiCuong[i].getDiem() != -1){
			tongDiem += MonDaiCuong[i].getDiem();
		}
	}
	return tongDiem/TongTin();
}

int SinhVienDaiCuong::TongTin(){
	int tongTin = 0;
	for (int i = 0; i < MonDaiCuong.size(); i++){
		if (MonDaiCuong[i].getDiem() != -1){
			tongTin += MonDaiCuong[i].getSoTin();
		}
	}
	return tongTin;
}

int SinhVienDaiCuong::TongTinCho(){
	int tongTinCho = 0;
	// Neu mon nao co diem = -1 thi cho thanh tin cho
	for (int i = 0; i < MonDaiCuong.size(); i++){
		if (MonDaiCuong[i].getDiem() == -1){
			tongTinCho += MonDaiCuong[i].getSoTin();
		}
	}
	return tongTinCho;
}

SinhVienDaiCuong::~SinhVienDaiCuong(){

}


// List SVDC

// doc file SVDC
ListSVDC::ListSVDC(){
	
}

// Them Sinh Vien
void ListSVDC::setList_SVDC(SinhVienDaiCuong SVDC){
	List_SVDC.push_back(SVDC);
}

vector<SinhVienDaiCuong> ListSVDC::getList_SVDC(){
	return List_SVDC;
}

void ListSVDC::ThemSinhVien(){
	cout << "Ban da chon them Sinh vien Dai cuong." << endl;
	string maSinhVien, tenSinhVien, ngaySinh, noiSinh, diaChi, soDienThoai, maKhoa;
	cout << "Moi ban them MSV: ";
	getline(cin, maSinhVien);
	cout << "Moi ban them ten: ";
	getline(cin, tenSinhVien);
	cout << "Moi ban them ngay sinh: ";
	getline(cin, ngaySinh);
	cout << "Moi ban them noi sinh: ";
	getline(cin, noiSinh);
	cout << "Moi ban them dia chi: ";
	getline(cin, diaChi);
	cout << "Moi ban them so dien thoai: ";
	getline(cin, soDienThoai);
	cout << "Moi ban them ma khoa: ";
	getline(cin, maKhoa);
	SinhVienDaiCuong SVDC(maSinhVien, tenSinhVien, ngaySinh, noiSinh, diaChi, soDienThoai, maKhoa);
	List_SVDC.push_back(SVDC);

	cout << "\nSinh vien da duoc them." << endl;
	cout << "-------------------" << endl;
}

// menu sua thong tin sv
void ListSVDC::SuaThongTinSinhVien(){
	string suaSinhVien, MSV;
	if (!TimKiemSinhVien()){
		return;
	}
	else{
		cout << "Nhap MSV can sua: ";
		getline(cin, MSV);
		for (int i = 0; i < List_SVDC.size(); i++){
			if (List_SVDC[i].getMaSinhVien() == MSV){
				HienThiSinhVien(i);
				char chon;
				do
				{
					cout << "Sua thong tin sinh vien: " << endl;
					cout << "1. Sua MSV." << endl;
					cout << "2. Sua ho ten." << endl;
					cout << "3. Sua ngay sinh." << endl;
					cout << "4. Sua noi sinh." << endl;
					cout << "5. Sua dia chi." << endl;
					cout << "6. Sua so dien thoai." << endl;
					cout << "7. Sua mon hoc." << endl;
					cout << "0. Thoat" << endl;
					cout << "Moi ban chon: ";
					cin >> chon;
					cout << "--------------" << endl;
					switch (chon)
					{
					case '1':
						cout << "Nhap MSV moi: ";
						getline(cin, suaSinhVien);
						List_SVDC[i].setMaSinhVien(suaSinhVien);
						cout << "Sua thanh cong." << endl;
						break;
					case '2':
						cout << "Nhap ho ten moi: ";
						getline(cin, suaSinhVien);
						List_SVDC[i].setTenSinhVien(suaSinhVien);
						cout << "Sua thanh cong." << endl;
						break;
					case '3':
						cout << "Nhap ngay sinh moi: ";
						getline(cin, suaSinhVien);
						List_SVDC[i].setNgaySinh(suaSinhVien);
						cout << "Sua thanh cong." << endl;
						break;
					case '4':
						cout << "Nhap noi sinh moi: ";
						getline(cin, suaSinhVien);
						List_SVDC[i].setNoiSinh(suaSinhVien);
						cout << "Sua thanh cong." << endl;
						break;
					case '5':
						cout << "Nhap dia chi moi: ";
						getline(cin, suaSinhVien);
						List_SVDC[i].setDiaChi(suaSinhVien);
						cout << "Sua thanh cong." << endl;
						break;
					case '6':
						cout << "Nhap so dien thoai moi: ";
						getline(cin, suaSinhVien);
						List_SVDC[i].setSoDienThoai(suaSinhVien);
						cout << "Sua thanh cong." << endl;
						break;
					case '7':
						List_SVDC[i].SuaMonDaiCuong();
						break;
					case '0':
						cout << "Cam on ban da su dung chuong trinh." << endl;
						break;
					default:
						cout << "Nhap sai. Vui long nhap lai" << endl;
						break;
					}
				} while (chon != '0');
				break;
			}
		}
	}
}

// menu xoa sv
void ListSVDC::XoaThongTinSinhVien(){
	string suaSinhVien, MSV;
	if (!TimKiemSinhVien()){
		return;
	}
	else{
		cout << "Nhap MSV cua sinh vien can xoa: ";
		getline(cin, MSV);
		for (int i = 0; i < List_SVDC.size(); i++){
			if (List_SVDC[i].getMaSinhVien() == MSV){
				HienThiSinhVien(i);
				List_SVDC.erase(List_SVDC.begin() + i - 1);
				break;
			}
		}
	}
}

// menu tim kiem sv
bool ListSVDC::TimKiemSinhVien(){
	string timSinhVien;
	bool flag = false;
	cout << "Tim sinh vien.\nNhap du lieu can tim: ";
	getline(cin, timSinhVien);
	for (int i = 0; i < List_SVDC.size(); i++){
		if (List_SVDC[i].getMaSinhVien().find(timSinhVien, 0) != -1){
			HienThiSinhVien(i);
			flag = true;
		}
		else{
			if (List_SVDC[i].getTenSinhVien().find(timSinhVien, 0) != -1){
				HienThiSinhVien(i);
				flag = true;
			}
			else{
				if (List_SVDC[i].getNgaySinh().find(timSinhVien, 0) != -1){
					HienThiSinhVien(i);
					flag = true;
				}
				else{
					if (List_SVDC[i].getNoiSinh().find(timSinhVien, 0) != -1){
						HienThiSinhVien(i);
						flag = true;
					}
					else{
						if (List_SVDC[i].getDiaChi().find(timSinhVien, 0) != -1){
							HienThiSinhVien(i);
							flag = true;
						}
						else{
							if (List_SVDC[i].getSoDienThoai().find(timSinhVien, 0) != -1){
								HienThiSinhVien(i);
								flag = true;
							}
						}
					}
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

// hien thi thong tin sv
void ListSVDC::HienThiSinhVien(int vitri){
	cout << "MSV: " << List_SVDC[vitri].getMaSinhVien() << endl;
	cout << "Ho ten: " << List_SVDC[vitri].getTenSinhVien() << endl;
	cout << "Ngay sinh: " << List_SVDC[vitri].getNgaySinh() << endl;
	cout << "Noi sinh: " << List_SVDC[vitri].getNoiSinh() << endl;
	cout << "Dia chi: " << List_SVDC[vitri].getDiaChi() << endl;
	cout << "So dien thoai: " << List_SVDC[vitri].getSoDienThoai() << endl;
	cout << "Ma khoa: ";
	for (int i = 0; i < List_SVDC[vitri].getMaKhoaDaHoc().size(); i++){
		cout << List_SVDC[vitri].getMaKhoaDaHoc()[i] << " ";
	}
	cout << endl;
}

void ListSVDC::InToanBoSinhVien(){
	for (int i = 0; i < List_SVDC.size(); i++){
		HienThiSinhVien(i);
	}
}

void ListSVDC::TopDiemTB_Khoa(){
	string maKhoa;
	cout << "Nhap ma khoa: ";
	getline(cin, maKhoa);
	double max = 0, min = 10;
	cout << "Sinh vien diem cao nhat.";
	for (int i = 0; i < List_SVDC.size(); i++){
		for (int j = 0; j < List_SVDC[i].getMaKhoaDaHoc().size(); j++){
			if (List_SVDC[i].getMaKhoaDaHoc()[j] == maKhoa){
				if (List_SVDC[i].DiemTrungBinh() > max){
					max = List_SVDC[i].DiemTrungBinh();
				}
				if (List_SVDC[i].DiemTrungBinh() < min){
					min = List_SVDC[i].DiemTrungBinh();
				}
			}
		}
	}
	for (int i = 0; i < List_SVDC.size(); i++){
		if (List_SVDC[i].DiemTrungBinh() == max){
			HienThiSinhVien(i);
		}
	}
	cout << "Sinh vien diem thap.";
	for (int i = 0; i < List_SVDC.size(); i++){
		if (List_SVDC[i].DiemTrungBinh() == min){
			HienThiSinhVien(i);
		}
	}
}

void ListSVDC::TopDiemTB_ToanTruong(){
	string maKhoa;
	cout << "Nhap chuyen nganh: ";
	getline(cin, maKhoa);
	double max = 0, min = 10;
	cout << "Sinh vien diem cao nhat.";
	for (int i = 0; i < List_SVDC.size(); i++){
		if (List_SVDC[i].DiemTrungBinh() > max){
			max = List_SVDC[i].DiemTrungBinh();
		}
		if (List_SVDC[i].DiemTrungBinh() < min){
			min = List_SVDC[i].DiemTrungBinh();
		}
	}
	for (int i = 0; i < List_SVDC.size(); i++){
		if (List_SVDC[i].DiemTrungBinh() == max){
			HienThiSinhVien(i);
		}
	}
	cout << "Sinh vien diem thap.";
	for (int i = 0; i < List_SVDC.size(); i++){
		if (List_SVDC[i].DiemTrungBinh() == min){
			HienThiSinhVien(i);
		}
	}
}

ListSVDC::~ListSVDC(){

}