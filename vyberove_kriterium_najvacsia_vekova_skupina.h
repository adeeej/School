#pragma once
#include "vyberove_kriterium_max.h"
#include "uzemna_jednotka.h"
#include "kriterium_uj_vekova_skupina_pocet.h"

class VyberoveKriteriumNajvacsiaVekovaSkupina : public VyberoveKriteriumMax<std::wstring, UzemnaJednotka*, int> {
public:
	VyberoveKriteriumNajvacsiaVekovaSkupina(EVS evs)
		: VyberoveKriteriumMax<std::wstring, UzemnaJednotka*, int>(new KriteriumUJVekovaSkupinaPocet(evs))
	{
	}
	virtual ~VyberoveKriteriumNajvacsiaVekovaSkupina() {};
};