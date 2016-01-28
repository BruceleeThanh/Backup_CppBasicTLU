#ifndef DIEM_H
#define DIEM_H

class Diem
{
	private:
		int x, y;

	public:
		Diem();		
		Diem(int, int);

		void setXY(int, int);
		
		void setX(int);
		int getX() const;

		void setY(int);
		int getY() const;
};

#endif