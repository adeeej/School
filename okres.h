#pragma once
#include "uzemna_jednotka.h"
#include "structures/common/heap_monitor.h"

class Okres : public UzemnaJednotka
{
public:
	Okres(std::wstring nazov, UzemnaJednotka* nazovKraja, UzemnaJednotka* nazovStatu) : 
		UzemnaJednotka(nazov, nullptr, nazovKraja, nazovStatu)
	{ 
		setTypUJ();
	}
	void setTypUJ() override { 
		typUJ_ = TypUzemnejJednotky::OKRES; 
	}
	~Okres() {};
};