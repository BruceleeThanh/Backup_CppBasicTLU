#include<iostream>
using namespace std;
#include"Single_Linked_List.h"

int main(){
	Single_Linked_List<int> list1;
	Single_Linked_List<int> list2;

	list1.insertToTail(2);
	list1.insertToHead(1);
	list1.insertToTail(3);
	list2.insertToHead(10);
	list2.insertToTail(20);
	list2.insertToTail(30);
	list2.insertToTail(40);

	list1.link(list2);
	



	return 0;
}