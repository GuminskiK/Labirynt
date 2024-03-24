#include <stdlib.h>
#include <stdio.h>

#include "mazePreanalyzer.h"
#include "graphCreator.h"
#include "mazeAnalyzer.h"

int main (int argc, char ** argv){ //glowna funkcja
	
	//plik z labiryntem
	FILE * f = fopen(argv[1], "r");
	
	if (f == NULL) {
       		printf("Error opening the file.\n");
        	return 1;
    	}
	// wymiary labiryntu
	int kolumny = 0;
	int wiersze = 1;
	
	countColumns (f, &kolumny);
	countRows (f, &wiersze);
	
	printf("Kolumny: %i Wiersze: %i", kolumny, wiersze);
	
	//array do operowania na 3 linijkach
	char x [kolumny][3];
	
	//resetujemy pointera w pliku
	rewind(f);

	//po prostu enter	
	printf("\n");
	
	//zmienne do operacji
	int i,g = 0;
	
	//liczba rozdroz
	int rozdroza = 0;
	int edge = 0;
	int wezel_P = 0;
	int wezel_K = 0;
	
	//petla do policzenia ile jest rozdroz
	for (int y = 0; y < wiersze-2; y++){
		
		//przepisujemy dopiero jak cos wczytamy dlatego od y >= 1
		if (y >= 1){
			
			rewrite ( x, kolumny);
		}
		
		//wczytywanie
		readTXT ( x, f, y);

		//funkcja sprawdzajaca czy w trzech liniach w srodkowej sa rozdroza
		countNodes (x, kolumny, &rozdroza, &wezel_P, &wezel_P);

		//print_odczyt(x,kolumny);
	}
	
	//wypisanie ile rozdroz
	printf("\nRozdroza: %i \n", rozdroza);
	
	//resetujemy pointera w pliku ponownie bo do analizy bedziemy wczytywac od poczatku
	rewind(f);	

	//analiza labiryntu by stworzyc graf
	createGraph(x,kolumny, rozdroza, &edge, wiersze, f);
	
	//INT main
	return 0;
}
