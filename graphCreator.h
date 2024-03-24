#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include "Czytaj.h"
#include "maze_coder.h"
#include "node.h"


void CreateGraph(char x[][3], int kolumny, int rozdroza, int * edge, int wiersze, FILE * f);

#endif

