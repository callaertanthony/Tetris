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
      if(piece.forme[i][j] != 0){
	wattron(fenetre, COLOR_PAIR(piece.forme[i][j]));
	mvwprintw(fenetre, y + i, x + j*2, "  ");
	wattroff(fenetre, COLOR_PAIR(piece.forme[i][j]));
	wrefresh(fenetre);
      }
    }
  }
}
