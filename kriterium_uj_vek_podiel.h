#pragma once
#include "kriterium_uzemna_jednotka.h"
#include "kriterium_uj_vek_pocet.h"

class KriteriumUJVekPodiel : public KriteriumUzemnaJednotka<double>
{
public:
	KriteriumUJVekPodiel(Pohlavie pohlavie, int vek) :
		vek_(vek),
		pohlavie_(pohlavie)
	{
	}
	double evaluate(UzemnaJednotka* uJ) override { return  100 * (static_cast<double>(KriteriumUJVekPocet(pohlavie_, vek_).evaluate(uJ)) / uJ->getVek()->getPocetObyvatelov()); }
	std::wstring toString() override { return L""; }
	virtual ~KriteriumUJVekPodiel() {};
private:
	int vek_;
	Pohlavie pohlavie_;
};
