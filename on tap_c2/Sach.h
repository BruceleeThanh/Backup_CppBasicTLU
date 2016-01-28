#ifndef SACH_H
#define SACH_H
#include <iostream>
using namespace std;
#include <string.h>
class Sach
{
protected:
	char tensach[50];
	int namxb;
	double heso;
public:
	Sach();
	Sach(const char*, int, double);
	//set
	void setTenSach(const char*);
	void setNamxb(int);
	void setHeSo(double);
	//get
	char* getTenSach();
	int getNamxb() const;
	double getHeSo() const;

	virtual double GiaBan();

	friend ostream &operator <<(ostream &, Sach &);
	friend istream &operator >>(istream &, Sach &);

	~Sach();
};

#endif