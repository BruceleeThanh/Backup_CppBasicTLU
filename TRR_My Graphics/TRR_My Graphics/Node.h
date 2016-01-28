#pragma once
#ifndef NODE_H
#define NODE_H
#include "Lib.h"
using namespace std;

template <class T >

struct Node
{
	T data;
	Node *next;
};

#endif