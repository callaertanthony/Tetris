/*
plateau.c
------
@Author : Anthony Callaert
@Date : 21/04/2014
------
Fonctions du plateau de jeu
 */
#include <stdio.h>
#include "constantes.h"
#include "pieces.h"

void initialiserPlateau(int plateau[HAUTEUR_PLATEAU + 5][LARGEUR_PLATEAU + 2]){
  int i, j;

  for(i = 0; i < HAUTEUR_PLATEAU + 5; i++){
    for(j = 0; j < LARGEUR_PLATEAU + 2; j++){
      if(j == 0 || j == LARGEUR_PLATEAU + 1 || i == HAUTEUR_PLATEAU + 4){
	plateau[i][j] = 1;
      } else {
	plateau[i][j] = 0;
      }
    }
  }
}

void afficherPlateauComplet(int plateau[HAUTEUR_PLATEAU + 5][LARGEUR_PLATEAU + 2]){
  int i, j;

  for(i = 0; i < HAUTEUR_PLATEAU + 5; i++){
    for(j = 0; j < LARGEUR_PLATEAU + 2; j ++){
      printf("%d", plateau[i][j]);
    }
    printf("\n");
  }
}

void afficherPlateau(int plateau[HAUTEUR_PLATEAU + 5][LARGEUR_PLATEAU + 2]){
  int i, j;

  for(i = 4; i < HAUTEUR_PLATEAU + 5; i++){
    for(j = 0; j < LARGEUR_PLATEAU + 2; j ++){
      printf("%d", plateau[i][j]);
    }
    printf("\n");
  }
}

void imprimerCase(int x){
  switch(x){
  case 0:
    printf(" ");
    break;
  case 1:
    printf("X");
    break;
  default:
    printf("%d", x);
    break;
  }
}

void afficherPlateauJeu(int plateau[HAUTEUR_PLATEAU + 5][LARGEUR_PLATEAU + 2], piece_s piece){
  int i, j;

  for(i = 4; i < HAUTEUR_PLATEAU + 5; i++){
    for(j = 0; j < LARGEUR_PLATEAU + 2; j ++){
      if(estCoordonneePiece(i, j, piece) == 0){
	if(valeurPourPlateau(i, j, piece) == 0){
	  imprimerCase(plateau[i][j]);
	} else {
	  printf("%d", valeurPourPlateau(i, j, piece));
	}
      } else {
	imprimerCase(plateau[i][j]);
      }
    }
    printf("\n");
  }
}
