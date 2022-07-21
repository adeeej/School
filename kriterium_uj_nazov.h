#pragma once
#include "kriterium_uzemna_jednotka.h"

class KriteriumUJNazov : public KriteriumUzemnaJednotka<std::wstring>
{
public:
	KriteriumUJNazov() {  };
	std::wstring evaluate(UzemnaJednotka* uJ) override { return uJ->getNazovUJ(); }
	std::wstring toString() override { return L""; }
	virtual ~KriteriumUJNazov() {};
};