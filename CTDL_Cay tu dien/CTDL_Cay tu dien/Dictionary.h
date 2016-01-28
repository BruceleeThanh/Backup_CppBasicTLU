#ifndef DICTIONARY_H
#define DICTIONARY_H
#include "Node.h"

ifstream fin;
ofstream fout;

class Dictionary{
private:
	Node *head;
public:
	Dictionary(){
		head = 0;
	}

	////////////////////////////////////////////
	//New Idea

	//////////////////////
	//Các hàm chính

	//Thêm từ vào cây (từ đầu tiên)
	void addWord_firstTime(Node *&n, char w[], string m, int x){
		Node *h = head;
		for (int i = 0; i < x; i++){
			//First Time
			if (n == 0){
				n = new Node;
				n->word = w[i];
				n->ptrChild = emptyNode();
				n->ptrNext = emptyNode();
				if (i == x - 1){
					n->key = true;
					n->meaning = m;
				}
				h = head = n;
				h = h->ptrChild;
			}
			else{
				//Child
				if (h->ptrChild == NULL){
					Node *p = new Node;
					newCharacters(p, w[i], i, m, x);
					while (h->ptrChild != NULL){
						h = h->ptrChild;
					}
					Change(h, p);
					h = h->ptrChild;
				}
			}
		}
	}

	//Thêm từ vào cây (tất cả các từ sau từ đầu tiên)
	void addWord_nextTime(char w[], string m, int x){
		int flag = 0;
		Node *h = head;
		for (int i = 0; i < x; i++){
			if ((int)h->word != (int)w[i] || (int)h->word != ((int)w[i] + 32) || (int)h->word != ((int)w[i] - 32)){
				while (h->ptrNext != NULL){
					if ((int)h->word == (int)w[i] || (int)h->word == ((int)w[i] + 32) || (int)h->word == ((int)w[i] - 32)){
						flag++;
						break;
					}
					h = h->ptrNext;
				}
				if (flag == 0){
					Node *p = new Node;
					newCharacters(p, w[i], i, m, x);
					Change(h, p);
					h = h->ptrChild;
				}
				else{
					flag = 0;
					if (i == x - 1){
						h->key = true;
						h->meaning = m;
					}
					h = h->ptrChild;
				}
			}
			else{
				if (i == x - 1){
					h->key = true;
					h->meaning = m;
				}
				h = h->ptrChild;
			}
		}
	}

	//Tìm từ trong cây (trả về màn hình nghĩa của từ cần tìm)
	void searchWord(char w[], int x){
		int flag = 0;
		Node *h = head;
		string m;
		for (int i = 0; i < x; i++){
			if ((int)h->word != (int)w[i] || (int)h->word != ((int)w[i] + 32) || (int)h->word != ((int)w[i] - 32)){
				while (h->ptrNext != NULL){
					if ((int)h->word == (int)w[i] || (int)h->word == ((int)w[i] + 32) || (int)h->word == ((int)w[i] - 32)){
						flag++;
						break;
					}
					h = h->ptrNext;
				}
				if (flag == 0){
					addOrSaveWord(w, x);
					return;
				}
				else{
					flag = 0;
					if (i == x - 1){
						if (h->key){
							cout << "\nTu " << w << " co nghia la: " << h->meaning << endl;
							return;
						}
						else{
							addOrSaveWord(w, x);
							return;
						}
					}
					h = h->ptrChild;
				}
			}
			else{
				if (i == x - 1){
					if (h->key){
						cout << "\nTu " << w << " co nghia la: " << h->meaning << endl;
						return;
					}
					else{
						addOrSaveWord(w, x);
						return;
					}
				}
				h = h->ptrChild;
			}
		}
	}


	//Thêm từ vào cây hoặc lưu từ vào cây và file
	void addOrSaveWord(char w[], int x){
		string m;
		int choose;
		while (1){
			cout << "\nTu ban nhap chua co trong tu dien.\n----------------\nNhan 1: De Them tu nay.\nNhan 2: De Luu tu nay.\nNhan 0: De Thoat.\n" << endl;
			cout << "Ban Chon: "; cin >> choose;
			cin.ignore();
			switch (choose)
			{
			case 1:
				cout << "=> Them tu:" << endl;
				cout << "Hay nhap nghia cho tu " << w << ": "; getline(cin, m);
				addWord_nextTime(w, m, x);
				cout << "\nTu " << w << " co nghia " << m << " da duoc Them." << endl;
				return;
			case 2:
				fout.open("Dictionary.txt", ios::app);
				cout << "=> Luu tu:" << endl;
				cout << "Hay nhap nghia cho tu " << w << ": "; getline(cin, m);
				addWord_nextTime(w, m, x);
				fout << "\n" << w << "\n" << m;
				cout << "\nTu " << w << " co nghia " << m << " da duoc Luu." << endl;
				fout.close();
				return;
			case 0:
				return;
			default:
				cout << "\nBan nhap khong chinh xac." << endl;
				break;
			}
			cout << "--------------------------------" << endl;
		}
	}

	//Sửa từ (sửa nghĩa hoặc sửa cả từ và nghĩa)
	void editWord(char w[], int x){
		string m;
		int choose;
		string readout = searchWord_returnMeaning(w, x);
		cout << "----------------\nNhan 1: De Sua Nghia cua tu.\nNhan 2: De Sua ca Tu va Nghia.\nNhan 0: De Thoat.\n" << endl;
		cout << "Ban chon: "; cin >> choose;
		cin.ignore();
		while (1){
			switch (choose)
			{
			case 1:
				fout.open("Dictionary.txt", ios::app);
				cout << "=> Sua Nghia:" << endl;
				cout << "Nhap nghia moi cho tu " << w << ": "; getline(cin, m);
				addWord_nextTime(w, m, x);
				editFile1(readout, m);
				cout << "Sua thanh cong." << endl;
				cout << "\nTu " << w << " co nghia moi la: " << m << endl;
				return;
			case 2:
				fout.open("Dictionary.txt", ios::app);
				cout << "Sua ca Tu va Nghia" << endl;
				deleteWord_noDisplay(w, x);
				cout << "Ban muon sua " << w << " thanh tu: "; cin.getline(w, 20);
				cout << "Nhap nghia cho tu " << w << ": "; getline(cin, m);
				addWord_nextTime(w, m, x);
				fout << "\n" << w << "\n" << m;
				fout.close();
				cout << "Sua thanh cong." << endl;
				cout << "\nTu " << w << " co nghia la: " << m << endl;
				return;
			case 0:
				return;
			default:
				cout << "\nBan nhap khong chinh xac." << endl;
				break;
			}
			cout << "--------------------------------" << endl;
		}
	}

	//Xóa từ khỏi cây và file
	void deleteWord(char w[], int x){
		int flag = 0;
		Node *h = head;
		string m;
		for (int i = 0; i < x; i++){
			if ((int)h->word != (int)w[i] || (int)h->word != ((int)w[i] + 32) || (int)h->word != ((int)w[i] - 32)){
				while (h->ptrNext != NULL){
					if ((int)h->word == (int)w[i] || (int)h->word == ((int)w[i] + 32) || (int)h->word == ((int)w[i] - 32)){
						flag++;
						break;
					}
					h = h->ptrNext;
				}
				if (flag == 0){
					cout << "\nTu ban muon Xoa khong ton tai trong tu dien." << endl;
					return;
				}
				else{
					flag = 0;
					if (i == x - 1){
						if (h->key){
							editFile2(w, searchWord_returnMeaning(w, x));
							h->key = false;
							cout << "\nXoa thanh cong." << endl;
							return;
						}
						else{
							cout << "\nTu ban muon Xoa khong ton tai trong tu dien." << endl;
							return;
						}
					}
					h = h->ptrChild;
				}
			}
			else{
				if (i == x - 1){
					if (h->key){
						editFile2(w, searchWord_returnMeaning(w, x));
						h->key = false;
						cout << "\nXoa thanh cong." << endl;
						return;
					}
					else{
						cout << "\nTu ban muon Xoa khong ton tai trong tu dien." << endl;
						return;
					}
				}
				h = h->ptrChild;
			}
		}
	}

	//////////////////////
	//Các hàm phụ

	//Tạo Node hoặc ký tự mới
	void newCharacters(Node *&p, char w, int i, string m, int x){
		p->word = w;
		p->ptrChild = emptyNode();
		p->ptrNext = emptyNode();
		if (i == x - 1){
			p->key = true;
			p->meaning = m;
		}
	}

	//Tạo nốt rỗng
	Node* emptyNode(){
		Node *q = new Node;
		q->ptrChild = NULL;
		q->ptrNext = NULL;
		return q;
	}

	//Biến Node p thành Node h
	void Change(Node *&h, Node *&p){
		h->word = p->word;
		h->meaning = p->meaning;
		h->key = p->key;
		h->ptrChild = p->ptrChild;
		h->ptrNext = p->ptrNext;
	}

	//Tìm từ trong cây (trả về True hoặc False)
	bool searchWord_noDisplay(char w[], int x){
		int flag = 0;
		Node *h = head;
		string m;
		for (int i = 0; i < x; i++){
			if ((int)h->word != (int)w[i] || (int)h->word != ((int)w[i] + 32) || (int)h->word != ((int)w[i] - 32)){
				while (h->ptrNext != NULL){
					if ((int)h->word == (int)w[i] || (int)h->word == ((int)w[i] + 32) || (int)h->word == ((int)w[i] - 32)){
						flag++;
						break;
					}
					h = h->ptrNext;
				}
				if (flag == 0){
					return false;
				}
				else{
					flag = 0;
					if (i == x - 1){
						if (h->key){
							return true;
						}
						else{
							return false;
						}
					}
					h = h->ptrChild;
				}
			}
			else{
				if (i == x - 1){
					if (h->key){
						return true;
					}
					else{
						return false;
					}
				}
				h = h->ptrChild;
			}
		}
	}
	
	//Tìm từ trong cây (trả về nghĩa của từ đó)
	string searchWord_returnMeaning(char w[], int x){
		int flag = 0;
		Node *h = head;
		string m;
		for (int i = 0; i < x; i++){
			if ((int)h->word != (int)w[i] || (int)h->word != ((int)w[i] + 32) || (int)h->word != ((int)w[i] - 32)){
				while (h->ptrNext != NULL){
					if ((int)h->word == (int)w[i] || (int)h->word == ((int)w[i] + 32) || (int)h->word == ((int)w[i] - 32)){
						flag++;
						break;
					}
					h = h->ptrNext;
				}
				if (flag == 0){
					return false;
				}
				else{
					flag = 0;
					if (i == x - 1){
						if (h->key){
							return h->meaning;
						}
						else{
							return false;
						}
					}
					h = h->ptrChild;
				}
			}
			else{
				if (i == x - 1){
					if (h->key){
						return h->meaning;
					}
					else{
						return false;
					}
				}
				h = h->ptrChild;
			}
		}
	}
	
	//Tra từ theo ký tự
	string search_Characters(Node *&n, char a, int &_count, string &w, string &z){
		if (n->ptrChild != NULL && n->ptrNext != NULL){
			z += n->word;
			if (n->word == a){
				_count++;
			}
			if (_count != 0){
				if (n->key){
					w += z + '\n';
				}
			}
			search_Characters(n->ptrChild, a, _count, w, z);
			z.erase(z.length() - 1, 1);
			if (n->word == a){
				_count--;
			}
			search_Characters(n->ptrNext, a, _count, w, z);
		}
		return w;
	}

	bool deleteWord_noDisplay(char w[], int x){
		int flag = 0;
		Node *h = head;
		string m;
		for (int i = 0; i < x; i++){
			if ((int)h->word != (int)w[i] || (int)h->word != ((int)w[i] + 32) || (int)h->word != ((int)w[i] - 32)){
				while (h->ptrNext != NULL){
					if ((int)h->word == (int)w[i] || (int)h->word == ((int)w[i] + 32) || (int)h->word == ((int)w[i] - 32)){
						flag++;
						break;
					}
					h = h->ptrNext;
				}
				if (flag == 0){
					//cout << "\nTu ban muon Xoa khong ton tai trong tu dien." << endl;
					return false;
				}
				else{
					flag = 0;
					if (i == x - 1){
						if (h->key){
							editFile2(w, searchWord_returnMeaning(w, x));
							h->key = false;
							//cout << "\nXoa thanh cong." << endl;
							return true;
						}
						else{
							//cout << "\nTu ban muon Xoa khong ton tai trong tu dien." << endl;
							return false;
						}
					}
					h = h->ptrChild;
				}
			}
			else{
				if (i == x - 1){
					if (h->key){
						editFile2(w, searchWord_returnMeaning(w, x));
						h->key = false;
						//cout << "\nXoa thanh cong." << endl;
						return true;
					}
					else{
						//cout << "\nTu ban muon Xoa khong ton tai trong tu dien." << endl;
						return false;
					}
				}
				h = h->ptrChild;
			}
		}
	}

	//Sửa nghĩa của một từ trong File
	void editFile1(string m, string newm){
		fin.open("Dictionary.txt");
		string x, n;
		while (!fin.eof()){
			getline(fin, x);
			if (x != m){
				n += x + '\n';
			}
			else{
				n += newm + '\n';
			}
		}
		fin.close();
		n.erase(n.length() - 1, 1);
		ofstream fout("Dictionary.txt");
		fout << n;
		fout.close();
	}

	//Xóa một từ và nghĩa của nó trong File
	void editFile2(char w[], string m){
		fin.open("Dictionary.txt");
		string x, n;
		int flag = 1;
		while (!fin.eof()){
			getline(fin, x);
			if (flag == 1){
				for (int i = 0; i < x.length(); i++){
					if (x[i] >= 65 && x[i] <= 90){
						x[i] = (char)((int)x[i] + 32);
					}
				}
				flag = 0;
			}
			else{
				flag = 1;
			}
			if (x != w && x != m){
				n += x + '\n';
			}
		}
		fin.close();
		n.erase(n.length() - 1, 1);
		ofstream fout("Dictionary.txt");
		fout << n;
		fout.close();
	}

	~Dictionary(){

	}
};

#endif