#include "fileReader.h"


int checkFormat( FILE *f )
{
    int x;
    int *i;
  //  printf("im in\n");
    fread(i, 1, 4, f);
    if(*i == 1381122627) 
    {
          x = 1;
         // *i = 0;
          fread(i, 1, 1, f);
        //  printf("%d\n", *i);
    }
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

void readRLE( FILE *f, int kol )
{
        //char *x = "zapis.txt";
        FILE *fw = fopen ("zapis", "w");
        int p[4], i;
        int*pom;
        for( i = 0; i < 4; i++ )
        {
              fread(pom, 1, 2, f);
              p[i] =*pom;
             *pom = 0;
        }
        for( i = 2; i <= 12; i+=2 )
        {
        fread(pom, 1, 2, f);
       *pom = 0;
        }
        fread(pom, 1, 5, f); // counter slow kodowych
        int ile =*pom;
        fread(pom, 1, 4, f);
        int col = 0, row = 1;
        char wp;
        while(ile--)
        {
              fread(pom, 1, 1, f); // separator
             *pom = 0;
              fread(pom, 1, 1, f); // wall or path
              wp =*pom;
             *pom = 0;
              fread(pom, 1, 1, f); // ile jest tych pol
              for( i = 0; i <=*pom; i++)
              {
                     if(col == kol)
                    {
                          col = 0;
                          fprintf(fw, "\n");
                          row++;
                    }
                    col++;
                    if(col == p[0] && row == p[1]) 
                    {
                          fprintf(fw, "P");
                          continue;
                    }
                    else if(col == p[2] && row == p[3])
                    {
                          fprintf(fw, "K");
                          continue;
                    }
                    fprintf(fw, "%c", wp);                   
              }
        }
        fclose(fw);
}

void rewrite(char x[][3], int kolumny){ //przepisuje dolne wiersze tablicy o jeden wiersz w gore

        for (int g = 0; g < 2; g++){

                for (int i = 0; i < kolumny; i++){

                        //do wyzszego wiersza nizszy
                        x[i][g] = x[i][g+1];
                }
        }

}


