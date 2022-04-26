#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "datumACas.h"
#include "sklad.h"
#include "firma.h"
#include "vozidlo.h"

#include <stdlib.h>
#include "CMemLeak.h"

bool suRovnakeVozidla(VOZIDLO * v1, VOZIDLO * v2) {
    if (v1->id == v2->id) {
        return true;
    }
    return false;
}

VOZIDLO * najdiVozidlo(SKLAD * sklad, unsigned int id) {
    for (int i = 0; i < sklad->pocetZaznamov; i++) {
        if (sklad->vozidla[i].id == id) {
            return sklad->vozidla + i;
        }
    }
    return NULL;
}

bool pridajVozidloDoSkladu(SKLAD * sklad, VOZIDLO * voz) {
    if (jePlnySklad(sklad)) {
        return false;
    }

    for (int i = 0; i < sklad->pocetZaznamov; i++) {
        if (suRovnakeVozidla(&sklad->vozidla[i], voz) == true) {
            return false;
        }
    }

    voz->okamihPozicania.rok = 0;
    voz->okamihVratenia.rok = 0;

    zvacsiSklad(sklad);
    sklad->vozidla[sklad->pocetZaznamov] = *voz;
    sklad->pocetZaznamov++;
    return true;
}

bool odoberVozidloZoSkladu(SKLAD * sklad) {
    if (sklad->pocetZaznamov <= 0) {
        printf("V sklade sa nenachádza žiadne vozidlo!\n");
        return false;
    }

    short id = 0;
    printf("Zadaj ID auta!\n");
    while (scanf("%d", &id) != 1) {
        while (getchar() != '\n');
        printf("Nesprávny formát ID! Prosím opakuj voľbu.\n");
    }

    VOZIDLO * pom = najdiVozidlo(sklad, id);

    if (pom == NULL) {
        printf("Nemôžete odstránit vozidlo zo skladu, ktoré sa nenachádza v evidencii vozidiel!\n");
        return false;
    }

    if (pom->okamihPozicania.rok != 0 && pom->okamihVratenia.rok != 0) {
        printf("Bohužiaľ, ale dané vozidlo ma momentálne nájomcu. Nemôžete odstránit toto vozidlo zo skladu!\n");
        return false;
    }

    for (int i = 0; i < sklad->pocetZaznamov; i++) {
        if (suRovnakeVozidla(&sklad->vozidla[i], pom)) {
            printf("%d\n", i);
            if ((sklad->pocetZaznamov -1) == i) {
                printf("%d\n", i);
                sklad->vozidla[i] = sklad->vozidla[i + 1];
                zmensiSklad(sklad);
                sklad->pocetZaznamov--;
                printf("Vozidlo bolo úspešne odstránené zo skladu!\n");
                return true;
            } else {
                printf("%d\n", i);
                sklad->vozidla[i] = sklad->vozidla[sklad->pocetZaznamov -1];
                zmensiSklad(sklad);
                sklad->pocetZaznamov--;
                printf("Vozidlo bolo úspešne odstránené zo skladu!\n");
                return true;
            }
        }
    }
    return false;
}

#define MAX_RIADOK 100
bool nacitajZTxt(SKLAD * sklad, const char * nazovSuboru) {
    FILE * zdroj = fopen(nazovSuboru,"r");
    if(zdroj == NULL) {
        perror("Nastala chyba pri čitaní súboru!");
        return false;
    }

    char riadok[MAX_RIADOK];
    while(!feof(zdroj)) {
        if(fgets(riadok,MAX_RIADOK,zdroj)>0) {
            VOZIDLO pomVozidlo;
            char * p1 = strchr(riadok,' ');
            strncpy(pomVozidlo.znacka, riadok,p1-riadok);
            pomVozidlo.znacka[p1-riadok] = '\0';
            p1++;
            char * p2 = strchr(p1,' ');
            pomVozidlo.id = atoi(p1);
            p2++;
            char * p3 = strchr(p2,' ');
            pomVozidlo.jednotkovaCena = atof(p2);
            p3++;
            pomVozidlo.zvysenaJednotkovaCena = atof(p3);
            memset(&pomVozidlo.okamihPozicania, 0, sizeof(DATUMACAS));
            memset(&pomVozidlo.okamihVratenia, 0, sizeof(DATUMACAS));
            if(pridajVozidloDoSkladu(sklad,&pomVozidlo)) {
                printf("Vozidlo sa podarilo pridať do skladu!\n");
            } else {
                printf("Vozidlo sa nepodarilo pridať do skladu!\n");
            }
        }
    }

    fclose(zdroj);
#undef MAX_RIADOK
    return true;
}

VOZIDLO * pozicajVozidloZoSkladu(SKLAD * sklad) {
    if (sklad->pocetZaznamov <= 0) {
        printf("Bohužiaľ, ale sklad je prázdny!\n");
        return NULL;
    }

    DATUMACAS datumPozicania, datumVratenia;

    short id = 0;
    printf("Zadaj ID auta!\n");
    while (scanf("%d", &id) != 1) {
        while (getchar() != '\n');
        printf("Nesprávny formát ID! Prosím opakuj voľbu.\n");
    }

    if (id < 0 || (short)id > USHRT_MAX) {
        printf("Zadali ste buď záporné alebo príliš vysoké ID!\n");
        return NULL;
    }

    VOZIDLO * pom = najdiVozidlo(sklad, id);

    if(!najdiVozidlo(sklad, id)) {
        printf("Dané vozidlo sa nenachádza v evidencii vozidiel!\n");
        return NULL;
    }

    if (pom->okamihPozicania.rok != 0 && pom->okamihVratenia.rok != 0) {
        printf("Bohužiaľ, ale dané vozidlo už má nájomcu. Prosím vyberte si iné vozidlo zo skladu!\n");
        return NULL;
    }

    printf("Zadaj dátum a čas požičania [hod, min, den, mesiac, rok]: ");
    while (scanf("%hu %hu %hu %hu %hu" ,&datumPozicania.hod, &datumPozicania.min, &datumPozicania.den, &datumPozicania.mesiac, &datumPozicania.rok) != 5) {
        while (getchar() != '\n');
        printf("Boli zadané nesprávne vstupy! Prosím opakuj svoju voľbu.\n");
        printf("Zadaj dátum a čas požičania [hod, min, den, mesiac, rok]: ");
    }

    printf("Zadaj dátum a čas vrátenia  [hod, min, den, mesiac, rok]: ");
    while (scanf("%hu %hu %hu %hu %hu" ,&datumVratenia.hod, &datumVratenia.min, &datumVratenia.den, &datumVratenia.mesiac, &datumVratenia.rok) != 5) {
        while (getchar() != '\n');
        printf("Boli zadané nesprávne vstupy! Prosím opakuj svoju voľbu.\n");
        printf("Zadaj dátum a čas počičania [hod, min, den, mesiac, rok]: ");
    }

    if (platnyDatumACas(&datumPozicania) && platnyDatumACas(&datumVratenia)) {
        if (porovnajDatumy(&datumPozicania, &datumVratenia) == 1) {
            pom->okamihPozicania = datumPozicania;
            pom->okamihVratenia = datumVratenia;
        } else {
            printf("Dátum a čas vrátenia nemôže byť rovnaký alebo skorší ako dátum požičania!\n");
        }
    } else {
        printf("Bohužiaľ, ale zadali ste nesprávny dátum a čas!\n");
        return NULL;
    }

    return pom;
}

double vypocitajCenuPozicania(VOZIDLO* voz, DATUMACAS * koniec) {
    int porovnanie = porovnajDatumy(&voz->okamihPozicania, koniec);
    double vyslednaCena = 0;

    if(!porovnanie || porovnanie == -1) {
        vyslednaCena = voz->jednotkovaCena * vypocitajRozdielVHodinach(&voz->okamihPozicania, koniec);
    }

    if(porovnanie == 1) {
        vyslednaCena = vypocitajRozdielVHodinach(&voz->okamihPozicania, &voz->okamihVratenia) * voz->jednotkovaCena;
        vyslednaCena += vypocitajRozdielVHodinach(&voz->okamihVratenia, koniec) * voz->zvysenaJednotkovaCena;
    }

    return vyslednaCena;
}

bool vratVozidloDoSkladu(SKLAD * sklad, FIRMA * firma) {
    DATUMACAS aktualnyDatum;

    short id = 0;
    printf("Zadaj ID vozidla: ");
    while (scanf("%d", &id) != 1) {
        while (getchar() != '\n');
        printf("Nesprávny formát ID! Prosím opakuj voľbu.\n");
    }

    if (id < 0 || (short)id > USHRT_MAX) {
        printf("Zadali ste buď záporné alebo príliš vysoké ID!\n");
    }

    VOZIDLO * pom = najdiVozidlo(sklad, id);

    if (pom == NULL) {
        printf("Bohužiaľ, ale vozidlo s daným ID sa nenachádza v sklade a nie je ani požičané!\n");
        return false;
    }

    if (!pom->okamihPozicania.rok && !pom->okamihVratenia.rok) {
        printf("Vozidlo sa nachádza v sklade! Nemôžete vrátiť nepožičané vozidlo.\n");
        return false;
    }

    printf("Zadaj aktuálny dátum a čas [hod, min, den, mesiac, rok]: ");
    while (scanf("%hu %hu %hu %hu %hu" ,&aktualnyDatum.hod, &aktualnyDatum.min, &aktualnyDatum.den, &aktualnyDatum.mesiac, &aktualnyDatum.rok) != 5) {
        while (getchar() != '\n');
        printf("Boli zadané nesprávne vstupy! Prosím opakuj svoju voľbu.\n");
        printf("Zadaj aktuálny dátum [hod, min, den, mesiac, rok]: ");
    }

    if (porovnajDatumy(&pom->okamihPozicania, &aktualnyDatum) != 1) {
        printf("Aktuálny čas nemôže byť rovnaký alebo skorší ako čas požičania vozidla!\n");
        return false;
    }

    double celkovaCena = vypocitajCenuPozicania(pom, &aktualnyDatum);
    pridajTrzbuFirme(firma, celkovaCena);

    pom->okamihPozicania.rok = 0;
    pom->okamihVratenia.rok = 0;

    return true;
}

void vymen(VOZIDLO* prve, VOZIDLO* druhe) {
    VOZIDLO pom;
    memcpy(&pom, prve, sizeof(VOZIDLO));
    memcpy(prve, druhe, sizeof(VOZIDLO));
    memcpy(druhe, &pom, sizeof(VOZIDLO));
}

void utried(SKLAD* sklad, bool (*porovnaj)(VOZIDLO*, VOZIDLO*)) {
    for (int i = 0; i < sklad->pocetZaznamov - 1; i++)
        for (int j = 0; j < sklad->pocetZaznamov - i - 1; j++)
            if (porovnaj(&sklad->vozidla[j], &sklad->vozidla[j + 1]))
                vymen(&sklad->vozidla[j], &sklad->vozidla[j + 1]);
}

bool porovnajId(VOZIDLO* prve, VOZIDLO* druhe) {
    return prve->id > druhe->id;
}

bool porovnajJednotkovuCenu(VOZIDLO* prve, VOZIDLO* druhe) {
    return prve->jednotkovaCena > druhe->jednotkovaCena;
}

bool porovnajZvysenuJednotkovuCenu(VOZIDLO* prve, VOZIDLO* druhe) {
    return prve->zvysenaJednotkovaCena > druhe->zvysenaJednotkovaCena;
}

bool porovnajDlzkuPozicania(VOZIDLO* prve, VOZIDLO* druhe) {
    unsigned int prvyDatumACas;
    unsigned int druhyDatumACas;

    prvyDatumACas = vypocitajRozdielVHodinach(&prve->okamihPozicania, &prve->okamihVratenia);
    druhyDatumACas = vypocitajRozdielVHodinach(&druhe->okamihPozicania, &druhe->okamihVratenia);

    return prvyDatumACas > druhyDatumACas;
}

char* vozidloToString(VOZIDLO * voz, char *dest) {
#define DLZKA 30
    char zaciatok[DLZKA], koniec[DLZKA];


    datumToString(&voz->okamihPozicania, zaciatok);
    datumToString(&voz->okamihVratenia, koniec);

    sprintf(dest, "%-10s\t%d\t\t%.2lf$\t\t%.2lf$", voz->znacka, voz->id, voz->jednotkovaCena, voz->zvysenaJednotkovaCena);

    if(!voz->okamihPozicania.rok && !voz->okamihVratenia.rok)
        sprintf(dest, "%s\t\tnepožičané\n", dest);
    else
        sprintf(dest, "%s\t\t\t\t\t\t%-17s\t%-17s\n", dest, zaciatok, koniec);

    return dest;
#undef DLZKA
}