#ifndef OLVASOK_H
#define OLVASOK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "konyvek.h"

//Olvasók adatstruktúrája
typedef struct olvasok
{
    char nev[50];
    int szul;
    char lakc[100];
    struct olvasok *kov;
}olvasok;

olvasok *olv_hozza(olvasok *p);

void olv_felsz(olvasok *tomb);

void olv_kereses(olvasok *p, konyvek *ptr);

#endif