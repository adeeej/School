#pragma once
#include "kriterium.h"
#include "filter_s_kriteriom.h"

template<typename ObjectType, typename ValueType>
class FilterSIntervalom : public FilterSKriteriom<ObjectType, ValueType> {
public:
	FilterSIntervalom(Kriterium<ObjectType, ValueType>* kriterium, ValueType min, ValueType max) : FilterSKriteriom<ObjectType, ValueType>(kriterium),
		min_(min),
		max_(max)
	{
	}
protected:
	inline bool passFilter(ValueType hodnota) { return hodnota >= min_ && hodnota <= max_; };
private:
	ValueType min_;
	ValueType max_;
};