#ifndef STACK_H
#define STACK_H
#include "Node.h"

template <class T>

class Stack{
private:
	Node <T> *top;
	string name;

public:
	Stack(){
		top = 0;
	}

	//Them vao dau danh sach
	void Push(T v){
		Node <T> *p = new Node < T >;
		p->data = v;
		p->next = top;
		top = p;
	}

	//Lay di mot phan tu o dau danh sach
	void Pop(){
		if (!isEmpty()){
			Node <T> *n = top;
			top = top->next;
			delete n;
		}
	}

	//Xem phan tu dau danh sach
	T getTop(){
		if (!isEmpty()){
			return top->data;
		}
	}

	//Kiem tra danh sach rong
	bool isEmpty(){
		if (top == 0){
			return 1;
		}
		else{
			return 0;
		}
	}

	//Tao va in toan bo danh sach
	void displayAll(){
	Stack <string> *q = new Stack < string > ;
		if (!isEmpty()){
			cout << "Cot " << getName() << ": " << endl;
			Node <T> *n = top;
			while (n != 0){
				q->Push(n->data);
				n = n->next;
			}
		}
		else{
			cout << "Cot " << getName() << " khong co dia." << endl;
		}
		q->display();
		delete q;
	}

	//In ra toan bo danh sach Ao
	void display(){
		if (!isEmpty()){
			Node <T> *n = top;
			while (n != 0){
				cout << n->data << "; ";
				n = n->next;
			}
			cout << endl;
		}
	}

	//Nhap ten cot
	void setName(){
		getline(cin, name);
	}

	//Lay ra ten cot
	string getName(){
		return name;
	}

	//Kiem tra so luong phan tu
	int Count(){
		int count = 0;
		Node <T> *n = top;
		while (n != 0){
			n = n->next;
			count++;
		}
		return count;
	}

	//Cach in theo cot -------------------------------------------------

	//Tao va in toan bo danh sach
	void displayAll_cot(){
		Stack <string> *q = new Stack < string >;
		if (!isEmpty()){
			cout << 
			Node <T> *n = top;
			while (n != 0){
				q->Push(n->data);
				n = n->next;
			}
		}
		else{
			cout << "Cot " << getName() << " khong co dia." << endl;
		}
		q->display();
		delete q;
	}

	//In ra toan bo danh sach Ao
	void display_cot(){
		if (!isEmpty()){
			Node <T> *n = top;
			while (n != 0){
				cout << n->data << "; ";
				n = n->next;
			}
			cout << endl;
		}
	}

	~Stack(){}


		
};


#endif