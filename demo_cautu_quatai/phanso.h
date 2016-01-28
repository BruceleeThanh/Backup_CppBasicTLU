#ifndef PHANSO_H
#define PHANSO_H

class PhanSo
{
private:
	int tuso, mauso;
public:
	PhanSo(int,int);
	PhanSo(int);
	PhanSo();
	void setTuso(int);
	void setMauso(int);
	double getPhanso() const;
	PhanSo operator *(PhanSo ps);
	PhanSo operator /(PhanSo ps);
	PhanSo operator +(PhanSo ps);
	PhanSo operator -(PhanSo ps);
	void operator ++();
	void operator --();
};


#endif