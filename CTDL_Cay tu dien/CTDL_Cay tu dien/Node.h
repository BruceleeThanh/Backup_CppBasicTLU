#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
using namespace std;

struct Node{
	char word;
	string meaning;
	bool key = false;
	Node *ptrChild;
	Node *ptrNext;
};

#endif