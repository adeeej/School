#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#include "datumACas.h"

#include <stdlib.h>
#include "CMemLeak.h"

int porovnajDatumy(DATUMACAS * d1, DATUMACAS * d2) {
    if (d1->rok == d2->rok) {
        if (d1->mesiac == d2->mesiac) {
            if (d1->den == d2->den) {
                if (d1->hod == d2->hod) {
                    if (d1->mesiac == d2->min) {
                        return 0;
                    }

                    if (d1->min < d2->min) {
                        return 1;
                    } else {
                        return -1;
                    }
                }

                if (d1->hod < d2->hod) {
                    return 1;
                } else {
                    return -1;
                }
            }

            if (d1->den < d2->den) {
                return 1;
            } else {
                return -1;
            }
        }

        if (d1->mesiac < d2->mesiac) {
            return 1;
        } else {
            return -1;
        }
    }

    if (d1->rok < d2->rok) {
        return 1;
    } else {
        return -1;
    }

}

bool jePriestupny(unsigned short rok) {
    if (rok % 4 == 0) {
        if (rok % 100 != 0 && rok % 400 != 0) {
            return false;
        }
        return true;
    } else {
        return false;
    }
}

bool platnyDatumACas(DATUMACAS * datacas) {
    if (datacas->hod >= 0 && datacas->hod <= 23) {

        if (datacas->min >= 0 && datacas->min <= 59) {

            if (datacas->rok > 0 && datacas->rok < 2500) {

                if (datacas->mesiac >= 1 && datacas->mesiac <= 12) {

                    if ((datacas->den >= 1 && datacas->den <= 31) &&
                        (datacas->mesiac == 1 || datacas->mesiac == 3 || datacas->mesiac == 5 || datacas->mesiac == 7 ||
                         datacas->mesiac == 8 || datacas->mesiac == 10 || datacas->mesiac == 12))
                        return true;
                    else if ((datacas->den >= 1 && datacas->den <= 30) &&
                             (datacas->mesiac == 4 || datacas->mesiac == 6 || datacas->mesiac == 9 ||
                              datacas->mesiac == 11))
                        return true;
                    else if ((datacas->den >= 1 && datacas->den <= 28) && (datacas->mesiac == 2))
                        return true;
                    else if (datacas->den == 29 && datacas->mesiac == 2 && jePriestupny(datacas->rok))
                        return true;
                    else
                        return false;
                } else {
                    return false;
                }
            } else {
                return false;
            }

        } else {
            return false;
        }
    } else {
        return false;
    }
}

unsigned int vypocitajRozdielVHodinach(DATUMACAS * zaciatok, DATUMACAS * koniec) {
    struct tm zac = {0}, kon = {0};

    zac.tm_year = zaciatok->rok;
    zac.tm_mon = zaciatok->mesiac;
    zac.tm_mday = zaciatok->den;
    zac.tm_hour = zaciatok->hod;
    zac.tm_min = zaciatok->min;

    kon.tm_year = koniec->rok;
    kon.tm_mon = koniec->mesiac;
    kon.tm_mday = koniec->den;
    kon.tm_hour = koniec->hod;
    kon.tm_min = koniec->min;

    return ceil(difftime(mktime(&kon), mktime(&zac)) / 3600);
}

char* datumToString(DATUMACAS * datum, char * dest) {
    sprintf(dest, "%02hu:%02hu %hu.%hu %hu", (unsigned short) datum->hod, (unsigned short) datum->min, (unsigned short) datum->den, (unsigned short) datum->mesiac, datum->rok);
    return dest;
}