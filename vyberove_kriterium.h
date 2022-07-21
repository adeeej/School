#pragma once
#include "kriterium.h"
#include "structures/table/table.h"

template <typename KeyType, typename ObjectType, typename ValueType>
class VyberoveKriterium {
public:
	VyberoveKriterium(Kriterium<ObjectType, ValueType>* kriterium) :
		kriterium_(kriterium)
	{
	}

	virtual ~VyberoveKriterium()
	{
		delete kriterium_;
		kriterium_ = nullptr;
	}

	ObjectType& vyberNajlepsi(structures::Table<KeyType, ObjectType>* tabulka)
	{

		ObjectType* najlepsia = nullptr;
		ValueType hodnota = NULL;
		for (auto object : *tabulka)
		{
			if (najlepsia == nullptr || this->jeTestovanaHodnotaLepsia(hodnota, this->kriterium_->evaluate(object->accessData())))
			{
				najlepsia = &object->accessData();
				hodnota = this->kriterium_->evaluate(*najlepsia);
			}
		}
		return *najlepsia;
	}

protected:
	virtual bool jeTestovanaHodnotaLepsia(ValueType najlepsiaTeraz, ValueType najlepsiaTestovana) = 0;

private:
	Kriterium<ObjectType, ValueType>* kriterium_;
};