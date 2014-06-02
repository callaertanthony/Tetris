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
  piece_s piece;
  int type_piece, i;
  int plateau[HAUTEUR_PLATEAU][LARGEUR_PLATEAU];

  initialiserPlateau(plateau);
  initialiserScreen();
  
  preview = creerFenetrePreview();
  jeu_f = creerFenetreJeu();
  wrefresh(jeu_f);
  refresh();
  sauvegarderFenetre(jeu_f);

  i = 0;
    type_piece = i%2;
    initialiserPiece(&piece, type_piece);
    for(i = 0; i < 10; i++){
      deplacerPiece(&piece, BAS);
    }
    pieceDansFenetrePreview(preview, piece);
    pieceDansFenetreJeu(jeu_f, piece);
    getch();
    while(peutDeplacer(piece, GAUCHE, plateau) == 0){
      deplacerPiece(&piece, GAUCHE);
      afficherJeu(jeu_f, plateau, piece);
      usleep(100000);
    }
    while(peutDeplacer(piece, DROITE, plateau) == 0){
      deplacerPiece(&piece, DROITE);
      afficherJeu(jeu_f, plateau, piece);
      usleep(100000);
    }
    ajouterPiecePlateau(piece, plateau);
    initialiserPiece(&piece, 1);
    afficherJeu(jeu_f, plateau, piece);
    while(peutDeplacer(piece, BAS, plateau) == 0){
      deplacerPiece(&piece, BAS);
      afficherJeu(jeu_f, plateau, piece);
      usleep(100000);
    }
    while(peutDeplacer(piece, GAUCHE, plateau) == 0){
      deplacerPiece(&piece, GAUCHE);
      afficherJeu(jeu_f, plateau, piece);
      usleep(100000);
    }
    while(peutDeplacer(piece, BAS, plateau) == 0){
      deplacerPiece(&piece, BAS);
      afficherJeu(jeu_f, plateau, piece);
      usleep(100000);
    }
  getch();
  terminerScreen();
  afficherPlateauJeu(plateau, piece);
  printf("%d\n", i);
  return EXIT_SUCCESS;
}
