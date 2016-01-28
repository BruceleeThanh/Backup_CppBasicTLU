#ifndef MYSTRING_H
#define MYSTRING_H
#include "NodeString.h"

class MyString
{
private:
	NodeString *head;
	NodeString *tail;
public:

	MyString(){
		head = 0;
		tail = 0;
	};
	//Them vao dau danh sach
	void addFirst(int v){
		NodeString *p = new NodeString;
		p->data = v;
		if (head == NULL){
			p->next = 0;
			head = tail = p;
		}
		else{
			p->next = head;
			head = p;
		}
	};
	//Them vao cuoi danh sach
	void addLast(int v){
		//Cach 1
		/*NodeString *p = new NodeString;
		p->data = v;
		p->next = NULL;
		if (head == 0){
		head = p;
		}
		else{
		NodeString *n = head;
		while (n->next != 0){
		n = n->next;
		}
		n->next = p;
		}*/
		//Cach 2
		NodeString *p = new NodeString;
		p->data = v;
		p->next = NULL;
		if (head == 0){
			head = tail = p;
		}
		else{
			tail->next = p;
			tail = p;
		}
	};
	//In ra danh sach
	void displayAll() const{
		NodeString *n = head;
		while (n != 0){
			cout << n->data << "; ";
			n = n->next;
		}
		cout << endl;
	};
	//Them vao mot vi tri bat ky
	void Insert(int pos, int v){
		NodeString *p = new NodeString;
		p->data = v;
		if (pos == 1){
			addFirst(v);
		}
		else{
			if (pos > Count() + 1){
				cout << "Khong the them vao vi tri so " << pos << endl;
			}
			else{
				if (pos == Count() + 1){
					NodeString *n = head;
					for (int i = 1; i <= pos - 2; i++){
						n = n->next;
					}
					p->next = n->next;
					n->next = p;
					tail = n->next;
				}
				else{
					NodeString *n = head;
					for (int i = 1; i <= pos - 2; i++){
						n = n->next;
					}
					p->next = n->next;
					n->next = p;
				}
			}
		}
	};
	//Thay doi gia tri cua mot phan tu bat ky
	void Change(int pos, int v){
		if (pos == 1){
			head->data = v;
		}
		else{
			NodeString *n = head;
			for (int i = 1; i < pos; i++){
				n = n->next;
			}
			n->data = v;
		}
	};
	//Xem gia tri cua mot phan tu bat ky
	int Search(int pos){
		NodeString *n = head;
		int x;
		if (pos == 1){
			x = head->data;
		}
		else{
			for (int i = 1; i < pos; i++){
				n = n->next;
			}
			x = n->data;
		}
		return x;
	}
	//Xoa mot phan tu bat ky
	void Delete(int pos){
		if (pos == 1){
			NodeString *n = head;
			head = head->next;
			delete n;
		}
		else{
			if (pos == Count()){
				NodeString *n = head;
				for (int i = 1; i <= pos - 2; i++){
					n = n->next;
				}
				tail = n;
				NodeString *p = n->next;
				n->next = n->next->next;
				delete p;
			}
			else{
				NodeString *n = head;
				for (int i = 1; i <= pos - 2; i++){
					n = n->next;
				}
				NodeString *p = n->next;
				n->next = n->next->next;
				delete p;
			}
		}
	};
	//Xoa toan bo danh sach
	void deleteAll(){
		NodeString *n = head;
		while (n != 0){
			NodeString *p = n;
			n = n->next;
			delete p;

		}
		head = 0;
	}
	//Kiem tra so luong phan tu
	int Count(){
		int count = 0;
		NodeString *n = head;
		while (n != 0){
			n = n->next;
			count++;
		}
		return count;
	};
	~MyString(){};
};

#endif
