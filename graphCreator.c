#include "graphCreator.h"

void createGraph(char x[][3], int kolumny, int rozdroza, int * edge,int wiersze, FILE * f){

	//edg - do przetrzymywania liczb, medg - do przechowywania ID liczb
	int edg[kolumny -1];
	int medg[kolumny -1];

        int ost = 0;
        int unknown = -3;
	
	edge_t gr[1];	

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
	
	int fo = 0;
	
	//petla liczaca edge
        for (int y = 0; y < wiersze-2; y++){

                if (y >= 1){

                        rewrite( x, kolumny);
                }

                readTXT( x, f, y);
                analyzeMaze(x, kolumny, &ost, edg, medg, &unknown, gr,rozdroza, edge, fo);

        }

	int Z = (*edge) + (rozdroza/7)  +3 ;
        edge_t Graph[Z];
	printf("Z %i E %i\n",Z, *edge);
	if (Graph == NULL) {

           fprintf(stderr, "Nie można zaalokować pamięci\n");
           exit(EXIT_FAILURE);
        }
	
	Graph[0].ID = 0;
        Graph[0].Value = 0;
        Graph[0].Direction = 0;
        Graph[0].X = 1;

        
	int count = 1;
	int i = 1;
	while( count <= rozdroza){
	
		Graph[i].ID = 0;
                Graph[i].Value = 0;
                Graph[i].Direction = 0;
                Graph[i].X = count + 7 <= rozdroza ? 7 : rozdroza - count;
		count += Graph[i].X;


		if(Graph[i].X == 0 && count == rozdroza){
			printf("GEN: %i %i", i,count);	
			Graph[i].X = 1;
			count++;
			//za maks
			Graph[i+1].ID = 0;
                	Graph[i+1].Value = 0;
                	Graph[i+1].Direction = 0;
			Graph[i+1].X = 0;
		}

		i++;
	}
	for(int u = 0; u< kolumny-1; u++){
                edg[u] = -1;
                medg[u] = -1;
        }
	
	for(int HU = 0; HU < Z; HU++){
                printf("HU: %i  ID: %i V:%i D:%i X: %i\n", HU, Graph[HU].ID, Graph[HU].Value, Graph[HU].Direction, Graph[HU].X);
        }
	printf("\n \n \n");
	fo++;
	rewind(f);
	ost = 0;
        unknown = -3;
	//petla analizujaca labirynt
	for (int y = 0; y < wiersze-2; y++){
                
		if (y >= 1){
			
                        rewrite( x, kolumny);
                }

                readTXT( x, f, y);
		//print_odczyt(x,kolumny);
                analyzeMaze(x, kolumny, &ost, edg, medg, &unknown, Graph, rozdroza, edge, fo);
		//for(int o = 1; o < kolumny -1 ; o++){
		//	printf("\n EDG: %i MEDG:%i  \n ", edg[o], medg[o]);
		//}
		
		//printf("\n");
		    
        }
	//printf("E%i, Z%i, R%i", *edge, Z +1, rozdroza);
	for(int HU = 0; HU < Z; HU++){	
		printf("HU: %i  ID: %i V:%i D:%i X: %i\n", HU, Graph[HU].ID, Graph[HU].Value, Graph[HU].Direction, Graph[HU].X);
	}

}
