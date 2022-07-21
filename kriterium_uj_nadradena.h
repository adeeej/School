#pragma once
#include "kriterium_uzemna_jednotka.h"

class KriteriumUJNadradena : public KriteriumUzemnaJednotka<UzemnaJednotka*>
{
public:
	KriteriumUJNadradena() {};
	UzemnaJednotka* evaluate(UzemnaJednotka* uJ) override { return uJ->getNadradenaUJ(); }
	std::wstring toString() override { return L""; }
	virtual ~KriteriumUJNadradena() {};
};