#pragma once
#include "structures/list/array_list.h"
#include "ekonomicka_vekova_skupina.h"
#include "pohlavie.h"
#include "structures/common/heap_monitor.h"

class Vek {
public:
	Vek() {
		vekPocetMuzi_ = new structures::ArrayList<int>();
		for (size_t i = 0; i < 101; i++)
		{
			vekPocetMuzi_->add(0);
		}
		vekPocetZeny_ = new structures::ArrayList<int>();
		for (size_t i = 0; i < 101; i++)
		{
			vekPocetZeny_->add(0);
		}

		pocetObyvatelov_ = 0;
	}
	~Vek()
	{
		delete vekPocetMuzi_;
		vekPocetMuzi_ = nullptr;
		delete vekPocetZeny_;
		vekPocetZeny_ = nullptr;
	}

	inline int getPocetVek(int vek, Pohlavie pohlavie) {
		if (pohlavie == Pohlavie::MUZ)
		{
			return vekPocetMuzi_->at(vek);
		}
		else 
		{
			return vekPocetZeny_->at(vek);
		}
	}

	inline int getPocetVekovaSkupina(EVS skupina) {
		int sucet = 0;
		if (skupina == EVS::PREDPRODUKTIVNI)
		{
			for (size_t i = 0; i <= 14; i++)
			{
				sucet += vekPocetMuzi_->at(i) + vekPocetZeny_->at(i);
			}
		}
		else if (skupina == EVS::PRODUKTIVNI)
		{
			for (size_t i = 15; i <= 64; i++)
			{
				sucet += vekPocetMuzi_->at(i) + vekPocetZeny_->at(i);
			}
		}
		else
		{
			for (size_t i = 65; i <= 100; i++)
			{
				sucet += vekPocetMuzi_->at(i) + vekPocetZeny_->at(i);
			}
		}

		return sucet;
	}

	void setVekPocetMuzi(structures::ArrayList<int>* vekMuzi) {
		int data = 0;
		for (size_t i = 0; i < vekMuzi->size(); i++)
		{
			/*data = vekPocetMuzi_->removeAt(i);
			data = data + vekMuzi->at(i);
			vekPocetMuzi_->insert(data, i);*/
			data = vekMuzi->at(i);
			vekPocetMuzi_->at(i) += data;
		}

		
	}

	void setVekPocetZeny(structures::ArrayList<int>* vekZeny) {
		int data = 0;
		for (size_t i = 0; i < vekZeny->size(); i++)
		{
			/*data = vekPocetZeny_->removeAt(i);
			data = data + vekZeny->at(i);
			vekPocetZeny_->insert(data, i);*/
			data = vekZeny->at(i);
			vekPocetZeny_->at(i) += data;
		}
	}

	int getPocetObyvatelov() {
		int pocetObyvatelov = 0;
		for (size_t i = 0; i < vekPocetMuzi_->size(); i++)
		{
			pocetObyvatelov += vekPocetMuzi_->at(i) + vekPocetZeny_->at(i);
		}
		return pocetObyvatelov;
	}

private:
	/*int predproduktivniPocetMuzi_;
	int produktivniPocetMuzi_;
	int poproduktivniPocetMuzi_;
	int predproduktivniPocetZeny_;
	int produktivniPocetZeny_;
	int poproduktivniPocetZeny_;*/
	structures::ArrayList<int>* vekPocetMuzi_;
	structures::ArrayList<int>* vekPocetZeny_;
	int pocetObyvatelov_;

};