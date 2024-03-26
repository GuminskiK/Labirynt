#include "mazePreanalyzer.h"

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
                        if( Path (GX) ) {
                                h+=1;
                        }

                        if( Path (LX) ){
                                h+=1;
                        }

                        if( Path (PX) ){
                                h+=1;
                        }

                        if( Path (DX)){
                                h+=1;
                        }


                        //jezeli dookola sciezki sa 3 lub wiecej pol sciezki to jest to rozdroze
                        if( h >= 3 || InOut( GX, PX, DX, LX, 'P') || InOut(GX, PX, DX, LX, 'K') || (Path(GX) || Path(DX)) && (Path(LX) || Path(PX))  ) {
                                
				*rozdroza +=1;
                                x[i][1] = 'O';
				
				//zapisanie numeru wezla obok wejscia/wyjscia
				if ( InOut( GX, PX, DX, LX, 'P')){
				
					*wezel_P = *rozdroza;

				} else if ( InOut( GX, PX, DX, LX, 'K')){
				
					*wezel_K = *rozdroza;
				
				}
                        }
              }
       }

}

