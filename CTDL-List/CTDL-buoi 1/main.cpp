//#include "List.h"
//#include "Stack.h"
#include "Queue.h"

int main(){
	/*List l;
	l.addFirst(10);
	l.addFirst(20);
	l.addFirst(30);
	l.addLast(200);
	l.addLast(100);
	l.Insert(7, 99);

	l.displayAll();
	cout << "So phan tu trong danh sach: " << l.Count() << endl;
	l.Change(3, 9999);
	l.displayAll();
	cout << endl << "------------" << endl;
	l.Delete(4);
	l.displayAll();
	l.Insert(4, 300);
	l.displayAll();
	cout<<l.getItem(2)<<endl;
	cout << "----------" << endl;
	l.deleteAll();
	l.displayAll();*/

	/*Stack s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	cout << "Top: " << s.getTop() << endl;
	s.Pop();
	s.Pop();
	cout << "Top: " << s.getTop() << endl;
	s.isEmpty();*/

	Queue q;
	q.Push(1);
	/*q.Push(2);
	q.Push(3);
	q.Push(4);*/
	cout << "Top: " << q.getTop() << endl;
	q.Pop();
	//cout << "Top: " << q.getTop() << endl;
	//cout << "Last: " << q.getLast() << endl;
	//q.Push(5);
	//cout << "Last: " << q.getLast() << endl;
	q.isEmpty();

	return 0;
}