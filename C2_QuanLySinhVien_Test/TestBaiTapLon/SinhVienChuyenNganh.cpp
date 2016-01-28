#include"SinhVienChuyenNganh.h"

SinhVienChuyenNganh::SinhVienChuyenNganh()
{

}

SinhVienChuyenNganh::SinhVienChuyenNganh(string maSinhVien, string tenSinhVien, string ngaySinh, string noiSinh, string diaChi, string soDienThoai, string maKhoa, string tenChuyenNganh) : SinhVienDaiCuong(maSinhVien, tenSinhVien, ngaySinh, noiSinh, diaChi, soDienThoai, maKhoa)
{
	TenChuyenNganh.push_back(tenChuyenNganh);
}

void SinhVienChuyenNganh::setTenChuyenNganh(string tenChuyenNganh){
	TenChuyenNganh.push_back(tenChuyenNganh);
}

void SinhVienChuyenNganh::setDiemKhoaLuanTN(double diemKhoaLuan){
	DiemKhoaLuanTN = diemKhoaLuan;
}

vector<string> SinhVienChuyenNganh::getTenChuyenNganh(){
	return TenChuyenNganh;
}

double SinhVienChuyenNganh::getDiemKhoaLuanTN(){
	return DiemKhoaLuanTN;
}

vector<Mon> SinhVienChuyenNganh::getMonChuyenNganh(){
	return MonChuyenNganh;
}

void SinhVienChuyenNganh::ThemChuyenNganh(){
	string chuyenNganh;
	cout << "Nhap chuyen nganh can them: ";
	getline(cin, chuyenNganh);
	setTenChuyenNganh(chuyenNganh);
}

void SinhVienChuyenNganh::SuaChuyenNganh(){
	string tenChuyenNganh, suaChuyenNganh;
	cout << "Tim chuyen nganh can sua:" << endl;
	if (!TimKiemMonChuyenNganh()){
		return;
	}
	else{
		cout << "Nhap chuyen nganh can sua: ";
		getline(cin, tenChuyenNganh);
		for (int i = 0; i < TenChuyenNganh.size(); i++){
			if (TenChuyenNganh[i] == tenChuyenNganh){
				HienThiChuyenNganh(i);
				cout << "Nhap chuyen nganh moi: ";
				getline(cin, suaChuyenNganh);
				TenChuyenNganh[i] = suaChuyenNganh;
				break;
			}
		}
	}
}

bool SinhVienChuyenNganh::TimKiemChuyenNganh(){
	string timChuyenNganh;
	bool flag = false;
	cout << "Nhap ten chuyen nganh can tim: ";
	getline(cin,timChuyenNganh);
	for (int i = 0; i < TenChuyenNganh.size(); i++){
		if (TenChuyenNganh[i].find(timChuyenNganh, 0) != -1){
			HienThiChuyenNganh(i);
			flag = true;
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

void SinhVienChuyenNganh::HienThiChuyenNganh(int vitri){
	cout << "Ten chuyen nganh: " << TenChuyenNganh[vitri] << endl;
}

void SinhVienChuyenNganh::ThemMonChuyenNganh(){
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
	MonChuyenNganh.push_back(temp);
}

void SinhVienChuyenNganh::SuaMonChuyenNganh(){
	string maMon, suaMaMon;
	double suaDiem;
	cout << "Tim mon can sua:" << endl;
	if (!TimKiemMonChuyenNganh()){
		return;
	}
	else{
		cout << "Nhap ma mon can sua: ";
		getline(cin, maMon);
		for (int i = 0; i < MonChuyenNganh.size(); i++){
			if (MonChuyenNganh[i].getMaMon() == maMon){
				HienThiMonChuyenNganh(i);
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
						MonChuyenNganh[i].setMaMon(suaMaMon);
						cout << "Sua thanh cong." << endl;
						break;
					case '2':
						cout << "Nhap diem moi: ";
						cin >> suaDiem;
						MonChuyenNganh[i].setDiem(suaDiem);
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

void SinhVienChuyenNganh::XoaMonChuyenNganh(){
	string maMon, suaMaMon;
	double suaDiem;
	cout << "Tim mon can xoa:" << endl;
	if (!TimKiemMonChuyenNganh()){
		return;
	}
	else{
		cout << "Nhap ma mon can xoa: ";
		getline(cin, maMon);
		for (int i = 0; i < MonChuyenNganh.size(); i++){
			if (MonChuyenNganh[i].getMaMon() == maMon){
				HienThiMonChuyenNganh(i);
				MonChuyenNganh.erase(MonChuyenNganh.begin() + i - 1);
			}
		}
	}
}

bool SinhVienChuyenNganh::TimKiemMonChuyenNganh(){
	string tim;
	bool flag = false;
	cout << "Nhap du lieu can tim: ";
	getline(cin, tim);
	for (int i = 0; i < MonChuyenNganh.size(); i++){
		if (MonChuyenNganh[i].getMaMon().find(tim, 0) != -1){
			HienThiMonChuyenNganh(i);
			flag = true;
		}
		else{
			if (MonChuyenNganh[i].getTenMon().find(tim, 0) != -1){
				HienThiMonChuyenNganh(i);
				flag = true;
			}
			else{
				if (MonChuyenNganh[i].getMaKhoa().find(tim, 0) != -1){
					HienThiMonChuyenNganh(i);
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

void SinhVienChuyenNganh::HienThiMonChuyenNganh(int vitri){
	cout << "Ma mon: " << MonChuyenNganh[vitri].getMaMon() << endl;
	cout << "Ten mon: " << MonChuyenNganh[vitri].getTenMon() << endl;
	cout << "Ma khoa: " << MonChuyenNganh[vitri].getMaKhoa() << endl;
	cout << "So tin: " << MonChuyenNganh[vitri].getSoTin() << endl;
	if (MonChuyenNganh[vitri].getDiem() == -1){
		cout << "Chua co diem tong ket." << endl;
	}
	else{
		cout << "Diem: " << MonChuyenNganh[vitri].getDiem() << endl;
	}
}

void SinhVienChuyenNganh::ThemDiemKhoaLuanTN(){
	double diemKhoaLuan;
	cout << "Nhap diem khoa luan tot nghiep: ";
	cin >> diemKhoaLuan;
	setDiemKhoaLuanTN(diemKhoaLuan);
}

void SinhVienChuyenNganh::SuaDiemKhoaLuanTN(){
	double diemKhoaLuan;
	cout << "Nhap diem khoa luan tot nghiep moi: ";
	cin >> diemKhoaLuan;
	setDiemKhoaLuanTN(diemKhoaLuan);
}

double SinhVienChuyenNganh::DiemTrungBinh(){
	double tongDiem = 0;
	for (int i = 0; i < MonChuyenNganh.size(); i++){
		if (MonChuyenNganh[i].getDiem() != -1){
			tongDiem += MonChuyenNganh[i].getDiem();
		}
	}
	return tongDiem / TongTin();
}

int SinhVienChuyenNganh::TongTin(){
	int tongTin = 0;
	for (int i = 0; i < MonChuyenNganh.size(); i++){
		if (MonChuyenNganh[i].getDiem() != -1){
			tongTin += MonChuyenNganh[i].getSoTin();
		}
	}
	return tongTin;
}

int SinhVienChuyenNganh::TongTinCho(){
	int tongTinCho = 0;
	// Neu mon nao co diem = -1 thi cho thanh tin cho
	for (int i = 0; i < MonChuyenNganh.size(); i++){
		if (MonChuyenNganh[i].getDiem() == -1){
			tongTinCho += MonChuyenNganh[i].getSoTin();
		}
	}
	return tongTinCho;
}

//khoa

void SinhVienChuyenNganh::ThemKhoa(){
	string maKhoa;
	cout << "Nhap ma khoa can them.";
	getline(cin, maKhoa);
	setMaKhoaDaHoc(maKhoa);
}

void SinhVienChuyenNganh::SuaKhoa(){
	string maKhoa, suaKhoa;
	cout << "Tim khoa can sua:" << endl;
	if (!TimKiemKhoa()){
		return;
	}
	else{
		cout << "Nhap ma khoa can sua: ";
		getline(cin, maKhoa);
		for (int i = 0; i < MaKhoaDaHoc.size(); i++){
			if (MaKhoaDaHoc[i] == maKhoa){
				HienThiKhoa(i);
				cout << "Nhap ma khoa moi: ";
				getline(cin, suaKhoa);
				MaKhoaDaHoc[i] = suaKhoa;
				break;
			}
		}
	}
}

bool SinhVienChuyenNganh::TimKiemKhoa(){
	string timKhoa;
	bool flag = false;
	cout << "Nhap ma khoa can tim: ";
	getline(cin, timKhoa);
	for (int i = 0; i < MaKhoaDaHoc.size(); i++){
		if (MaKhoaDaHoc[i].find(timKhoa, 0) != -1){
			HienThiKhoa(i);
			flag = true;
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

void SinhVienChuyenNganh::HienThiKhoa(int vitri){
	cout << "Ma khoa: " << MaKhoaDaHoc[vitri];
}

SinhVienChuyenNganh::~SinhVienChuyenNganh(){

}

// List SVCN

ListSVCN::ListSVCN(){

}

// Them Sinh Vien
void ListSVCN::setList_SVCN(SinhVienChuyenNganh SVCN){
	List_SVCN.push_back(SVCN);
} 

vector<SinhVienChuyenNganh> ListSVCN::getList_SVCN(){
	return List_SVCN;
}

void ListSVCN::ThemSinhVien(){
	cout << "Ban da chon them Sinh vien Chuyen Nganh." << endl;
	string maSinhVien, tenSinhVien, ngaySinh, noiSinh, diaChi, soDienThoai, maKhoa, tenChuyenNganh;
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
	cout << "Moi ban them chuyen nganh: ";
	getline(cin, tenChuyenNganh);
	SinhVienChuyenNganh SVCN(maSinhVien, tenSinhVien, ngaySinh, noiSinh, diaChi, soDienThoai, maKhoa, tenChuyenNganh);
	List_SVCN.push_back(SVCN);
	cout << "\nSinh vien da duoc them." << endl;
	cout << "-------------------" << endl;
}

void ListSVCN::SuaThongTinSinhVien(){
	string suaSinhVien, MSV;
	if (!TimKiemSinhVien()){
		return;
	}
	else{
		cout << "Nhap MSV can sua: ";
		getline(cin, MSV);
		for (int i = 0; i < List_SVCN.size(); i++){
			if (List_SVCN[i].getMaSinhVien() == MSV){
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
					cout << "8. Sua ten chuyen nganh." << endl;
					cout << "9. Sua diem khoa luan tot nghiep." << endl;
					cout << "0. Thoat" << endl;
					cout << "Moi ban chon: ";
					cin >> chon;
					cout << "--------------" << endl;
					switch (chon)
					{
					case '1':
						cout << "Nhap MSV moi: ";
						getline(cin, suaSinhVien);
						List_SVCN[i].setMaSinhVien(suaSinhVien);
						cout << "Sua thanh cong." << endl;
						break;
					case '2':
						cout << "Nhap ho ten moi: ";
						getline(cin, suaSinhVien);
						List_SVCN[i].setTenSinhVien(suaSinhVien);
						cout << "Sua thanh cong." << endl;
						break;
					case '3':
						cout << "Nhap ngay sinh moi: ";
						getline(cin, suaSinhVien);
						List_SVCN[i].setNgaySinh(suaSinhVien);
						cout << "Sua thanh cong." << endl;
						break;
					case '4':
						cout << "Nhap noi sinh moi: ";
						getline(cin, suaSinhVien);
						List_SVCN[i].setNoiSinh(suaSinhVien);
						cout << "Sua thanh cong." << endl;
						break;
					case '5':
						cout << "Nhap dia chi moi: ";
						getline(cin, suaSinhVien);
						List_SVCN[i].setDiaChi(suaSinhVien);
						cout << "Sua thanh cong." << endl;
						break;
					case '6':
						cout << "Nhap so dien thoai moi: ";
						getline(cin, suaSinhVien);
						List_SVCN[i].setSoDienThoai(suaSinhVien);
						cout << "Sua thanh cong." << endl;
						break;
					case '7':
						List_SVCN[i].SuaMonChuyenNganh();
						break;
					case '8':
						cout << "Nhap ten chuyen nganh moi: ";
						getline(cin, suaSinhVien);
						List_SVCN[i].setTenChuyenNganh(suaSinhVien);
						cout << "Sua thanh cong." << endl;
						break;
					case '9':
						if (List_SVCN[i].getDiemKhoaLuanTN() == -1){
							cout << "Chua co diem khoa luan tot nghiep." << endl;
							List_SVCN[i].ThemDiemKhoaLuanTN();
						}
						else{
							List_SVCN[i].SuaDiemKhoaLuanTN();
						}
						cout << "Sua thanh cong." << endl;
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

void ListSVCN::XoaThongTinSinhVien(){
	string suaSinhVien, MSV;
	if (!TimKiemSinhVien()){
		return;
	}
	else{
		cout << "Nhap MSV cua sinh vien can xoa: ";
		getline(cin, MSV);
		for (int i = 0; i < List_SVCN.size(); i++){
			if (List_SVCN[i].getMaSinhVien() == MSV){
				HienThiSinhVien(i);
				List_SVCN.erase(List_SVCN.begin() + i - 1);
				break;
			}
		}
	}
}

bool ListSVCN::TimKiemSinhVien(){
	string timSinhVien;
	bool flag = false;
	cout << "Tim sinh vien.\nNhap du lieu can tim: ";
	getline(cin, timSinhVien);
	for (int i = 0; i < List_SVCN.size(); i++){
		if (List_SVCN[i].getMaSinhVien().find(timSinhVien, 0) != -1){
			HienThiSinhVien(i);
			flag = true;
		}
		else{
			if (List_SVCN[i].getTenSinhVien().find(timSinhVien, 0) != -1){
				HienThiSinhVien(i);
				flag = true;
			}
			else{
				if (List_SVCN[i].getNgaySinh().find(timSinhVien, 0) != -1){
					HienThiSinhVien(i);
					flag = true;
				}
				else{
					if (List_SVCN[i].getNoiSinh().find(timSinhVien, 0) != -1){
						HienThiSinhVien(i);
						flag = true;
					}
					else{
						if (List_SVCN[i].getDiaChi().find(timSinhVien, 0) != -1){
							HienThiSinhVien(i);
							flag = true;
						}
						else{
							if (List_SVCN[i].getSoDienThoai().find(timSinhVien, 0) != -1){
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

void ListSVCN::HienThiSinhVien(int vitri){
	cout << "MSV: " << List_SVCN[vitri].getMaSinhVien() << endl;
	cout << "Ho ten: " << List_SVCN[vitri].getTenSinhVien() << endl;
	cout << "Ngay sinh: " << List_SVCN[vitri].getNgaySinh() << endl;
	cout << "Noi sinh: " << List_SVCN[vitri].getNoiSinh() << endl;
	cout << "Dia chi: " << List_SVCN[vitri].getDiaChi() << endl;
	cout << "So dien thoai: " << List_SVCN[vitri].getSoDienThoai() << endl;
	for (int i = 0; i < List_SVCN[vitri].getTenChuyenNganh().size(); i++){
		cout << "Ten chuyen nganh: " << List_SVCN[vitri].getTenChuyenNganh()[i] << endl;
	}
	
}

void ListSVCN::InToanBoSinhVien(){
	for (int i = 0; i < List_SVCN.size(); i++){
		HienThiSinhVien(i);
	}
}

void ListSVCN::TopDiemTB_Khoa(){
	string maKhoa;
	cout << "Nhap ma khoa: ";
	getline(cin, maKhoa);
	double max = 0, min = 10;
	cout << "Sinh vien diem cao nhat.";
	for (int i = 0; i < List_SVCN.size(); i++){
		for (int j = 0; j < List_SVCN[i].getMaKhoaDaHoc().size(); j++){
			if (List_SVCN[i].getMaKhoaDaHoc()[j] == maKhoa){
				if (List_SVCN[i].DiemTrungBinh() > max){
					max = List_SVCN[i].DiemTrungBinh();
				}
				if (List_SVCN[i].DiemTrungBinh() < min){
					min = List_SVCN[i].DiemTrungBinh();
				}
			}
		}
	}
	for (int i = 0; i < List_SVCN.size(); i++){
		if (List_SVCN[i].DiemTrungBinh() == max){
			HienThiSinhVien(i);
		}
	}
	cout << "Sinh vien diem thap.";
	for (int i = 0; i < List_SVCN.size(); i++){
		if (List_SVCN[i].DiemTrungBinh() == min){
			HienThiSinhVien(i);
		}
	}
}

void ListSVCN::TopDiemTB_ChuyenNganh(){
	string maKhoa;
	cout << "Nhap chuyen nganh: ";
	getline(cin, maKhoa);
	double max = 0, min = 10;
	cout << "Sinh vien diem cao nhat.";
	for (int i = 0; i < List_SVCN.size(); i++){
		for (int j = 0; j < List_SVCN[i].getTenChuyenNganh().size(); j++){
			if (List_SVCN[i].getTenChuyenNganh()[j] == maKhoa){
				if (List_SVCN[i].DiemTrungBinh() > max){
					max = List_SVCN[i].DiemTrungBinh();
				}
				if (List_SVCN[i].DiemTrungBinh() < min){
					min = List_SVCN[i].DiemTrungBinh();
				}
			}
		}
	}
	for (int i = 0; i < List_SVCN.size(); i++){
		if (List_SVCN[i].DiemTrungBinh() == max){
			HienThiSinhVien(i);
		}
	}
	cout << "Sinh vien diem thap.";
	for (int i = 0; i < List_SVCN.size(); i++){
		if (List_SVCN[i].DiemTrungBinh() == min){
			HienThiSinhVien(i);
		}
	}
}

void ListSVCN::TopDiemTB_ToanTruong(){
	string maKhoa;
	cout << "Nhap chuyen nganh: ";
	getline(cin, maKhoa);
	double max = 0, min = 10;
	cout << "Sinh vien diem cao nhat.";
	for (int i = 0; i < List_SVCN.size(); i++){
		if (List_SVCN[i].DiemTrungBinh() > max){
			max = List_SVCN[i].DiemTrungBinh();
		}
		if (List_SVCN[i].DiemTrungBinh() < min){
			min = List_SVCN[i].DiemTrungBinh();
		}
	}
	for (int i = 0; i < List_SVCN.size(); i++){
		if (List_SVCN[i].DiemTrungBinh() == max){
			HienThiSinhVien(i);
		}
	}
	cout << "Sinh vien diem thap.";
	for (int i = 0; i < List_SVCN.size(); i++){
		if (List_SVCN[i].DiemTrungBinh() == min){
			HienThiSinhVien(i);
		}
	}
}


ListSVCN::~ListSVCN(){

}