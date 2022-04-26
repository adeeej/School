#include <stdio.h>
#include "firma.h"
#include <stdlib.h>
#include "CMemLeak.h"

void initFirma(FIRMA * firma) {
    firma->trzba = 0;
}

void pridajTrzbuFirme(FIRMA * firma, double trzba) {
    firma->trzba += trzba;
}

void vypisCelkovuTrzbuFirmy(FIRMA * firma) {
    printf("Od vzniku firma zarobila: %.2f$\n", firma->trzba);
}
