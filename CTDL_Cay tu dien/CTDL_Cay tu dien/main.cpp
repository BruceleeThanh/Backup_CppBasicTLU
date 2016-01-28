#include "Dictionary.h"
#include "Node.h"

int _choose, j = 0;
bool out = false;
char w[20], a;
char k[20];
string m, x, z;
int done, _count = 0, _count1 = 0;

Dictionary d;
Node *p = new Node;

void addDictionary(Node *&p, char w[], string m);

int main(){
	p = NULL;
	addDictionary(p, w, m);
	cout << "\t\tChao mung ban den voi SMART DICTIONARY.!" << endl;
	while (1){
		cout << "\nNhan 1: De Tra cuu tu.\nNhan 2: De Them mot tu.\nNhan 3: De Luu mot tu.\nNhan 4: De Sua mot tu.\nNhan 5: De Xoa mot tu.\nNhan 6: De Tra cac tu co xuat hien chu cai nao do.\nNhan 0: De Thoat.\n" << endl;
		cout << "Ban chon: "; cin >> _choose;
		cin.ignore();
		switch (_choose)
		{
		case 1:
			cout << "=> Tra cuu tu:" << endl;
			cout << "Nhap tu ban muon tim: "; cin.getline(w, 20);
			d.searchWord(w, strlen(w));
			break;
		case 2:
			cout << "=> Them tu:" << endl;
			cout << "Nhap tu ban muon them: "; cin.getline(w, 20);
			if (d.searchWord_noDisplay(w, strlen(w))){
				cout << "\nTu ban nhap da co trong tu dien.";
				d.searchWord(w, strlen(w));
			}
			else{
				cout << "Hay nhap nghia cho tu " << w << ": "; getline(cin, m);
				d.addWord_nextTime(w, m, strlen(w));
				cout << "\nTu " << w << " co nghia " << m << " da duoc Them." << endl;
			}
			break;
		case 3:
			fout.open("Dictionary.txt", ios::app);
			cout << "=> Luu tu:" << endl;
			cout << "Nhap tu ban muon luu: "; cin.getline(w, 20);
			if (d.searchWord_noDisplay(w, strlen(w))){
				cout << "\nTu ban nhap da co trong tu dien.";
				d.searchWord(w, strlen(w));
			}
			else{
				cout << "Hay nhap nghia cho tu " << w << ": "; getline(cin, m);
				d.addWord_nextTime(w, m, strlen(w));
				fout << "\n" << w << "\n" << m;
				fout.close();
				cout << "\nTu " << w << " co nghia " << m << " da duoc Luu." << endl;
			}
			break;
		case 4:
			cout << "=> Sua tu:" << endl;
			cout << "Nhap tu ban muon sua: "; cin.getline(w, 20);
			if (d.searchWord_noDisplay(w, strlen(w))){
				d.searchWord(w, strlen(w));
				d.editWord(w, strlen(w));
			}
			else{
				d.addOrSaveWord(w, strlen(w));
			}

			break;
		case 5:
			cout << "=> Xoa tu:" << endl;
			cout << "Nhap tu ban muon xoa: "; cin.getline(w, 20);
			//d.searchWord(w, strlen(w));
			d.deleteWord(w, strlen(w));
			break;
		case 6:
			cout << "=> Tra tu co xuat hien chu cai can tim: " << endl;
			cout << "Nhap chu cai can tra: "; cin >> a;
			d.search_Characters(p, a, _count1, x, z);
			if (x.length() == 0){
				cout << "\nChu cai ban nhap khong co trong tu dien." << endl;
			}
			else{
				for (int i = 0; i < x.length(); i++){
					if (x[i] == '\n'){
						j = 0;
						d.searchWord(k, strlen(k));
						for (int h = 0; h < 20; h++){
							k[h] = NULL;
						}
					}
					else{
						k[j] = x[i];
						j++;
					}
				}
			}
			x.erase(0, x.length() - 1);
			break;
		case 0:
			out = true;
			break;
		default:
			cout << "\nBan nhap khong chinh xac." << endl;
			break;
		}
		cout << "-------------------------------------------------------" << endl;
		if (out){
			break;
		}
	}
	cout << "\nTam biet.!" << endl << endl;

	fin.close();
	return 0;
}

void addDictionary(Node *&p, char w[], string m){
	fin.open("Dictionary.txt");
	if (!fin.is_open()){
		cout << "Khong the mo duoc file." << endl;
	}
	else{
		while (!fin.eof()){
			fin.getline(w, 20);
			getline(fin, m);
			_count++;
			if (_count == 1){
				d.addWord_firstTime(p, w, m, strlen(w));
			}
			else{
				d.addWord_nextTime(w, m, strlen(w));
			}
		}
	}
	fin.close();
}