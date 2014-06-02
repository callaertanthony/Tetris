#include <stdlib.h>
#include <stdio.h>
#include "constantes.h"
#include "plateau.h"
#include "pieces.h"
#include "screen.h"
#include "jeu.h"
#include <ncurses.h>
#include <unistd.h>
#define DELAY 30000
int main(int argc, char **argv){
  WINDOW *jeu_f;
  piece_s piece;

  initialiserScreen();
  initialiserPiece(&piece, 1);
  jeu_f = creerFenetre(HAUTEUR_PLATEAU, (LARGEUR_PLATEAU * 2) - 2, 1, 1);
  wrefresh(jeu_f);
  refresh();
  afficherPieceDansFenetre(jeu_f, piece, piece.coordonnee_y, piece.coordonnee_x);
  getch();
  terminerScreen();
  return EXIT_SUCCESS;
}
