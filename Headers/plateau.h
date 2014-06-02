/*
plateau.h
------
@Author : Anthony Callaert
@Date : 21/04/2014
------
Fonctions du plateau de jeu
 */
#ifndef PLATEAU_H
#define PLATEAU_H

#include "constantes.h"
#include "pieces.h"

/*
procédure initialiserPlateau
@param :
  -plateau : le plateau à initiliser
@return : null
------
initialise un plateau de jeu avec un encadrement de 1 et un contenu de 0
 */
void initialiserPlateau(int plateau[HAUTEUR_PLATEAU][LARGEUR_PLATEAU]);

/*
procédure afficherPlateauComplet
@param :
  -plateau : le plateau à afficher au complet
@return : null
 */
void afficherPlateauComplet(int plateau[HAUTEUR_PLATEAU][LARGEUR_PLATEAU]);

/*
procédure afficherPlateau
@param :
  -plateau : le plateau à afficher
@return : null
------
affiche que la partie visible pour le jeu, les 4 premières lignes sont ignorées
 */
void afficherPlateau(int plateau[HAUTEUR_PLATEAU][LARGEUR_PLATEAU]);

void imprimerCase(int x);

/*
procédure afficherPlateauJeu
@param :
  -plateau : le plateau à afficher
@return : null
------
affiche que la partie visible pour le jeu, les 4 premières lignes sont ignorées
n'affiche pas les cases vides
 */
void afficherPlateauJeu(int plateau[HAUTEUR_PLATEAU][LARGEUR_PLATEAU], piece_s piece);

#endif
