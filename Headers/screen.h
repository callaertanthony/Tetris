/*
screen.h
------
@Author : Anthony Callaert
@Date : 29/05/2014
------
Prototypes des fonctions et variables pour l'affichage du jeu
*/
#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>
#include <stdlib.h>
#include "constantes.h"
#include "pieces.h"

int initialiserScreen();

void terminerScreen();

WINDOW *creerFenetre(int hauteur, int largeur, int y, int x);

void afficherPieceDansFenetre(WINDOW *fenetre, piece_s piece, int y, int x);
#endif
