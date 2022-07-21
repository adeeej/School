#pragma once
#include "Filter.h"
#include "structures/list/array_list.h"

template<typename ObjectType>
class KompozitnyFilter : public Filter<ObjectType>
{
public:
	KompozitnyFilter() :
		filtre_(new structures::ArrayList<Filter<ObjectType>*>())
	{
	}
	~KompozitnyFilter() { 
		delete filtre_;
		filtre_ == nullptr;
	}

	void zaregistrujFilter(Filter<ObjectType>* filter)
	{
		filtre_->add(filter);
	}

	std::wstring toString() {
		std::wstring retazec;
		for (auto item : *filtre_)
		{
			retazec += item->toString();
		}
		return retazec;
	}

	bool pass(ObjectType& object) override {
		for (auto item : *filtre_) {
			if (!item->pass(object)) {
				return false;
			}
		}
		return true;
	}

protected:
	structures::ArrayList<Filter<ObjectType>*>* filtre_;
};