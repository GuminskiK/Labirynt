#ifndef _mazeAnalyzer_
#define _mazeAnalyzer_

#include <stdlib.h>
#include <stdio.h>

#include "edge.h"
#include "define.h"

void analyzeMaze ( char x[][3], int kolumny, int *ost, int * edg, int * medg, int * unknown, int Graph[][8], int * rozdroza, int * edge);

void markDeadEnd ( int * edg, int medg[], int kolumny, int ID, int i);
void updateValue ( int * edg, int medg[], int kolumny);
void updateID ( int medg[], int ID, int newID, int kolumny );

int codeDirection (int ID, char X);
int decodeDirection (int ID);

#endif
