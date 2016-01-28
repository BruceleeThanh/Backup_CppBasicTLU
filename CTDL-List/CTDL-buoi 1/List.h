#ifndef LIST_H
#define LIST_H
#include "Node.h"

class List
{
private:
	Node *head;
public:

	List(){
		head = 0;
	};
	//Them vao dau danh sach
	void addFirst(int v){
		Node *p = new Node;
		p->data = v;
		p->next = head;
		head = p;
	};
	//Them vao cuoi danh sach
	void addLast(int v){
		Node *p = new Node;
		p->data = v;
		p->next = NULL;
		if (head == 0){
			head = p;
		}
		else{
			Node *n = head;
			while (n->next != 0){
				n = n->next;
			}
			n->next = p;
		}
	};
	//In ra danh sach
	void displayAll() const{
		Node *n = head;
		while (n != 0){
			cout << n->data << "; ";
			n = n->next;
		}
		cout << endl;
	};
	//In ra doan danh sach theo y muon
	void displayFromTo(int from, int to) const{
		Node *n = head;
		for (int i = 1; i < from; i++){
			n = n->next;
		}
		for (int i = 1; i < to - from; i++){
			cout << n->data << "; ";
			n = n->next;
		}
	}
	//Them vao mot vi tri bat ky
	void Insert(int pos, int v){
		Node *p = new Node;
		p->data = v;
		if (pos == 1){
			addFirst(v);
		}
		else{
			if (pos > Count() + 1){
				cout << "Khong the them vao vi tri so " << pos << endl;
			}
			else{
				Node *n = head;
				for (int i = 1; i <= pos - 2; i++){
					n = n->next;
				}
				p->next = n->next;
				n->next = p;
			}
		}
	}

	//Thay doi gia tri cua mot phan tu bat ky
	void Change(int pos, int v){
		if (pos == 1){
			head->data = v;
		}
		else{
			Node *n = head;
			for (int i = 1; i < pos; i++){
				n = n->next;
			}
			n->data = v;
		}
	};
	//Xem gia tri cua mot phan tu bat ky
	int getItem(int pos){
		Node *n = head;
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
			Node *n = head;
			head = head->next;
			delete n;
		}
		else{
			Node *n = head;
			for (int i = 1; i <= pos - 2; i++){
				n = n->next;
			}
			Node *p = n->next;
			n->next = n->next->next;
			delete p;
		}
	};
	//Xoa toan bo danh sach
	void deleteAll(){
		Node *n = head;
		while (n != 0){
			Node *p = n;
			n = n->next;
			delete p;

		}
		head = 0;
	}
	//Kiem tra so luong phan tu
	int Count(){
		int count = 0;
		Node *n = head;
		while (n != 0){
			n = n->next;
			count++;
		}
		return count;
	};
	~List(){};
};

#endif
