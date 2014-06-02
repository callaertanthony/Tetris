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

WINDOW *creerFenetreJeu();

WINDOW *creerFenetrePreview();

void pieceDansFenetreJeu(WINDOW *jeu_f, piece_s piece);

void pieceDansFenetrePreview(WINDOW *preview, piece_s piece);

void afficherJeu(WINDOW *jeu_f, int plateau[HAUTEUR_PLATEAU][LARGEUR_PLATEAU], piece_s piece);
#endif
