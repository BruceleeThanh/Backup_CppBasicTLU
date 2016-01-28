#pragma once
#include "PhanSo.h"

class SoPhuc
{
private:
	PhanSo phanthuc;
	PhanSo phanao;
public:
	SoPhuc();
	SoPhuc(int, int, int, int);
	void setPT(int, int);
	void setPA(int, int);
	PhanSo getPT();
	PhanSo getPA();
	SoPhuc operator +(SoPhuc);
	SoPhuc operator -(SoPhuc);
	SoPhuc operator *(SoPhuc);
	SoPhuc operator /(SoPhuc);
	void operator =(SoPhuc);
	void InSoPhuc();


	~SoPhuc();
};
