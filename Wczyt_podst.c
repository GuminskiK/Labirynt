#include "Wczyt_podst.h"

void policz_kolumny(FILE * f, int * kolumny){ //funckcja liczaca kolumny
	
        //bufor do fgetc        
        char c;

        //petla do liczenia kolumn
        while ((c = fgetc(f)) != EOF && c != '\n'){
                *kolumny += 1;

        }
}

void policz_wiersze(FILE * f, int * wiersze){ //funkcja liczaca wiersze

        //bufor do fgets
        char buf [2050];

        //petla do liczenia wierszy
        while ( fgets(buf, 2050,f) != NULL && ( buf[0] == 'X' || buf[0] == 'P' || buf[0] == 'K' )){

                *wiersze += 1;

        }


}


void szukajwezlow(char x[][3], int kolumny, int * rozdroza, int * wezel_P, int * wezel_K){
	
	//zmienna do operacji
        int i = 0;

        //petla iterujaca po calym wierszu (srodkowym) z pominieciem skrajnych punktow
        for(i = 1; i < (kolumny - 1); i++){

                //rozdroze moze byc tylko na sciezce
                if (x[i][1] == ' '){

                        //zmienna do przechowywania ile pol do okola jest sciezka
                        int h = 0;

                        //czy bloczek na gorze jest sciezka, poczatek i koniec to takze czesc sciezki
                        if(x[i][0] == ' ' || x[i][0] == 'P' || x[i][0] == 'K' ) {
                                h+=1;
                        }

                        //to co u gory dla lewa
                        if(x[i-1][1] == ' '|| x[i-1][1] == 'P' || x[i-1][1] == 'K'){
                                h+=1;
                        }

                        //to co u gory dla prawa
                        if(x[i+1][1] == ' ' || x[i+1][1] == 'P' || x[i+1][1] == 'K'){
                                h+=1;
                        }

                        //to co u gory dla dolu
                        if(x[i][2] ==  ' ' || x[i][2] == 'P' || x[i][2] == 'K'){
                                h+=1;
                        }

                        //jezeli dookola sciezki sa 3 lub wiecej pol sciezki to jest to rozdroze
                        if( h >= 3 || x[i][0] == 'P' ||  x[i][2] == 'P' ||  x[i-1][1] == 'P' ||  x[i+1][1] == 'P' ||   x[i][0] == 'K' ||  x[i][2] == 'K' ||  x[i-1][1] == 'K' ||  x[i+1][1] == 'K') {
                                
				*rozdroza +=1;
                                x[i][1] = 'O';
				
				//zapisanie numeru wezla znajdujacego sie obok wejscia
				if (x[i][0] == 'P' ||  x[i][2] == 'P' ||  x[i-1][1] == 'P' ||  x[i+1][1] == 'P'){
				
					*wezel_P = *rozdroza;
				//zapisanie numeru wezla znajdujacegp sie obok wyjscia
				} else if (x[i][0] == 'K' ||  x[i][2] == 'K' ||  x[i-1][1] == 'K' ||  x[i+1][1] == 'K'){
				
					*wezel_K = *rozdroza;
				
				}
                        }
              }
       }
}

