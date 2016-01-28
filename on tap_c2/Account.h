#pragma once
#include <iostream>
using namespace std;
#include <string.h>

class Account
{
private:
	char id[50], hoten[50], password[50];
	long long sotien;
public:
	Account();
	Account(const char*, const char*, const char*, double);
	//set
	void setID(const char*);
	void setHoTen(const char*);
	void setPassword(const char*);
	void setSoTien(double);
	//get
	char* getID();
	char* getHoTen();
	char* getPassword();
	double getSoTien()const;

	void operator +=(long long);
	void operator -=(long long);

	friend ostream &operator << (ostream &, Account &);
	friend istream &operator >> (istream &, Account &);

	~Account();
};

