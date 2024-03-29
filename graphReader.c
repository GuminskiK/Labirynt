#include "graphReader.h"

void readGraph(int ID, int x[8], FILE * in) {

   char buf [1000];
   rewind(in);
   for( int i = 0; i  < ID; i++){
      fgets( buf, 1000, in); //spr
   }
   
   fscanf( in, "%i %i %i %i %i %i %i %i", &x[0], &x[1], &x[2], &x[3], &x[4], &x[5], &x[6], &x[7] );
}

void readAnalyze(FILE * f, int * wezel_p, int * wezel_k, int * PD, int * KD){

	fscanf(f, "%i %i %i %i", wezel_p, wezel_k, PD, KD);

}


void readNumber( int * rozdroza, FILE * f){
	
	char buf [2050];

	while (fgets(buf, 2050,f) != NULL){

        	*rozdroza += 1;

        }

}
