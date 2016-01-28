#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "Node.h"

class Queue{
private:
	Node *boss;
public:
	Queue(){
		boss = 0;
	}
	//Them phan tu tu duoi len
	void Push(int v){
		Node *p = new Node;
		p->data = v;
		p->next = boss;
		boss = p;
	}
	//Loai phan tu tu tren xuong
	void Pop(){
		Node *n = boss;
		if (Count() == 1){
			Node *p = n;
			n = n->next;
			delete p;
			boss = 0;
		}
		else{
			for (int i = 1; i <= Count() - 2; i++){
				n = n->next;
			}
			Node *p = n->next;
			n->next = n->next->next;
			delete p;
		}
	}
	//Xem phan tu dau (tu tren xuong)
	int getTop(){
		Node *n = boss;
		for (int i = 1; i < Count(); i++){
			n = n->next;
		}
		return n->data;
	}
	//Xem phan tu cuoi (tu duoi len)
	int getLast(){
		return boss->data;
	}
	//Kiem tra rong
	void isEmpty(){
		if (boss == 0){
			cout << "Danh sach Queue dang rong." << endl;
		}
		else{
			cout << "Danh sach Queue dang co phan tu." << endl;
		}
	}
	//Kiem tra so luong phan tu
	int Count(){
		int count = 0;
		Node *n = boss;
		while (n != 0){
			n = n->next;
			count++;
		}
		return count;
	};

	~Queue(){}
};


#endif