#pragma once

template<typename ObjectType>
class Filter
{
public:
	virtual bool pass(ObjectType& object) = 0;
	virtual std::wstring toString() = 0;
};
