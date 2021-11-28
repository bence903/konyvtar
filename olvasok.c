#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "olvasok.h"
#include "konyvek.h"



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
    while (p != NULL)
        p = p->kov;
    p = uj;

    return p;
}



void olv_kereses(olvasok *p, konyvek *ptr){

    int n = 0, i;
    char nev[50];
    printf("\nNév: ");
    fgetc(stdin);
    fgets(nev, 50, stdin);
    printf("\nSzületési év: ");
    scanf("%d",&i);
    strcpy(nev,ujSor_Ki(nev));
            
    while (p != NULL)
    {
        if(strcmp(p->nev,nev)==0 && p->szul == i)
        {
            printf("\n%s, %d, %s",p->nev,p->szul,p->lakc);
            while (ptr != NULL)
            {
                if(strcmp(ptr->kolcs,nev)==0)
                    printf("\n\t%s , %s, %d, %s",ptr->szerzo,ptr->cim,ptr->kiadas,ptr->tema);
                ptr = ptr->kov;
            }
            
        }
        p = p->kov;
     }

    

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