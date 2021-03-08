//
//  TP4_cousu.c
//  NF16_TP4
//
//  Created by How-Choong Inès on 31/12/2018.
//  Copyright © 2018 How-Choong Inès. All rights reserved.
//

#include "TP4_cousu.h"
#include "TP4.h"

T_Noeud_C* cousu_creer_noeud(int valeur)
{
    T_Noeud_C* noeud = NULL;
    noeud=(T_Noeud_C*)malloc(sizeof(T_Noeud_C));
    noeud->pd=1;
    noeud->pg=1;
    noeud->fg=NULL;
    noeud->fd=NULL;
    noeud->val=valeur;
    return (noeud);
}

void cousu_prefixe(T_Arbre_C arbre)
{
    T_Noeud_C* noeud=NULL;
    noeud= arbre;
    if (noeud==NULL)
        printf("L'arbre n'existe pas");
    else
    {
        printf ("Noeud --> %d \n",noeud->val);
        if(noeud->fg!=NULL)
            printf ("--> FG(%d) : %d ",noeud->pg,noeud->fg->val);
        else
            printf("--> FG(%d) : NULL",noeud->pg);
        if(noeud->fd!=NULL)
            printf ("--> FD(%d) : %d\n",noeud->pd,noeud->fd->val);
        else
            printf("--> FD(%d) : NULL\n",noeud->pd);
        if(noeud->pg==0)
            cousu_prefixe(noeud->fg);
        if(noeud->pd==0)
            cousu_prefixe(noeud->fd);
        
    }
    
}

void cousu_inserer(int valeur,T_Arbre_C *arbre)
{
    T_Noeud_C*noeud=NULL;
    T_Noeud_C*nouv=NULL;
    int lim=0;
    noeud = *arbre;
    nouv=cousu_creer_noeud(valeur);
    if (noeud==NULL) //Cas où l'arbre est vide
        *arbre=nouv;
    
    else
    {
        while ((noeud!=NULL) || (lim==1))
        {
            if (valeur<noeud->val)
            {
                if (noeud->pg==1)
                {
                    noeud->pg=0;
                    nouv->fg=noeud->fg;
                    noeud->fg=nouv;
                    nouv->fd=noeud;
                    lim=1;
                    
                }
            
            else
                    noeud=noeud->fg;
            }
            if(valeur>noeud->val)
            {
                if (noeud->pd==1)
                {
                    noeud->pd=0;
                    nouv->fd=noeud->fd;
                    noeud->fd=nouv;
                    nouv->fg=noeud;
                    lim=1;
                }
                else
                    noeud=noeud->fd;
            }
            if (valeur==noeud->val)
            {
                printf("noeud déjà existant");
                lim=1;
            }
        }
        
    }
}
void cousu_infixe (T_Arbre_C *arbre)
{
    T_Noeud_C* noeud=NULL;
    noeud=*arbre;
    if (noeud==NULL)
        printf("L'arbre n'existe pas");
    else
    {
        while(noeud->pg==0)// Trouver le noeud le plus à gauche
        {
            noeud=noeud->fg;
        }
        printf ("Noeud --> %d \n",noeud->val);
        
        while (noeud->fd!=NULL)
        {
            if (noeud->pd==1)
            {
                noeud=noeud->fd;
                printf ("Noeud --> %d \n",noeud->val);
            }
            else
            {   noeud=noeud->fd;
                while(noeud->pg==0)// Trouver le noeud le plus à gauche de l'arbre droit
                {
                    noeud=noeud->fg;
                }
                printf ("Noeud --> %d \n",noeud->val);
            }
        }
    }
    
    
}
void abr_to_cousu(T_Arbre abr, T_Arbre_C *clone,T_Noeud_C* parent)

{
    if (parent==NULL)
    {
        T_Noeud_C* noeudcousu = NULL;
        noeudcousu=(T_Noeud_C*)malloc(sizeof(T_Noeud_C)); //Nouveau Noeud cousu
        parent=noeudcousu;
        noeudcousu->fg=NULL;
        noeudcousu->fd=NULL;
    }
        
        parent->val=abr->val;
        if (abr->fg!=NULL)
        {
            parent->pg=0;
            T_Noeud_C* noeudcousug;
            noeudcousug=(T_Noeud_C*)malloc(sizeof(T_Noeud_C));
            if (parent->fg!=NULL)
                noeudcousug->fg=parent->fg;
            else
                noeudcousug->fg=NULL;
            parent->fg=noeudcousug;
            noeudcousug->fd=parent;
            abr_to_cousu(abr->fg,clone,noeudcousug);
            
        }
        else
        {
            parent->pg=1;
        }
        if (abr->fd!=NULL)
        {
            parent->pd=0;
            T_Noeud_C* noeudcousud;
            noeudcousud=(T_Noeud_C*)malloc(sizeof(T_Noeud_C));
            if (parent->fd!=NULL)
                noeudcousud->fd=parent->fd;
            else
                noeudcousud->fd=NULL;
            parent->fd=noeudcousud;
            noeudcousud->fg=parent;
            abr_to_cousu(abr->fd,clone,noeudcousud);
        }
        else
        {
            parent->pd=1;
            

        }
        
        *clone=parent;
    }



void detruire_arbre_c(T_Arbre_C *arbre)
{
    T_Noeud_C* noeud = *arbre;
    
    if (noeud==NULL)
        return;
    
    if (noeud->pg==1)
        detruire_arbre_c(&(noeud->fg));
    
    if (noeud->pd==1)
        detruire_arbre_c(&(noeud->fd));
    
    free(noeud);
    
    *arbre=NULL;
    
}

