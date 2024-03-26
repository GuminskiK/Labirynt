#ifndef _graphCreator_
#define _graphCreator_

#include <stdio.h>
#include <stdlib.h>
#include "fileReader.h"
#include "mazeAnalyzer.h"
#include "fileWriter.h"

void createGraph(char x[][3], int kolumny, int * rozdroza, int * edge, int wiersze, FILE * in, FILE * out);

#endif

