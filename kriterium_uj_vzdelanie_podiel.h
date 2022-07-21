#pragma once
#include "kriterium_uzemna_jednotka.h"
#include "kriterium_uj_vzdelanie_pocet.h"

class KriteriumUJVzdelaniePodiel : public KriteriumUzemnaJednotka<double>
{
public:
	KriteriumUJVzdelaniePodiel(TypVzdelania vzdelanie) :
		typVzdelania_(vzdelanie)
	{
	}
	double evaluate(UzemnaJednotka* uJ) override { return 100 * static_cast<double>(KriteriumUJVzdelaniePocet(typVzdelania_).evaluate(uJ)) / (uJ->getVek()->getPocetObyvatelov()); }
	std::wstring toString() override { return L""; }
	virtual ~KriteriumUJVzdelaniePodiel() {};
private:
	TypVzdelania typVzdelania_;
};