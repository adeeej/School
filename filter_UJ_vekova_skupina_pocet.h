#pragma once
#include "filter_s_intervalom.h"
#include "kriterium_uj_vekova_skupina_pocet.h"

class FilterUJVekovaSkupinaPocet : public FilterSIntervalom<UzemnaJednotka*, int> {
public:
	FilterUJVekovaSkupinaPocet(int min, int max, EVS skupina) :
		FilterSIntervalom(new KriteriumUJVekovaSkupinaPocet(skupina), min, max)
	{
	}
};
