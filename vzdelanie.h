#pragma once
#include "typ_vzdelania.h"
#include "structures/common/heap_monitor.h"

class Vzdelanie {
public:
	Vzdelanie() :
		neukoncenePocet_(0),
		zakladPocet_(0),
		bezMaturityPocet_(0),
		sMaturitouPocet_(0),
		vyssieOdbornePocet_(0),
		vysokoSkolskePocet_(0),
		bezVzdelaniaPocet_(0),
		nezistenePocet_(0)
	{
	}
	inline long getPocetVzdelanie(TypVzdelania typVzdelania) {
		if (typVzdelania == TypVzdelania::NEUKONCENE)
		{
			return neukoncenePocet_;
		}
		else if (typVzdelania == TypVzdelania::ZAKLAD)
		{
			return zakladPocet_;
		}
		else if (typVzdelania == TypVzdelania::BEZ_MATURITY)
		{
			return bezMaturityPocet_;
		}
		else if (typVzdelania == TypVzdelania::S_MATURITOU)
		{
			return sMaturitouPocet_;
		}
		else if (typVzdelania == TypVzdelania::VYSSIE_ODBORNE)
		{
			return vyssieOdbornePocet_;
		}
		else if (typVzdelania == TypVzdelania::VYSOKOSKOLSKE)
		{
			return vysokoSkolskePocet_;
		}
		else if (typVzdelania == TypVzdelania::BEZ_VZDELANIA)
		{
			return bezVzdelaniaPocet_;
		}
		else
		{
			return nezistenePocet_;
		}
	}

	inline void setPocetNeukoncene(int pocet) {
		neukoncenePocet_ += pocet;
	}

	inline void setPocetZaklad(int pocet) {
		zakladPocet_ += pocet;
	}

	inline void setPocetBezMaturity(int pocet) {
		bezMaturityPocet_ += pocet;
	}

	inline void setPocetSMaturitou(int pocet) {
		sMaturitouPocet_ += pocet;
	}

	inline void setPocetVyssieOdborne(int pocet) {
		vyssieOdbornePocet_ += pocet;
	}

	inline void setPocetVysokoSkolske(int pocet) {
		vysokoSkolskePocet_ += pocet;
	}

	inline void setPocetBezVzdelania(int pocet) {
		bezVzdelaniaPocet_ += pocet;
	}

	inline void setPocetNezistene(int pocet) {
		nezistenePocet_ += pocet;
	}

private:
	int neukoncenePocet_;
	int zakladPocet_;
	int bezMaturityPocet_;
	int sMaturitouPocet_;
	int vyssieOdbornePocet_;
	int vysokoSkolskePocet_;
	int bezVzdelaniaPocet_;
	int nezistenePocet_;
};
