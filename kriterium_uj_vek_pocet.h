#pragma once
#include "kriterium_uzemna_jednotka.h"

class KriteriumUJVekPocet : public KriteriumUzemnaJednotka<int>
{
public:
	KriteriumUJVekPocet(Pohlavie pohlavie, int vek) :
		vek_(vek),
		pohlavie_(pohlavie)
	{
	}
	int evaluate(UzemnaJednotka* uJ) override { return uJ->getVek()->getPocetVek(vek_, pohlavie_); }
	std::wstring toString() override { return L""; }
	virtual ~KriteriumUJVekPocet() {};
private:
	int vek_;
	Pohlavie pohlavie_;
};