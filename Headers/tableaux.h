/*
tableaux.h
------
@Author : Anthony Callaert
@Date : 26/05/2014
------
Prototypes des fonctions de manipulation sur les tableaux
*/
#ifndef TABLEAUX_H
#define TABLEAUX_H

void copierTableau(int tab[4][4], int copie[4][4]);

void initialiserTableau(int tab[4][4]);

/*
  Procédure afficherTableau
  affiche la forme donnée en paramètre
  @param :
    -int tab[][] : le tableau
*/
void afficherTableau(int tab[4][4]);

void pivoterTableau(int tab[4][4]);

int compterVerticalesVides(int tab[4][4]);

int compterHorizontalesVides(int tab[4][4]);

#endif
