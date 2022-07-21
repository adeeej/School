#pragma once
#include "kriterium_uzemna_jednotka.h"

class KriteriumUJVzdelaniePocet : public KriteriumUzemnaJednotka<int>
{
public:
	KriteriumUJVzdelaniePocet(TypVzdelania vzdelanie) :
		typVzdelania_(vzdelanie)
	{
	}
	int evaluate(UzemnaJednotka* uJ) override { return uJ->getVzdelanie()->getPocetVzdelanie(typVzdelania_); }
	std::wstring toString() override { return typVzdelaniaToString(typVzdelania_); }
	virtual ~KriteriumUJVzdelaniePocet() {};
private:
	TypVzdelania typVzdelania_;
};