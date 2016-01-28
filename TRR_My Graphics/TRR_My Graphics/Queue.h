#ifndef QUEUE_H
#define QUEUE_H
#include "Lib.h"

template <class T>

class Queue
{
private:
	Node <T> *top;
	string _name;
public:
	Queue(){
		top = 0;
	}

	//Add to head of Queue
	void Push(T v){
		Node <T> *p = new Node < T > ;
		p->data = v;
		p->next = top;
		top = p;
	}

	//Delete tail of Queue
	T Pop(){
		T temp;
		Node <T> *n = top;
		if (Count() == 1){
			Node <T> *p = n;
			n = n->next;
			temp = p->data;
			delete p;
			top = 0;
		}
		else{
			for (int i = 1; i <= Count() - 2; i++){
				n = n->next;
			}
			Node <T> *p = n->next;
			n->next = n->next->next;
			temp = p->data;
			delete p;
		}
		
		return temp;
	}

	//Check the amount of elements
	int Count(){
		int count = 0;
		Node <T> *n = top;
		while (n != 0){
			n = n->next;
			count++;
		}
		return count;
	}

	//Check Empty Queue
	bool isEmpty(){
		if (top == 0){
			return 1;
		}
		else{
			return 0;
		}
	}

	~Queue(){

	}



};



#endif