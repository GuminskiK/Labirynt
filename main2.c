#include <stdlib.h>
#include <stdio.h>
#include "graphReader.h"
#include "mazeSolver.h"


int main (int argc, char ** argv){

	FILE * f = fopen(argv[1],"r");

	if ( f == NULL){

                printf("\nNie udało się otworzyć pliku.\n");
                return 1;
        }
	int wezel_p, wezel_k, PD, KD; //do wczytania jakos
	int rozdroza = -1;
	readAnalyze(f,&wezel_p, &wezel_k, &PD, &KD);
	readNumber(&rozdroza, f);
	manageSolving (f, &rozdroza, wezel_p, wezel_k, PD, KD);
	return 0;
}
