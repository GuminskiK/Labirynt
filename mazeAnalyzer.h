#ifndef _mazeAnalyzer_
#define _mazeAnalyzer_

#include <stdlib.h>
#include <stdio.h>

#include "edge.h"

void analyzeMaze ( char x[][3], int kolumny, int *ost, int * edg, int * medg, int * unknown, edge_t Graph[], int rozdroza, int * edge, int fo);
void addEdge ( edge_t Graph[], int IDH, int IDL, int Value, int kierunek, int rozdroza);
void moveEdges ( edge_t Graph[], int i, int rozdroza, int count);
int direction2Number ( char kierunek1, char kierunek2);

void markDeadEnd ( int * edg, int medg[], int kolumny, int ID, int i);
void updateValue ( int * edg, int medg[], int kolumny);
void updateID ( int medg[], int ID, int newID, int kolumny );

int codeDirection (int ID, char X);
char decodeDirection (int ID);

#endif
