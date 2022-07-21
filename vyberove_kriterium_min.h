#pragma once

#include "vyberove_kriterium.h"

template <typename KeyType, typename ObjectType, typename ValueType>
class VyberoveKriteriumMin : public VyberoveKriterium<KeyType, ObjectType, ValueType> {
public:
	VyberoveKriteriumMin(Kriterium<ObjectType, ValueType>* kriterium)
		: VyberoveKriterium<KeyType, ObjectType, ValueType>(kriterium)
	{
	}
	virtual ~VyberoveKriteriumMin() {};

protected:
	bool jeTestovanaHodnotaLepsia(ValueType najlepsiaTeraz, ValueType najlepsiaTestovana) override
	{
		return najlepsiaTeraz > najlepsiaTestovana;
	}
};