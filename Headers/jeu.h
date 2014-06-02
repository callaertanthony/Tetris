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

int sauvegarderFenetre(WINDOW *fenetre);

int recupererFenetre(WINDOW *fenetre);

#endif
