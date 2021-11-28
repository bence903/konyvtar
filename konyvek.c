#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "konyvek.h"
#include "debugmalloc.h"
#include "olvasok.h"


char *ujSorKi(char *str){
    int n = 0;
    while (str[n] != '\0')
    {
        if (str[n] == '\n')
            str[n] = '\0';
        else
            n++;
        
    }

    return str;
    
}

char *kisbetu(char *str){
    int n = 0;
    while (str[n] != '\0')
    {
        str[n] = tolower(str[n]);
        n++;
    }
    return str;
}
//Új könyvek eltárolására szolgáló függvény
konyvek *konyv_hozza(konyvek *p){

    int n = 0;
    int ev;
    char cim[101];
    char szerzo[51];
    char tema[21];

    konyvek *uj;
    uj = (konyvek*) malloc(sizeof(konyvek));
    uj->kov = p;
    printf("\nKérem a könyv adatait:\n");
    printf("\nCím: ");
    fgetc(stdin);

    fgets(cim, 100, stdin);
    strcpy(cim,ujSorKi(cim));
    
    printf("\nSzerző: ");
    fgets(szerzo, 50, stdin);
    n = 0;
    strcpy(szerzo,ujSorKi(szerzo));
    printf("\nKiadás: ");
    scanf("%d",&ev);
    printf("\nTéma: ");
    fgetc(stdin);
    fgets(tema, 20, stdin);
    strcpy(tema,ujSorKi(tema));
    strcpy(uj->cim,cim);
    strcpy(uj->szerzo,szerzo);
    strcpy(uj->tema,tema);
    uj->kolcs = 0;
    uj->kiadas = ev;
    while (p != NULL)
        p = p->kov;
    p = uj;

    return p;
    
    
}

void konyv_torl(konyvek *lista){

    int n = 0;
    konyvek *ptr;
    ptr = lista;
    char torKo[101];
    char torIro[51];
    char kisKo[101];
    char kisIro[51];
    int kiad;
    printf("\nKönyv címe: ");
    fgetc(stdin);
    fgets(torKo, 100, stdin);
    printf("\nSzerző neve: ");
    fgets(torIro, 50, stdin);
    printf("\nKiadás éve: ");
    scanf("%d",&kiad);
    strcpy(torKo,ujSorKi(torKo));
    strcpy(torIro,ujSorKi(torIro));

    
    while (lista != NULL)
    {
        strcpy(kisKo,lista->cim);
        strcpy(kisIro,lista->szerzo);
       if (strcmp(kisbetu(torKo),kisbetu(kisKo))==0 && strcmp(kisbetu(torIro),kisbetu(kisIro))==0 && kiad == lista->kiadas)
        {
            ptr->kov = lista->kov;
            free(lista);
            printf("\nA törlés sikeres volt!");
            return;
        }
        else
        {
            ptr = lista;
            lista = lista->kov;
        }
    }
    printf("\nNincs ilyen elem!");
    
    
}


// Könyvek listának a felszabadítása
void konyv_felsz(konyvek *tomb){

    konyvek *p;
    while (tomb !=NULL)
    {
        p = tomb;
        tomb = tomb->kov;
        free(p);
    }

    
}

// Könyvek keresése szempontok alapján

