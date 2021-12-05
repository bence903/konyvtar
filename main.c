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


int main(){

    olvasok *olv;
    konyvek *konyv;
    konyv = beo_konyv();
    olv = beo_olv();
    menu(olv,konyv);
    return 0;
    
}