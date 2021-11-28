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
   
   reverse_print(list->kov,fp);
   fprintf(fp,"%s;%s;%d;%s;%s\n",list->szerzo,list->cim,list->kiadas,list->tema,list->kolcs);
   
}


/*konyvek *beo_konyv(){
    int n;
    konyvek *konyv;

    
    if (access("konyvek.txt",F_OK)!=0)
    {
        fp = fopen("konyvek.txt","w");
        konyv = (konyvek*) malloc(sizeof(konyvek));
    }
    else{ 
        fp = fopen("konyvek.txt", "r");
        konyv = (konyvek*) malloc(n*sizeof(konyvek));
        while (fp != EOF)
        {
            scanf("%s;%s;%d;%s;%s",konyv[n].szerzo,konyv[n].cim,&konyv[n].kiadas,konyv[n].tema,konyv[n].kolcs);
        }
        
            
            
    }
        
    
    fclose(fp);
    return konyv;
}*/

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

