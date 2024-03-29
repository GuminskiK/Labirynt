#ifndef _mazePreanalyzer_
#define _mazePreanalyzer_

#include <stdlib.h>
#include <stdio.h>
#include "define.h"

void countColumns(FILE * f, int * kolumny);
void countRows(FILE * f, int * wiersze);
void countNodes( char x[][3], int kolumny, int * rozdroza, int * wezel_P, int * wezel_K, int * PD, int * KD);

#endif
