/*
tableaux.c
------
@Author : Anthony Callaert
@Date : 22/05/2014
------
Fonctions pour les tableaux
 */
#include <stdlib.h>
#include <stdio.h>

void copierTableau(int tab[4][4], int copie[4][4]){
  int i, j;
  for(i = 0; i < 4; i++){
    for(j = 0; j < 4; j++){
      copie[i][j] = tab[i][j];
    }
  }
}

void initialiserTableau(int tab[4][4]){
  int i, j;
  for(i = 0; i < 4; i++){
    for(j = 0; j < 4; j++){
      tab[i][j] = 0;
    }
  }
}

void afficherTableau(int tab[4][4]){
  int i, j;
  for(i = 0; i < 4; i++){
    for(j = 0; j < 4; j++){
      printf("%d", tab[i][j]);
    }
    printf("\n");
  }
}

void pivoterTableau(int tab[4][4]){
  int temp[4][4];
  int i, j;
  for(i = 0; i < 4; i++){
    for(j = 0; j < 4; j++){
      temp[i][j] = tab[i][j];
    }
  }
  for(i = 0; i < 4; i++){
    for(j = 0; j < 4; j++){
      tab[i][j] = temp[3-j][i];
    }
  }
}
