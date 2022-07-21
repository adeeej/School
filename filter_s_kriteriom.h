#pragma once
#include "filter.h"
#include "kriterium.h"

template<typename ObjectType, typename ValueType>
class FilterSKriteriom : public Filter<ObjectType>
{
public:
	FilterSKriteriom(Kriterium<ObjectType, ValueType>* kriterium) :
		kriterium_(kriterium)
	{
	}
	~FilterSKriteriom() {
		delete kriterium_;
		kriterium_ = nullptr;
	}
		
	bool pass(ObjectType& object) override {
		return passFilter(kriterium_->evaluate(object));
	};

	std::wstring toString() {
		return kriterium_->toString();
	}

protected:
	virtual bool passFilter(ValueType hodnota) = 0;
private:
	Kriterium<ObjectType, ValueType>* kriterium_;
};