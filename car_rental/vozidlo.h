#ifndef MAIN_C_VOZIDLO_H
#define MAIN_C_VOZIDLO_H

#include "struktury.h"

bool suRovnakeVozidla(VOZIDLO * v1, VOZIDLO * v2);
VOZIDLO * najdiVozidlo(SKLAD * sklad, unsigned int id);
bool pridajVozidloDoSkladu(SKLAD * sklad, VOZIDLO * voz);
bool odoberVozidloZoSkladu(SKLAD * sklad);
bool nacitajZTxt(SKLAD * sklad, const char * nazovSuboru);
VOZIDLO * pozicajVozidloZoSkladu(SKLAD * sklad);
double vypocitajCenuPozicania(VOZIDLO* voz, DATUMACAS * koniec);
bool vratVozidloDoSkladu(SKLAD * sklad, FIRMA * firma);
void vymen(VOZIDLO* prve, VOZIDLO* druhe);
void utried(SKLAD* sklad, bool (*porovnaj)(VOZIDLO*, VOZIDLO*));
bool porovnajId(VOZIDLO* prve, VOZIDLO* druhe);
bool porovnajJednotkovuCenu(VOZIDLO* prve, VOZIDLO* druhe);
bool porovnajZvysenuJednotkovuCenu(VOZIDLO* prve, VOZIDLO* druhe);
bool porovnajDlzkuPozicania(VOZIDLO* prve, VOZIDLO* druhe);
char* vozidloToString(VOZIDLO * voz, char *dest);

#endif //MAIN_C_VOZIDLO_H
