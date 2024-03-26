#include "graphCreator.h"

void createGraph(char x[][3], int kolumny, int * rozdroza, int * edge,int wiersze, FILE * in, FILE * out){

	//edg - do przetrzymywania liczb, medg - do przechowywania ID liczb
	int edg[kolumny -1];
	int medg[kolumny -1];

        int ost = 0;
        int unknown = -3;

	//sprawdzamy czy miejsce sie zaalokowalo
	if (edg == NULL || medg == NULL) {

 	   fprintf(stderr, "Nie można zaalokować pamięci\n");
 	   exit(EXIT_FAILURE);
	}	
	
	//wypelniamy arraye wartościami, jakie ma sciana bo nie czytamy tym razem pierwszej linijki
	for(int u = 0; u< kolumny-1; u++){
		edg[u] = -1;
		medg[u] = -1;
	}

	rewind(in);
	ost = 0;
        unknown = -3;
	
	int Graph[(*rozdroza)+1][8];
	for (int i = 0; i < (*rozdroza)+1; i++){
		for (int u = 0; u< 8; u++){
			Graph[i][u] = 0;
		}
	}
	//petla analizujaca labirynt
	for (int y = 0; y < wiersze-2; y++){
                
		if (y >= 1){
			
                        rewrite( x, kolumny);
                }

                readTXT( x, in, y);
                analyzeMaze(x, kolumny, &ost, edg, medg, &unknown, Graph, rozdroza, edge);
		    
        }

	for (int i = 1; i < (*rozdroza) + 1; i++){
		printf("GRAPH ID:%i Połączenia: N:%i L:%i E:%i L:%i P:%i L:%i W:%i L:%i\n", i, Graph[i][0], Graph[i][4], Graph[i][1], Graph[i][5], Graph[i][2], Graph[i][6], Graph[i][3], Graph[i][7]);

	}

	writeFile( out, rozdroza, Graph);
}
