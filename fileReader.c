#include "fileReader.h"
#include <string.h>

int checkFormat( char *c )
{
    int x = strlen(c);
    int p;
   char l[4];
   strcpy(l, c + x - 3);
   if( strcmp(l,"bin") == 0 ) p = 1;
   else p = 2;
    return p;
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
        FILE *fw = fopen ("zapis.txt", "w");
        int p[4], i;
        int *pom;
        pom = malloc(sizeof(int));
        for( i = 0; i < 4; i++ )
        {
              fread(pom, 1, 2, f);
              p[i] =*pom;
             *pom = 0;
             printf("%d\n", p[i]);
        }
        for( i = 2; i <= 12; i+=2 )
        {
        fread(pom, 1, 2, f);
       *pom = 0;
        }
        fread(pom, 1, 4, f); // counter slow kodowych
        int ile =*pom;
        printf("%d to jest ile\n", ile);
        fread(pom, 1, 4, f);
        int col = 0, row = 1;
        char wp;
        //ile = 5;
        while(ile--)
        {
              fread(pom, 1, 1, f); // separator
             *pom = 0;
              fread(pom, 1, 1, f); // wall or path
              wp =*pom;
             // printf("%c\n", wp);
             *pom = 0;
              fread(pom, 1, 1, f); 
             // printf("ile jest tych pol: %d\n", *pom);// ile jest tych pol
              for( i = 0; i <=*pom; i++)
              {
                    
                     if(col == kol)
                    {
                          col = 0;
                          fprintf(fw, "\n");
                          row++;
                    }
                    col++;
                    if(col == p[0] && row == p[1]) fprintf(fw, "P");
                    else if(col == p[2] && row == p[3]) fprintf(fw, "K");
                    else if( wp == 'X' ) fprintf(fw, "X");
                    else if( wp == ' ' ) fprintf(fw, " ");
                    
                   // fprintf(fw, "%c", wp);                   
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


