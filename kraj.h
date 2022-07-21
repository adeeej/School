#pragma once
#include "uzemna_jednotka.h"
#include "structures/common/heap_monitor.h"

class Kraj : public UzemnaJednotka
{
public:
	Kraj(std::wstring nazov, UzemnaJednotka* nazovStatu) :
		UzemnaJednotka(nazov, nullptr, nullptr, nazovStatu)
	{
		setTypUJ();
	}
	void setTypUJ() override {
		typUJ_ = TypUzemnejJednotky::KRAJ;
	}
	~Kraj() {};
};
