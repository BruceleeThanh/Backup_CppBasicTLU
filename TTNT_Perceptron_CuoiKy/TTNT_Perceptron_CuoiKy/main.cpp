#include "HocSinh.h"
#include <time.h>
#include <math.h>
#include <fstream>

#define E (2.7182818284590452353602874713526624977572470937L ) // Đây là số e

ifstream fin;
vector<HocSinh> DSHocSinh; // Danh sách dữ liệu mẫu
vector<vector<double>> MaTranTrongSo; // Ma trận trọng số W (đối với số liệu hiện giờ thì ma trận này có độ lớn 5x2)
vector<double> TrongSo; // Lưu lại danh sách trọng số (đối với dữ liệu hiện giờ thì danh sách này có 5 phần tử), danh sách này về sau sẽ được đưa vào Ma trận trọng số W
vector<int> DSTrangThaiDauRa; // Danh sách trạng thái đầu ra (đối với dữ liệu hiện giờ thì danh sách này có 2 phần tử)
double bias;

void DocFile();
void NhapDauVao(vector<double> &dauVaoThucTe);
int TinhToanKetQua(vector<double> dauVao);
void XuLyPerceptron();
void SinhTrongSo(vector<double> &trongSo, int soLuong, double min, double max);
double TinhDauRaPerceptron(vector<double> trongSo, vector<double> dauVao, double bias);
double TinhLogSigmoid(double n);
int KiemTraDauRaPerceptron(double dauRaPerceptron, int dauRaHocSinh, int dauRaChapNhan);
void TangTrongSo(vector<double> &trongSo, vector<double> dauVao, double hangSoHoc);
void GiamTrongSo(vector<double> &trongSo, vector<double> dauVao, double hangSoHoc);
double SinhSoNgauNhien(double minimum, double maximum);

int main(){

	vector<double> dauVaoThucTe;
	int ketQua;

	DSTrangThaiDauRa.push_back(1);
	DSTrangThaiDauRa.push_back(2);

	// Mình học dữ liệu trước
	DocFile();
	XuLyPerceptron();

	// Sau đó mình cho người dùng nhập vào
	NhapDauVao(dauVaoThucTe);
	ketQua = TinhToanKetQua(dauVaoThucTe);
	cout << "-------------------------" << endl << "Ket qua la: ";
	if (DSTrangThaiDauRa[ketQua] == 1){
		cout << "Ban khong nen hoc nganh nay." << endl;
	}
	else{
		if (DSTrangThaiDauRa[ketQua] == 2){
			cout << "Ban nen hoc nganh nay." << endl;
		}
	}
}

void DocFile(){
	fin.open("SoLieu.txt");
	if (!fin.is_open()){
		cout << "Khong the mo duoc file." << endl;
	}
	else{
		vector<double> dauVao;
		double dauRa;
		while (!fin.eof()){
			dauVao.clear();
			double temp;
			fin >> temp;
			dauVao.push_back(temp);
			fin >> temp;
			dauVao.push_back(temp);
			fin >> temp;
			dauVao.push_back(temp);
			fin >> temp;
			dauVao.push_back(temp);
			fin >> temp;
			dauVao.push_back(temp);
			fin >> dauRa;
			HocSinh hocSinh = HocSinh(dauVao, dauRa);
			DSHocSinh.push_back(hocSinh);
		}
	}
	fin.close();
}

// Hàm dành cho người dùng nhập dữ liệu đầu vào
void NhapDauVao(vector<double> &dauVaoThucTe){
	double temp;
	cout << "------- CHUONG TRINH TU VAN CHON NGANH TOAN TIN --------" << endl;
	cout << "Moi ban nhap vao theo cac yeu cau khao sat sau day." << endl;
	cout << "---------------------------------------------------" << endl;
	cout << "1 - Tu duy logic cua ban o muc nao?" << endl << "1(Khong co logic) 2(Binh thuong) 3(Co logic): ";
	cin >> temp;
	dauVaoThucTe.push_back(temp);
	cout << "2 - Ban co thich mon tin hoc khong?" << endl << "1(Khong thich) 2(Binh thuong) 3(Thich) 4(Rat thich): ";
	cin >> temp;
	dauVaoThucTe.push_back(temp);
	cout << "3 - Ban da tung tham gia cuoc thi nao ve tin hoc chua?" << endl << "1(Chua tung tham gia) 2(Da tung tham gia): ";
	cin >> temp;
	dauVaoThucTe.push_back(temp);
	cout << "4 - Ban da tung lap trinh chua?" << endl << "1(Chua tung lap trinh) 2(Lap trinh don gian) 3(Lap trinh gioi): ";
	cin >> temp;
	dauVaoThucTe.push_back(temp);
	cout << "5 - Trinh do tieng Anh cua ban o muc nao?" << endl << "1(Kem) 2(Kha) 3(Tot) 4(Gioi): ";
	cin >> temp;
	dauVaoThucTe.push_back(temp);
}

// Hàm tính toán kết quả người dùng nhập vào
int TinhToanKetQua(vector<double> dauVao){
	double max = -1000000;
	int ketQua;
	for (int i = 0; i < MaTranTrongSo.size(); i++){
		double temp = TinhDauRaPerceptron(MaTranTrongSo[i], dauVao, bias);
		if (temp >= max){
			max = temp;
			ketQua = i;
		}
	}
	return ketQua;
}

// Xử lý Perceptron - Đây là Hàm quan trọng nhất
void XuLyPerceptron() {
	int soLuongTrongSo = DSHocSinh[0].getDauVao().size();
	//bias = -(SinhSoNgauNhien(0.0, 3.0));
	bias = -2; // bias mặc định mình nên đặt là = -2
	double hangSoHoc = 0.01; // đây là hằng số học (ý nghĩa của nó là để cho việc học dễ dàng hơn)
	for (int i = 0; i < DSTrangThaiDauRa.size(); i++) { // đối với mỗi một đầu ra, mình sẽ tính ra một danh sách trọng số ứng vs đầu ra ấy
		TrongSo.clear();
		SinhTrongSo(TrongSo, soLuongTrongSo, -2.5, 2.5); // trước khi tính thì mình phải random để danh sách trọng số có giá trị
		while (true) {
			bool saiSo = false; // biến Sai số này để kiểm tra xem còn bản ghi dữ liệu mẫu nào chưa thoả mãn danh sách trọng số hay không
			for (int j = 0; j < DSHocSinh.size(); j++) { // Chúng ta sẽ thử danh sách trọng số lần lượt với từng bản ghi dữ liệu mẫu
				double dauRaPerceptron = TinhDauRaPerceptron(TrongSo, DSHocSinh[j].getDauVao(), bias); // đây là kết quả phép tính: a = LogSigmoid( W.P + bias ) (LogSigmoid là một trong những hàm kích hoạt, kiểu như Hardlimd ấy)
				int check = KiemTraDauRaPerceptron(dauRaPerceptron, (int)DSHocSinh[j].getDauRa(), DSTrangThaiDauRa[i]); // Kiểm tra xem cái kết quả mình vừa tính được đã thoả mãn chưa
				if (check == 1) { // trường hợp sai thứ nhất: ta cần phải tăng các trọng số trong danh sách trọng số 
					TangTrongSo(TrongSo, DSHocSinh[j].getDauVao(), hangSoHoc);
					saiSo = true;
				}
				else {
					if (check == 2) { // trường hợp sai thứ hai: ta cần phải giảm các trọng số trong danh sách trọng số 
						GiamTrongSo(TrongSo, DSHocSinh[j].getDauVao(), hangSoHoc);
						saiSo = true;
					}
				}
			}
			if (!saiSo) { // đến khi không còn sai số (danh sách trọng số đã thoả mãn hết các bản ghi dữ liệu mẫu)
				MaTranTrongSo.push_back(TrongSo); // mình sẽ add danh sách trọng số vào Ma trận trọng số
				break; // mình thoát để duyệt tiếp với các đầu ra tiếp theo
			}
		}
	}
}

// Hàm sinh trọng số - sinh ngẫu nhiên ra một danh sách trọng số
void SinhTrongSo(vector<double> &trongSo, int soLuong, double min, double max) {
	for (int i = 0; i < soLuong; i++) {
		trongSo.push_back(SinhSoNgauNhien(min, max));
	}
}

// Hàm tính đầu ra của mạng - công thức là: a = LogSigmoid( W.P + bias )
double TinhDauRaPerceptron(vector<double> trongSo, vector<double> dauVao, double bias) {
	double x = 0;
	for (int i = 0; i < dauVao.size(); i++) {
		x += (trongSo[i] * dauVao[i]);
	}
	x += bias;
	return TinhLogSigmoid(x);
}

// Hàm tính dựa vào công thức LogSigmoid = 1/(1 + e^-n)
double TinhLogSigmoid(double n) {
	return (1.0 / (1.0 + pow(E, -n)));
}

// Hàm kiểm tra kết quả đầu ra của mạng
int KiemTraDauRaPerceptron(double dauRaPerceptron, int dauRaHocSinh, int dauRaChapNhan) {
	if (dauRaPerceptron <= 0.5 && dauRaHocSinh == dauRaChapNhan) {
		return 1;
	}
	else {
		if (dauRaPerceptron > 0.5 && dauRaHocSinh != dauRaChapNhan) {
			return 2;
		}
	}
	return 0;
}

// Hàm tăng W (trọng số). W(new) = W(old) + P * alpha (alpha là hằng số học)
void TangTrongSo(vector<double> &trongSo, vector<double> dauVao, double hangSoHoc) {
	for (int i = 0; i < dauVao.size(); i++) {
		trongSo[i] += (dauVao[i] * hangSoHoc);
	}
}

// Hàm giảm W (trọng số). W(new) = W(old) - P * alpha (alpha là hằng số học)
void GiamTrongSo(vector<double> &trongSo, vector<double> dauVao, double hangSoHoc) {
	for (int i = 0; i < dauVao.size(); i++) {
		trongSo[i] -= (dauVao[i] * hangSoHoc);
	}
}

// Random ra một số thực nằm trong khoảng từ minimum đến maximum
double SinhSoNgauNhien(double minimum, double maximum) {
	const long max_rand = 1000000L;
	double f = (double)rand() / RAND_MAX;
	return minimum + f * (maximum - minimum);
}
