#include <stdlib.h>
#include <stdio.h>

int main (int argc, char ** argc){

	FILE * f = fopen(argv[1],"r");

	if ( f == NULL){

                printf("\nNie udało się otworzyć pliku.\n");
                return 1;
        }



}
