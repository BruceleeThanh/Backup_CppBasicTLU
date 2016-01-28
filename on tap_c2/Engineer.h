#ifndef ENGINEER_H
#define ENGINEER_H

#include <iostream>
using namespace std;
#include <string.h>
#include "Person.h"

class Engineer : public Person
{
private:
	char nganhhoc[50];
	int namtotnghiep;
public:
	Engineer();
	Engineer(const char*, int, int, int, const char*,const char*,int);

	void setNganhHoc(const char*);
	char* getNganhHoc();

	void setNamTotNghiep(int);
	int getNamTotNghiep() const;

	friend ostream &operator <<(ostream &, Engineer &);
	friend istream &operator >>(istream &, Engineer &);

	~Engineer();
};

#endif
