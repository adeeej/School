#pragma once

#pragma once
#include "kriterium_uzemna_jednotka.h"

class KriteriumUJTyp : public KriteriumUzemnaJednotka<TypUzemnejJednotky>
{
public:
	KriteriumUJTyp() {};
	TypUzemnejJednotky evaluate(UzemnaJednotka* uJ) override { return uJ->getTypUJ(); }
	std::wstring toString() override { return L""; }
	virtual ~KriteriumUJTyp() {};
};