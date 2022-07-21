#pragma once
#include "filter_s_intervalom.h"
#include "kriterium_uj_vek_podiel.h"

class FilterUJVekPodiel : public FilterSIntervalom<UzemnaJednotka*, double> {
public:
	FilterUJVekPodiel(double min, double max, int vek, Pohlavie pohlavie) :
		FilterSIntervalom(new KriteriumUJVekPodiel(pohlavie, vek), min, max)
	{
	}
	//double miesto int do podielov
};
