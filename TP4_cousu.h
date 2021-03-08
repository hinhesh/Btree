//
//  TP4_cousu.h
//  NF16_TP4
//
//  Created by How-Choong Inès on 31/12/2018.
//  Copyright © 2018 How-Choong Inès. All rights reserved.
//

#ifndef TP4_cousu_h
#define TP4_cousu_h

#include <stdio.h>
#include <stdlib.h>
#include "TP4.h"

struct Noeud_C {
    int val;
    struct Noeud_C* fg;
    struct Noeud_C* fd;
    int pd;
    int pg;
};
typedef struct Noeud_C T_Noeud_C;
typedef T_Noeud_C * T_Arbre_C;

T_Noeud_C* cousu_creer_noeud(int valeur);
void cousu_prefixe(T_Arbre_C arbre);
void cousu_inserer(int valeur,T_Arbre_C *arbre);
void cousu_infixe (T_Arbre_C *arbre);
void abr_to_cousu(T_Arbre abr, T_Arbre_C *clone,T_Noeud_C* parent);
void detruire_arbre_c(T_Arbre_C *arbre);

#endif /* TP4_cousu_h */
