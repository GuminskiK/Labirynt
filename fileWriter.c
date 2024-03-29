#include "fileWriter.h"

void writeFile( FILE * out, int * rozdroza, int Graph[][8], int wezel_p, int wezel_k, int PD, int KD){
	
	fprintf(out, "%i %i %i %i\n", wezel_p, wezel_k, PD, KD);

	for(int i = 1; i < (*rozdroza) + 1; i++){
		fprintf(out, "%i %i %i %i %i %i %i %i \n", Graph[i][0], Graph[i][4], Graph[i][1], Graph[i][5], Graph[i][2], Graph[i][6], Graph[i][3], Graph[i][7]);	
	}
}
