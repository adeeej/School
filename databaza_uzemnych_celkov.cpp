#include "databaza_uzemnych_celkov.h"
#include <string>
#include <fstream>
#include <cstdlib>

DatabazaUzemnychCelkov::DatabazaUzemnychCelkov() :
	obce_(new structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>()),
	okresy_(new structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>()),
	kraje_(new structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>()),
	staty_(new structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>()),
	uzemneJednotky_(new structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>())
{
}

DatabazaUzemnychCelkov::~DatabazaUzemnychCelkov()
{
	/*for (auto item : *obce_) {
		delete item->accessData();
	}

	for (auto item : *okresy_) {
		delete item->accessData();
	}

	for (auto item : *kraje_) {
		delete item->accessData();
	}

	for (auto item : *staty_) {
		delete item->accessData();
	}*/

	for (auto item : *uzemneJednotky_)
	{
		delete item->accessData();
	}

	delete obce_;
	obce_ = nullptr;
	delete okresy_;
	okresy_ = nullptr;
	delete kraje_;
	kraje_ = nullptr;
	delete staty_;
	staty_ = nullptr;
	delete uzemneJednotky_;
	uzemneJednotky_ = nullptr;
}

void DatabazaUzemnychCelkov::nacitajData(std::string nazovSuboru1, std::string nazovSuboru2)
{
	std::wstring nazovObce;
	std::wstring nazovOkresu;
	std::wstring nazovKraja;

	std::wstring neukoncene;
	std::wstring zaklad;
	std::wstring bezMaturity;
	std::wstring sMaturitou;
	std::wstring vyssieOdborne;
	std::wstring vysokoskolske;
	std::wstring bezVzdelania;
	std::wstring nezistene;

	std::wstring pocetVek;

	UzemnaJednotka* obceUJ = nullptr;

	structures::ArrayList<int>* vekPocetMuzi = new structures::ArrayList<int>();
	structures::ArrayList<int>* vekPocetZeny = new structures::ArrayList<int>();

	// Create an input filestream
	std::wifstream subor1(nazovSuboru1);
	std::wifstream subor2(nazovSuboru2);

	// Make sure the file is open
	if (!subor1.is_open()) throw std::runtime_error("Could not open file1");
	if (!subor2.is_open()) throw std::runtime_error("Could not open file2");

	//treba preskocit prvy riadok
	//std::string preskocRiadok;
	std::wstring preskocRiadok;
	std::getline(subor1, preskocRiadok);
	std::getline(subor2, preskocRiadok);

	int i = 0;
	while (subor1.good() && subor2.good())
	{
		Okres* okresy = nullptr;
		Kraj* kraje = nullptr;
		Stat* staty = nullptr;

		getline(subor1, nazovObce, L';');
		getline(subor1, nazovOkresu, L';');
		getline(subor1, nazovKraja);

		if (!subor1.good() || !subor2.good())
			break;

		//if (!existuje(staty_, L"Slovensko"))
		//{
		//	staty = new Stat(L"Slovensko");
		//	staty_->insert(L"Slovensko", staty);
		//	//uzemneJednotky_->insert(L"Slovensko", staty);
		//}
		//else
		//{
		//	staty = najdiStat(L"Slovensko", staty);
		//}

		if (!staty_->containsKey(L"Slovensko"))
		{
			staty = new Stat(L"Slovensko");
			staty_->insert(L"Slovensko", staty);
			//uzemneJednotky_->insert(L"Slovensko", staty);
		}
		else
		{
			staty = najdiStat(L"Slovensko", staty);
		}

		//if (!existuje(kraje_, nazovKraja))
		//{
		//	kraje = new Kraj(nazovKraja, staty);
		//	kraje_->insert(nazovKraja, kraje);
		//	//uzemneJednotky_->insert(nazovKraja, kraje);
		//}
		//else
		//{
		//	kraje = najdiKraj(nazovKraja, kraje);
		//}

		if (!kraje_->containsKey(nazovKraja))
		{
			kraje = new Kraj(nazovKraja, staty);
			kraje_->insert(nazovKraja, kraje);
			//uzemneJednotky_->insert(nazovKraja, kraje);
		}
		else
		{
			kraje = najdiKraj(nazovKraja, kraje);
		}

		//if (!existuje(okresy_, nazovOkresu))
		//{
		//	okresy = new Okres(nazovOkresu, kraje, staty);
		//	okresy_->insert(nazovOkresu, okresy);
		//	//uzemneJednotky_->insert(nazovOkresu, okresy);
		//}
		//else
		//{
		//	okresy = najdiOkres(nazovOkresu, okresy);
		//}

		if (!okresy_->containsKey(nazovOkresu))
		{
			okresy = new Okres(nazovOkresu, kraje, staty);
			okresy_->insert(nazovOkresu, okresy);
			//uzemneJednotky_->insert(nazovOkresu, okresy);
		}
		else
		{
			okresy = najdiOkres(nazovOkresu, okresy);
		}

		if (obce_->containsKey(nazovObce))
		{
			throw std::logic_error("Nazov obce sa nachadza v tabulke!");
		}
		else
		{
			Obec* obce = new Obec(nazovObce, okresy, kraje, staty);
			obce_->insert(nazovObce, obce);
			//uzemneJednotky_->insert(nazovObce, obce);
			obceUJ = obce_->find(nazovObce);
		}

		std::getline(subor2, nazovObce, L';');
		std::getline(subor2, neukoncene, L';');
		std::getline(subor2, zaklad, L';');
		std::getline(subor2, bezMaturity, L';');
		std::getline(subor2, sMaturitou, L';');
		std::getline(subor2, vyssieOdborne, L';');
		std::getline(subor2, vysokoskolske, L';');
		std::getline(subor2, bezVzdelania, L';');
		std::getline(subor2, nezistene, L';');


		for (size_t i = 0; i < 101; i++)
		{
			std::getline(subor2, pocetVek, L';');
			vekPocetMuzi->add(std::stoi(pocetVek.c_str()));
		}

		for (size_t i = 0; i < 100; i++)
		{
			std::getline(subor2, pocetVek, L';');
			vekPocetZeny->add(std::stoi(pocetVek.c_str()));
		}
		std::getline(subor2, pocetVek);
		vekPocetZeny->add(std::stoi(pocetVek.c_str()));
		
		obceUJ->getVzdelanie()->setPocetNeukoncene(std::stoi(neukoncene.c_str()));
		obceUJ->getVzdelanie()->setPocetZaklad(std::stoi(zaklad.c_str()));
		obceUJ->getVzdelanie()->setPocetBezMaturity(std::stoi(bezMaturity.c_str()));
		obceUJ->getVzdelanie()->setPocetSMaturitou(std::stoi(sMaturitou.c_str()));
		obceUJ->getVzdelanie()->setPocetVyssieOdborne(std::stoi(vyssieOdborne.c_str()));
		obceUJ->getVzdelanie()->setPocetVysokoSkolske(std::stoi(vysokoskolske.c_str()));
		obceUJ->getVzdelanie()->setPocetBezVzdelania(std::stoi(bezVzdelania.c_str()));
		obceUJ->getVzdelanie()->setPocetNezistene(std::stoi(nezistene.c_str()));

		obceUJ->getVek()->setVekPocetMuzi(vekPocetMuzi);
		obceUJ->getVek()->setVekPocetZeny(vekPocetZeny);

		okresy->getVzdelanie()->setPocetNeukoncene(std::stoi(neukoncene.c_str()));
		okresy->getVzdelanie()->setPocetZaklad(std::stoi(zaklad.c_str()));
		okresy->getVzdelanie()->setPocetBezMaturity(std::stoi(bezMaturity.c_str()));
		okresy->getVzdelanie()->setPocetSMaturitou(std::stoi(sMaturitou.c_str()));
		okresy->getVzdelanie()->setPocetVyssieOdborne(std::stoi(vyssieOdborne.c_str()));
		okresy->getVzdelanie()->setPocetVysokoSkolske(std::stoi(vysokoskolske.c_str()));
		okresy->getVzdelanie()->setPocetBezVzdelania(std::stoi(bezVzdelania.c_str()));
		okresy->getVzdelanie()->setPocetNezistene(std::stoi(nezistene.c_str()));

		okresy->getVek()->setVekPocetMuzi(vekPocetMuzi);
		okresy->getVek()->setVekPocetZeny(vekPocetZeny);

		kraje->getVzdelanie()->setPocetNeukoncene(std::stoi(neukoncene.c_str()));
		kraje->getVzdelanie()->setPocetZaklad(std::stoi(zaklad.c_str()));
		kraje->getVzdelanie()->setPocetBezMaturity(std::stoi(bezMaturity.c_str()));
		kraje->getVzdelanie()->setPocetSMaturitou(std::stoi(sMaturitou.c_str()));
		kraje->getVzdelanie()->setPocetVyssieOdborne(std::stoi(vyssieOdborne.c_str()));
		kraje->getVzdelanie()->setPocetVysokoSkolske(std::stoi(vysokoskolske.c_str()));
		kraje->getVzdelanie()->setPocetBezVzdelania(std::stoi(bezVzdelania.c_str()));
		kraje->getVzdelanie()->setPocetNezistene(std::stoi(nezistene.c_str()));

		kraje->getVek()->setVekPocetMuzi(vekPocetMuzi);
		kraje->getVek()->setVekPocetZeny(vekPocetZeny);

		staty->getVzdelanie()->setPocetNeukoncene(std::stoi(neukoncene.c_str()));
		staty->getVzdelanie()->setPocetZaklad(std::stoi(zaklad.c_str()));
		staty->getVzdelanie()->setPocetBezMaturity(std::stoi(bezMaturity.c_str()));
		staty->getVzdelanie()->setPocetSMaturitou(std::stoi(sMaturitou.c_str()));
		staty->getVzdelanie()->setPocetVyssieOdborne(std::stoi(vyssieOdborne.c_str()));
		staty->getVzdelanie()->setPocetVysokoSkolske(std::stoi(vysokoskolske.c_str()));
		staty->getVzdelanie()->setPocetBezVzdelania(std::stoi(bezVzdelania.c_str()));
		staty->getVzdelanie()->setPocetNezistene(std::stoi(nezistene.c_str()));

		staty->getVek()->setVekPocetMuzi(vekPocetMuzi);
		staty->getVek()->setVekPocetZeny(vekPocetZeny);

		vekPocetMuzi->clear();
		vekPocetZeny->clear();
	}

	subor1.close();
	subor2.close();
	delete vekPocetMuzi;
	vekPocetMuzi = nullptr;
	delete vekPocetZeny;
	vekPocetZeny = nullptr;
}

void DatabazaUzemnychCelkov::dajDoTabulkyPreUzemneCelky()
{
	for (auto item : *obce_)
	{
		uzemneJednotky_->insert(item->getKey(), item->accessData());
	}

	for (auto item : *okresy_)
	{
		uzemneJednotky_->insert(item->getKey(), item->accessData());
	}

	for (auto item : *kraje_)
	{
		uzemneJednotky_->insert(item->getKey(), item->accessData());
	}

	for (auto item : *staty_)
	{
		uzemneJednotky_->insert(item->getKey(), item->accessData());
	}
}

Okres* DatabazaUzemnychCelkov::najdiOkres(std::wstring nazovOkresu, Okres* okresy)
{
	for (auto item : *okresy_) {
		if (item->accessData()->getNazovUJ() == nazovOkresu) {
			return okresy = dynamic_cast<Okres*>(item->accessData());
		}
	}
}

Kraj* DatabazaUzemnychCelkov::najdiKraj(std::wstring nazovKraja, Kraj* kraje)
{
	for (auto item : *kraje_) {
		if (item->accessData()->getNazovUJ() == nazovKraja) {
			return kraje = dynamic_cast<Kraj*>(item->accessData());
		}
	}

	/*kraje = dynamic_cast<Kraj*>(kraje_->find(nazovKraja));
	return kraje;*/
}

Stat* DatabazaUzemnychCelkov::najdiStat(std::wstring nazovStatu, Stat* staty)
{
	for (auto item : *staty_) {
		if (item->accessData()->getNazovUJ() == nazovStatu) {
			return staty = dynamic_cast<Stat*>(item->accessData());
		}
	}
}
