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

  printf("coordonnee_x : %d\n", piece.coordonnee_x);
  printf("coordonnee_y : %d\n", piece.coordonnee_y);

  afficherPlateauJeu(plateau, piece);


  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);

  afficherPlateauJeu(plateau, piece);

  if(peutDeplacer(piece, GAUCHE, plateau) == 0)
    deplacerPiece(&piece, GAUCHE);
  afficherPlateauJeu(plateau, piece);
  if(peutDeplacer(piece, GAUCHE, plateau) == 0)
    deplacerPiece(&piece, GAUCHE);
  afficherPlateauJeu(plateau, piece);
  if(peutDeplacer(piece, GAUCHE, plateau) == 0)
    deplacerPiece(&piece, GAUCHE);
  afficherPlateauJeu(plateau, piece);
  if(peutDeplacer(piece, GAUCHE, plateau) == 0)
    deplacerPiece(&piece, GAUCHE);
  afficherPlateauJeu(plateau, piece);

  if(peutDeplacer(piece, DROITE, plateau) == 0)
    deplacerPiece(&piece, DROITE);
  afficherPlateauJeu(plateau, piece);
  if(peutDeplacer(piece, DROITE, plateau) == 0)
    deplacerPiece(&piece, DROITE);
  afficherPlateauJeu(plateau, piece);
  if(peutDeplacer(piece, DROITE, plateau) == 0)
    deplacerPiece(&piece, DROITE);
  afficherPlateauJeu(plateau, piece);
  if(peutDeplacer(piece, DROITE, plateau) == 0)
    deplacerPiece(&piece, DROITE);
  afficherPlateauJeu(plateau, piece);
  if(peutDeplacer(piece, DROITE, plateau) == 0)
    deplacerPiece(&piece, DROITE);
  afficherPlateauJeu(plateau, piece);
  if(peutDeplacer(piece, DROITE, plateau) == 0)
    deplacerPiece(&piece, DROITE);
  afficherPlateauJeu(plateau, piece);
  if(peutDeplacer(piece, DROITE, plateau) == 0)
    deplacerPiece(&piece, DROITE);
  afficherPlateauJeu(plateau, piece);

  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  afficherPlateauJeu(plateau, piece);
  
  ajouterPiecePlateau(piece, plateau);

  initialiserPiece(&piece, 0);

  afficherPlateauJeu(plateau, piece);

if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);

  afficherPlateauJeu(plateau, piece);

  if(peutDeplacer(piece, GAUCHE, plateau) == 0)
    deplacerPiece(&piece, GAUCHE);
  afficherPlateauJeu(plateau, piece);
  if(peutDeplacer(piece, GAUCHE, plateau) == 0)
    deplacerPiece(&piece, GAUCHE);
  afficherPlateauJeu(plateau, piece);
  if(peutDeplacer(piece, GAUCHE, plateau) == 0)
    deplacerPiece(&piece, GAUCHE);
  afficherPlateauJeu(plateau, piece);
  if(peutDeplacer(piece, GAUCHE, plateau) == 0)
    deplacerPiece(&piece, GAUCHE);
  afficherPlateauJeu(plateau, piece);

  if(peutDeplacer(piece, DROITE, plateau) == 0)
    deplacerPiece(&piece, DROITE);
  afficherPlateauJeu(plateau, piece);
  if(peutDeplacer(piece, DROITE, plateau) == 0)
    deplacerPiece(&piece, DROITE);
  afficherPlateauJeu(plateau, piece);
  if(peutDeplacer(piece, DROITE, plateau) == 0)
    deplacerPiece(&piece, DROITE);
  afficherPlateauJeu(plateau, piece);
  if(peutDeplacer(piece, DROITE, plateau) == 0)
    deplacerPiece(&piece, DROITE);
  afficherPlateauJeu(plateau, piece);
  if(peutDeplacer(piece, DROITE, plateau) == 0)
    deplacerPiece(&piece, DROITE);
  afficherPlateauJeu(plateau, piece);
  if(peutDeplacer(piece, DROITE, plateau) == 0)
    deplacerPiece(&piece, DROITE);
  afficherPlateauJeu(plateau, piece);
  if(peutDeplacer(piece, DROITE, plateau) == 0)
    deplacerPiece(&piece, DROITE);
  afficherPlateauJeu(plateau, piece);

  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  afficherPlateauJeu(plateau, piece);

  if(peutDeplacer(piece, GAUCHE, plateau) == 0)
    deplacerPiece(&piece, GAUCHE);
  if(peutDeplacer(piece, BAS, plateau) == 0)
    deplacerPiece(&piece, BAS);
  afficherPlateauJeu(plateau, piece);
  return EXIT_SUCCESS;
}
