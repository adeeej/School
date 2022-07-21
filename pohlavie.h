#pragma once

enum class Pohlavie
{
	MUZ,
	ZENA
};

static std::wstring pohlavieToString(Pohlavie pohlavie) {
	switch (pohlavie)
	{
	case Pohlavie::MUZ:
		return L"MUZ";
		break;
	case Pohlavie::ZENA:
		return L"ZENA";
		break;
	default:
		break;
	}
}