#ifndef MAIN_C_SKLAD_H
#define MAIN_C_SKLAD_H

#include "struktury.h"

#define KAPACITA_SKLADU 20

void alokujSklad(SKLAD * sklad);
void initSklad(SKLAD * sklad);
void zvacsiSklad(SKLAD * sklad);
void zmensiSklad(SKLAD * sklad);
void dealokujSklad(SKLAD * sklad);
bool jePlnySklad(SKLAD * sklad);
bool utriedPodla(SKLAD * sklad);
void vypisSklad(SKLAD * sklad);

#endif //MAIN_C_SKLAD_H
