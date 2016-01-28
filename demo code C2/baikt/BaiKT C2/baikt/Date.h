#ifndef DATE_H
#define DATE_H

class Date{
private:
	int ngay, thang, nam;
public:
	Date();
	Date(int,int,int);
	void setNgay(int);
	int getNgay() const;
	void setThang(int);
	int getThang()const;
	void setNam(int);
	int getNam()const;
	void disPlay();

};


#endif