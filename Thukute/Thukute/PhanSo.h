#pragma once

#include<iostream>
using namespace std;


class PhanSo
{
private:
	int ts;
	int ms;
public:
	PhanSo();
	PhanSo(int ts,int ms);
	int getts();
	int getms();
	void setts(int ts);
	void setms(int ms);
	void ToiGian();
	void In();
	PhanSo operator +(PhanSo);
	PhanSo operator -(PhanSo);
	PhanSo operator *(PhanSo);
	PhanSo operator /(PhanSo);
	void operator =(PhanSo);
	void operator ++();
	void operator --();
	void operator += (PhanSo);
	void operator -= (PhanSo);
	void operator *= (PhanSo);
	bool operator ==(PhanSo);
	bool operator >(PhanSo);
	bool operator <(PhanSo);
	bool operator >=(PhanSo);
	bool operator <=(PhanSo);
	double convert();
	
	~PhanSo();
	
};
void SapXep(PhanSo x[], int n);

