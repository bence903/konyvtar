#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "olvasok.h"
#include "konyvek.h"
#include "debugmalloc.h"


char *ujSor_Ki(char *str){
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

char *kisBetu(char *str){
    int n = 0;
    while (str[n] != '\0')
    {
        str[n] = tolower(str[n]);
        n++;
    }
    return str;
}

 // Ez a függvény felel az új olvasók felvételére
olvasok *olv_hozza(olvasok *p){
    int n = 0, i;
    char nev[50];
    char lakc[100];
    int olv_id = 1;
    olvasok *uj;
    uj = (olvasok*) malloc(sizeof(olvasok));
    uj->kov = p;
    printf("\nKérem az olvasó adatait:\n");
    printf("\nNév: ");
    fgetc(stdin);

    fgets(nev, 50, stdin);
    strcpy(nev,ujSor_Ki(nev));
    
    printf("\nSzületési év: ");
    scanf("%d",&i);
    printf("\nLakcím: ");
    fgetc(stdin);
    fgets(lakc, 100, stdin);
    n = 0;
    strcpy(lakc,ujSor_Ki(lakc));
    
    strcpy(uj->nev, nev);
    strcpy(uj->lakc, lakc);
    uj->szul = i;
    while (p != NULL){
        olv_id = p->ID + 1;
        p = p->kov;
        
    }
    uj->ID = olv_id;
    p = uj;

    return p;
}

void olv_torl(olvasok *lista){

    int n = 0;
    olvasok *ptr;
    ptr = lista;
    char torNev[51];
    char kisNev[51];
    int szulev;
    printf("\nOlvasó neve: ");
    fgetc(stdin);
    fgets(torNev, 50, stdin);
    printf("\nSzületési éve: ");
    scanf("%d",&szulev);
    strcpy(torNev,ujSorKi(torNev));

    
    while (lista != NULL)
    {
        strcpy(kisNev,lista->nev);
       if (strcmp(kisbetu(torNev),kisbetu(kisNev))==0 && szulev == lista->szul)
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





// Ez a függvény felel az olvasok lista felszabadításáért
void olv_felsz(olvasok *tomb){
    olvasok *p;
    while (tomb !=NULL)
    {
        p = tomb;
        tomb = tomb->kov;
        free(p);
    }
}