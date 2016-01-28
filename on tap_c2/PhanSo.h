#ifndef PAHN_SO_H
#define PHAN_SO_H
#include <iostream>
using namespace std;

class PhanSo
{
private:
	int tuso, mauso;
public:
	PhanSo();
	PhanSo(int);
	PhanSo(int, int);
	~PhanSo();

	void setTuSo(int);
	int getTuSo() const;

	void setMauSo(int);
	int getMauSo() const;

	PhanSo ToiGian();

	PhanSo operator +(PhanSo);
	PhanSo operator -(PhanSo);
	PhanSo operator *(PhanSo);
	PhanSo operator /(PhanSo);

	bool operator ==(PhanSo);
	bool operator >(PhanSo);
	bool operator >=(PhanSo);
	bool operator <(PhanSo);
	bool operator <=(PhanSo);

	PhanSo operator ++();
	PhanSo operator --();
	PhanSo operator +=(PhanSo);
	PhanSo operator -=(PhanSo);
	PhanSo operator *=(PhanSo);
	PhanSo operator /=(PhanSo);

	friend ostream &operator <<(ostream &, PhanSo &);
	friend istream &operator >>(istream &, PhanSo &);

};


#endif
