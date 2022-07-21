#pragma once
#include "typ_uzemnej_jednotky.h"
#include "vek.h"
#include "vzdelanie.h"
#include "structures/common/heap_monitor.h"
#include <string>

class UzemnaJednotka {
public: 
	UzemnaJednotka(std::wstring nazov, UzemnaJednotka* patriOkresu, UzemnaJednotka* patriKraju, UzemnaJednotka* patriStatu);
	~UzemnaJednotka();
	inline std::wstring getNazovUJ() {
		return nazovUJ_;
	}
	bool patriDoVUC(UzemnaJednotka* uJ);
	TypUzemnejJednotky getTypUJ();
	UzemnaJednotka* getOkres();
	UzemnaJednotka* getKraj();
	UzemnaJednotka* getStat();
	virtual void setTypUJ() = 0;
	inline Vek* getVek() {
		return vek_;
	}
	inline Vzdelanie* getVzdelanie() {
		return vzdelanie_;
	}
	UzemnaJednotka* getNadradenaUJ();
	
	
private:
	std::wstring nazovUJ_;
	UzemnaJednotka* patriOkresu_;
	UzemnaJednotka* patriKraju_;
	UzemnaJednotka* patriStatu_;
	Vek* vek_;
	Vzdelanie* vzdelanie_;
protected:
	TypUzemnejJednotky typUJ_;
};

