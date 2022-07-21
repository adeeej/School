#pragma once
#include "filter_s_intervalom.h"
#include "kriterium_uj_vek_pocet.h"

class FilterUJVekPocet : public FilterSIntervalom<UzemnaJednotka*, int> {
public:
	FilterUJVekPocet(int min, int max, int vek, Pohlavie pohlavie) :
		FilterSIntervalom(new KriteriumUJVekPocet(pohlavie, vek), min, max)
	{
	}
};