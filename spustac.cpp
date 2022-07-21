#include "spustac.h"
#include "uzemna_jednotka.h"

void Spustac::obecVypis()
{
	structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>* tabulkaObce = databaza_->getObce();
	std::wstring nazov;
	int pocet = 0;

	for (auto item : *tabulkaObce)
	{
		nazov = item->accessData()->getNazovUJ();
		std::wcout << nazov << "\t";
		nazov = typUzemnejJednotkyToString(TypUzemnejJednotky::OBEC);
		std::wcout << nazov << "\t";
		pocet = item->accessData()->getVzdelanie()->getPocetVzdelanie(this->typVzdelania_);
		std::cout << pocet << "\t";
		pocet = item->accessData()->getVek()->getPocetVekovaSkupina(this->vekovaSkupina_);
		std::cout << pocet << "\t";
		UzemnaJednotka* jednotka = item->accessData()->getNadradenaUJ();
		while (jednotka != nullptr)
		{
			nazov = jednotka->getNazovUJ();
			std::wcout << nazov << "\t";
			nazov = typUzemnejJednotkyToString(jednotka->getTypUJ());
			std::wcout << nazov << "\t";
			jednotka = jednotka->getNadradenaUJ();
		}
		std::cout << pocet << "\n";
	}
}

void Spustac::okresyVypis()
{
	structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>* tabulkaOkresy = databaza_->getOkresy();
	std::wstring nazov;
	int pocet = 0;

	for (auto item : *tabulkaOkresy)
	{
		nazov = item->accessData()->getNazovUJ();
		std::wcout << nazov << "\t";
		nazov = typUzemnejJednotkyToString(TypUzemnejJednotky::OKRES);
		std::wcout << nazov << "\t";
		pocet = item->accessData()->getVzdelanie()->getPocetVzdelanie(this->typVzdelania_);
		std::cout << pocet << "\t";
		pocet = item->accessData()->getVek()->getPocetVekovaSkupina(this->vekovaSkupina_);
		std::cout << pocet << "\t";
		UzemnaJednotka* jednotka = item->accessData()->getNadradenaUJ();
		while (jednotka != nullptr)
		{
			nazov = jednotka->getNazovUJ();
			std::wcout << nazov << "\t";
			nazov = typUzemnejJednotkyToString(jednotka->getTypUJ());
			std::wcout << nazov << "\t";
			jednotka = jednotka->getNadradenaUJ();
		}
		std::cout << pocet << "\n";
	}
}

void Spustac::krajVypis()
{
	structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>* tabulkaKraje = databaza_->getKraje();
	std::wstring nazov;
	int pocet;

	for (auto item : *tabulkaKraje)
	{
		nazov = item->accessData()->getNazovUJ();
		std::wcout << nazov << "\t";
		nazov = typUzemnejJednotkyToString(TypUzemnejJednotky::KRAJ);
		std::wcout << nazov << "\t";
		pocet = item->accessData()->getVzdelanie()->getPocetVzdelanie(this->typVzdelania_);
		std::cout << pocet << "\t";
		pocet = item->accessData()->getVek()->getPocetVekovaSkupina(this->vekovaSkupina_);
		std::cout << pocet << "\t";
		UzemnaJednotka* jednotka = item->accessData()->getNadradenaUJ();
		while (jednotka != nullptr)
		{
			nazov = jednotka->getNazovUJ();
			std::wcout << nazov << "\t";
			nazov = typUzemnejJednotkyToString(jednotka->getTypUJ());
			std::wcout << nazov << "\t";
			jednotka = jednotka->getNadradenaUJ();
		}
		std::cout << pocet << "\n";
	}
}

void Spustac::nastavTypVzdelania(int vzdelanie)
{
	if (vzdelanie == 1)
	{
		typVzdelania_ = TypVzdelania::NEUKONCENE;
	}
	else if (vzdelanie == 2)
	{
		typVzdelania_ = TypVzdelania::ZAKLAD;
	}
	else if (vzdelanie == 3)
	{
		typVzdelania_ = TypVzdelania::BEZ_MATURITY;
	}
	else if (vzdelanie == 4)
	{
		typVzdelania_ = TypVzdelania::S_MATURITOU;
	}
	else if (vzdelanie == 5)
	{
		typVzdelania_ = TypVzdelania::VYSSIE_ODBORNE;
	}
	else if (vzdelanie == 6)
	{
		typVzdelania_ = TypVzdelania::VYSOKOSKOLSKE;
	}
	else if (vzdelanie == 7)
	{
		typVzdelania_ = TypVzdelania::BEZ_VZDELANIA;
	}
	else if (vzdelanie == 8)
	{
		typVzdelania_ = TypVzdelania::NEZISTENE;
	}
}

void Spustac::vyberTypUJ(int typUJ)
{
	if (typUJ == 1)
	{
		//obec
		//tabulka_ = databaza_->getObce();
		typUJ_ = TypUzemnejJednotky::OBEC;
	}
	else if (typUJ == 2)
	{
		//okres
		//tabulka_ = databaza_->getOkresy();
		typUJ_ = TypUzemnejJednotky::OKRES;
	}
	else if (typUJ == 3)
	{
		//kraje
		//tabulka_ = databaza_->getKraje();
		typUJ_ = TypUzemnejJednotky::KRAJ;
	}
	else if (typUJ == 4)
	{
		//staty
		//tabulka_ = databaza_->getStaty();
		typUJ_ = TypUzemnejJednotky::STAT;
	}
}

void Spustac::vyberPohlavie(int pohlavie)
{
	if (pohlavie == 1)
	{
		pohlavie_ = Pohlavie::MUZ;
	}
	else if (pohlavie == 2)
	{
		pohlavie_ = Pohlavie::ZENA;
	}
}

void Spustac::vyberVek(int vek)
{
	vek_ = vek;
}

void Spustac::nastavVekovuSkupinu(int vekovaSkupina)
{
	if (vekovaSkupina == 1)
	{
		vekovaSkupina_ = EVS::PREDPRODUKTIVNI;
	}
	else if (vekovaSkupina == 2)
	{
		vekovaSkupina_ = EVS::PRODUKTIVNI;
	}
	else if (vekovaSkupina == 3)
	{
		vekovaSkupina_ = EVS::POPRODUKTIVNI;
	}
}

void Spustac::bodoveVyhladavanie()
{
	int pocetVzdelanie = 0;
	int pocetVekovaSkupina = 0;
	int moznost = 0;
	std::wstring nazov;
	std::cout << "Zvolte nazov uzemnej jednotky: " << "\n";
	std::cout << "Vstup: ";
	std::getline(std::wcin >> std::ws, nazov);
	UzemnaJednotka* jednotka = tabulka_->find(nazov);
	std::cout << "Zvolte typ vzdelania: " << "\n";
	std::cout << "1. NEUKONCENE" << "\n";
	std::cout << "2. ZAKLADNE" << "\n";
	std::cout << "3. BEZ MATURITY" << "\n";
	std::cout << "4. S MATURITOU" << "\n";
	std::cout << "5. VYSSIE ODBORNE" << "\n";
	std::cout << "6. VYSOKO SKOLSKE" << "\n";
	std::cout << "7. BEZ VZDELANIA" << "\n";
	std::cout << "8. NEZISTENE" << "\n";
	std::cout << "Vstup: ";
	std::cin >> moznost;
	nastavTypVzdelania(moznost);
	pocetVzdelanie = jednotka->getVzdelanie()->getPocetVzdelanie(this->typVzdelania_);
	std::cout << "Zvolte vekovu skupinu: " << "\n";
	std::cout << "1. PREDPRODUKTIVNI" << "\n";
	std::cout << "2. PRODUKTIVNI" << "\n";
	std::cout << "3. POPRODUKTIVNI" << "\n";
	std::cout << "Vstup: ";
	std::cin >> moznost;
	nastavVekovuSkupinu(moznost);
	pocetVekovaSkupina = jednotka->getVek()->getPocetVekovaSkupina(this->vekovaSkupina_);
	nazov = jednotka->getNazovUJ();
	std::wcout << nazov << "\t";
	nazov = typUzemnejJednotkyToString(jednotka->getTypUJ());
	std::wcout << nazov << "\t";
	nazov = typVzdelaniaToString(this->typVzdelania_);
	std::wcout << nazov << ":\t";
	std::cout << pocetVzdelanie << "\t";
	nazov = typEkonomickejVekovejSkupinyToString(this->vekovaSkupina_);
	std::wcout << nazov << ":\t";
	std::cout << pocetVekovaSkupina << "\t";
	jednotka = jednotka->getNadradenaUJ();
	while (jednotka != nullptr)
	{
		nazov = jednotka->getNazovUJ();
		std::wcout << nazov << "\t";
		nazov = typUzemnejJednotkyToString(jednotka->getTypUJ());
		std::wcout << nazov << "\t";
		jednotka = jednotka->getNadradenaUJ();
	}
}

void Spustac::triedenie()
{
	KompozitnyFilter<UzemnaJednotka*>* kompozitnyFilter = new KompozitnyFilter<UzemnaJednotka*>();

	FilterUJVzdelaniePocet* filterVzdelaniePocet = nullptr;
	FilterUJVzdelaniePodiel* filterVzdelaniePodiel = nullptr;
	FilterUJTyp* filterUJTyp = nullptr;
	FilterUJPrislusnost* filterPrislusnost = nullptr;
	FilterUJVekovaSkupinaPocet* filterVekovaSkupinaPocet = nullptr;
	FilterUJVekPodiel* filterVekPodiel = nullptr;
	FilterUJVekPocet* filterVekPocet = nullptr;
	FilterUJVekovaSkupinaPodiel* filterVekovaSkupinaPodiel = nullptr;

	KriteriumUJVekPodiel* kriteriumUJVekPodiel = nullptr;
	KriteriumUJVekovaSkupinaPocet* kriteriumUJVekovaSkupinaPocet = nullptr;
	KriteriumUJVzdelaniePocet* kriteriumUJVzdelaniePocet = nullptr;
	KriteriumUJVzdelaniePodiel* kriteriumUJVzdelaniePodiel = nullptr;
	KriteriumUJPrislusnost* kriteriumUJPrislusnost = nullptr;
	KriteriumUJTyp* kriteriumUJTyp = nullptr;
	KriteriumUJNazov* kriteriumUJNazov = nullptr;

	int moznostKriteria = 0;
	int moznost = 0;
	int vek = 0;
	int vekovaSkupina = 0;

	std::cout << "Vyberte si dane kriterium podla ktoreho chcete triedit:" << "\n";
	std::cout << "1. Triedenie podla nazvu" << "\n";
	std::cout << "2. Triedenie podla vzdelania pocet" << "\n";
	std::cout << "3. Triedenie podla vzdelania podiel" << "\n";
	std::cout << "4. Triedenie podla vek podiel" << "\n";
	std::cout << "5. Triedenie podla vekova skupina pocet" << "\n";
	std::cout << "Vstup: ";
	std::cin >> moznostKriteria;

	int krit = 0;
	krit = moznostKriteria;

	switch (moznostKriteria)
	{
	case 1:
		kriteriumUJNazov = new KriteriumUJNazov();
		break;
	case 2:
		//typ vzdelania
		std::cout << "\nVyberte si typ vzdelania:" << "\n";
		std::cout << "1. NEUKONCENE" << "\n";
		std::cout << "2. ZAKLADNE" << "\n";
		std::cout << "3. BEZ MATURITY" << "\n";
		std::cout << "4. S MATURITOU" << "\n";
		std::cout << "5. VYSSIE ODBORNE" << "\n";
		std::cout << "6. VYSOKO SKOLSKE" << "\n";
		std::cout << "7. BEZ VZDELANIA" << "\n";
		std::cout << "8. NEZISTENE" << "\n";
		std::cout << "Vstup: ";
		std::cin >> moznost;
		nastavTypVzdelania(moznost);
		kriteriumUJVzdelaniePocet = new KriteriumUJVzdelaniePocet(typVzdelania_);
		break;
	case 3:
		//vzdelanie podiel
		std::cout << "\nVyberte si typ vzdelania:" << "\n";
		std::cout << "1. NEUKONCENE" << "\n";
		std::cout << "2. ZAKLADNE" << "\n";
		std::cout << "3. BEZ MATURITY" << "\n";
		std::cout << "4. S MATURITOU" << "\n";
		std::cout << "5. VYSSIE ODBORNE" << "\n";
		std::cout << "6. VYSOKO SKOLSKE" << "\n";
		std::cout << "7. BEZ VZDELANIA" << "\n";
		std::cout << "8. NEZISTENE" << "\n";
		std::cout << "Vstup: ";
		std::cin >> moznost;
		nastavTypVzdelania(moznost);
		kriteriumUJVzdelaniePodiel = new KriteriumUJVzdelaniePodiel(typVzdelania_);
		break;
	case 4:
		std::cout << "\nZvolte vek: ";
		std::cin >> vek;
		vyberVek(vek);
		std::cout << "\nZvolte pohlavie: \n";
		std::cout << "1. MUZ" << "\n";
		std::cout << "2. ZENA" << "\n";
		std::cout << "Vstup: ";
		std::cin >> moznost;
		vyberPohlavie(moznost);
		kriteriumUJVekPodiel = new KriteriumUJVekPodiel(pohlavie_, vek_);
		break;
	case 5:
		std::cout << "\nVyber vekovej skupiny: " << "\n";
		std::cout << "1. Predproduktivni" << "\n";
		std::cout << "2. Produktivni" << "\n";
		std::cout << "3. Poproduktivni" << "\n";
		std::cout << "Vstup: ";
		std::cin >> vekovaSkupina;
		nastavVekovuSkupinu(vekovaSkupina);
		kriteriumUJVekovaSkupinaPocet = new KriteriumUJVekovaSkupinaPocet(vekovaSkupina_);
		break;
	default:
		break;
	}

	bool pokracuj = true;
	//int moznost = 0;
	std::wstring nazov;
	bool pouzityFilter = false;

	do
	{
		std::cout << "Pred triedenim mozete este pouzit tieto spolocne filtre:" << "\n";
		std::cout << "1. Filter uzemna jednotka typ" << "\n";
		std::cout << "2. Filter uzemna jednotka prislusnost" << "\n";
		std::cout << "3. Ziaden" << "\n";
		std::cout << "Vstup: ";
		std::cin >> moznost;

		

		switch (moznost)
		{
		case 1:
			if (filterUJTyp == nullptr)
			{
				std::cout << "\nZvolte typ uzemnej jednotky: " << "\n";
				std::cout << "1. OBEC" << "\n";
				std::cout << "2. OKRES" << "\n";
				std::cout << "3. KRAJ" << "\n";
				std::cout << "3. STAT" << "\n";
				std::cout << "Vstup: ";
				std::cin >> moznost;
				vyberTypUJ(moznost);
				filterUJTyp = new FilterUJTyp(typUJ_);
				kompozitnyFilter->zaregistrujFilter(filterUJTyp);
				pouzityFilter = true;
				//filterToString += L"Filter uzemna jednotka typ | Typ uzemnej jednotky :" + typUzemnejJednotkyToString(typUJ_) + L"\n";
			}
			else
			{
				std::cout << "\nFilter uzemna jednotka typ uz bol pridany do kompozitneho filtra\n ";
			}
			break;
		case 2:
			if (filterPrislusnost == nullptr)
			{
				std::cout << "\nZadajte nazov VUC: ";
				std::getline(std::wcin >> std::ws, nazov);
				std::cout << "\n";
				UzemnaJednotka* jednotka = tabulka_->find(nazov);
				filterPrislusnost = new FilterUJPrislusnost(jednotka);
				kompozitnyFilter->zaregistrujFilter(filterPrislusnost);
				pouzityFilter = true;
				//filterToString += L"Filter prislusnost | Nazov VUC :" + jednotka->getNazovUJ() + L"\n";
			}
			else
			{
				std::cout << "Filter prislusnost uz bol pridany do kompozitneho filtra\n ";
			}
			break;
		case 3:
			pokracuj = false;
			break;
		default:
			break;
		}
	} while (pokracuj);


	int filter = 0;
	std::cout << "Chces este dany filter ku vybranemu kriteriu?" << "\n";
	std::cout << "ANO = 1" << "\n";
	std::cout << "NIE = 2" << "\n";
	std::cout << "Vstup: ";
	std::cin >> filter;

	
	int moznost1 = 0;
	int minPocet = 0;
	int maxPocet = 0;
	double minPodiel = 0;
	double maxPodiel = 0;

	if (filter == 1) {
			switch (krit)
			{
			case 1:
				//nic
				break;
			case 2:
				//filter vzdelanie pocet
				std::cout << "Zvolte MIN pocet: ";
				std::cin >> minPocet;
				std::cout << "\nZvolte MAX pocet: ";
				std::cin >> maxPocet;
				filterVzdelaniePocet = new FilterUJVzdelaniePocet(minPocet, maxPocet, typVzdelania_);
				kompozitnyFilter->zaregistrujFilter(filterVzdelaniePocet);
				pouzityFilter = true;
				//filterToString += L"Filter vzdelanie pocet | MIN: " + std::to_wstring(minPocet) + L" MAX: " + std::to_wstring(maxPocet) + L"  | Typ vzdelania :" + typVzdelaniaToString(typVzdelania_) + L"\n";
				break;
			case 3:
				//filter vzdelanie podiel
				std::cout << "Zvolte MIN podiel: ";
				std::cin >> minPodiel;
				std::cout << "\nZvolte MAX podiel: ";
				std::cin >> maxPodiel;
				filterVzdelaniePodiel = new FilterUJVzdelaniePodiel(minPodiel, maxPodiel, typVzdelania_);
				kompozitnyFilter->zaregistrujFilter(filterVzdelaniePodiel);
				pouzityFilter = true;
				//filterToString += L"Filter vzdelanie podiel | MIN: " + std::to_wstring(minPodiel) + L" MAX: " + std::to_wstring(maxPodiel) + L"  | Typ vzdelania :" + typVzdelaniaToString(typVzdelania_) + L"\n";
				break;
			case 4:
				//filter vek podiel
				std::cout << "Zvolte MIN podiel: ";
				std::cin >> minPodiel;
				std::cout << "\nZvolte MAX podiel: ";
				std::cin >> maxPodiel;
				filterVekPodiel = new FilterUJVekPodiel(minPodiel, maxPodiel, vek_, pohlavie_);
				kompozitnyFilter->zaregistrujFilter(filterVekPodiel);
				pouzityFilter = true;
				//filterToString += L"Filter vek podiel | MIN: " + std::to_wstring(minPodiel) + L" MAX: " + std::to_wstring(maxPodiel) + L"  | Vek:" + std::to_wstring(vek_) + L"Pohlavie: " + pohlavieToString(pohlavie_) + L"\n";
				break;
			case 5:
				//filter vekova skupina pocet
				std::cout << "Zvolte MIN pocet: ";
				std::cin >> minPocet;
				std::cout << "\nZvolte MAX pocet: ";
				std::cin >> maxPocet;
				filterVekovaSkupinaPocet = new FilterUJVekovaSkupinaPocet(minPocet, maxPocet, vekovaSkupina_);
				kompozitnyFilter->zaregistrujFilter(filterVekovaSkupinaPocet);
				pouzityFilter = true;
				//filterToString += L"Filter vekova skupina pocet| MIN: " + std::to_wstring(minPocet) + L" MAX: " + std::to_wstring(maxPocet) + typEkonomickejVekovejSkupinyToString(vekovaSkupina_) + L"\n";
				break;
			default:
				break;
			}
	}

	std::cout << "\n";
	utriedena_->clear();

	if (pouzityFilter == true) {
		for (auto item : *tabulka_)
		{
			if (kompozitnyFilter->pass(item->accessData()))
			{
				utriedena_->insert(item->getKey(), item->accessData());
			}
		}
	}
	else if (pouzityFilter == false)
	{
		for (auto item : *tabulka_)
		{
			utriedena_->insert(item->getKey(), item->accessData());
		}
	}
	
	std::cout << "Zvolte smer triedenia: ";
	std::cout << "1. Vzostupne ";
	std::cout << "2. Zostuupne ";
	std::cout << "Vstup: ";
	std::cin >> moznost1;


	if (moznost1 == 1) {
		//vzostupne
		if (moznostKriteria == 1)
		{
			structures::QuickSort<std::wstring, UzemnaJednotka*, std::wstring>* sortovanie = new structures::QuickSort<std::wstring, UzemnaJednotka*, std::wstring>(kriteriumUJNazov);
			sortovanie->sort(*utriedena_, true);
			delete sortovanie;
			sortovanie = nullptr;
		}

		if (moznostKriteria == 2)
		{
			structures::QuickSort<std::wstring, UzemnaJednotka*, int>* sortovanie = new structures::QuickSort<std::wstring, UzemnaJednotka*, int>(kriteriumUJVzdelaniePocet);
			sortovanie->sort(*utriedena_, true);
			delete sortovanie;
			sortovanie = nullptr;
		}

		if (moznostKriteria == 3)
		{
			structures::QuickSort<std::wstring, UzemnaJednotka*, double>* sortovanie = new structures::QuickSort<std::wstring, UzemnaJednotka*, double>(kriteriumUJVzdelaniePodiel);
			sortovanie->sort(*utriedena_, true);
			delete sortovanie;
			sortovanie = nullptr;
		}

		if (moznostKriteria == 4)
		{
			structures::QuickSort<std::wstring, UzemnaJednotka*, double>* sortovanie = new structures::QuickSort<std::wstring, UzemnaJednotka*, double>(kriteriumUJVekPodiel);
			sortovanie->sort(*utriedena_, true);
			delete sortovanie;
			sortovanie = nullptr;
		}

		if (moznostKriteria == 5)
		{
			structures::QuickSort<std::wstring, UzemnaJednotka*, int>* sortovanie = new structures::QuickSort<std::wstring, UzemnaJednotka*, int>(kriteriumUJVekovaSkupinaPocet);
			sortovanie->sort(*utriedena_, true);
			delete sortovanie;
			sortovanie = nullptr;
		}
		
	}
	else if (moznost1 == 2)
	{
		//zostupne
		if (moznostKriteria == 1)
		{
			structures::QuickSort<std::wstring, UzemnaJednotka*, std::wstring>* sortovanie = new structures::QuickSort<std::wstring, UzemnaJednotka*, std::wstring>(kriteriumUJNazov);
			sortovanie->sort(*utriedena_, false);
			delete sortovanie;
			sortovanie = nullptr;
		}

		if (moznostKriteria == 2)
		{
			structures::QuickSort<std::wstring, UzemnaJednotka*, int>* sortovanie = new structures::QuickSort<std::wstring, UzemnaJednotka*, int>(kriteriumUJVzdelaniePocet);
			sortovanie->sort(*utriedena_, false);
			delete sortovanie;
			sortovanie = nullptr;
		}

		if (moznostKriteria == 3)
		{
			structures::QuickSort<std::wstring, UzemnaJednotka*, double>* sortovanie = new structures::QuickSort<std::wstring, UzemnaJednotka*, double>(kriteriumUJVzdelaniePodiel);
			sortovanie->sort(*utriedena_, false);
			delete sortovanie;
			sortovanie = nullptr;
		}

		if (moznostKriteria == 4)
		{
			structures::QuickSort<std::wstring, UzemnaJednotka*, double>* sortovanie = new structures::QuickSort<std::wstring, UzemnaJednotka*, double>(kriteriumUJVekPodiel);
			sortovanie->sort(*utriedena_, false);
			delete sortovanie;
			sortovanie = nullptr;
		}

		if (moznostKriteria == 5)
		{
			structures::QuickSort<std::wstring, UzemnaJednotka*, int>* sortovanie = new structures::QuickSort<std::wstring, UzemnaJednotka*, int>(kriteriumUJVekovaSkupinaPocet);
			sortovanie->sort(*utriedena_, false);
			delete sortovanie;
			sortovanie = nullptr;
		}
	}

	std::cout << "\n";

	for (auto item : *utriedena_)
	{
		nazov = item->accessData()->getNazovUJ();
		std::wcout << nazov << "\t";

		if (kriteriumUJVzdelaniePocet != nullptr)
		{
			std::wcout << L"Vzdelanie pocet: " + std::to_wstring(kriteriumUJVzdelaniePocet->evaluate(item->accessData())) << L"\t";
		}

		if (kriteriumUJVzdelaniePodiel != nullptr)
		{
			std::wcout << L"Vzdelanie podiel: " + std::to_wstring(kriteriumUJVzdelaniePodiel->evaluate(item->accessData())) << L"\t";
		}

		if (kriteriumUJVekPodiel != nullptr)
		{
			std::wcout << L"Vek podiel: " + std::to_wstring(kriteriumUJVekPodiel->evaluate(item->accessData())) << L"\t";
		}

		if (kriteriumUJVekovaSkupinaPocet != nullptr)
		{
			std::wcout << L"Vekova skupina pocet: " + std::to_wstring(kriteriumUJVekovaSkupinaPocet->evaluate(item->accessData())) << L"\t";
		}
		std::wcout << "\n";
	}

	delete kompozitnyFilter;

	if (filterVzdelaniePocet != nullptr) {
		delete filterVzdelaniePocet;
	}

	if (kriteriumUJVzdelaniePocet != nullptr)
	{
		delete kriteriumUJVzdelaniePocet;
	}

	if (filterVzdelaniePodiel != nullptr) {
		delete filterVzdelaniePodiel;
	}

	if (kriteriumUJVzdelaniePodiel != nullptr)
	{
		delete kriteriumUJVzdelaniePodiel;
	}

	if (filterUJTyp != nullptr) {
		delete filterUJTyp;
	}

	if (filterPrislusnost != nullptr) {
		delete filterPrislusnost;
	}

	if (filterVekPodiel != nullptr) {
		delete filterVekPodiel;
	}

	if (kriteriumUJVekPodiel != nullptr)
	{
		delete kriteriumUJVekPodiel;
	}

	if (filterVekovaSkupinaPocet != nullptr) {
		delete filterVekovaSkupinaPocet;
	}

	if (kriteriumUJVekovaSkupinaPocet != nullptr)
	{
		delete kriteriumUJVekovaSkupinaPocet;
	}

	if (kriteriumUJNazov != nullptr)
	{
		delete kriteriumUJNazov;
	}
}

void Spustac::vyberNajlepsi()
{
	int moznost = 0;
	int vekovaSkupina = 0;
	KompozitnyFilter<UzemnaJednotka*>* kompozitnyFilter = new KompozitnyFilter<UzemnaJednotka*>();
	FilterUJTyp* filterUJTyp = nullptr;
	FilterUJPrislusnost* filterUJPrislusnost = nullptr;
	VyberoveKriteriumNajmensiaVekovaSkupina* vyberKritNajmensiaVekovaSkupina = nullptr;
	VyberoveKriteriumNajvacsiaVekovaSkupina* vyberKritNajvacsiaVekovaSkupina = nullptr;

	std::cout << "Chcete pred vyberovym kriteriom aplikovat nejake filtre? [ANO = 1] [NIE = 2] " << "\n";
	std::cout << "Vstup: ";
	std::cin >> moznost;
	bool pokracuj = true;
	int moznostFiltra = 0;
	//bool pouzityFilter = false;

	if (moznost == 1)
	{
		//ideme este filtrovat
		do
		{
			std::cout << "1. Filter uzemna jednotka typ" << "\n";
			std::cout << "2. Filter uzemna jednotka prislusnost" << "\n";
			std::cout << "3. Pokracuj" << "\n";
			std::cout << "Vstup: ";
			std::cin >> moznostFiltra;
			std::wstring nazov;
			switch (moznostFiltra)
			{
			case 1:
				//filter typ
				if (filterUJTyp == nullptr)
				{
					std::cout << "Zvolte typ uzemnej jednotky: " << "\n";
					std::cout << "1. OBEC" << "\n";
					std::cout << "2. OKRES" << "\n";
					std::cout << "3. KRAJ" << "\n";
					std::cout << "4. STAT" << "\n";
					std::cin >> moznost;
					vyberTypUJ(moznost);
					filterUJTyp = new FilterUJTyp(typUJ_);
					kompozitnyFilter->zaregistrujFilter(filterUJTyp);
					//pouzityFilter = true;
					//kriteriumUJTyp = new KriteriumUJTyp();
					//filterToString += L"Filter uzemna jednotka typ | Typ uzemnej jednotky :" + typUzemnejJednotkyToString(typUJ_) + L"\n";
				}
				else
				{
					std::cout << "Filter UJ typ uz bol pridany do kompozitneho filtra\n ";
				}
				break;

			case 2:
				//filter prislusnost
				if (filterUJPrislusnost == nullptr)
				{
					std::cout << "Zadajte nazov VUC: ";
					std::getline(std::wcin >> std::ws, nazov);
					std::cout << "\n";
					UzemnaJednotka* jednotka = tabulka_->find(nazov);
					filterUJPrislusnost = new FilterUJPrislusnost(jednotka);
					kompozitnyFilter->zaregistrujFilter(filterUJPrislusnost);
					//pouzityFilter = true;
					//kriteriumUJPrislusnost = new KriteriumUJPrislusnost(jednotka);
					//filterToString += L"Filter prislusnost | Nazov VUC :" + jednotka->getNazovUJ() + L"\n";
				}
				else
				{
					std::cout << "Filter prislusnost uz bol pridany do kompozitneho filtra\n ";
				}
				break;
			case 3:
				pokracuj = false;
				break;
			default:
				break;
			}

		} while (pokracuj);
	}
	
		//pouzivatel si moze vybrat vyberove kriterium
		std::cout << "Vyberove kriterium: " << "\n";
		std::cout << "1. Najvacsia vekova skupina" << "\n";
		std::cout << "2. Najmensia vekova skupina" << "\n";
		std::cout << "Vstup: ";
		std::cin >> moznost;
		std::cout << "Vyber vekovej skupiny: " << "\n";
		std::cout << "1. Predproduktivni" << "\n";
		std::cout << "2. Produktivni" << "\n";
		std::cout << "3. Poproduktivni" << "\n";
		std::cout << "Vstup: ";
		std::cin >> vekovaSkupina;
		nastavVekovuSkupinu(vekovaSkupina);
		int pocet = 0;
		std::wstring nazov;
		utriedena_->clear();
		if (moznost == 1)
		{
			//najvacsia
			vyberKritNajvacsiaVekovaSkupina = new VyberoveKriteriumNajvacsiaVekovaSkupina(vekovaSkupina_);

			//if (pouzityFilter == true)
			//{
			for (auto item : *tabulka_)
			{
				if (kompozitnyFilter->pass(item->accessData()))
				{
					utriedena_->insert(item->getKey(), item->accessData());
				}
			}
				//}
				UzemnaJednotka*& jednotka = vyberKritNajvacsiaVekovaSkupina->vyberNajlepsi(utriedena_);
				std::wcout << jednotka->getNazovUJ() << "\t";
				nazov = typUzemnejJednotkyToString(jednotka->getTypUJ());
				std::wcout << nazov << "\t";
				pocet = jednotka->getVek()->getPocetVekovaSkupina(vekovaSkupina_);
				jednotka = jednotka->getNadradenaUJ();
				while (jednotka != nullptr)
				{
					nazov = jednotka->getNazovUJ();
					std::wcout << nazov << "\t";
					nazov = typUzemnejJednotkyToString(jednotka->getTypUJ());
					std::wcout << nazov << "\t";
					jednotka = jednotka->getNadradenaUJ();
				}
				std::wcout << L"Pocet:  " + std::to_wstring(pocet) << L"\n";
			/*}
			else if (pouzityFilter == false)
			{
				UzemnaJednotka*& jednotka = vyberKritNajvacsiaVekovaSkupina->vyberNajlepsi(tabulka_);
				std::wcout << jednotka->getNazovUJ() << "\t";
				nazov = typUzemnejJednotkyToString(jednotka->getTypUJ());
				std::wcout << nazov << "\t";
				pocet = jednotka->getVek()->getPocetVekovaSkupina(vekovaSkupina_);
				jednotka = jednotka->getNadradenaUJ();
				while (jednotka != nullptr)
				{
					nazov = jednotka->getNazovUJ();
					std::wcout << nazov << "\t";
					nazov = typUzemnejJednotkyToString(jednotka->getTypUJ());
					std::wcout << nazov << "\t";
					jednotka = jednotka->getNadradenaUJ();
				}
				std::wcout << L"Pocet:  " + std::to_wstring(pocet) << L"\n";
			}*/
		}
		else if (moznost == 2)
		{
			//najmensia
			vyberKritNajmensiaVekovaSkupina = new VyberoveKriteriumNajmensiaVekovaSkupina(vekovaSkupina_);

			//if (pouzityFilter == true)
			//{
			for (auto item : *tabulka_)
			{
				if (kompozitnyFilter->pass(item->accessData()))
				{
					utriedena_->insert(item->getKey(), item->accessData());
				}
			}
				//}

				UzemnaJednotka*& jednotka = vyberKritNajmensiaVekovaSkupina->vyberNajlepsi(utriedena_);
				std::wcout << jednotka->getNazovUJ() << "\t";
				nazov = typUzemnejJednotkyToString(jednotka->getTypUJ());
				std::wcout << nazov << "\t";
				pocet = jednotka->getVek()->getPocetVekovaSkupina(vekovaSkupina_);
				jednotka = jednotka->getNadradenaUJ();
				while (jednotka != nullptr)
				{
					nazov = jednotka->getNazovUJ();
					std::wcout << nazov << "\t";
					nazov = typUzemnejJednotkyToString(jednotka->getTypUJ());
					std::wcout << nazov << "\t";
					jednotka = jednotka->getNadradenaUJ();
				}
				std::wcout << L"Pocet:  " + std::to_wstring(pocet) << L"\n";
			/*}
			else if (pouzityFilter == false)
			{
				UzemnaJednotka*& jednotka = vyberKritNajmensiaVekovaSkupina->vyberNajlepsi(tabulka_);
				std::wcout << jednotka->getNazovUJ() << "\t";
				nazov = typUzemnejJednotkyToString(jednotka->getTypUJ());
				std::wcout << nazov << "\t";
				pocet = jednotka->getVek()->getPocetVekovaSkupina(vekovaSkupina_);
				jednotka = jednotka->getNadradenaUJ();
				while (jednotka != nullptr)
				{
					nazov = jednotka->getNazovUJ();
					std::wcout << nazov << "\t";
					nazov = typUzemnejJednotkyToString(jednotka->getTypUJ());
					std::wcout << nazov << "\t";
					jednotka = jednotka->getNadradenaUJ();
				}
				std::wcout << L"Pocet:  " + std::to_wstring(pocet) << L"\n";
			}*/
		}

		delete kompozitnyFilter;

		if (filterUJTyp != nullptr)
		{
			delete filterUJTyp;
		}

		if (filterUJPrislusnost != nullptr)
		{
			delete filterUJPrislusnost;
		}

		if (vyberKritNajmensiaVekovaSkupina != nullptr)
		{
			delete vyberKritNajmensiaVekovaSkupina;
		}

		if (vyberKritNajvacsiaVekovaSkupina != nullptr)
		{
			delete vyberKritNajvacsiaVekovaSkupina;
		}
}

void Spustac::spusti()
{
	int moznost = 0;
	bool zapni = true;
	while (zapni) {
		std::cout << "\n\n\n---------------------------Databaza uzemnych celkov----------------------------------" << "\n";
		std::cout << "Zvolte cislo akcie: " << "\n";
		std::cout << "1. Bodove vyhladavanie" << "\n";
		std::cout << "2. Filtrovanie" << "\n";
		std::cout << "3. Triedenie" << "\n";
		std::cout << "4. Vyber najlepsieho" << "\n";
		std::cout << "5. Vypis uzemnych celkov s danym typom" << "\n";
		std::cout << "6. Ukoncit aplikaciu" << "\n";
		std::cin >> moznost;
		switch (moznost)
		{
		case 1:
			bodoveVyhladavanie();
			break;
		case 2:
			//nazvy pre filtre
			vytvorFilter();
			break;
		case 3:
			triedenie();
			break;
		case 4:
			vyberNajlepsi();
			break;
		case 5:
			vypisUzemychCelkovSDanymTypom();
			break;
		case 6:
			zapni = false;
			break;
		}
	}
}

void Spustac::vytvorFilter()
{
	KompozitnyFilter<UzemnaJednotka*>* kompozitnyFilter = new KompozitnyFilter<UzemnaJednotka*>();
	
	FilterUJVzdelaniePocet* filterVzdelaniePocet = nullptr;
	FilterUJVzdelaniePodiel* filterVzdelaniePodiel = nullptr;
	FilterUJTyp* filterUJTyp = nullptr;
	FilterUJPrislusnost* filterPrislusnost = nullptr;
	FilterUJVekPocet* filterVekPocet = nullptr;
	FilterUJVekPodiel* filterVekPodiel = nullptr;
	FilterUJVekovaSkupinaPocet* filterVekovaSkupinaPocet = nullptr;
	FilterUJVekovaSkupinaPodiel* filterVekovaSkupinaPodiel = nullptr;

	KriteriumUJVekPocet* kriteriumUJVekPocet = nullptr;
	KriteriumUJVekPodiel* kriteriumUJVekPodiel = nullptr;
	KriteriumUJVekovaSkupinaPocet* kriteriumUJVekovaSkupinaPocet = nullptr;
	KriteriumUJVekovaSkupinaPodiel* kriteriumUJVekovaSkupinaPodiel = nullptr;
	KriteriumUJVzdelaniePocet* kriteriumUJVzdelaniePocet = nullptr;
	KriteriumUJVzdelaniePodiel* kriteriumUJVzdelaniePodiel = nullptr;

	std::wstring filterToString = L"";
	int moznost;

	int minPocet = 0;
	int maxPocet = 0;
	double minPodiel = 0;
	double maxPodiel = 0;
	std::wstring nazov;
	int vek = 0;

	bool pouzityFilter = false;

	bool pokracuj = true;
	do
	{
		std::cout << "1. Filter vzdelanie pocet" << "\n";
		std::cout << "2. Filter vzdelanie podiel" << "\n";
		std::cout << "3. Filter uzemna jednotka typ" << "\n";
		std::cout << "4. Filter uzemna jednotka prislusnost" << "\n";
		std::cout << "5. Filter vek pocet" << "\n";
		std::cout << "6. Filter vek podiel" << "\n";
		std::cout << "7. Filter vekova skupina pocet" << "\n";
		std::cout << "8. Filter vekova skupina podiel" << "\n";
		std::cout << "9. Hotovo" << "\n";
		std::cout << "Vstup: ";
		std::cin >> moznost;


		switch (moznost)
		{
		case 1:
			if (filterVzdelaniePocet == nullptr)
			{
				std::cout << "Zvolte MIN pocet: ";
				std::cin >> minPocet;
				std::cout << "\nZvolte MAX pocet: ";
				std::cin >> maxPocet;
				std::cout << "\nZvolte typ vzdelania: " << "\n";
				std::cout << "1. NEUKONCENE" << "\n";
				std::cout << "2. ZAKLADNE" << "\n";
				std::cout << "3. BEZ MATURITY" << "\n";
				std::cout << "4. S MATURITOU" << "\n";
				std::cout << "5. VYSSIE ODBORNE" << "\n";
				std::cout << "6. VYSOKO SKOLSKE" << "\n";
				std::cout << "7. BEZ VZDELANIA" << "\n";
				std::cout << "8. NEZISTENE" << "\n";
				std::cout << "Vstup: ";
				std::cin >> moznost;
				nastavTypVzdelania(moznost);
				filterVzdelaniePocet = new FilterUJVzdelaniePocet(minPocet, maxPocet, typVzdelania_);
				kompozitnyFilter->zaregistrujFilter(filterVzdelaniePocet);
				kriteriumUJVzdelaniePocet = new KriteriumUJVzdelaniePocet(typVzdelania_);
				pouzityFilter = true;
				filterToString += L"Filter vzdelanie pocet | MIN: "+ std::to_wstring(minPocet) + L" MAX: " + std::to_wstring(maxPocet) + L"  | Typ vzdelania :" + typVzdelaniaToString(typVzdelania_) + L"\n";
			}
			else
			{
				std::cout << "Filter vzdelanie pocet uz bol pridany do kompozitneho filtra\n ";
			}
			break;
		case 2:
			if (filterVzdelaniePodiel == nullptr)
			{
				std::cout << "Zvolte MIN podiel: ";
				std::cin >> minPodiel;
				std::cout << "\nZvolte MAX podiel: ";
				std::cin >> maxPodiel;
				std::cout << "\nZvolte typ vzdelania: " << "\n";
				std::cout << "1. NEUKONCENE" << "\n";
				std::cout << "2. ZAKLADNE" << "\n";
				std::cout << "3. BEZ MATURITY" << "\n";
				std::cout << "4. S MATURITOU" << "\n";
				std::cout << "5. VYSSIE ODBORNE" << "\n";
				std::cout << "6. VYSOKO SKOLSKE" << "\n";
				std::cout << "7. BEZ VZDELANIA" << "\n";
				std::cout << "8. NEZISTENE" << "\n";
				std::cout << "Vstup: ";
				std::cin >> moznost;
				nastavTypVzdelania(moznost);
				filterVzdelaniePodiel = new FilterUJVzdelaniePodiel(minPodiel, maxPodiel, typVzdelania_);
				kompozitnyFilter->zaregistrujFilter(filterVzdelaniePodiel);
				kriteriumUJVzdelaniePodiel = new KriteriumUJVzdelaniePodiel(typVzdelania_);
				pouzityFilter = true;
				filterToString += L"Filter vzdelanie podiel | MIN: " + std::to_wstring(minPodiel) + L" MAX: " + std::to_wstring(maxPodiel) + L"  | Typ vzdelania :" + typVzdelaniaToString(typVzdelania_) + L"\n";
			}
			else
			{
				std::cout << "Filter vzdelanie podiel uz bol pridany do kompozitneho filtra\n ";
			}
			break;
		case 3:
			if (filterUJTyp == nullptr)
			{
				std::cout << "Zvolte typ uzemnej jednotky: " << "\n";
				std::cout << "1. OBEC" << "\n";
				std::cout << "2. OKRES" << "\n";
				std::cout << "3. KRAJ" << "\n";
				std::cout << "3. STAT" << "\n";
				std::cin >> moznost;
				vyberTypUJ(moznost);
				filterUJTyp = new FilterUJTyp(typUJ_);
				kompozitnyFilter->zaregistrujFilter(filterUJTyp);
				pouzityFilter = true;
				filterToString += L"Filter uzemna jednotka typ | Typ uzemnej jednotky :" + typUzemnejJednotkyToString(typUJ_) + L"\n";
			}
			else
			{
				std::cout << "Filter uzemna jednotka typ uz bol pridany do kompozitneho filtra\n ";
			}
			break;
		case 4:
			if (filterPrislusnost == nullptr)
			{
				std::cout << "Zadajte nazov VUC: ";
				std::getline(std::wcin >> std::ws, nazov);
				std::cout << "\n";
				
					UzemnaJednotka* jednotka = tabulka_->find(nazov);
					filterPrislusnost = new FilterUJPrislusnost(jednotka);
					kompozitnyFilter->zaregistrujFilter(filterPrislusnost);
					pouzityFilter = true;
					filterToString += L"Filter prislusnost | Nazov VUC :" + jednotka->getNazovUJ() + L"\n";
			}
			else
			{
				std::cout << "Filter prislusnost uz bol pridany do kompozitneho filtra\n ";
			}
			break;
		case 5:
			std::cout << "Zvolte MIN pocet: ";
			std::cin >> minPocet;
			std::cout << "\nZvolte MAX pocet: ";
			std::cin >> maxPocet;
			std::cout << "\nZvolte vek: ";
			std::cin >> vek;
			vyberVek(vek);
			std::cout << "\nZvolte pohlavie: \n";
			std::cout << "1. MUZ" << "\n";
			std::cout << "2. ZENA" << "\n";
			std::cout << "Vstup: ";
			std::cin >> moznost;
			vyberPohlavie(moznost);
			filterVekPocet = new FilterUJVekPocet(minPocet, maxPocet, vek_, pohlavie_);
			kompozitnyFilter->zaregistrujFilter(filterVekPocet);
			kriteriumUJVekPocet = new KriteriumUJVekPocet(pohlavie_, vek_);
			pouzityFilter = true;
			filterToString += L"Filter vek pocet | MIN: " + std::to_wstring(minPocet) + L" MAX: " + std::to_wstring(maxPocet) + L"  | Vek:" + std::to_wstring(vek_) + L"Pohlavie: " + pohlavieToString(pohlavie_) + L"\n";
			break;
		case 6:
			std::cout << "Zvolte MIN podiel: ";
			std::cin >> minPodiel;
			std::cout << "\nZvolte MAX podiel: ";
			std::cin >> maxPodiel;
			std::cout << "\nZvolte vek: ";
			std::cin >> vek;
			std::cout << "\nZvolte pohlavie: \n";
			std::cout << "1. MUZ" << "\n";
			std::cout << "2. ZENA" << "\n";
			std::cout << "Vstup: ";
			std::cin >> moznost;
			vyberPohlavie(moznost);
			filterVekPodiel = new FilterUJVekPodiel(minPodiel, maxPodiel, vek_, pohlavie_);
			kompozitnyFilter->zaregistrujFilter(filterVekPodiel);
			kriteriumUJVekPodiel = new KriteriumUJVekPodiel(pohlavie_, vek_);
			pouzityFilter = true;
			filterToString += L"Filter vek podiel | MIN: " + std::to_wstring(minPodiel) + L" MAX: " + std::to_wstring(maxPodiel) + L"  | Vek:" + std::to_wstring(vek_) + L"Pohlavie: " + pohlavieToString(pohlavie_) + L"\n";
			break;
		case 7:
			std::cout << "Zvolte MIN pocet: ";
			std::cin >> minPocet;
			std::cout << "\nZvolte MAX pocet: ";
			std::cin >> maxPocet;
			std::cout << "\nZvolte vekovu skupinu: \n";
			std::cout << "1. PREDPRODUKTIVNI" << "\n";
			std::cout << "2. PRODUKTIVNI" << "\n";
			std::cout << "3. POPRODUKTIVNI" << "\n";
			std::cout << "Vstup: ";
			std::cin >> moznost;
			nastavVekovuSkupinu(moznost);
			filterVekovaSkupinaPocet = new FilterUJVekovaSkupinaPocet(minPocet, maxPocet, vekovaSkupina_);
			kompozitnyFilter->zaregistrujFilter(filterVekovaSkupinaPocet);
			kriteriumUJVekovaSkupinaPocet = new KriteriumUJVekovaSkupinaPocet(vekovaSkupina_);
			pouzityFilter = true;
			filterToString += L"Filter vekova skupina pocet| MIN: " + std::to_wstring(minPocet) + L" MAX: " + std::to_wstring(maxPocet) + typEkonomickejVekovejSkupinyToString(vekovaSkupina_) + L"\n";
			break;
		case 8:
			std::cout << "Zvolte MIN podiel: ";
			std::cin >> minPodiel;
			std::cout << "\nZvolte MAX podiel: ";
			std::cin >> maxPodiel;
			std::cout << "\nZvolte vekovu skupinu: \n";
			std::cout << "1. PREDPRODUKTIVNI" << "\n";
			std::cout << "2. PRODUKTIVNI" << "\n";
			std::cout << "3. POPRODUKTIVNI" << "\n";
			std::cout << "Vstup: ";
			std::cin >> moznost;
			nastavVekovuSkupinu(moznost);
			filterVekovaSkupinaPodiel = new FilterUJVekovaSkupinaPodiel(minPodiel, maxPodiel, vekovaSkupina_);
			kompozitnyFilter->zaregistrujFilter(filterVekovaSkupinaPodiel);
			kriteriumUJVekovaSkupinaPodiel = new KriteriumUJVekovaSkupinaPodiel(vekovaSkupina_);
			pouzityFilter = true;
			filterToString += L"Filter vekova skupina podiel| MIN: " + std::to_wstring(minPodiel) + L" MAX: " + std::to_wstring(maxPodiel) + typEkonomickejVekovejSkupinyToString(vekovaSkupina_) + L"\n";
			break;
		case 9:
			pokracuj = false;
			break;
		default:
			break;
		}

	} while (pokracuj);


	std::wcout << filterToString << "\n";
	utriedena_->clear();

	if (pouzityFilter == true)
	{
		for (auto item : *tabulka_)
		{
			if (kompozitnyFilter->pass(item->accessData()))
			{
				//utriedena_->insert(item->getKey(), item->accessData());
				nazov = item->accessData()->getNazovUJ();
				std::wcout << nazov << "\t";
				nazov = typUzemnejJednotkyToString(item->accessData()->getTypUJ());
				std::wcout << nazov << "\t";
				UzemnaJednotka* jednotka = item->accessData()->getNadradenaUJ();
				while (jednotka != nullptr)
				{
					nazov = jednotka->getNazovUJ();
					std::wcout << nazov << "\t";
					nazov = typUzemnejJednotkyToString(jednotka->getTypUJ());
					std::wcout << nazov << "\t";
					jednotka = jednotka->getNadradenaUJ();
				}
				if (kriteriumUJVzdelaniePocet != nullptr)
				{
					std::wcout << L"Vzdelanie pocet: " + std::to_wstring(kriteriumUJVzdelaniePocet->evaluate(item->accessData())) << L"\t";
				}

				if (kriteriumUJVzdelaniePodiel != nullptr)
				{
					std::wcout << L"Vzdelanie podiel: " + std::to_wstring(kriteriumUJVzdelaniePodiel->evaluate(item->accessData())) << L"\t";
				}

				if (kriteriumUJVekPocet != nullptr)
				{
					std::wcout << L"Vek pocet: " + std::to_wstring(kriteriumUJVekPocet->evaluate(item->accessData())) << L"\t";
				}

				if (kriteriumUJVekPodiel != nullptr)
				{
					std::wcout << L"Vek podiel: " + std::to_wstring(kriteriumUJVekPodiel->evaluate(item->accessData())) << L"\t";
				}

				if (kriteriumUJVekovaSkupinaPocet != nullptr)
				{
					std::wcout << L"Vekova skupina pocet: " + std::to_wstring(kriteriumUJVekovaSkupinaPocet->evaluate(item->accessData())) << L"\t";
				}

				if (kriteriumUJVekovaSkupinaPodiel != nullptr)
				{
					std::wcout << L"Vekova skupina podiel: " + std::to_wstring(kriteriumUJVekovaSkupinaPodiel->evaluate(item->accessData())) << L"\t";
				}

				std::cout << "\n";
			}
		}
	}
	else if (pouzityFilter == false)
	{
		for (auto item : *tabulka_)
		{
			//utriedena_->insert(item->getKey(), item->accessData());
			nazov = item->accessData()->getNazovUJ();
			std::wcout << nazov << "\t";
			nazov = typUzemnejJednotkyToString(item->accessData()->getTypUJ());
			std::wcout << nazov << "\t";
			UzemnaJednotka* jednotka = item->accessData()->getNadradenaUJ();
			while (jednotka != nullptr)
			{
				nazov = jednotka->getNazovUJ();
				std::wcout << nazov << "\t";
				nazov = typUzemnejJednotkyToString(jednotka->getTypUJ());
				std::wcout << nazov << "\t";
				jednotka = jednotka->getNadradenaUJ();
			}
			if (kriteriumUJVzdelaniePocet != nullptr)
			{
				std::wcout << L"Vzdelanie pocet: " + std::to_wstring(kriteriumUJVzdelaniePocet->evaluate(item->accessData())) << L"\t";
			}

			if (kriteriumUJVzdelaniePodiel != nullptr)
			{
				std::wcout << L"Vzdelanie podiel: " + std::to_wstring(kriteriumUJVzdelaniePodiel->evaluate(item->accessData())) << L"\t";
			}

			if (kriteriumUJVekPocet != nullptr)
			{
				std::wcout << L"Vek pocet: " + std::to_wstring(kriteriumUJVekPocet->evaluate(item->accessData())) << L"\t";
			}

			if (kriteriumUJVekPodiel != nullptr)
			{
				std::wcout << L"Vek podiel: " + std::to_wstring(kriteriumUJVekPodiel->evaluate(item->accessData())) << L"\t";
			}

			if (kriteriumUJVekovaSkupinaPocet != nullptr)
			{
				std::wcout << L"Vekova skupina pocet: " + std::to_wstring(kriteriumUJVekovaSkupinaPocet->evaluate(item->accessData())) << L"\t";
			}

			if (kriteriumUJVekovaSkupinaPodiel != nullptr)
			{
				std::wcout << L"Vekova skupina podiel: " + std::to_wstring(kriteriumUJVekovaSkupinaPodiel->evaluate(item->accessData())) << L"\t";
			}

			std::cout << "\n";
		}
	}

	delete kompozitnyFilter;

	if (filterVzdelaniePocet != nullptr) {
		delete filterVzdelaniePocet;
		delete kriteriumUJVzdelaniePocet;
	}

	if (filterVzdelaniePodiel != nullptr) {
		delete filterVzdelaniePodiel;
		delete kriteriumUJVzdelaniePodiel;
	}
	
	if (filterUJTyp != nullptr) {
		delete filterUJTyp;
	}

	if (filterPrislusnost != nullptr) {
		delete filterPrislusnost;
	}

	if (filterVekPocet != nullptr) {
		delete filterVekPocet;
		delete kriteriumUJVekPocet;
	}

	if (filterVekPodiel != nullptr) {
		delete filterVekPodiel;
		delete kriteriumUJVekPodiel;
	}

	if (filterVekovaSkupinaPocet != nullptr) {
		delete filterVekovaSkupinaPocet;
		delete kriteriumUJVekovaSkupinaPocet;
	}

	if (filterVekovaSkupinaPodiel != nullptr) {
		delete filterVekovaSkupinaPodiel;
		delete kriteriumUJVekovaSkupinaPodiel;
	}

}

void Spustac::vypisUzemychCelkovSDanymTypom()
{
	int moznost = 0;
	std::cout << "Zvolte typ uzemnej jednotky, ktore chcete vypisat: " << "\n";
	std::cout << "1. OBEC" << "\n";
	std::cout << "2. OKRES" << "\n";
	std::cout << "3. KRAJ" << "\n";
	std::cout << "3. STAT" << "\n";
	std::cin >> moznost;
	//vyberTypUJ(moznost);
	vyberTypUJPreTabulku(moznost);
	
	std::cout << "NAZOV UZEMNEJ JEDNOTKY" << "\n";
	for (auto item : *tabulka_)
	{
		std::wcout << item->accessData()->getNazovUJ() << "\n";
	}
}

void Spustac::vytvorVyberoveKriterium(int hodnota)
{
	VyberoveKriteriumNajvacsiaVekovaSkupina* vyberoveNajvacsiaVekovaSkupina = nullptr;
	VyberoveKriteriumNajmensiaVekovaSkupina* vyberoveNajmensiaVekovaSkupina = nullptr;

	std::wstring nazov;
	if (hodnota == 1)
	{
		//najvacsia
		vyberoveNajvacsiaVekovaSkupina = new VyberoveKriteriumNajvacsiaVekovaSkupina(vekovaSkupina_);
		UzemnaJednotka* jednotka = vyberoveNajvacsiaVekovaSkupina->vyberNajlepsi(tabulka_);
		std::wcout << jednotka->getNazovUJ() << "\t";
		nazov = typUzemnejJednotkyToString(jednotka->getTypUJ());
		std::wcout << nazov << "\t";
		jednotka = jednotka->getNadradenaUJ();
		while (jednotka != nullptr)
		{
			nazov = jednotka->getNazovUJ();
			std::wcout << nazov << "\t";
			nazov = typUzemnejJednotkyToString(jednotka->getTypUJ());
			std::wcout << nazov << "\t";
			jednotka = jednotka->getNadradenaUJ();
		}

		delete vyberoveNajvacsiaVekovaSkupina;
	}
	else if (hodnota == 2)
	{
		//najmensia
		vyberoveNajmensiaVekovaSkupina = new VyberoveKriteriumNajmensiaVekovaSkupina(vekovaSkupina_);
		UzemnaJednotka* jednotka = vyberoveNajmensiaVekovaSkupina->vyberNajlepsi(tabulka_);
		std::wcout << jednotka->getNazovUJ() << "\t";
		nazov = typUzemnejJednotkyToString(jednotka->getTypUJ());
		std::wcout << nazov << "\t";
		jednotka = jednotka->getNadradenaUJ();
		while (jednotka != nullptr)
		{
			nazov = jednotka->getNazovUJ();
			std::wcout << nazov << "\t";
			nazov = typUzemnejJednotkyToString(jednotka->getTypUJ());
			std::wcout << nazov << "\t";
			jednotka = jednotka->getNadradenaUJ();
		}

		delete vyberoveNajmensiaVekovaSkupina;
	}
}

void Spustac::vyberTypUJPreTabulku(int hodnota)
{
	if (hodnota == 1)
	{
		//obec
		tabulka_ = databaza_->getObce();
		typUJPreTabulku_ = TypUzemnejJednotky::OBEC;
	}
	else if (hodnota == 2)
	{
		//okres
		tabulka_ = databaza_->getOkresy();
		typUJPreTabulku_ = TypUzemnejJednotky::OKRES;
	}
	else if (hodnota == 3)
	{
		//kraje
		tabulka_ = databaza_->getKraje();
		typUJPreTabulku_ = TypUzemnejJednotky::KRAJ;
	}
	else if (hodnota == 4)
	{
		//staty
		tabulka_ = databaza_->getStaty();
		typUJPreTabulku_ = TypUzemnejJednotky::STAT;
	}
}
