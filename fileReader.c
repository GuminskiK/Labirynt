#include "fileReader.h"
#include <stdio.h>

void readTXT(char x[][3], FILE * f, int y){ //wczytuje wiersze do tablicy
	
	//zmienne do operacji
        int c,i;

        // za pierwszym razem wczytujemy 3 linie
        if ( y == 0){

                for ( int g = 0; g < 3; g++){

                        i = 0;

                        //iterujemy po calym wierszu az do konca albo entera
                        while( (c = fgetc(f)) != EOF && c != '\n'){

                                x[i][g] = c;

                                //to jest while wiec samo sie nie zrobi
                                i++;

                        }
                }

        // potem mamy przepisz wiec wczytujemy tylko 1 dolna linijke
        }else{

                i = 0;

                while( (c = fgetc(f)) != EOF && c != '\n'){

                        x[i][2] = c;

                        //while
                        i++;

               }
        }
}

void rewrite(char x[][3], int kolumny){ //przepisuje dolne wiersze tablicy o jeden wiersz w gore

	//zwykla petla 2 linie a potem kolumny kolumn
        for (int g = 0; g < 2; g++){

                for (int i = 0; i < kolumny; i++){

                        //do wyzszego wiersza nizszy
                        x[i][g] = x[i][g+1];
                }
        }

}


