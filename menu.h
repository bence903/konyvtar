#ifndef MENU_H
#define MENU_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu(olvasok *olv, konyvek *konyv);

void olv_kereses(olvasok *p, konyvek *ptr);

void foglalas(konyvek *list);

void konyv_kereses(konyvek *p,olvasok *ptr,int tip);

char *UjSorKi(char *str);

#endif