#include "SoPhuc.h"

SoPhuc::SoPhuc() : phanthuc(0, 1), phanao(0, 1)
{

}

SoPhuc::SoPhuc(int tsphanthuc, int msphanthuc, int tsphanao, int msphanao) : phanthuc(tsphanthuc, msphanthuc), phanao(tsphanao, msphanao)
{

}

void SoPhuc::setPT(int ts, int ms)
{
	phanthuc.setts(ts);
	phanthuc.setms(ms);
}

void SoPhuc::setPA(int ts, int ms)
{
	phanao.setts(ts);
	phanao.setms(ms);
}


PhanSo SoPhuc::getPT()
{
	return phanthuc;
}

PhanSo SoPhuc::getPA()
{
	return phanao;
}

SoPhuc SoPhuc::operator+ (SoPhuc sp)
{
	SoPhuc k;
	k.phanthuc = phanthuc + sp.phanthuc;
	k.phanao = phanao + sp.phanao;
	return k;
}

SoPhuc SoPhuc::operator- (SoPhuc sp)
{
	SoPhuc k;
	k.phanthuc = phanthuc - sp.phanthuc;
	k.phanao = phanao - sp.phanao;
	return k;
}

SoPhuc SoPhuc::operator* (SoPhuc sp)
{
	SoPhuc k;
	k.phanthuc = phanthuc * sp.phanthuc - phanao * sp.phanao;
	k.phanao = phanao * sp.phanthuc + phanthuc * sp.phanao;
	return k;
}

SoPhuc SoPhuc::operator/ (SoPhuc sp)
{
	SoPhuc k;
	k.phanthuc = (phanthuc * sp.phanthuc + phanao * sp.phanao) / (sp.phanthuc * sp.phanthuc + sp.phanao * sp.phanao);
	k.phanao = (phanao * sp.phanthuc - phanthuc * sp.phanao) / (sp.phanthuc * sp.phanthuc + sp.phanao * sp.phanao);
	return k;
}

void SoPhuc::operator= (SoPhuc sp)
{
	phanthuc = sp.phanthuc;
	phanao = sp.phanao;
}

void SoPhuc::InSoPhuc()
{
	cout << phanthuc.convert() << " + " << phanao.convert() << "i";
}

SoPhuc::~SoPhuc()
{

}