#include "mazePreanalyzer.h"

#define G x[i][0]
#define P x[i+1][1]
#define L x[i-1][1]
#define D x[i][2]

#define D1(a) a == ' ' || a == 'P' || a == 'K'
#define D2(a,b,c,d,e) a == e || b == e || c == e || d == e

void countColumns(FILE * f, int * kolumny){ //funckcja liczaca kolumny
	        
        char c;

        while ((c = fgetc(f)) != EOF && c != '\n'){
                *kolumny += 1;

        }
}

void countRows(FILE * f, int * wiersze){ //funkcja liczaca wiersze

        char buf [2050];

        while ( fgets(buf, 2050,f) != NULL && ( buf[0] == 'X' || buf[0] == 'P' || buf[0] == 'K' )){

                *wiersze += 1;

        }


}


void countNodes(char x[][3], int kolumny, int * rozdroza, int * wezel_P, int * wezel_K){
	
        int i = 0;

        //iteracja po wierszu srodkowym bez skrajnych punktow
        for(i = 1; i < (kolumny - 1); i++){

                //rozdroze moze byc tylko na sciezce
                if (x[i][1] == ' '){

                        int h = 0;

                        //sprawdzamy czy pobliskie elementy tablicy sa sciezkami
                        if( D1 (G) ) {
                                h+=1;
                        }

                        if( D1 (L) ){
                                h+=1;
                        }

                        if( D1 (P) ){
                                h+=1;
                        }

                        if( D1 (D)){
                                h+=1;
                        }

                        //jezeli dookola sciezki sa 3 lub wiecej pol sciezki to jest to rozdroze
                        if( h >= 3 || D2( G, P, D, L, 'P') || D2(G, P, D, L, 'K')) {
                                
				*rozdroza +=1;
                                x[i][1] = 'O';
				
				//zapisanie numeru wezla obok wejscia/wyjscia
				if ( D2( G, P, D, L, 'P')){
				
					*wezel_P = *rozdroza;

				} else if ( D2( G, P, D, L, 'K')){
				
					*wezel_K = *rozdroza;
				
				}
                        }
              }
       }
}
