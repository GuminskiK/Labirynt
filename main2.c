#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "graphReader.h"
#include "mazeSolver.h"
#include "helpWriter.h"

int main (int argc, char ** argv){
	int opt;
        while( (opt = getopt(argc, argv, ":hf:")) != -1 )
        {
                switch(opt)
                {
                        case 'h':
                               writeHelp(); //wypisz pomoc
				return 0;
                        break;
                        case 'f':
                                FILE * f = fopen(optarg, "r");
                                if ( f == NULL){
                                        printf("\nNie udało się otworzyć pliku.\n");
                                        return 1;
                                }
				 int wezel_p, wezel_k, PD, KD; //do wczytania jakos
			        int rozdroza = -1;
				printf("START");
        			readAnalyze(f,&wezel_p, &wezel_k, &PD, &KD);
        			readNumber(&rozdroza, f);
       				manageSolving(f, &rozdroza, wezel_p, wezel_k, PD, KD);
				printf("STOP");

                        break;
                        case ':':
                                printf("Brak podanego pliku wejsciowego przy argumencie f!\n");
				return 1;
                        break;
                        case '?':
                                printf("Nieznany argument: %c\n", optopt);
				return 1;
                        break;
                }
        }
	return 0;
}
