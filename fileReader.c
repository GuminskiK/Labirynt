#include "fileReader.h"


int checkFormat( FILE *f )
{
    int x;
    int *i;
    fread(i, 1, 4, f);
    if(*i == 1381122627) x = 1; 
    else x = 2;
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

void readRLE( FILE *f, int *kol )
{
        char *x = "zapis.txt";
        FILE *fw = fopen (x, "w");
        int p[4], i;
        int *pom;
        fread(pom, 1, 9, f);
        *pom = 0;
        for( i = 0; i < 4; i++ )
        {
              fread(pom, 1, 2, f);
              p[i] = *pom;
              *pom = 0;
        }
        fread(pom, 1, 12, f);
        *pom = 0;
        fread(pom, 1, 5, f);
        int ile = *pom;
        fread(pom, 1, 5, f);
        int col = 0, row = 1;
        while(ile--)
        {
              col++;
              *pom = 0;
              fread(pom, 1, 1, f);
              *pom = 0;
              fread(pom, 1, 1, f);
              if((col == p[0]) && (row == p[1])) 
              {
                    fprintf(fw, "P");
                    continue;
              }
              else if(col == p[2] && row == p[3])
              {
                    fprintf(fw, "K");
              }
              fprintf(fw, "%c", *pom);
              if(col == *kol)
              {
                    col = 0;
                    row++;
                    fprintf(fw, "\n");
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


