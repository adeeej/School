#pragma once
#include "structures/table/sorted_sequence_table.h"
#include "uzemna_jednotka.h"
#include "structures/list/array_list.h"
#include "obec.h"
#include "okres.h"
#include "kraj.h"
#include "stat.h"
#include "structures/common/heap_monitor.h"
#include<fstream>
#include<iostream>
#include <codecvt>

class DatabazaUzemnychCelkov
{
public:
	DatabazaUzemnychCelkov();
	~DatabazaUzemnychCelkov();
	void nacitajData(std::string nazovSuboru1, std::string nazovSuboru2);
	inline structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>* getObce() { return obce_; };
	inline structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>* getOkresy() { return okresy_; };
	inline structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>* getKraje() { return kraje_; };
	inline structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>* getStaty() { return staty_; };
	inline structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>* getUzemneJednotky() { return uzemneJednotky_; };
	void dajDoTabulkyPreUzemneCelky();
private:
	structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>* obce_;
	structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>* okresy_;
	structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>* kraje_;
	structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>* staty_;
	structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>* uzemneJednotky_;

	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>, wchar_t> utf16_conv;

	bool existuje(structures::Table<std::wstring, UzemnaJednotka*>* tabulka, std::wstring nazovUJ)
	{
		for (auto item : *tabulka)
		{
			//if (nazovUJ == (*item).accessData()->getNazovUJ())
			if (!nazovUJ.compare(item->accessData()->getNazovUJ()))
			{
				return true;
			}
		}
		return false;
	}
	Okres* najdiOkres(std::wstring nazovOkresu, Okres* okresy);
	Kraj* najdiKraj(std::wstring nazovKraja, Kraj* kraje);
	Stat* najdiStat(std::wstring nazovStatu, Stat* staty);
};

