/*
jeu.h
------
@Author : Anthony Callaert
@Date : 02/06/2014
------
Prototypes des fonctions pour le jeu
*/

#ifndef JEU_H
#define JEU_H

#define SAUVEGARDE "piece"

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include "constantes.h"
#include "plateau.h"
#include "pieces.h"
#include "screen.h"

int sauvegarderFenetre(WINDOW *fenetre);

int recupererFenetre(WINDOW *fenetre);

void jouer();

#endif
