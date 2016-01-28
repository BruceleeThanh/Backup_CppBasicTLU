//#include <iostream>
//using namespace std;
//
//struct Node{
//	int data;
//	Node *next;
//};
//
//void addFirst(Node *&h, int v);
//void addLast(Node *&h, int v);
//void insert(Node *&h,int pos, int v);
//void displayAll(Node *h);
//int getItem(Node *h, int x);
//int count(Node *h);
//
//int main(){
//	/*Node a,b,c;
//	a.data=10;
//	a.next=&b;
//	b.data=20;
//	b.next=&c;
//	c.data=30;
//	cout<<a.next->next->data<<endl;*/
//
//	Node *h1;
//	h1=0;
//	addFirst(h1,10);
//	addFirst(h1,20);
//	addFirst(h1,30);
//	//cout<<h1->next->data<<endl;
//	//displayAll(h1);
//	//cout<<getItem(h1,5);
//	//cout<<count(h1)<<endl;
//	//addLast(h1,40);
//	insert(h1,2,99);
//	displayAll(h1);
//
//	return 0;
//}
//
//void addFirst(Node *&h, int v){
//	Node *p=new Node;
//	p->data=v;
//	p->next=h;
//	h=p;
//}
//
//void addLast(Node *&h,int v){
//	Node *n=new Node;
//	n->data=v;
//	n->next=0;
//	if(h==0){
//		h=n;
//	} else{
//		Node *p=h;
//		while(p->next!=0){
//			p=p->next;
//		}
//		p->next=n;
//	}
//	/*while(p){
//		p=p->next;
//		if(p->next==NULL){
//			
//		}
//	}*/
//}
//
//void insert(Node *&h,int pos, int v){
//	if(pos==1){
//		addFirst(h,v);
//	}else{
//		if(pos-count(h)==1){
//			addLast(h,v);
//		}else{
//			Node *n=new Node;
//			Node *p=h;
//			for(int i=1;i<pos-1;i++){
//				p=p->next;
//			}
//			p=n;
//			n->data=v;
//			n->next=p->next;
//
//			
//
//			/*Node *p=h;
//			for(int i=1;i<pos-1;i++){
//				p=p->next;
//			}
//			n=p->next;
//			Node *q=h;
//			for(int i=1;i<pos;i++){
//				q=q->next;
//			}
//			q=n->next;*/
//		}
//	}
//
//}
//
//void displayAll(Node *h){
//	/*while (h!=0){
//		cout<<h->data<<", ";
//		h=h->next;
//	}*/
//
//	for(Node *p=h;p!=0;p=p->next){
//		cout<<p->data<<" ";
//	}
//}
//
//int getItem(Node *h,int pos){
//	if(pos>count(h)){
//		cout<<"Vuot qua so luong phan tu."<<endl;
//	}else{
//		for(int i=1;i<pos;i++){
//			h=h->next;
//		}
//		return h->data;
//	}
//}
//
//int count(Node *h){
//	int count=0;
//	while(h!=0){
//		h=h->next;
//		count++;
//	}
//	return count;
//}