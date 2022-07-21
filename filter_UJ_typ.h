#pragma once
#include "filter_s_hodnotou.h"
#include "kriterium_uj_typ.h"

class FilterUJTyp : public FilterSHodnotou<UzemnaJednotka*, TypUzemnejJednotky> {
public:
	FilterUJTyp(TypUzemnejJednotky typUJ) :
		FilterSHodnotou(new KriteriumUJTyp(), typUJ)
	{
	}
};