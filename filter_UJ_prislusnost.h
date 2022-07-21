#pragma once
#include "filter_s_hodnotou.h"
#include "kriterium_uj_prislusnost.h"

class FilterUJPrislusnost : public FilterSHodnotou<UzemnaJednotka*, bool> {
public:
	FilterUJPrislusnost(UzemnaJednotka* vuc) :
		FilterSHodnotou(new KriteriumUJPrislusnost(vuc), true)
	{
	}
};