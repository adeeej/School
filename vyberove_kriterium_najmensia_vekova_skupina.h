#pragma once
#include "vyberove_kriterium_min.h"
#include "uzemna_jednotka.h"
#include "kriterium_uj_vekova_skupina_pocet.h"

class VyberoveKriteriumNajmensiaVekovaSkupina : public VyberoveKriteriumMin<std::wstring, UzemnaJednotka*, int> {
public:
	VyberoveKriteriumNajmensiaVekovaSkupina(EVS evs)
		: VyberoveKriteriumMin<std::wstring, UzemnaJednotka*, int>(new KriteriumUJVekovaSkupinaPocet(evs))
	{
	}
	virtual ~VyberoveKriteriumNajmensiaVekovaSkupina() {};
};