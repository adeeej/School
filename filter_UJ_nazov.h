#pragma once
#include "filter_s_hodnotou.h"
#include "kriterium_uj_nazov.h"

class FilterUJNazov : public FilterSHodnotou<UzemnaJednotka*, std::wstring> {
public:
	FilterUJNazov(std::wstring nazov) : 
		FilterSHodnotou(new KriteriumUJNazov(), nazov)
	{
	}
};