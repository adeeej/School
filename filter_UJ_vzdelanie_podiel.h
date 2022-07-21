#pragma once
#include "filter_s_intervalom.h"
#include "kriterium_uj_vzdelanie_podiel.h"

class FilterUJVzdelaniePodiel : public FilterSIntervalom<UzemnaJednotka*, double> {
public:
	FilterUJVzdelaniePodiel(double min, double max, TypVzdelania vzdelanie) :
		FilterSIntervalom(new KriteriumUJVzdelaniePodiel(vzdelanie), min, max)
	{
	}
};