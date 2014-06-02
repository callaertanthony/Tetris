/*
tableaux.c
------
@Author : Anthony Callaert
@Date : 02/06/2014
------
Fonctions pour le jeu
 */

#include "jeu.h"

int sauvegarderFenetre(WINDOW *fenetre){
  FILE *piece_file;
  int status;

  piece_file = fopen(SAUVEGARDE, "w");
  if(piece_file == NULL){
    return EXIT_FAILURE;
  }
  status = putwin(fenetre, piece_file);
  if(status == ERR){
    return EXIT_FAILURE;
  }
  fclose(piece_file);
  wrefresh(fenetre);
  return EXIT_SUCCESS;
}

int recupererFenetre(WINDOW *fenetre){
  FILE *piece_file;

  piece_file = fopen(SAUVEGARDE, "r");
  if(piece_file == NULL){
    return EXIT_SUCCESS;
  }
  wclear(fenetre);
  fenetre = getwin(piece_file);
  if(fenetre == NULL){
    return EXIT_FAILURE;
  }
  fclose(piece_file);
  wrefresh(fenetre);
  return EXIT_SUCCESS;
}
