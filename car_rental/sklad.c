#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "vozidlo.h"
#include "sklad.h"

#include <stdlib.h>
#include "CMemLeak.h"

void alokujSklad(SKLAD * sklad) {
    sklad->vozidla = malloc(sizeof(VOZIDLO));
}

void initSklad(SKLAD * sklad) {
    sklad->pocetZaznamov = 0;
    alokujSklad(sklad);
}

void zvacsiSklad(SKLAD * sklad) {
    VOZIDLO * tmp = realloc(sklad->vozidla, sizeof(VOZIDLO) * (sklad->pocetZaznamov + 1));
    if(!tmp) {
        perror("Sklad sa nepodarilo zväčšiť!");
        return;
    }

    sklad->vozidla = tmp;
}

void zmensiSklad(SKLAD * sklad) {
    sklad->vozidla = realloc(sklad->vozidla, sizeof(VOZIDLO) * (sklad->pocetZaznamov - 1));
}

void dealokujSklad(SKLAD * sklad) {
    free(sklad->vozidla);
    sklad->vozidla = NULL;
}


bool jePlnySklad(SKLAD * sklad) {
    if (sklad->pocetZaznamov == KAPACITA_SKLADU) {
        return true;
    }
    return false;
}

bool utriedPodla(SKLAD * sklad) {
    printf("Triedenie vozidiel:\n");
    printf("1 - Utrieď ID vozidiel vzostupne.\n");
    printf("2 - Utrieď vozidlá podľa jednotkovej ceny/hod vzostupne.\n");
    printf("3 - Utrieď vozidlá podľa zvýšenej jednotkovej ceny/hod vzostupne.\n");
    printf("4 - Utrieď vozidlá podľa dĺžky požičania.\n");

    bool run = true;
    unsigned short vyber;

    while(run) {
        scanf("%hu", &vyber);
        switch (vyber) {
            case 1:
                utried(sklad, porovnajId);
                run = false;
                break;
            case 2:
                utried(sklad, porovnajJednotkovuCenu);
                run = false;
                break;
            case 3:
                utried(sklad, porovnajZvysenuJednotkovuCenu);
                run = false;
                break;
            case 4:
                utried(sklad, porovnajDlzkuPozicania);
                run = false;
                break;
            default:
                printf("Nesprávny výber, zadaj prosím znovu!\n");
        }
    }

    return true;

}

#define MAX_ZNAKOV_SK 100
void vypisSklad(SKLAD * sklad) {
    if (sklad->pocetZaznamov <= 0) {
        printf("Sklad je prázdny!\n");
        return;
    }

    printf("----------------------------------------- *** SKLAD *** -----------------------------------------\n");
    printf("%-10s\t%-6s\t%-9s\t%-10s\t%-11s\t\t%-20s%-20s\n\n", "ZNACKA", "ID", "CENA/HOD", "CENA/HOD+", "POZICANE", "OD", "DO");
    char dest[MAX_ZNAKOV_SK];
    for (int i = 0; i < sklad->pocetZaznamov; i++) {
        vozidloToString(&sklad->vozidla[i], dest);
        printf("%s", dest);
    }
    printf("\n-------------------------------------- *** SKLAD KONIEC *** --------------------------------------\n");
}
#undef MAX_ZNAKOV_SK