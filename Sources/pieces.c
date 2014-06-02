/*
pieces.c
------
@Author : Anthony Callaert
@Date : 22/05/2014
------
Fonctions pour les pièces du jeu
 */

#include "pieces.h"

int formes[NB_PIECES][4][4] = {
  {
    /*
      indice : 0
      ------
      nom : O
      ------
      valeur : 2
    */
      {0,0,0,0},
      {0,2,2,0},
      {0,2,2,0},
      {0,0,0,0}
  },
  {
    /*
      indice : 1
      ------
      nom : S
      ------
      valeur : 2
    */
      {0,0,0,0},
      {0,0,3,3},
      {0,3,3,0},
      {0,0,0,0}
  }
};

void placerDansCoin(int tab[4][4]){
  int nb_h = 0;
  int nb_v = 0;
  int i, j;
  int temp[4][4];
  int x = 0;
  for(i = 3; i >= 0; i--){
    x = 0;
    for(j = 0; j < 4; j++){
      x += tab[i][j];
    }
    if(x == 0 && nb_h == 3-i){
      nb_h++;
    }
  }
  for(i = 0; i < 4; i++){
    x = 0;
    for(j = 0; j < 4; j++){
      x += tab[j][i];
    }
    if(x == 0 && nb_v == i){
      nb_v++;
    }
  }
  if(nb_v > 0){
    initialiserTableau(temp);
    for(i = 0; i < 4; i++){
      for(j = 0; j < 4; j++){
	if((j + nb_v) < 4){
	  temp[i][j] = tab[i][j + nb_v];
	}
      }
    }
    copierTableau(temp, tab);
  }
  if(nb_h > 0){
    initialiserTableau(temp);
    for(i = 3; i >= 0; i--){
      for(j = 0; j < 4; j++){
	if((i - nb_h) >= 0){
	  temp[i][j] = tab[i - nb_h][j];
	}
      }
    }
    copierTableau(temp, tab);
  }
}

void afficherPiece(piece_s piece){
  afficherTableau(piece.forme);
}

int initialiserPiece(piece_s *piece, int type_forme){
  int i, j, nb_h;
  if(type_forme < 0 || type_forme >= NB_PIECES){
    return EXIT_FAILURE;
  } else {
    for(i = 0; i < 4; i++){
      for(j = 0; j < 4; j++){
	piece->forme[i][j] = formes[type_forme][i][j];
      }
    }
    placerDansCoin(piece->forme);
    nb_h = compterHorizontalesVides(piece->forme);
    piece->coordonnee_x = 4;
    piece->coordonnee_y = - 3 +nb_h - nb_h;
    piece->indice_rotation = 0;
  }
  return EXIT_SUCCESS;
}

void pivoterPiece(piece_s *piece){
  if(piece->indice_rotation == 3){
    piece->indice_rotation = 0;
    pivoterTableau(piece->forme);
    placerDansCoin(piece->forme);
  } else {
    piece->indice_rotation += 1;
    pivoterTableau(piece->forme);
    placerDansCoin(piece->forme);
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
  afficherFormeJeu(piece.forme);
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
  return piece.forme[i-piece.coordonnee_y][j-piece.coordonnee_x];
}

int peutDeplacer(piece_s piece, direction_u direction, int plateau[HAUTEUR_PLATEAU][LARGEUR_PLATEAU]){
  int i, j, x, bool;
  switch(direction){
  case BAS:
    bool = 0;
    j = 0;
    while(j < 4 && bool == 0){
      i = 3;
      x = 0;
      while(x == 0 && i >= 0){
	if(piece.forme[i][j] != 0){
	  x += piece.forme[i][j];
	} else {
	  i--;
	}
      }
      if(x != 0){
	if(plateau[piece.coordonnee_y + i + 1][piece.coordonnee_x + j] != 0){
	  bool++;
	}
      }
      j++;
    }
    break;
  case GAUCHE:
    bool = 0;
    i = 0;
    while(i < 4 && bool == 0){
      j = 0;
      x = 0;
      while(x == 0 && j < 4){
	if(piece.forme[i][j] != 0){
	  x += piece.forme[i][j];
	} else {
	  j++;
	}
      }
      if(x != 0){
	if(plateau[piece.coordonnee_y + i][piece.coordonnee_x + j - 1] != 0){
	  bool++;
	}
      }
      i++;
    }
    break;
  case DROITE:
    bool = 0;
    i = 0;
    while(i < 4 && bool == 0){
      j = 3;
      x = 0;
      while(x == 0 && j >= 0){
	if(piece.forme[i][j] != 0){
	  x += piece.forme[i][j];
	} else {
	  j--;
	}
      }
      if(x != 0){
	if(plateau[piece.coordonnee_y + i][piece.coordonnee_x + j + 1] != 0){
	  bool++;
	}
      }
      i++;
    }
    break;
  default:
    bool = 1;
    break;
  }
  return bool;
}

void ajouterPiecePlateau(piece_s piece, int plateau[HAUTEUR_PLATEAU][LARGEUR_PLATEAU]){
  int i, j;
  for(i = 0; i < 4; i++){
    for(j = 0; j < 4; j++){
      if(piece.forme[i][j] != 0){
	plateau[piece.coordonnee_y + i][piece.coordonnee_x + j] = piece.forme[i][j];
      }
    }
  }
}
