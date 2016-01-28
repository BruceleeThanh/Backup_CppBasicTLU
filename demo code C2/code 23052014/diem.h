#ifndef DIEM_H
#define DIEM_H

class Diem{
private:
	int x,y;
public:
	Diem();
	Diem(int,int);
	void setXY(int,int);
	void setX(int);
	void setY(int);
	int getX()const;
	int getY()const;

};
Diem::Diem(){
	x=0,y=0;
}
Diem::Diem(int x,int y){
	this->x = x;
	this->y = y;
}
void Diem::setXY(int x,int y){
	this->x=x;
	this->y=y;
}
void Diem::setX(int x){
	this->x=x;
}
void Diem::setY(int y){
	this->y=y;
}


int Diem::getX()const{
	return x;
}
int Diem::getY()const{
	return y;
}

#endif