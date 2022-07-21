#pragma once
#include "Kriterium.h"
#include "uzemna_jednotka.h"

template<typename ResultType>
class KriteriumUzemnaJednotka : public Kriterium<UzemnaJednotka*, ResultType>
{
public:
	virtual ~KriteriumUzemnaJednotka() {};
};