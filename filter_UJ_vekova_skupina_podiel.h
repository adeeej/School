#pragma once
#include "filter_s_intervalom.h"
#include "kriterium_uj_vekova_skupina_podiel.h"

class FilterUJVekovaSkupinaPodiel : public FilterSIntervalom<UzemnaJednotka*, double> {
public:
	FilterUJVekovaSkupinaPodiel(double min, double max, EVS skupina) :
		FilterSIntervalom(new KriteriumUJVekovaSkupinaPodiel(skupina), min, max)
	{
	}
};
