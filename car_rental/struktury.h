//
// Created by Ado on 5. 1. 2021.
//

#ifndef MAIN_C_STRUKTURY_H
#define MAIN_C_STRUKTURY_H

typedef struct datumACas{
    unsigned char hod;
    unsigned char min;
    unsigned char den;
    unsigned char mesiac;
    unsigned short rok;
}DATUMACAS;

#define MAX_ZNAKOV 15

typedef struct vozidlo{
    char znacka[MAX_ZNAKOV];
    unsigned short id;
    double jednotkovaCena;
    double zvysenaJednotkovaCena;
    DATUMACAS okamihPozicania;
    DATUMACAS okamihVratenia;
}VOZIDLO;

typedef struct sklad{
    unsigned short pocetZaznamov;
    VOZIDLO* vozidla;
}SKLAD;

typedef struct firma {
    double trzba;
}FIRMA;

#endif //MAIN_C_STRUKTURY_H
