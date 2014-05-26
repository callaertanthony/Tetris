#include <stdlib.h>
#include <stdio.h>
#include "constantes.h"
#include "plateau.h"
#include "pieces.h"

int main(int argc, char **argv){
  piece_s piece;
  int plateau[HAUTEUR_PLATEAU + 5][LARGEUR_PLATEAU + 2];

  initialiserPlateau(plateau);
  initialiserPiece(&piece, 1);

  afficherPieceJeu(piece);
  printf("\n");

  piece.coordonnee_x = 5;
  piece.coordonnee_y = 8;
  
  afficherPlateau(plateau);
  printf("\n");

  afficherPlateauJeu(plateau, piece);
  return EXIT_SUCCESS;
}
