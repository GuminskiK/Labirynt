#include "fileReader.h"


int checkFormat( FILE *f )
{
	int x;
        char c = getc(f);
        if( isdigit(c) ) x = 1; // plik binarny
	else x = 2; // plik tekstowy txt
	
	return x;
}

void readTXT(char x[][3], FILE * f, int y){ //wczytuje wiersze do tablicy
	
        int c,i;

        // za pierwszym razem wczytujemy 3 linie
        if ( y == 0){

                for ( int g = 0; g < 3; g++){

                        i = 0;

                        while( (c = fgetc(f)) != EOF && c != '\n'){

                                x[i][g] = c;
                                i++;

                        }
                }

        // potem mamy rewrite wiec wczytujemy tylko 1 dolna linijke
        }else{

                i = 0;

                while( (c = fgetc(f)) != EOF && c != '\n'){

                        x[i][2] = c;

                        i++;

               }
        }
}

void readRLE(char x[][3], FILE *f, int y)
{
        int c,i;

        // za pierwszym razem wczytujemy 3 linie
        if ( y == 0 ){

                for ( int g = 0; g < 3; g++){

                        i = 0;

                        while( (c = fgetc(f)) != EOF && c != '\n'){

                                x[i][g] = c;
                                i++;

                        }
                }

        // potem mamy rewrite wiec wczytujemy tylko 1 dolna linijke
        }else{

                i = 0;

                while( (c = fgetc(f)) != EOF && c != '\n'){

                        x[i][2] = c;

                        i++;

               }
        }
}

void rewrite(char x[][3], int kolumny){ //przepisuje dolne wiersze tablicy o jeden wiersz w gore

        for (int g = 0; g < 2; g++){

                for (int i = 0; i < kolumny; i++){

                        //do wyzszego wiersza nizszy
                        x[i][g] = x[i][g+1];
                }
        }

}


