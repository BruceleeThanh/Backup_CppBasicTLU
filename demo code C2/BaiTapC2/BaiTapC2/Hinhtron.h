#ifndef HINH_TRON_H
#define HINH_TRON_H

#define PI 3.14

class HinhTron
{
	protected:
		int banKinh;

	public:
		HinhTron();
		HinhTron(int);

		void setBanKinh(int);
		int getBanKinh() const;

		int getDuongKinh() const;
		double getDienTich() const;
		double getChuVi() const;
};

#endif