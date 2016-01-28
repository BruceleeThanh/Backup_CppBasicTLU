#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;
#include <string.h>

class Person
{
protected:
	int ngay, thang, nam;
	char hoten[50], quequan[50];
public:
	Person();
	Person(const char*, int, int, int, const char*);

	void setSinhNhat(int, int, int);
	int getNgay() const;
	int getThang() const;
	int getNam() const;

	void setHoTen(const char*);
	char* getHoTen();

	void setQueQuan(const char*);
	char* getQueQuan();

	

	~Person();
};

#endif