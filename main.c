#include <stdlib.h>
#include <stdio.h>
#include "mazePreanalyzer.h"
#include "mazeAnalyzer.h"
#include "fileReader.h"
#include "graphCreator.h"



int main(int argc, char ** argv){
	
	if (argc < 2){
	
		printf("\nNależy podać plik wejściowy jako argument. Jeżeli potrzebujesz pomocy podaj w argumencie -h.\n");
		return 1;
	}

	FILE * in = fopen(argv[1], "r");
	FILE * out = fopen("out", "w");

	if ( in == NULL){
	
		printf("\nNie udało się otworzyć pliku.\n");
		return 1;
	}

	if ( out == NULL){

                printf("\nNie udało się otworzyć/stworzyć pliku wyjściowego.\n");
		return 1;
        }

	int kolumny = 0;
        int wiersze = 1;

        countColumns (in, &kolumny);
        countRows (in, &wiersze);


	printf("\nKolumny: %i Wiersze: %i\n", kolumny, wiersze);
	
	rewind(in);

	char x[kolumny][3];
	int rozdroza = 0;
	int wezel_p;
	int wezel_k;
	int PD;
	int KD;
	//petla do policzenia ile jest rozdroz
        for (int y = 0; y < wiersze-2; y++){

                //przepisujemy dopiero jak cos wczytamy dlatego od y >= 1
                if (y >= 1){

                        rewrite ( x, kolumny);
                }

                //wczytywanie
                readTXT ( x, in, y);

                //funkcja sprawdzajaca czy w trzech liniach w srodkowej sa rozdroza
                countNodes (x, kolumny, &rozdroza, &wezel_p, &wezel_k, &PD, &KD);

        }
	printf("\nRozdroza:%i\n", rozdroza);
	
	rewind(in);
	
	int edge = 0;
        //analiza labiryntu by stworzyc graf
        createGraph(x,kolumny, &rozdroza, &edge, wiersze, in, out, wezel_p, wezel_k, PD, KD);
	
	return 0;

}
