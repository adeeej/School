#pragma once
#include "kriterium_uzemna_jednotka.h"

class KriteriumUJVekovaSkupinaPocet: public KriteriumUzemnaJednotka<int>
{
public:
	KriteriumUJVekovaSkupinaPocet(EVS vekovaSkupina) :
		vekovaSkupina_(vekovaSkupina)
	{
	}
	int evaluate(UzemnaJednotka* uJ) override { return uJ->getVek()->getPocetVekovaSkupina(vekovaSkupina_); }
	std::wstring toString() override { return L""; }
	virtual ~KriteriumUJVekovaSkupinaPocet() {};
private:
	EVS vekovaSkupina_;
};