#pragma once

#include "vyberove_kriterium.h"

template <typename KeyType, typename ObjectType, typename ValueType>
class VyberoveKriteriumMax : public VyberoveKriterium<KeyType, ObjectType, ValueType> {
public:
	VyberoveKriteriumMax(Kriterium<ObjectType, ValueType>* kriterium)
		: VyberoveKriterium<KeyType, ObjectType, ValueType>(kriterium)
	{
	}
	virtual ~VyberoveKriteriumMax() {};

protected:
	bool jeTestovanaHodnotaLepsia(ValueType najlepsiaTeraz, ValueType najlepsiaTestovana) override
	{
		return najlepsiaTeraz < najlepsiaTestovana;
	}
};