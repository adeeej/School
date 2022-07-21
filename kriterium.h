#pragma once
#include <string>

template<typename ObjectType, typename ResultType>
class Kriterium
{
public:
	virtual ResultType evaluate(ObjectType o) = 0;
	virtual std::wstring toString() = 0;
	virtual ~Kriterium() {};
};