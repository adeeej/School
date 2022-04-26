#include <stdio.h>
#include <stdbool.h>

#include "sklad.h"
#include "firma.h"
#include "vozidlo.h"

#include <stdlib.h>
#include "CMemLeak.h"


int main() {
    SKLAD sklad;
    initSklad(&sklad);
    FIRMA firma;
    initFirma(&firma);

    bool run = true;
    short vyber;

    while(run) {
        printf("\n1 - Vypíš sklad\n");
        printf("2 - Načítaj vozidlá zo súboru\n");
        printf("3 - Odstráň vozidlo zo skladu\n");
        printf("4 - Požičaj vozidlo\n");
        printf("5 - Vráť vozidlo do skladu\n");
        printf("6 - Utrieď vozidlá\n");
        printf("7 - Vypíš tržbu firmy\n");
        printf("0 - Ukonči program\n");
        printf("Tvoj výber: ");

        while (scanf("%d", &vyber) != 1) {
            while (getchar() != '\n');
            printf("Nespravny vyber, zadaj prosim znovu!\n");
        }

        switch (vyber) {
            case 0:
                run = false;
                break;
            case 1:
                vypisSklad(&sklad);
                break;
            case 2:
                if(nacitajZTxt(&sklad, "data.txt")) {
                    printf("Načítanie úspešné.\n");
                } else {
                    printf("Načitanie neúspešné.\n");
                }
                break;
            case 3:
                odoberVozidloZoSkladu(&sklad);
                break;
            case 4:
                pozicajVozidloZoSkladu(&sklad);
                break;
            case 5:
                vratVozidloDoSkladu(&sklad, &firma);
                break;
            case 6:
                utriedPodla(&sklad);
                break;
            case 7:
                vypisCelkovuTrzbuFirmy(&firma);
                break;
            default:
                printf("Nesprávny výber, zadaj prosím znovu!\n");
        }
    }

    dealokujSklad(&sklad);
    return 0;
}
