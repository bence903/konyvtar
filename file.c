#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include "olvasok.h"
#include "konyvek.h"
#include "debugmalloc.h"
#include "file.h"


void reverse_print(olvasok *list, FILE *fp) {
   if(list == NULL) {
      
      return;
   }
   
   reverse_print(list->kov,fp);
   fprintf(fp,"%s;%d;%s;%d\n",list->nev,list->szul,list->lakc,list->ID);
   
}

void reverse_print2(konyvek *list, FILE *fp) {
   if(list == NULL) {
      
      return;
   }
   
   reverse_print2(list->kov,fp);
   fprintf(fp,"%s;%s;%d;%s;%d\n",list->szerzo,list->cim,list->kiadas,list->tema,list->kolcs);
   
}


konyvek *beo_konyv(){
    konyvek *elso = NULL;
    FILE *fp;
    fp = fopen("konyvek.txt","r");
    if (fp == NULL)
    {
        fp = fopen("konyvek.txt","w");
        fclose(fp);
        return elso;
    }
    else
    {
        char ideig[180];
        char CimBe[101];
        char SzerBe[51];
        char teBe[21];
        char id[4];
        char ev[5];
        int idBe, kiBe;
        int n = 0;

        while (fgets(ideig,180,fp))
        {
            konyvek *uj;
            uj = (konyvek*) malloc(sizeof(konyvek));
            n = 0;
            while (ideig[n]!='\0')
            {
                if (ideig[n]=='\n')
                    ideig[n] = '\0';
                n++;
                
            }
            n = 0;
            if(ideig[n]=='\0')
            {
                return elso;
            }
            int chaCount = 0;
            while (ideig[n]!=';')
            {
                SzerBe[n] = ideig[n];
                n++;
                
            }
            SzerBe[n] = '\0';
            n++;
            while (ideig[n]!=';')
            {
                CimBe[chaCount] = ideig[n];
                n++;
                chaCount++;
            }
            CimBe[chaCount] = '\0';
            chaCount = 0;
            n++;
            while (ideig[n]!=';')
            {
                ev[chaCount] = ideig[n];
                n++;
                chaCount++;
            }
            ev[chaCount] = '\0';
            chaCount = 0;
            n++;
            while (ideig[n]!=';')
            {
                teBe[chaCount] = ideig[n];
                n++;
                chaCount++;
            }
            teBe[chaCount] = '\0';
            chaCount = 0;
            n++;
            while (ideig[n]!='\0')
            {
                id[chaCount] = ideig[n];
                n++;
                chaCount++;
            }
            id[chaCount] = '\0';

            strcpy(uj->szerzo,SzerBe);
            strcpy(uj->cim,CimBe);
            kiBe = atoi(ev);
            idBe = atoi(id);
            uj->kiadas = kiBe;
            strcpy(uj->tema,teBe);
            uj->kolcs = idBe;
            uj->kov = elso;

            elso = uj;

        }
    
    fclose(fp);
    
    }
    return elso;
    
}

olvasok *beo_olv(){
    olvasok *elso = NULL;
    FILE *fp;
    fp = fopen("olvasok.txt","r");
    if (fp == NULL)
    {
        fp = fopen("olvasok.txt","w");
        fclose(fp);
        return elso;
    }
    else
    {
        char ideig[180];
        char NevBe[51];
        char LakcBe[51];
        char id[4];
        char szev[5];
        int idBe, szBe;
        int n = 0;

        while (fgets(ideig,180,fp))
        {
            olvasok *uj;
            uj = (olvasok*) malloc(sizeof(olvasok));
            n = 0;
            while (ideig[n]!='\0')
            {
                if (ideig[n]=='\n')
                    ideig[n] = '\0';
                n++;
                
            }
            n = 0;
            if(ideig[n]=='\0')
            {
                return elso;
            }
            int chaCount = 0;
            while (ideig[n]!=';')
            {
                NevBe[n] = ideig[n];
                n++;
                
            }
            NevBe[n] = '\0';
            n++;
            while (ideig[n]!=';')
            {
                szev[chaCount] = ideig[n];
                n++;
                chaCount++;
            }
            szev[chaCount] = '\0';
            chaCount = 0;
            n++;
            while (ideig[n]!=';')
            {
                LakcBe[chaCount] = ideig[n];
                n++;
                chaCount++;
            }
            LakcBe[chaCount] = '\0';
            chaCount = 0;
            n++;
            while (ideig[n]!='\0')
            {
                id[chaCount] = ideig[n];
                n++;
                chaCount++;
            }
            id[chaCount] = '\0';

            strcpy(uj->nev,NevBe);
            strcpy(uj->lakc,LakcBe);
            szBe = atoi(szev);
            idBe = atoi(id);
            uj->szul = szBe;
            uj->ID = idBe;
            uj->kov = elso;

            elso = uj;

        }
    
    fclose(fp);
    
    }
    return elso;
    
}

void konyv_ki(konyvek *p){

    FILE *fp;

    fp = fopen("konyvek.txt","w");
    
    reverse_print2(p,fp);
    fclose(fp);

}






void olv_ki(olvasok *p){

    FILE *fp;
    fp = fopen("olvasok.txt","w");
    reverse_print(p,fp);
    fclose(fp);

}

