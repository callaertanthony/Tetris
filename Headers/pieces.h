/*
pieces.h
------
@Author : Anthony Callaert
@Date : 22/05/2014
------
Prototypes des fonctions et variables des pièces du jeu
*/
#ifndef PIECE_H
#define PIECE_H

#include <stdio.h>
#include <stdlib.h>
#include "constantes.h"
#include "pieces.h"
#include "tableaux.h"

/*
  Déclaration des formes pour les pièces
  NB_PIECES : le nombre de pièces du jeu
  Chaque forme est déclinée sous 4 rotations possibles
*/
extern int formes[NB_PIECES][4][4][4];

/*
  Déclaration de la structure piece
  type_forme : le type de pièce
  indice_rotation : l'indice de la rotation allant de 0 à 3
  coordonnee : coordonnee dans le plateau de jeu
 */
struct piece_s{
  int forme[4][4];
  int indice_rotation;

  int coordonnee_x;
  int coordonnee_y;
};

typedef struct piece_s piece_s;

void placerDansCoin(int tab[4][4]);

/*
  Procédure afficherPiece
  affiche la piece donnée en parametre
  @param :
    -piece_s piece
 */
void afficherPiece(piece_s piece);

/*
  fonction initialiserPiece
  initialise la piece pointée en paramètre avec la forme indiquée
  @param :
    -piece_s *piece : pointeur de la piece à initialiser
    -int type_forme : type de la pièce
 */
int initialiserPiece(piece_s *piece, int type_forme);

/*
  fonction pivoterPiece
  pivote la piece pointée en paramètre
  @param :
    -pice_s *piece : pointeur de la pièce à pivoter
 */
void pivoterPiece(piece_s *piece);

void afficherFormeJeu(int tab[4][4]);

void afficherPieceJeu(piece_s piece);

enum direction_u {
  BAS, GAUCHE, DROITE
};

typedef enum direction_u direction_u;

void deplacerPiece(piece_s *piece, direction_u direction);

int estCoordonneePiece(int i, int j, piece_s piece);

int valeurPourPlateau(int i, int j, piece_s piece);

int peutDeplacer(piece_s piece, direction_u direction, int plateau[HAUTEUR_PLATEAU + 5][LARGEUR_PLATEAU + 2]);

void ajouterPiecePlateau(piece_s piece, int plateau[HAUTEUR_PLATEAU + 5][LARGEUR_PLATEAU + 2]);

#endif
