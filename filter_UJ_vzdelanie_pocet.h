#pragma once
#include "filter_s_intervalom.h"
#include "kriterium_uj_vzdelanie_pocet.h"

class FilterUJVzdelaniePocet : public FilterSIntervalom<UzemnaJednotka*, int> {
public:
	FilterUJVzdelaniePocet(int min, int max, TypVzdelania vzdelanie) :
		FilterSIntervalom(new KriteriumUJVzdelaniePocet(vzdelanie), min, max)
	{
	}
};
