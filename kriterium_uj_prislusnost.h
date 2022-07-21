#pragma once
#include "kriterium_uzemna_jednotka.h"

class KriteriumUJPrislusnost : public KriteriumUzemnaJednotka<bool>
{
public:
	KriteriumUJPrislusnost(UzemnaJednotka* vuc) :
		VUC(vuc)
	{  
	}
	bool evaluate(UzemnaJednotka* uJ) override { return uJ->patriDoVUC(VUC); }
	std::wstring toString() override { return L""; }
	virtual ~KriteriumUJPrislusnost() {};
private:
	UzemnaJednotka* VUC;
};