#ifndef STACK_H
#define STACK_H
#include "Node.h"

class Stack{
private:
	Node *top;
public:
	Stack(){
		top = 0;
	}
	//Them phan tu dau
	void Push(int v){
		Node *p = new Node;
		p->data = v;
		p->next = top;
		top = p;
	}
	//Loai phan tu dau
	void Pop(){
		Node *n = top;
		top = top->next;
		delete n;
	}
	//Xem phan tu dau
	int getTop(){
		return top->data;
	}
	//Kiem tra rong
	void isEmpty(){
		if (top == 0){
			cout << "Danh sach Stack dang rong." << endl;
		}
		else{
			cout << "Danh sach Stack dang co phan tu." << endl;
		}
	}
	
	~Stack(){}
};

#endif