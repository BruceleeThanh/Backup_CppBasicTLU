#ifndef STACK_H
#define STACK_H
#include "Lib.h"

template <class T>

class Stack{
private:
	Node <T> *top;
	string _name;
public:
	Stack(){
		top = 0;
	}

	//Add to head of Stack
	void Push(T v){
		Node <T> *p = new Node < T > ;
		p->data = v;
		p->next = top;
		top = p;
	}

	//Delete head of Stack
	void Pop(){
		if (!isEmpty()){
			Node <T> *n = top;
			top = top->next;
			delete n;
		}
	}

	//Display head of Stack
	T getTop(){
		if (!isEmpty()){
			return top->data;
		}
	}

	//Check Empty Stack
	bool isEmpty(){
		if (top == 0){
			return 1;
		}
		else{
			return 0;
		}
	}

	~Stack(){

	}


};




#endif