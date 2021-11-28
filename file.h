#ifndef FILE_H
#define FILE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include "konyvek.h"
#include "olvasok.h"

//konyvek *beo_konyv();
void konyv_ki(konyvek *p);
void olv_ki(olvasok *p);
void reverse_print(olvasok *list, FILE *fp);

#endif