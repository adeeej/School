#ifndef MAIN_C_DATUMACAS_H
#define MAIN_C_DATUMACAS_H

#include "struktury.h"

int porovnajDatumy(DATUMACAS * d1, DATUMACAS * d2);
bool jePriestupny(unsigned short rok);
bool platnyDatumACas(DATUMACAS * datacas);
unsigned int vypocitajRozdielVHodinach(DATUMACAS * zaciatok, DATUMACAS * koniec);
char* datumToString(DATUMACAS * datum, char * dest);

#endif //MAIN_C_DATUMACAS_H
