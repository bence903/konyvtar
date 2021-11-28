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
                    break;
                case 3:
                    olv_kereses(olv,konyv);
                    break;
                case 4:
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
                                konyv_kereses(konyv,1);
                                break;
                            case 2:
                                konyv_kereses(konyv,2);
                                break;
                            case 3:
                                konyv_kereses(konyv,3);
                                break;
                            case 4:
                                konyv_kereses(konyv,4);
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