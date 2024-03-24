#ifndef _maze_coder_
#define _maze_coder_

#include <stdlib.h>
#include <stdio.h>
#include "node.h"

void analyzemaze(char x[][3], int kolumny, int *ost, int * edg, int * medg, int * unknown, Node Graph[], int rozdroza, int * edge, int fo);
void addNode(Node Graph[], int IDH, int IDL, int Value, int kierunek, int rozdroza);
void graphManager(Node Graph[], int i, int rozdroza, int count);
int kierunek(char kierunek1, char kierunek2);

void IDdestroyer( int * edg, int medg[], int kolumny, int ID, int i);
void IDmanager( int * edg, int medg[], int kolumny);
void IDupdate( int medg[], int ID, int newID, int kolumny );

int kierunekkod (int ID, char X);
char kierunekdekod (int ID);

#endif
