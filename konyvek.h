#ifndef KONYVEK_H
#define KONYVEK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// Könyvek adatstruktúrája
typedef struct konyvek
{
    char cim[101];
    char szerzo[51];
    int kiadas;
    char tema[21];
    char kolcs[51];
    struct konyvek *kov;
}konyvek;

konyvek *konyv_hozza(konyvek *p);

void konyv_felsz(konyvek *tomb);

void konyv_kereses(konyvek *p,int tip);

void konyv_torl(konyvek *lista);

char *kisbetu(char *str);

#endif