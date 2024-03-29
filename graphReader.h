#ifndef _graphReader_
#define _graphReader_

#include <stdlib.h>
#include <stdio.h>

void readGraph( int ID, int x[8], FILE * in);
void readNumber( int * rozdroza, FILE * f);
void readAnalyze( FILE * f ,int * wezel_p, int * wezel_k, int * PD, int * KD);
#endif
