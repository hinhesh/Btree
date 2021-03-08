//
//  TP4.h
//  NF16_TP4
//
//  Created by How-Choong Inès on 14/12/2018.
//  Copyright © 2018 How-Choong Inès. All rights reserved.
//

#ifndef tp4
#define tp4

#include <stdio.h>
#include <stdlib.h>


struct Noeud {
    int val;
    struct Noeud* fg;
    struct Noeud* fd;
};
typedef struct Noeud T_Noeud;
typedef T_Noeud* T_Arbre;

T_Noeud* abr_creer_noeud(int valeur);

void abr_prefixe(T_Arbre abr);
void abr_inserer(int valeur,T_Arbre* abr);
T_Noeud* rechercher(int valeur,T_Arbre* abr);
T_Noeud* rechercherpere(int valeur, T_Arbre abr);
T_Noeud*rechercher_min(T_Arbre abr);
void abr_supprimer(int valeur,T_Arbre*abr);
void detruire_arbre (T_Arbre* abr );
int choixProgramme(void);
void abr_clone(T_Arbre original, T_Arbre *clone, T_Noeud* parent);


#endif
