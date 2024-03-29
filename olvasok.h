#ifndef OLVASOK_H
#define OLVASOK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "konyvek.h"

struct konyvek;

//Olvasók adatstruktúrája
typedef struct olvasok
{
    char nev[50];
    int szul;
    char lakc[100];
    int ID;
    struct olvasok *kov;
}olvasok;

olvasok *olv_hozza(olvasok *p);

void olv_felsz(olvasok *tomb);

char *ujSorKi(char *str);

char *kisBetu(char *str);

void olv_torl(olvasok *lista);



#endif