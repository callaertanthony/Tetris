/*
screen.c
------
@Author : Anthony Callaert
@Date : 29/05/2014
------
Fonctions et variables pour l'affichage du jeu
*/
#include "screen.h"

int initialiserScreen(){
  int x, y;
  initscr();
  noecho();
  curs_set(FALSE);
  keypad(stdscr, TRUE);
  start_color();
  if(!has_colors()){
    endwin();
    printf("This terminal does not support colors\n");
    return EXIT_FAILURE;
  }
  getmaxyx(stdscr, y, x);
  printw("x : %d\n", x);
  printw("y : %d\n", y);
  init_pair(2, COLOR_WHITE, COLOR_GREEN);
  init_pair(3, COLOR_WHITE, COLOR_RED);
  clear();
  return EXIT_SUCCESS;
}

void terminerScreen(){
  endwin();
}

WINDOW *creerFenetre(int hauteur, int largeur, int y, int x){
  WINDOW *fenetre;
  fenetre = newwin(hauteur, largeur, y, x);
  refresh();
  box(fenetre, 0, 0);
  wrefresh(fenetre);
  return fenetre;
}

void afficherPieceDansFenetre(WINDOW *fenetre, piece_s piece, int y, int x){
  int i, j;
  for(i = 0; i < 4; i++){
    for(j = 0; j < 4; j++){
      if(piece.forme[i][j] != 0 && (y + i) != 0){
	wattron(fenetre, COLOR_PAIR(piece.forme[i][j]));
	mvwprintw(fenetre, y + i, x + j*2, "  ");
	wattroff(fenetre, COLOR_PAIR(piece.forme[i][j]));
	wrefresh(fenetre);
      }
    }
  }
}

WINDOW *creerFenetreJeu(){
  return creerFenetre(HAUTEUR_PLATEAU, LARGEUR_PLATEAU * 2 - 2, 1, 1);
}

WINDOW *creerFenetrePreview(){
  return creerFenetre(4 + 2, 4*2 + 2, 10, LARGEUR_PLATEAU * 2 + 2);
}

void pieceDansFenetreJeu(WINDOW *jeu_f, piece_s piece){
  afficherPieceDansFenetre(jeu_f, piece, piece.coordonnee_y, piece.coordonnee_x * 2-1);
}

void pieceDansFenetrePreview(WINDOW *preview, piece_s piece){
  wclear(preview);
  box(preview, 0, 0);
  afficherPieceDansFenetre(preview, piece, 1, 1);
}

void afficherJeuPiece(WINDOW *jeu_f, int plateau[HAUTEUR_PLATEAU][LARGEUR_PLATEAU], piece_s piece){
  int i, j;
  wclear(jeu_f);
  box(jeu_f, 0, 0);
  for(i=1; i < HAUTEUR_PLATEAU - 2; i++){
    for(j = 1; j < LARGEUR_PLATEAU - 1; j++){
      if(plateau[i][j] != 0){
	wattron(jeu_f, COLOR_PAIR(plateau[i][j]));
	mvwprintw(jeu_f, i, j*2 - 1, "  ");
	wattroff(jeu_f, COLOR_PAIR(plateau[i][j]));
	wrefresh(jeu_f);
      }
    }
  }
  pieceDansFenetreJeu(jeu_f, piece);
}

void afficherJeu(WINDOW *jeu_f, int plateau[HAUTEUR_PLATEAU][LARGEUR_PLATEAU]){
  int i, j;
  wclear(jeu_f);
  box(jeu_f, 0, 0);
  for(i=1; i < HAUTEUR_PLATEAU - 2; i++){
    for(j = 1; j < LARGEUR_PLATEAU - 1; j++){
      if(plateau[i][j] != 0){
	wattron(jeu_f, COLOR_PAIR(plateau[i][j]));
	mvwprintw(jeu_f, i, j*2 - 1, "  ");
	wattroff(jeu_f, COLOR_PAIR(plateau[i][j]));
	wrefresh(jeu_f);
      }
    }
  }
}
