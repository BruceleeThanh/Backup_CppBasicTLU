#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
using namespace std;



void readFile(string filename, string &f, string &x);
string findClosure(string f, string x);
bool checkBelongs(string s, string z);
string findMoreAttributes(string s, string y);
bool checkMoreAttributes(string s, string y);
void convertFromStringToFD(string input, string &z, string &y);
string findKey(string f, string x);
void getObject(string &s, string &a, int pos);
void setObject(string &s, string &a, int pos);
string splitFDInString(string f, int pos);
string findFc(string f);
string splitAttributesInRightSideOfFD(string f);
string removeRedundantFD(string f);
string removeAttributesInLeftSideOfFD(string f);
void removeDuplicateOfFD(string &f);

int main(){
	string f;
	string x;
	string xplus;
	string r;
	string key;
	string filename;
	string fc;
	/*filename = "input.txt";
	readFile(filename, f, x);
	cout << "Tim bao dong: " << endl;
	xplus = findClosure(f, x);
	cout << "Bao dong la: " << xplus << endl;*/

	/*filename = "input1.txt";
	readFile(filename, f, r);
	key = findKey(f, r);
	cout << "Khoa la: " << key << endl;*/
	
	filename = "input2.txt";
	readFile(filename, f, x);
	fc = findFc(f);
	//cout << "Phu cuc tieu la: " << fc << endl;

	//string test = "A->B\nAB->C\n";
	/*cout << removeAttributesInLeftSideOfFD(f);*/
	

	return 0;
}

// Doc file input
void readFile(string filename, string &f, string &x){
	string temp;
	ifstream fin(filename);
	if (!fin.is_open()){
		cout << "Can't open file." << endl;
	}
	else{
		fin >> x;
		while (!fin.eof()){
			fin >> temp;
			f = f + temp + "\n";
		}
	}
	fin.close();
}

// TIM BAO DONG CUA TAP THUOC TINH --------------------------------

// Tim bao dong.
string findClosure(string f, string x){
	string s, z, y;
	bool flag = true;
	s = x;
	// Hien thi:
	cout << x << endl;
	// --------
	while (flag){
		int pos = 0;
		flag = false;
		while(pos < f.length()){
			string temp = splitFDInString(f, pos);
			pos = pos + temp.length() + 1;
			convertFromStringToFD(temp, z, y);
			if (checkBelongs(s, z)){
				if (checkMoreAttributes(s, y)){
					s += findMoreAttributes(s, y);
					flag = true;
					// Hien thi:
					cout << temp << " : " << s << endl;
					// --------
				}
			}
		}
	}
	
	return s;
}

// Kiem tra xau z co thuoc s hay ko?
bool checkBelongs(string s, string z){
	int count = 0;
	for (int i = 0; i < z.length(); i++){
		for (int j = 0; j < s.length(); j++){
			if ((int)z[i] == (int)s[j]){
				count++;
			}
		}
	}
	if (count == z.length()){
		return true;
	}
	else{
		return false;
	}
}

// Tim thuoc tinh chua xuat hien trong tap thuoc tinh bao dong
string findMoreAttributes(string s, string y){
	string temp;
	for (int i = 0; i < y.length(); i++){
		bool check_existed = false;
		for (int j = 0; j < s.length(); j++){
			if ((int)y[i] == (int)s[j]){
				check_existed = true;
			}
		}
		if (!check_existed){
			temp += y[i];
		}
	}

	return temp;
}

// Kiem tra thuoc tinh chua xuat hien trong tap thuoc tinh bao dong
bool checkMoreAttributes(string s, string y){
	bool check_more = false;
	for (int i = 0; i < y.length(); i++){
		bool check_existed = false;
		for (int j = 0; j < s.length(); j++){
			if ((int)y[i] == (int)s[j]){
				check_existed = true;
			}
		}
		if (!check_existed){
			check_more = true;
		}
	}
	return check_more;
}

// Chuyen doi tu Xau input sang Phu Thuoc Ham (FD = Functional Dependencies)
void convertFromStringToFD(string input, string &z, string &y){
	string z_temp, y_temp;
	bool move = false;
	for (int i = 0; i < input.length(); i++){
		if ((int)input[i] >= 65 && (int)input[i] <= 90 && !move){
			z_temp += input[i];
		}
		else{
			move = true;
			if ((int)input[i] >= 65 && (int)input[i] <= 90 && move){
				y_temp += input[i];
			}
		}
	}
	z = z_temp;
	y = y_temp;
}

//----------------------------------------------------------------


// TIM KHOA TRONG MOT TAP THUOC TINH -----------------------------

// Tim khoa tu mot tap thuoc tinh va tap quan he
string findKey(string f, string r){
	string s, a, temp;
	int length;
	bool flag = true;
	s = r;
	while (flag){
		flag = false;
		length = s.length();
		for (int i = length - 1; i >= 0; i--){
			getObject(s, a, i);
			temp = findClosure(f, s);
			// Hien thi:
			cout << "Kiem tra " << a << ": (" << s << ")+ = " << temp << "   -> ";
			// --------
			if (!checkBelongs(temp, r)){
				setObject(s, a, i);
				// Hien thi:
				cout << "khong loai " << a << endl;
				// --------
			}
			else{
				flag = true;
				// Hien thi:
				cout << "loai " << a << endl;
				// --------
			}
		}
	}
	
	return s;
}

// Lay ra 1 thuoc tinh tai 1 vi tri va xoa thuoc tinh ay trong xau
void getObject(string &s, string &a, int pos){
	a = s[pos];
	s.erase(pos, 1);
}

// Chen them 1 thuoc tinh tai 1 vi tri vao xau
void setObject(string &s, string &a, int pos){
	s.insert(pos, a);
}

// Tach cac FD trong xau
string splitFDInString(string f, int pos){
	string result;
	for (int i = pos; i < f.length(); i++){
		if ((int)f[i] == 10){
			break;
		}
		else{
			result += f[i];
		}
	}
	return result;
}

//----------------------------------------------------------------


// TIM PHU CUC TIEU ----------------------------------------------

// Tim Phu Cuc Tieu
string findFc(string f){
	string fc;
	fc = splitAttributesInRightSideOfFD(f);
	// Hien thi:
	cout << "Buoc 1:\n" << fc << endl;
	// --------
	fc = removeRedundantFD(fc);
	// Hien thi:
	cout << "Buoc 2:\n" << fc << endl;
	// --------
	fc = removeAttributesInLeftSideOfFD(fc);
	// Hien thi:
	cout << "Buoc 3:\n" << fc << endl;
	// --------
	return fc;
}

// Tach nho cac FD co ve phai > 1 thanh = 1 (Buoc 1)
string splitAttributesInRightSideOfFD(string f){
	string result, z, y;
	int pos = 0;
	while (pos < f.length()){
		string temp = splitFDInString(f, pos);
		pos = pos + temp.length() + 1;
		convertFromStringToFD(temp, z, y);
		for (int i = 0; i < y.length(); i++){
			result = result + z + "->" + y[i] + "\n";
		}
	}
	removeDuplicateOfFD(result);
	return result;
}

// Loai bo cac FD du thua (Buoc 2)
string removeRedundantFD(string f){
	string result = f, f_temp;
	string z, y;
	int pos = 0;
	while (pos < f.length()){
		f_temp = result;
		string sub_temp = splitFDInString(f, pos);
		pos = pos + sub_temp.length() + 1;
		convertFromStringToFD(sub_temp, z, y);
		f_temp.erase(f_temp.find(sub_temp), sub_temp.length() + 1);
		if (checkBelongs(findClosure(f_temp, z), y)){
			// FD nay du thua can phai loai bo
			result = f_temp;
		}
	}
	return result;
}

// Loai bo cac thuoc tinh du thua o ve phai cua FD (Buoc 3)
string removeAttributesInLeftSideOfFD(string f){
	string result = f, f_temp;
	string z, y;
	int pos = 0;
	while (pos < f.length()){
		string sub_temp = splitFDInString(f, pos);
		pos = pos + sub_temp.length() + 1;
		f_temp = result;
		if (sub_temp.length() > 4){
			string attributes_temp;
			int pos_sub_temp = f_temp.find(sub_temp);
			convertFromStringToFD(sub_temp, z, y);
			f_temp.erase(pos_sub_temp, sub_temp.length() + 1);
			for (int i = 0; i < z.length(); i++){
				string z_temp = z;
				z_temp.erase(i, 1);
				if (!checkBelongs(findClosure(f_temp, z_temp), y)){
					attributes_temp += z[i];
				}
			}
			attributes_temp = attributes_temp + "->" + y + "\n";
			f_temp.insert(pos_sub_temp, attributes_temp);
			result = f_temp;
		}
	}
	return result;
}

// Loai bo cac FD trung lap
void removeDuplicateOfFD(string &f){
	int pos = 0, sub_pos = 0;
	while (pos < f.length()){
		string sub_temp = splitFDInString(f, pos);
		pos = pos + sub_temp.length() + 1;
		sub_pos = pos;
		while (sub_pos < f.length()){
			string dup_sub_temp = splitFDInString(f, sub_pos);
			if (sub_temp == dup_sub_temp){
				f.erase(sub_pos, sub_temp.length() + 1);
			}
			else{
				sub_pos = sub_pos + dup_sub_temp.length() + 1;
			}
		}
	}
}

//----------------------------------------------------------------

// Kiem tra noi khong mat-----------------------------------------

string checkLossLessJoin(string f, string r, string decay){
	string lossless[100][100];
	string temp;
	int amount_row = 0, amount_col = 0;
	for (int i = 0; i < r.length(); i++){
		lossless[0][amount_col++] = r[i];
	}
	for (int i = 0; i < decay.length(); i++){
		if ((int)decay[i] == 10){
			lossless[amount_row++][0] = temp;
			temp = "";
			break;
		}
		else{
			temp += decay[i];
		}
	}
	for (int i = 1; i < amount_row; i++){
		for (int j = 1; j < amount_col; j++){
			if (checkBelongs(lossless[i - 1][0], lossless[0][j - 1])){
				lossless[i][j] = "a" + (char)(j + 48);
			}
			else{
				lossless[i][j] = "b" + (char)()
			}
		}
	}
}

// Dem so phan ra
int countDecays(string decay){
	int count = 0;
	for (int i = 0; i < decay.length(); i++){
		if ((int)decay[i] == 10){
			count++;
		}
	}
	return count;
}

// Dem so FD
int countFD(string f){
	int count = 0;
	for (int i = 0; i < f.length(); i++){
		if ((int)f[i] == 10){
			count++;
		}
	}
	return count;
}

string convertFromIntToString()