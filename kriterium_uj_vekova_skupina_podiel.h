#pragma once
#include "kriterium_uzemna_jednotka.h"
#include "kriterium_uj_vekova_skupina_pocet.h"

class KriteriumUJVekovaSkupinaPodiel : public KriteriumUzemnaJednotka<double>
{
public:
	KriteriumUJVekovaSkupinaPodiel(EVS vekovaSkupina) :
		vekovaSkupina_(vekovaSkupina)
	{
	}
	double evaluate(UzemnaJednotka* uJ) override { return 100 * (static_cast<double>(KriteriumUJVekovaSkupinaPocet(vekovaSkupina_).evaluate(uJ)) / uJ->getVek()->getPocetObyvatelov()); }
	std::wstring toString() override { return L""; }
	virtual ~KriteriumUJVekovaSkupinaPodiel() {};
private:
	EVS vekovaSkupina_;
};