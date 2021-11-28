#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include "olvasok.h"
#include "konyvek.h"
#include "debugmalloc.h"
#include "file.h"


FILE *fp;

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

    fp = fopen("konyvek.txt","w");
    
    while (p != NULL)
    {
        fprintf(fp,"%s;%s;%d;%s;%s\n",p->szerzo,p->cim,p->kiadas,p->tema,p->kolcs);
        p = p->kov;

    }
    fclose(fp);

}

void olv_ki(olvasok *p){

    fp = fopen("olvasok.txt","w");
    
    while (p != NULL)
    {
        fprintf(fp,"%s;%d;%s\n",p->nev,p->szul,p->lakc);
        p = p->kov;

    }
    fclose(fp);

}
