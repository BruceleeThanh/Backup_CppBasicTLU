#ifndef LIST_H
#define LIST_H
#include "Node.h"
class List{
private:
	Node *head;
	Node *tail;
public:
	List(){
		head = tail = 0;
	}


	~List(){}
};

#endif