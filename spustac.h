#pragma once
#include "databaza_uzemnych_celkov.h"
#include "structures/table/unsorted_sequence_table.h"
#include "structures/table/sorting/quick_sort.h"
#include "kriterium_uj_nazov.h"
#include "kriterium_uj_vzdelanie_pocet.h"
#include "filter_UJ_typ.h"
#include "kriterium_uj_vzdelanie_podiel.h"
#include "kriterium_uj_prislusnost.h"
#include "kriterium_uj_vek_podiel.h"
#include "kriterium_uj_vek_podiel.h"
#include "kriterium_uj_vekova_skupina_pocet.h"
#include "kriterium_uj_vekova_skupina_podiel.h"
#include "kriterium_uj_nadradena.h"
#include "filter_UJ_nazov.h"
#include "filter_UJ_vzdelanie_pocet.h"
#include "filter_UJ_vzdelanie_pocet.h"
#include "filter_UJ_vzdelanie_podiel.h"
#include "filter_UJ_vek_podiel.h"
#include "filter_UJ_vek_pocet.h"
#include "filter_UJ_prislusnost.h"
#include "filter_UJ_vekova_skupina_pocet.h"
#include "filter_UJ_vekova_skupina_podiel.h"
#include "kompozitny_filter.h"
#include "vyberove_kriterium_najmensia_vekova_skupina.h"
#include "vyberove_kriterium_najvacsia_vekova_skupina.h"


class Spustac
{
public:
	Spustac() {
		databaza_ = new DatabazaUzemnychCelkov();
		databaza_->nacitajData("uzemne_jednotky.csv", "vzdelanie_a_vek.csv");
		databaza_->dajDoTabulkyPreUzemneCelky();
		//tabulka_ = new structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>();
		utriedena_ = new structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>();
		tabulka_ = databaza_->getUzemneJednotky();
		minPocet_ = 0;
		maxPocet_ = 0;
		minPodiel_ = 0;
		maxPodiel_ = 0;
	}

	~Spustac() {
		delete databaza_;
		databaza_ = nullptr;

		//if (utriedena_ != nullptr)
		//{
		//	for (auto item : *utriedena_)
		//	{
		//		delete item->accessData();
		//	}
		//	/*delete utriedena_;
		//	utriedena_ = nullptr;*/
		//}
		
		
			/*for (auto item : *tabulka_)
			{
				delete item->accessData();
			}*/
			

		//delete tabulka_;
		delete utriedena_;
	}

	void obecVypis();
	void okresyVypis();
	void krajVypis();
	void nastavTypVzdelania(int vzdelanie);
	void vyberTypUJ(int typUJ);
	void vyberPohlavie(int pohlavie);
	void vyberVek(int vek);
	void nastavVekovuSkupinu(int vekovaSkupina);
	void bodoveVyhladavanie();
	void triedenie();
	void vyberNajlepsi();
	void spusti();
	void vytvorFilter();
	void vypisUzemychCelkovSDanymTypom();
	void vytvorVyberoveKriterium(int hodnota);
	void vyberTypUJPreTabulku(int hodnota);
	
	
private:
	structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>* tabulka_;
	structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* utriedena_;
	DatabazaUzemnychCelkov* databaza_;
	bool vzostupne_;
	TypVzdelania typVzdelania_;
	TypUzemnejJednotky typUJ_;
	TypUzemnejJednotky typUJPreTabulku_;
	Pohlavie pohlavie_;
	int vek_;
	EVS vekovaSkupina_;
	std::wstring nazovUJ_;
	int minPocet_;
	int maxPocet_;
	int minPodiel_;
	int maxPodiel_;
};

