#include "mazeAnalyzer.h"


void updateValue( int * edg, int medg[], int kolumny){ //funkcja do zmiany updatu edg dla danego ID

	//zmienna do operacji z ID ktore ma sciana, aby nie robilo problemow
	int ID_now  = -1;

	//kolumna sprawdzajaca wiersz
	for( int i = 1; i < kolumny-1; i++){

		//jezeli id inne niz to ktore bylo ostatnio
		if( ID_now != medg[i]){

			//zapisz to inne id
			ID_now = medg[i];

			//zmienna do znalezienia max wartosci z danego id
			int max = 0;

			//szukamy max wartosci w calym wierszu dla danego id
			for(int z = 1; z < kolumny-1; z++){

				//jezeli takie samo id to sprawdz czy aktualny max nie jest mniejszy od tego edg
				if(ID_now == medg[z]){

					if(max < edg[z]){

						max = edg[z];
					}
				}
			}

		       	//sprawdzamy czy jest jakis max
			if (max != 0){

				//jak tak to updatujemy wszytskie edg z danym id
				for(int z = 1; z < kolumny-1; z++ ){

					if( ID_now == medg[z]){

						edg[z] = max;
					}
				}
			}
		}

	}

}

void markDeadEnd ( int * edg, int medg[], int kolumny, int ID, int i){ //funkcja do zaznaczania zaulkow

	//idziemy i dla kazdego kto jest kolo zaulka dajemy wartosc ktora spowoduje ze nigdzie sie nie bedzie liczyc
	for( int y = 1; y < kolumny-1; y++){

		if( medg[y] == ID){
			edg[y] = -1000;
			medg[y] = medg[i];
		}

	}
}

void updateID ( int medg[], int ID, int newID, int kolumny ){ //funkcja do updatu medg czyli id

	//przechodzimy przez caly wiersz i jak cos ma stare id to zamieniamy na nowe
	for(int z = 1; z < kolumny-1; z++){

		if( medg[z] == ID){

			medg[z] = newID;
		}

	}
}

int codeDirection ( int ID, char X){ //kodowanie kierunku w id

	//kierunek zapisujemy w ostatniej cyfrze dlatego mnozymy razy 10 i dodajemy liczbe odpowiadajaca kierunkowi
	int newID = ID * 10;

	switch(X){

		case 'N':
			newID += 0;
			break;
		case 'E':
			newID += 1;
			break;
		case 'P':
			newID += 2;
			break;
		case 'W':
			newID += 3;
			break;
	}

	//zwracamy zakodowane id
	return newID;

}

int decodeDirection ( int ID){ //funkcja odczytujaca kierunek z zakodowanego id
	
	return ID%10 ;
}

void analyzeMaze ( char x[][3], int kolumny, int * ost, int * edg, int * medg, int * unknown, int Graph[][8], int *rozdroza, int * edge){ //funkcja analizujaca wiersz by moc stworzyc graf

	//zmienna do operacji
	int i = 0;

	//glowna petla iterujaca po wierszu
        for(i = 1; i < (kolumny - 1); i++){

		//nowa linia by napisy testowe ladnie wygladaly
                //printf("%i \n", i);

		//Rozbudowana analiza dotyczy tylko sciezki
		if (x[i][1] == ' '){

			//zmienne przetrzymujace, ktore albo ile pol nalezy so sciezki
			int G = 0;
			int P = 0;
			int D = 0;
			int L = 0;
			int h = 0;

			//gora
			if( Path(GX)) {
				G+=1;
				h++;
			}
			//printf ("G:%c:G, %i \n", x[i][0],G);

			//lewo
			if( Path(LX) ){
                        	L+=1;
				h++;
        	        }
       	                //printf ("L:%c:L, %i \n", x[i-1][1],L);

			//prawo
	                if( Path(PX) ){
                                P+=1;
				h++;
                        }
                        //printf ("P:%c:P, %i\n", x[i+1][1],P);

			//dol
                        if( Path(DX) ){
                                D+=1;
				h++;
                        }
                        //printf ("D:%c:D, %i \n", x[i][2], D);


			//znaleziono rozdroze, przypadki dot (*rozdroza)
			if( h >= 3 || InOut( GX, PX, DX, LX, 'P') || InOut(GX, PX, DX, LX, 'K') || (Path(GX) || Path(DX)) && (Path(LX) || Path(PX))){

				//zaznaczamy w arrayu z 3 wierszami rozdroze jako O
				x[i][1] = 'O';

				//zwiekszamy liczbe ktora indeksuje (*rozdroza) (przetrzymuje id poprzedniego rozdroza)
				*ost += 1;

				//sciezka u gory i nie jest to zaulek ani unknown
				if (G == 1 && medg[i] >0){

					//zapisanie edgow w grafie
					Graph[medg[i]/10][decodeDirection(medg[i])] = *ost;
					Graph[*ost][0] = medg[i]/10;
					//zapisanie dlugosci
					Graph[medg[i]/10][decodeDirection(medg[i])+4] = edg[i] + 1;
                                        Graph[*ost][4] = edg[i] + 1;


					//wyzerowanie wart. pola
					edg[i] = 0;

				}else if ( G == 1 && medg[i] < 0 && edg[i] > 0){

					updateID (medg, medg[i], codeDirection (*ost, 'N'), kolumny);
					edg[i] = 0;
				}

				//sciezka po lewej i jest to albo zwykla liczba albo unknown
				if (L == 1 && x[i-1][1] != 'P' && (medg[i-1] > 0 || (medg[i-1] < 0 && edg[i-1] >0))){

					//jezeli unknown
					if( medg[i-1] < 0){

						//to otrzymuje on wartosc indeksu od (*rozdroza)
						updateID (medg, medg[i-1], codeDirection (*ost, 'W'), kolumny);

					//jezeli juz oindeksowana liczba
					}else{

						//zapisujemy edge w grafie
						//zapisujemy edge w grafie
						Graph [*ost][3] = medg[i-1] /10;
						Graph [medg[i-1]/10][decodeDirection(medg[i-1])] = *ost;

						//zapisujemy dlugosci
						Graph [*ost][3+4] = edg[i-1] + 1;
                                                Graph [medg[i-1]/10][decodeDirection(medg[i-1])+4] = edg[i-1] + 1;
					}

				}

				//sciezka na dole to rozpoczynamy w niej liczenie od (*rozdroza)
				if (D == 1){

					edg[i] = 1;
					medg[i] = codeDirection (*ost,'P');

				}

				//sciezka na prawo to zaczynamy w niej liczenie od (*rozdroza)
				if (P == 1 && i <= kolumny - 2){ //K?

					edg[i+1] = 1;
					medg[i+1] = codeDirection (*ost, 'E');
				}
				

			//analizowany punkt nie jest rozdrozem
			}else{
				//polaczenie poziome lub kolanko w dol, po prostu dodajemy 1
				if ( ((L == 1 && P == 1) || (L == 1 && D == 1)) && i >= 2 ){

					edg[i] = edg[i-1] + 1;
					medg[i] = medg[i-1];


				//kolanko DP nie mamy zadanego id wiec rozpoczynamy liczenie unknown
				} else if ( D == 1 && P == 1){

					//nie pamietam wsumie dlaczego
					if( edg[i] == -1 ){
						edg[i] = 1;
						medg[i] = *unknown;
						*unknown = (*unknown) - 1;
					}

				//polacznie pionowe lub kolanko GP po prostu dodajemy 1 do gornej wartosci
				} else if ( G == 1 &&( D == 1 || P == 1)){

					edg[i] += 1;

				//kolanko GL sumujemy lewo i gore + 1
				} else if ( G == 1 && L == 1 && i >= 2){

					edg[i] = edg[i] + edg[i-1] + 1;

					//jezeli lewo zaulek/unknown
					if (medg[i-1] < -1){

						//jezeli unknown -> lewo unkown gora ID
						if(edg[i-1] > 0 && edg[i] >= 0){

							updateID ( medg, medg[i-1], medg[i], kolumny);

						//jezeli zaulek -> lewo zaulek gora ID lub unknown
						} else if ( edg[i-1] < -5){

							markDeadEnd ( edg, medg, kolumny, medg[i], i);

						}

					//jeżeli gora zaulek/unknown
					} else if ( medg[i] < -1){

						// gora unknown lewo ID
						if( edg[i] > 0){

							updateID ( medg, medg[i], medg[i-1], kolumny);

						//gora zaulek lewo ID/unknown
						}else if ( edg[i] < -5){

							markDeadEnd ( edg, medg, kolumny, medg[i-1], i);

						}


					// ID - ID
					} else {

						//zapisanie edge to grafu
						Graph[medg[i]/10][decodeDirection(medg[i])] = medg[i-1] / 10;
					       	Graph[medg[i-1]/10][decodeDirection(medg[i-1])] = medg[i] / 10;
	
						//zapisanie dlugosci
						Graph[medg[i]/10][decodeDirection(medg[i])+4] = edg[i] + 1;
                                                Graph[medg[i-1]/10][decodeDirection(medg[i-1])+4] = edg[i] + 1;

					}

				//zaulek wiec zmieniamy wartosc na niemozliwa do uzytku, ma niszczyc wszystko co jego dotknie
				} else if (h == 1 && x[i-1][1] != 'O' && x[i+1][1] != 'O' && x[i][2] != 'O' && x[i][0] != 'O'){

					//jezeli lewo wolne czyli jest on ostatnim polem do ktorego dochodzi id, to w sumie nie ma co robic i tak nie polaczy sie z niczym
					if ( L == 1 && i >= 2){

						medg[i] = medg[i-1];

					//jezeli prawo wolne,to jest punktem poczatkowym bez id wiec oznaczamy go jako unknowna
					} else if ( P == 1 && i<= kolumny -2){

						if (medg[i+1] == -1){

                                                        medg[i] = *unknown;
                                                        *unknown = *unknown -1;

                                                }else{

							medg[i] = medg[i+1];

						}

					//gora lub dol wolny; G -> rozpoczynamy od niego unknowna; D -> i tak sie z niczym nie polaczy
					}else{
						//jezeli wyzej byla sciana to oznaczamy jako unkown
						if (medg[i] == -1){
							medg[i] = *unknown;
							*unknown = *unknown -1;
						}

					}

					//niszczymy wszytsko co jest z ID ktore ma kontakt z zaulkiem
                                        markDeadEnd ( edg, medg, kolumny, medg[i], i);
					edg[i] = -100;

                                        //zaułek usuń liczbe ktora tu szla lub wstaw -1 = tam zaulek => nie licz
				}
			}

			//do testow
	                //printf("it:%i, h:%i, r:%i \n", i,h, (*rozdroza));

		//sciana wiec ustawiamy -1 -1
		}else{
	      		edg[i] = -1;
			medg[i] = -1;
		}

		//do testow drukowanie wart edg medg
		/*	
		for(int o = 1; o < kolumny -1 ; o++){
                        printf(" \n %i X: EDG: %i  MEDG:%i \n" , i, edg[o], medg[o]);
                }
		*/
		updateValue (edg,medg,kolumny);
		

	}
	//updatujemy edg w wierszu, tak by wszystkie o tym samym id mialy wart max z tego id
	//IDmanager(edg,medg,kolumny);
}
