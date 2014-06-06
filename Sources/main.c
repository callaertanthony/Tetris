#include <stdlib.h>
#include <stdio.h>
#include "constantes.h"
#include "plateau.h"
#include "pieces.h"
#include "screen.h"
#include "jeu.h"
#include <ncurses.h>
#include <unistd.h>
#include <time.h>

#define DELAY 30000
int main(int argc, char **argv){
  WINDOW *jeu_f, *preview;
  piece_s piece, piece_suivante;
  int type_piece = 0, jouer = 0;
  int plateau[HAUTEUR_PLATEAU][LARGEUR_PLATEAU];

  initialiserPlateau(plateau);
  initialiserScreen();
  
  preview = creerFenetrePreview();
  jeu_f = creerFenetreJeu();

  srand(time(NULL));
  type_piece = rand() % NB_PIECES;
  initialiserPiece(&piece, type_piece);
  pieceDansFenetrePreview(preview, piece);
  getch();
  
  while(jouer == 0){
    srand(time(NULL));
    type_piece = rand() % NB_PIECES;
    initialiserPiece(&piece_suivante, type_piece);
    pieceDansFenetrePreview(preview, piece_suivante);
    switch(getch()){
    case KEY_UP:
      jouer = 1;
      break;
    case KEY_DOWN:
      if(peutDeplacer(piece, BAS, plateau) == 0){
	deplacerPiece(&piece, BAS);
      }
      break;
    case KEY_RIGHT:
      if(peutDeplacer(piece, DROITE, plateau) == 0){
	deplacerPiece(&piece, DROITE);
      }
      break;
    case KEY_LEFT:
      if(peutDeplacer(piece, GAUCHE, plateau) == 0){
	deplacerPiece(&piece, GAUCHE);
      }
      break;
    case 'q':
      jouer = 1;
      break;
    }
    afficherJeuPiece(jeu_f, plateau, piece);
  }
  getch();
  terminerScreen();
  afficherPlateau(plateau);
  return EXIT_SUCCESS;
}
