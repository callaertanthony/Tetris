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

void initialiserPlateau(int plateau[HAUTEUR_PLATEAU][LARGEUR_PLATEAU]){
  int i, j;

  for(i = 0; i < HAUTEUR_PLATEAU; i++){
    for(j = 0; j < LARGEUR_PLATEAU; j++){
      if(j == 0 || j == LARGEUR_PLATEAU - 1 || i == HAUTEUR_PLATEAU - 1 ){
	plateau[i][j] = 1;
      } else {
	plateau[i][j] = 0;
      }
    }
  }
}

void afficherPlateauComplet(int plateau[HAUTEUR_PLATEAU][LARGEUR_PLATEAU]){
  int i, j;

  for(i = 0; i < HAUTEUR_PLATEAU; i++){
    for(j = 0; j < LARGEUR_PLATEAU; j ++){
      printf("%d", plateau[i][j]);
    }
    printf("\n");
  }
}

void afficherPlateau(int plateau[HAUTEUR_PLATEAU][LARGEUR_PLATEAU]){
  int i, j;

  for(i = 0; i < HAUTEUR_PLATEAU; i++){
    for(j = 0; j < LARGEUR_PLATEAU; j ++){
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

void afficherPlateauJeu(int plateau[HAUTEUR_PLATEAU][LARGEUR_PLATEAU], piece_s piece){
  int i, j;

  for(i = 0; i < HAUTEUR_PLATEAU; i++){
    for(j = 0; j < LARGEUR_PLATEAU; j ++){
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

void supprimerLignes(int plateau[HAUTEUR_PLATEAU][LARGEUR_PLATEAU], int y, int nb_lignes){
  int i, j;
  for(j = 0; j < nb_lignes; j++){
    for(i = 1; i < LARGEUR_PLATEAU - 1; i++){
      plateau[j+y][i] = 0;
    }
  }
  for(j = y; j > 0 + nb_lignes; j--){
    for(i = 1; i < LARGEUR_PLATEAU - 1; i ++){
      plateau[j][i] = plateau[j - nb_lignes][i];
    }
  }
}

int estLignePleine(int plateau[HAUTEUR_PLATEAU][LARGEUR_PLATEAU], int y){
  int i, x = 0;
  for(i = 1; i < LARGEUR_PLATEAU - 1; i++){
    if(plateau[y][i] == 0){
      x++;
    }
  }
  return x;
}

void supprimerLignesPleines(int plateau[HAUTEUR_PLATEAU][LARGEUR_PLATEAU]){
  int j = 0, y, nb_lignes;
  while(j < HAUTEUR_PLATEAU - 1){
    if(estLignePleine(plateau, j) == 0){
      y = j;
      nb_lignes++;
      while(j != HAUTEUR_PLATEAU - 2 && estLignePleine(plateau, j + 1) == 0){
	nb_lignes++;
	j++;
      }
      supprimerLignes(plateau, y, nb_lignes);
    }
    j++;
  }
}
