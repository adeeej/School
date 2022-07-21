#pragma once
#include "uzemna_jednotka.h"
#include "structures/common/heap_monitor.h"

class Obec : public UzemnaJednotka
{
public:
	Obec(std::wstring nazov, UzemnaJednotka* nazovOkresu, UzemnaJednotka* nazovKraja, UzemnaJednotka* nazovStatu) :
		UzemnaJednotka(nazov, nazovOkresu, nazovKraja, nazovStatu)
	{
		setTypUJ();
	}
	void setTypUJ() override {
		typUJ_ = TypUzemnejJednotky::OBEC;
	}
	~Obec() {};
};
