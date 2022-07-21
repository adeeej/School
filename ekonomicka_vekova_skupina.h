#pragma once

enum class EVS
{
	PREDPRODUKTIVNI,
	PRODUKTIVNI,
	POPRODUKTIVNI
};

static std::wstring typEkonomickejVekovejSkupinyToString(EVS evs) {
	switch (evs)
	{
	case EVS::PREDPRODUKTIVNI:
		return L"PREDPRODUKTIVNI";
		break;
	case EVS::PRODUKTIVNI:
		return L"PRODUKTIVNI";
		break;
	case EVS::POPRODUKTIVNI:
		return L"POPRODUKTIVNI";
		break;
	default:
		break;
	}
}