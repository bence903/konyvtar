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
konyvek *konyv_hozza(konyvek *p)
{
    int ev = 0;
    char cim[101];
    char szerzo[51];
    char tema[21];

    konyvek *uj = (konyvek*) malloc(sizeof(konyvek));
    printf("\nKérem a könyv adatait:\n");
    printf("\nCím: ");

    //Könyv címe
    fgetc(stdin);
    fgets(cim, 100, stdin);
    cim[strcspn(cim, "\n")] = 0;

    //Könyv szerzője
    printf("\nSzerző: ");
    fgets(szerzo, 50, stdin);
    szerzo[strcspn(szerzo, "\n")] = 0;

    //Könyv kiadása
    printf("\nKiadás: ");
    scanf("%d",&ev);

    //Könyv témája
    printf("\nTéma: ");
    fgetc(stdin);
    fgets(tema, 20, stdin);
    tema[strcspn(tema, "\n")] = 0;

    strcpy(uj->cim,cim);
    strcpy(uj->szerzo,szerzo);
    strcpy(uj->tema,tema);
    uj->kolcs = 0;
    uj->kiadas = ev;
    uj->kov = NULL;

    if (p == NULL) {
        p = uj;
    } else {
        konyvek *last = p;
        while (last->kov != NULL) {
            last = last->kov;
        }
        last->kov = uj;
    }

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

