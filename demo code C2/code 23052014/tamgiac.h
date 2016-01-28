#ifndef TAMGIAC_H
#define TAMGIAC_H
#include "diem.h"
#include <math.h>
class TamGiac{
private:
	Diem a,b,c;
	double getlength(Diem,Diem) const;
public:
	TamGiac();
	TamGiac(Diem,Diem,Diem);
	TamGiac(int,int,int,int,int,int);

	void setA(Diem); void setA(int,int); Diem getA() const;
	void setB(Diem); void setB(int,int); Diem getB() const;
	void setC(Diem); void setC(int,int); Diem getC() const;

	double getDienTich() const;
	double getChuVi() const;

	void Print()const;

};

TamGiac::TamGiac(){
}
TamGiac::TamGiac(Diem a,Diem b,Diem c){
	this->a=a;
	this->b=b;
	this->c=c;
}
TamGiac::TamGiac(int xa,int ya,int xb,int yb,int xc,int yc){
	a.setX(xa); a.setY(ya);
	b.setX(xb); b.setY(yb);
	c.setX(xc); c.setY(yc);
}
void TamGiac::setA(Diem a){
	this->a=a;
}
void TamGiac::setA(int xa,int ya){
	a.setXY(xa,ya);
}
void TamGiac::setB(Diem b){
	this->b=b;
}
void TamGiac::setB(int xb,int yb){
	b.setXY(xb,yb);
}
void TamGiac::setC(Diem c){
	this->c=c;
}
void TamGiac::setC(int xc,int yc){
	c.setXY(xc,yc);
}
Diem TamGiac::getA() const{
	return a;
}
Diem TamGiac::getB() const{
	return b;
}
Diem TamGiac::getC() const{
	return c;
}
double TamGiac::getlength(Diem x,Diem y) const{
	double hieu1=(double)y.getX()-x.getX();
	double hieu2=(double)y.getY()-x.getY();
	return sqrt(pow(hieu1,2)+pow(hieu2,2));
}
double TamGiac::getChuVi() const{
	return getlength(a,b)+getlength(b,c)+getlength(c,a);
}
double TamGiac::getDienTich() const{
	double p=getChuVi()/2;
	return sqrt(p*(p-getlength(a,b))*(p-getlength(b,c))*(p-getlength(c,a)));
}
void TamGiac::Print() const{
	cout<<"Toa do 3 dinh cua tam giac la: "<<"A("<<a.getX()<<","<<a.getY()<<") B("<<b.getX()<<","<<b.getY()<<") C("<<c.getX()<<","<<c.getY()<<")"<<endl;
	cout<<"Chu vi la: "<<getChuVi()<<endl;
	cout<<"Dien Tich la: "<<getDienTich()<<endl;
}

#endif