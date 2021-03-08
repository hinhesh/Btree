//
//  TP4.c
//  TP4
//
//  Created by How-Choong Inès on 10/12/2018.
//

#include "TP4.h"
T_Noeud* abr_creer_noeud(int valeur)
{
    T_Noeud* noeud = NULL;
    noeud=(T_Noeud*)malloc(sizeof(T_Noeud));
    noeud->fg=NULL;
    noeud->fd=NULL;
    noeud->val=valeur;
    return(noeud);
}

void abr_prefixe(T_Arbre abr)
{
    T_Noeud* noeud=NULL;
    noeud= abr;
    if (noeud==NULL)
        printf("L'arbre n'existe pas\n");
    else
    {
        printf ("Noeud --> %d \n",noeud->val);
        if(noeud->fg!=NULL)
            printf ("--> FG : %d ",noeud->fg->val);
        else
            printf("--> FG : NULL");
        if(noeud->fd!=NULL)
            printf ("--> FD : %d\n",noeud->fd->val);
        else
            printf("--> FD : NULL\n ");
        if(noeud->fg!=NULL)
            abr_prefixe(noeud->fg);
        if(noeud->fd!=NULL)
            abr_prefixe(noeud->fd);
    
    }
}

void abr_inserer(int valeur,T_Arbre* abr)
{
    T_Noeud*noeud=NULL;
    T_Noeud*nouv=NULL;

        noeud = *abr;
        nouv=abr_creer_noeud(valeur);
        if (noeud==NULL)
            *abr=nouv;
        else
        {
            if (valeur< noeud->val)
                abr_inserer(valeur,&((*abr)->fg));
            if (valeur> noeud-> val)
                abr_inserer(valeur,&((*abr)->fd));
            if (valeur==noeud->val)
                printf("noeud déjà existant");
        }
        
}


T_Noeud* rechercher(int valeur,T_Arbre* abr)
{
    T_Noeud* noeud;
    noeud=*abr;

    if (noeud==NULL)
    {
        return(NULL);
    }
    while ((noeud->val!=valeur)||(noeud==NULL))
    {
        if((noeud->fg!=NULL) && (valeur<noeud->val))
            noeud= noeud->fg;
    
        if ((noeud->fd!=NULL)&& (valeur> noeud->val))
            noeud=noeud->fd;
        
    }

        return(noeud);
}
T_Noeud* rechercherpere(int valeur, T_Arbre abr) // dans l'hypothèse que le noeud fils existe
{
    if(abr == NULL)
        return NULL;
    
    T_Noeud* noeud = abr;
    if (noeud->val==valeur)
        return NULL;
    
    if ((noeud->fg!=NULL && noeud->fg->val==valeur )|| (noeud->fd!=NULL && noeud->fd->val==valeur))
        return(noeud);
    else
    {
        if (noeud->val<valeur)
            return rechercherpere(valeur,noeud->fd);
    
    // if(noeud->val>valeur)
            return rechercherpere(valeur,noeud->fg);
    }
    
    
}

T_Noeud*rechercher_min(T_Arbre abr)
{
    T_Noeud* noeud_min;
    
    noeud_min=abr;
    if (noeud_min==NULL)
    {
        printf("arbre vide");
        return(abr);
    }
    else
        while(noeud_min->fg!=NULL)
            noeud_min=noeud_min->fg;
    return (noeud_min);
}

void abr_supprimer(int valeur,T_Arbre*abr)
{
    T_Noeud* noeud=NULL;
    T_Noeud*noeudpere=NULL;
    T_Noeud*noeud_remplace=NULL;
    
    noeud=rechercher(valeur,abr);
    if (noeud==NULL)
    {
        printf("Le noeud n'existe pas\n");
    }
    else
    {
        
        
        if (noeud->fg==NULL && noeud->fd==NULL) //Cas ou l'élement n'a pas de fils//
        {   noeudpere= rechercherpere(valeur,*abr);
            if (noeudpere!=NULL) // Cas où son père existe ou pas
            {
                if (noeudpere->val<valeur)
                    noeudpere->fd=NULL;
                else
                    noeudpere->fg=NULL;
            }
            else
                *abr=NULL;
        }
        
        if (noeud->fg!=NULL && noeud->fd!=NULL) //Cas ou il a deux fils//
        {
            
            //remplacer le noeud par le noeud min de l'abre droite//
            noeud_remplace=rechercher_min(noeud->fd);
            printf("%d",noeud_remplace->val);
            noeudpere=rechercherpere(noeud_remplace->val, *abr);
            noeud->val=noeud_remplace->val;
            printf("%d",noeud->val);

            noeudpere->fg=noeud_remplace->fd;


        }
        //Cas ou il a qu'un seul fils
        if (noeud->fg == NULL && noeud->fd!=NULL)
            
        {
            noeudpere= rechercherpere(valeur,*abr);
            if (noeudpere!=NULL)
        {
            if (noeudpere->fg==noeud)
                noeudpere->fg=noeud->fd;
            else
                noeudpere->fd=noeud->fd;
        }
            else
            *abr=noeud->fd;
        }
        
        if (noeud->fg!=NULL && noeud->fd==NULL)
        {
            noeudpere= rechercherpere(valeur,*abr);
            if (noeudpere!=NULL)
        {
            if (noeudpere->fg==noeud)
                noeudpere->fg=noeud->fg;
            else
                noeudpere->fd=noeud->fg;
            
        }
        else
            *abr=noeud->fg;
        }
    }
    
    
    //Cas ou il a qu'un seul fils
    
    
    
}
void abr_clone(T_Arbre original, T_Arbre *clone, T_Noeud* parent)
{
    if (parent==NULL)
        {
            T_Noeud* noeud = NULL;
            noeud=(T_Noeud*)malloc(sizeof(T_Noeud)); //Nouveau Noeud cousu
            parent=noeud;
            noeud->fg=NULL;
            noeud->fd=NULL;
        }
        
        parent->val=original->val;
        if (original->fg!=NULL)
        {
            T_Noeud* noeudg;
            noeudg=(T_Noeud*)malloc(sizeof(T_Noeud));
            noeudg->fg=NULL;
            noeudg->fd=NULL;
            parent->fg=noeudg;
            abr_clone(original->fg,clone,noeudg);
            
        }
        if (original->fd!=NULL)
        {
            T_Noeud* noeudd;
            noeudd=(T_Noeud*)malloc(sizeof(T_Noeud));
            noeudd->fd=NULL;
            parent->fd=noeudd;
            noeudd->fg=NULL;
            abr_clone(original->fd,clone,noeudd);
        }
          *clone=parent;
            
        }
        


    
    




void detruire_arbre (T_Arbre* abr )
{
    T_Noeud* noeud = *abr;
    
    if (noeud==NULL)
        return;
    
    if (noeud->fg!=NULL){
        detruire_arbre(&(noeud->fg));
        
    if (noeud->fd!=NULL)
        detruire_arbre(&(noeud->fd));
        
        free(noeud);
        
        *abr=NULL;
        
    }
}
    
int choixProgramme(){
    int choix = -1;
    int succesScan = 0;
    
    printf("---------------MENU PRINCIPAL---------------\n1. Créer un arbre ABR en préfixe \n2. Afficher l'ABR en préfixe\n3. Insérer une valeur dans l'ABR \n4. Supprimer une valeur de l'ABR \n5. Cloner l'ABR \n6. Afficher le clone en préfixe \n7 Créer un arbre binaire cousu à partir d'un ABR \n8 Afficher l'arbre binaire cousu en préfixe \n9 Afficher l'arbre binaire cousu en infixe \n10 Insérer une valeur dans l'arbre binaire cousu \n11 .Quitter\n--------------------------------------------\nChoisissez le numéro de l'option souhaitée : ");
    
    
    while( (succesScan = scanf("%d",&choix) ) != 1 || choix < 0 || choix > 11){
        printf("Non reconnu. Choisissez de nouveau le numéro de l'option souhaitée : ");
        if(!succesScan)
            scanf("%*[^\n]");
    }
    printf("\n");
    return choix;
}

