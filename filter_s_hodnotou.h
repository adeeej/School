#pragma once
#include "kriterium.h"
#include "filter_s_kriteriom.h"

template<typename ObjectType, typename ValueType>
class FilterSHodnotou : public FilterSKriteriom<ObjectType, ValueType> {
public:
	FilterSHodnotou(Kriterium<ObjectType, ValueType>* kriterium, ValueType hodnota) : FilterSKriteriom<ObjectType, ValueType>(kriterium) {
		hodnota_ = hodnota;
	}
	
protected:
	inline bool passFilter(ValueType hodnota) override { return hodnota == hodnota_; }
private:
	ValueType hodnota_;
};