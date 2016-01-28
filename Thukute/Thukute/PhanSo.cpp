#include"PhanSo.h"

PhanSo::PhanSo()
{
	this->ts=0;
	this->ms=1;
}
PhanSo::PhanSo(int ts,int ms)
{
	this->ts=ts;
	this->ms=ms;
}
void PhanSo::setts(int ts)
{
	this->ts=ts;
	this->ms = 1;
}
int PhanSo::getts()
{
	return ts;
}

void PhanSo::setms(int ms)
{
	this->ms=ms;
}
int PhanSo::getms()
{
	return ms;
}

void PhanSo::ToiGian()
{
	PhanSo kq;
	int ucln,max,min;
	max=ts>ms?ts:ms;
	min=ts<ms?ts:ms;
	ucln=max%min;
	while(ucln>0)
	{
		max=min;
		min=ucln;
		ucln=max%min;
	}
	ucln=min;
	kq.ts=ts/ucln;
	kq.ms=ms/ucln;
	ts=kq.ts;
	ms=kq.ms;
}

void PhanSo::In()
{
	cout<<ts<<"/"<<ms<<endl;
}
PhanSo PhanSo::operator+(PhanSo a)
{
	PhanSo kq;
	kq.ts=ts*a.getms()+a.getts()*ms;
	kq.ms=ms*a.getms();
	kq.ToiGian();
	return kq;
}

PhanSo PhanSo::operator-(PhanSo b)
{
	PhanSo kq;
	kq.ts=ts*b.getms()-b.getts()*ms;
	kq.ms=ms*b.getms();
	kq.ToiGian();
	return kq;
}

PhanSo PhanSo::operator *(PhanSo c)
{
	PhanSo kq;
	kq.ts=ts*c.getts();
	kq.ms=ms*c.getms();
	kq.ToiGian();
	return kq;
}
PhanSo PhanSo::operator /(PhanSo d)
{
	PhanSo kq;
	kq.ts = ts*d.getms();
	kq.ms = ms*d.getts();
	kq.ToiGian();
	return kq;
}

void PhanSo::operator=(PhanSo a)
{
	ts = a.getts();
	ms = a.getms();
}
void PhanSo::operator++()
{
	ts = ts + ms;
}

void PhanSo::operator--()
{
	ts = ts - ms;
}

void PhanSo::operator +=(PhanSo a)
{
	ts = ts*a.getms() + a.getts()*ms;
	ms = ms*a.getms();
	ToiGian();
}

void PhanSo::operator -=(PhanSo a)
{
	ts = ts*a.getms() - a.getts()*ms;
	ms = ms*a.getms();
	ToiGian();
}

void PhanSo::operator *=(PhanSo a)
{
	ts = ts*a.getts();
	ms = ms*a.getms();
	ToiGian();
}


bool PhanSo::operator ==(PhanSo a)
{
	ToiGian();
	if (ts*a.getms()==a.getts()*ms)
		return 1;
	else
		return 0;
}

bool PhanSo::operator >(PhanSo a)
{
	ToiGian();
	if (ts*a.getms() > a.getts()*ms)
		return 1;
	else
		return 0;
}

bool PhanSo::operator <(PhanSo a)
{
	ToiGian();
	if (ts*a.getms() < a.getts()*ms)
		return 1;
	else
		return 0;
}

bool PhanSo::operator >=(PhanSo a)
{
	ToiGian();
	if (ts*a.getms() >= a.getts()*ms)
		return 1;
	else
		return 0;
}

bool PhanSo::operator <=(PhanSo a)
{
	ToiGian();
	if (ts*a.getms() <= a.getts()*ms)
		return 1;
	else
		return 0;
}

void SapXep(PhanSo x[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (x[i]>x[j])
			{
				PhanSo a = x[i];
				x[i] = x[j];
				x[j] = a;
			}
		}
	}
}

double PhanSo::convert(){
	return (double)ts / ms;
}

PhanSo::~PhanSo()
{
}