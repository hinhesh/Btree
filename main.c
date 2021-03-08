#include <stdio.h>
#include "TP4.h"
#include "TP4_cousu.h"

int main() {
    int quitter=0;
    T_Arbre arbre=NULL;
    T_Arbre clone=NULL;
    T_Arbre_C arbrec=NULL;

    int n;
  
    do{
        switch(choixProgramme()){
                
            case 1:
                if (arbre!=NULL)
                {
                    printf("L'arbre précédent est écrasé\n");
                    detruire_arbre(&arbre);
                
                }
                printf("Valeur entrée\n");
                scanf("%d",&n);
                abr_inserer(n,&arbre);
                break;
            case 2:
                abr_prefixe(arbre);
                break;
            case 3:
                printf("Valeur entrée\n");
                scanf("%d",&n);
                abr_inserer(n,&arbre);
                break;
            case 4:
                printf("valeur à supprimer");
                scanf("%d",&n);
                abr_supprimer(n,&arbre);
                break;
            case 5:
                if (clone!=NULL)
            {
                printf("L'arbre cloné est écrasé\n");
                detruire_arbre(&clone);
                
            }
                abr_clone(arbre,&clone,NULL);
                abr_prefixe(clone);
                break;
            case 6:
                abr_prefixe(clone);
                break;
            case 7 :
                abr_to_cousu(arbre, &arbrec, NULL);
                break;
            case 8 :
                cousu_prefixe(arbrec);
                break;
            case 9 :
                cousu_infixe(&arbrec);
                break;
            case 10 :
                printf("Valeur entrée\n");
                scanf("%d",&n);
                cousu_inserer(n, &arbrec);
                break;
            default:
                quitter=1;
                
                        }
    }while(!quitter);//
    
    detruire_arbre(&arbre);
    detruire_arbre(&clone);
    detruire_arbre_c(&arbrec);
    
    
    return 0;
    
}

