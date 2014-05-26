/*
pieces.c
------
@Author : Anthony Callaert
@Date : 22/04/2014
------
Fonctions pour les pièces du jeu
 */

#include <stdio.h>
#include <stdlib.h>
#include "constantes.h"
#include "pieces.h"

int formes[NB_PIECES][4][4][4] = {
  {
    /*
      indice : 0
      ------
      nom : O
      ------
      valeur : 2
    */
    {
      {0,0,0,0},
      {0,2,2,0},
      {0,2,2,0},
      {0,0,0,0}
    },
    {
      {0,0,0,0},
      {0,2,2,0},
      {0,2,2,0},
      {0,0,0,0}
    },
    {
      {0,0,0,0},
      {0,2,2,0},
      {0,2,2,0},
      {0,0,0,0}
    },
    {
      {0,0,0,0},
      {0,2,2,0},
      {0,2,2,0},
      {0,0,0,0}
    }
  },
  {
    /*
      indice : 1
      ------
      nom : S
      ------
      valeur : 2
    */
    {
      {0,0,0,0},
      {0,0,3,3},
      {0,3,3,0},
      {0,0,0,0}
    },
    {
      {0,0,3,0},
      {0,0,3,3},
      {0,0,0,3},
      {0,0,0,0}
    },
    {
      {0,0,0,0},
      {0,0,3,3},
      {0,3,3,0},
      {0,0,0,0}
    },
    {
      {0,0,3,0},
      {0,0,3,3},
      {0,0,0,3},
      {0,0,0,0}
    }
  }
};

void afficherForme(int tab[4][4]){
  int i, j;
  
  for(i = 0; i < 4; i++){
    for(j = 0; j < 4; j++){
      printf("%d", tab[i][j]);
    }
    printf("\n");
  }
}

void afficherPiece(piece_s piece){
  afficherForme(formes[piece.type_forme][piece.indice_rotation]);
}

int initialiserPiece(piece_s *piece, int type_forme){
  if(type_forme < 0 || type_forme >= NB_PIECES){
    return EXIT_FAILURE;
  } else {
    piece->type_forme = type_forme;
    piece->indice_rotation = 0;
  }
  return EXIT_SUCCESS;
}

void pivoterPiece(piece_s *piece){
  if(piece->indice_rotation == 3){
    piece->indice_rotation = 0;
  } else {
    piece->indice_rotation += 1;
  }
}

void afficherFormeJeu(int tab[4][4]){
  int i, j;
  
  for(i = 0; i < 4; i++){
    for(j = 0; j < 4; j++){
      if(tab[i][j] == 0){
	printf(" ");
      } else {
	printf("%d", tab[i][j]);
      }
    }
    printf("\n");
  }
}

void afficherPieceJeu(piece_s piece){
  afficherFormeJeu(formes[piece.type_forme][piece.indice_rotation]);
}

void deplacerPiece(piece_s *piece, direction_u direction){
  switch(direction){
  case BAS:
    piece->coordonnee_y += 1;
    break;
  case GAUCHE:
    piece->coordonnee_x -= 1;
    break;
  case DROITE:
    piece->coordonnee_x += 1;
    break;
  default:
    break;
  }
}

int estCoordonneePiece(int i, int j, piece_s piece){
  if(i >= piece.coordonnee_y && i < piece.coordonnee_y + 4){
    if(j >= piece.coordonnee_x && j < piece.coordonnee_x + 4){
      return 0;
    } else {
      return 1;
    }
  } else {
    return 1;
  }
}

int valeurPourPlateau(int i, int j, piece_s piece){
  return formes[piece.type_forme][piece.indice_rotation][i-piece.coordonnee_y][j-piece.coordonnee_x];
}
