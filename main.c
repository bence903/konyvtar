#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "file.h"

#include "debugmalloc.h"
#include "konyvek.h"
#include "olvasok.h"
#include "menu.h"

// A main-be fogja a program meghívni a többi modult
// Egyelőre még csak az olvasók és a könyvek adatait tudja dinamikusan eltárolni a program

// A végleges programban fog szerepelni fájlkezelés illetve lehetőség lesz az adatok törlésére és keresésére is

int main(){

    olvasok *olv;
    konyvek *konyv;
    olv = NULL;
    konyv = NULL;
    menu(olv,konyv);
    return 0;
    
}