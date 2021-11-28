#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"

#include "debugmalloc.h"
#include "konyvek.h"
#include "olvasok.h"


// Ez a függvény a menü működéséért és, az aktuálisan használt 
// adatmanipulációs függvények meghívásáért felelős

// Megkapja a két listát és azokkal dolgozik
char *UjSorKi(char *str){
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

void konyv_kereses(konyvek *p,olvasok *ptr,int tip){

    int n = 0;
    char kisKer[101];
    char kereses[101];
    if(tip == 1){

        printf("Keresés: ");
        fgetc(stdin);
        fgets(kereses, 100, stdin);
        strcpy(kereses,UjSorKi(kereses));
            
        while (p != NULL)
        {
            strcpy(kisKer,p->cim);
            if(strcmp(kisbetu(kisKer),kisbetu(kereses))==0)
            {
                printf("\n%s, %s, %d, %s, ",p->cim,p->szerzo,p->kiadas,p->tema);
                while (ptr != NULL)
                {
                    if (ptr->ID == p->kolcs)
                    {
                        printf("%s",ptr->nev);
                        return;
                    }
                    ptr = ptr->kov;
                    
                }
                
                return;
            }
            p = p->kov;
        }
        printf("\nNincs ilyen könyv!");
        
    }
    else if(tip == 2){
        
        printf("Keresés: ");
        fgetc(stdin);
        fgets(kereses, 50, stdin);
        strcpy(kereses,UjSorKi(kereses));
        while (p != NULL)
        {
            strcpy(kisKer,p->szerzo);
            if(strcmp(kisbetu(kisKer),kisbetu(kereses))==0)
            {
                printf("\n%s, %s, %d, %s, ",p->cim,p->szerzo,p->kiadas,p->tema);
                while (ptr != NULL)
                {
                    if (ptr->ID == p->kolcs)
                    {
                        printf("%s",ptr->nev);
                        return;
                    }
                    ptr = ptr->kov;
                    
                }
                
            }
            p = p->kov;
        }
        printf("\nNincs ilyen könyv!");
    }
    else if(tip == 3){
        printf("Keresés: ");
        scanf("%d",&n);
        while (p != NULL)
        {
            if(p->kiadas == n)
            {
                printf("\n%s, %s, %d, %s, ",p->cim,p->szerzo,p->kiadas,p->tema);
                while (ptr != NULL)
                {
                    if (ptr->ID == p->kolcs)
                    {
                        printf("%s",ptr->nev);
                        return;
                    }
                    ptr = ptr->kov;
                    
                }
                
            }
            p = p->kov;
        }
        //printf("\nNincs ilyen könyv!");
    }
    else{

        printf("Keresés: ");
        fgetc(stdin);
        fgets(kereses, 21, stdin);
        strcpy(kereses,UjSorKi(kereses));
        while (p != NULL)
        {
            strcpy(kisKer,p->tema);
            if(strcmp(kisbetu(kisKer),kisbetu(kereses))==0)
            {
                printf("\n%s, %s, %d, %s, ",p->cim,p->szerzo,p->kiadas,p->tema);
                while (ptr != NULL)
                {
                    if (ptr->ID == p->kolcs)
                    {
                        printf("%s",ptr->nev);
                        return;
                    }
                    ptr = ptr->kov;
                    
                }
                
            }
            p = p->kov;
        }
        //printf("\nNincs ilyen könyv!");
    }
}

void olv_kereses(olvasok *p, konyvek *ptr){

    int n = 0, i;
    char nev[51];
    char kisNev[51];
    char kisNev2[51];
    printf("\nNév: ");
    fgetc(stdin);
    fgets(nev, 50, stdin);
    printf("\nSzületési év: ");
    scanf("%d",&i);
    strcpy(nev,UjSorKi(nev));
            
    while (p != NULL)
    {
        strcpy(kisNev, p->nev);
        if(strcmp(kisBetu(kisNev),kisBetu(nev))==0 && p->szul == i)
        {
            printf("\n%s, %d, %s, %d",p->nev,p->szul,p->lakc,p->ID);
            while (ptr != NULL)
            {

                if(ptr->kolcs == p->ID)
                {
                    printf("\n\t%s , %s, %d, %s",ptr->szerzo,ptr->cim,ptr->kiadas,ptr->tema);
                }
                ptr = ptr->kov;
            }
            
        }
        p = p->kov;
     }

    

}

void foglalas(konyvek *list){

    char fogCim[101];
    char fogSzer[51];
    char kisSzer[51];
    char kisCim[101];
    int fogEv;
    int fogID;
    int fogKiad;
    printf("\nFoglalandó könyv adatai");
    printf("\nKönyv címe: ");
    fgetc(stdin);
    fgets(fogCim, 100, stdin);
    printf("\nSzerző neve: ");
    fgets(fogSzer, 50, stdin);
    printf("\nKiadás éve: ");
    scanf("%d",&fogKiad);
    strcpy(fogCim,UjSorKi(fogCim));
    strcpy(fogSzer,UjSorKi(fogSzer));
    printf("\nFoglaló adatai");
    printf("\nID: ");
    scanf("%d",&fogID);

    while (list != NULL){
        strcpy(kisSzer,list->szerzo);
        strcpy(kisCim,list->cim);
        if (strcmp(kisBetu(kisSzer),kisBetu(fogSzer))==0 && strcmp(kisBetu(kisCim),kisBetu(fogCim))==0 && fogKiad == list->kiadas && list->kolcs == 0)
        {
            list->kolcs = fogID;
            printf("\nKönyv lefoglalva");
            return;
        }
        else if(strcmp(kisBetu(kisSzer),kisBetu(fogSzer))==0 && strcmp(kisBetu(kisCim),kisBetu(fogCim))==0 && fogKiad == list->kiadas && list->kolcs != 0)
        {
            if (fogID == 0)
            {
                list->kolcs = fogID;
                printf("\nFoglalás törölve!");
                return;
            }
            
            printf("\nA könyv már le lett foglalva!");
            return;
        }
        list = list->kov;
        
    }
    printf("\nNincs ilyen könyv!");

    


}

void menu(olvasok *olv, konyvek *konyv){

    int n, k, m;
    while (n != 3){

        // Főmenü
        printf("\nKérem válasszon a menüpontok közül:\n");
        printf(" 1, Olvasók\n");
        printf(" 2, Könyvek\n");
        printf(" 3, Kilépés\n");

        scanf("%d",&n);
        printf("\n");

        switch (n)
        {
        case 1:
            
            // Olvasók menüje
            while(k != 5){
                printf("\nKérem válasszon a menüpontok közül:\n");
                printf("1, Hozzáadás\n");
                printf("2, Törlés\n");
                printf("3, Keresés\n");
                printf("4, Kölcsönzés\n");
                printf("5, Vissza\n\n");

                scanf("%d",&k);
                printf("\n");

                switch (k)
                {
                case 1:
                    olv = olv_hozza(olv);
                    break;
                case 2:
                    olv_torl(olv);
                    break;
                case 3:
                    olv_kereses(olv,konyv);
                    break;
                case 4:
                    foglalas(konyv);
                    break;
                case 5:
                    break;
                default:
                    printf("\nNincs ilyen menüpont");
                    break;
                }
            }
            k = 0;
            break;
        
        case 2:

            // Könyvek menüje
            while(k != 4){
                printf("\nKérem válasszon a menüpontok közül:\n");
                printf("1, Hozzáadás\n");
                printf("2, Törlés\n");
                printf("3, Keresés\n");
                printf("4, Vissza\n");

                scanf("%d",&k);
                printf("\n");

                switch (k)
                {
                    case 1:
                        //Könyv hozzáadása
                        konyv = konyv_hozza(konyv);
                        break;
                    case 2:
                        konyv_torl(konyv);
                        break;
                    case 3:
                        // Könyv keresés
                        printf("\nKérem válasszon a menüpontok közül:\n");
                        printf("1, Cím\n");
                        printf("2, Szerző\n");
                        printf("3, Kiadás\n");
                        printf("4, Téma\n");
                        printf("5, Vissza\n");

                        scanf("%d",&m);
                        printf("\n");

                        switch (m)
                        {
                            case 1:
                                konyv_kereses(konyv,olv,1);
                                break;
                            case 2:
                                konyv_kereses(konyv,olv,2);
                                break;
                            case 3:
                                konyv_kereses(konyv,olv,3);
                                break;
                            case 4:
                                konyv_kereses(konyv,olv,4);
                                break;
                            case 5:
                                break;
                            default:
                                printf("\nNincs ilyen menüpont");
                                break;
                            
                        }
                        break;
                        
                    case 4:
                        break;
                    default:
                        printf("\nNincs ilyen menüpont");
                        break;
                }
            }
            k = 0;
            break;

        case 3: 

            konyv_ki(konyv);
            olv_ki(olv);
            // A dinamikusan foglalt listák felszabadítása
            
            olv_felsz(olv);
            konyv_felsz(konyv);
            break;
        default:
            printf("\nNincs ilyen menüpont");
            break;
        }
    }
}