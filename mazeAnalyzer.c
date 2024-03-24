#include "maze_coder.h"


void IDmanager( int * edg, int medg[], int kolumny){ //funkcja do zmiany updatu edg dla danego ID

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

void IDdestroyer( int * edg, int medg[], int kolumny, int ID, int i){ //funkcja do zaznaczania zaulkow

	//destrukcja po jpn
	//printf("\n \n HAKAI, %i", ID);

	//idziemy i dla kazdego kto jest kolo zaulka dajemy wartosc ktora spowoduje ze nigdzie sie nie bedzie liczyc
	for( int y = 1; y < kolumny-1; y++){

		if( medg[y] == ID){
			edg[y] = -1000;
			medg[y] = medg[i];
		}

	}
}

void IDupdate( int medg[], int ID, int newID, int kolumny ){ //funkcja do updatu medg czyli id

	//przechodzimy przez caly wiersz i jak cos ma stare id to zamieniamy na nowe
	for(int z = 1; z < kolumny-1; z++){

		if( medg[z] == ID){

			medg[z] = newID;
		}

	}
}

int kierunekkod (int ID, char X){ //kodowanie kierunku w id

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

char kierunekdekod(int ID){ //funkcja odczytujaca kierunek z zakodowanego id
	
	char X;
	int IDX = ID % 10;
	if( IDX == 0){
	
		X = 'N';

	}else if (IDX == 1){
	
		X = 'E';

	}else if (IDX == 2){
	
		X = 'P';

	}else if (IDX == 3){
	
		X = 'W';
	}

	return X ;
}

int kierunek(char kierunek1, char kierunek2){
	
	int x;
	switch(kierunek1){
	
		case 'N':
			switch(kierunek2){
				case 'N':
					x = 0;
					break;
				case 'E':
					x = 1;
					break;
				case 'P':
					x = 2;
					break;
				case 'W':
					x = 3;
					break;
			}
			break;

		case 'E':
			switch(kierunek2){
                                case 'N':
					x = 4;
                                        break;
                                case 'E':
					x = 5;
                                        break;
                                case 'P':
					x = 6;
                                        break;
				case 'W':
					x = 7;
                                        break;
			}
			break;

		case 'P':
			switch(kierunek2){
                                case 'N':
					x = 8;
                                        break;
                                case 'E':
					x = 9;
                                        break;
                                case 'P':
					x = 10;
                                        break;
				case 'W':
					x = 11;
                                        break;
			}
			break;
		case 'W':
			switch(kierunek2){
                                case 'N':
					x = 12;
                                        break;
                                case 'E':
					x = 13;
                                        break;
                                case 'P':
					x = 14;
                                        break;
				case 'W':
					x = 15;
                                        break;
			}
			break;

	}
	return x;
}

void graphManager(Node Graph[], int i, int rozdroza, int count){ //sprawidzić czy nie wychodzi
	
	count += Graph[i].X;
	i++;
	int TEMPID, TEMPV, TEMPD, TEMPX;
        int TEMPID2 = Graph[i].ID;
        int TEMPV2 = Graph[i].Value;
        int TEMPD2 = Graph[i].Direction;
	int TEMPX2 = Graph[i].X;
	
	while( count <= rozdroza ){

		TEMPID = Graph[i+1].ID;
                TEMPV = Graph[i+1].Value;
                TEMPD = Graph[i+1].Direction;
		TEMPX = Graph[i+1].X;

                Graph[i+1].ID = TEMPID2;
                Graph[i+1].Value = TEMPV2;
                Graph[i+1].Direction = TEMPD2;
		Graph[i+1].X = TEMPX2;

                TEMPID2 = TEMPID;
                TEMPV2 = TEMPV;
                TEMPD2 = TEMPD;
		TEMPX2 = TEMPX;
		
                if (Graph[i].X != 0){
                        count += Graph[i].X;
                }

		i++;
	}
}
void addNode(Node Graph[], int IDH, int IDL, int Value, int kierunek, int rozdroza){
	/*
	//sprawdz czy nie wychodzi za
	int i = 0;
	int count = 0;
	printf("JEstem tu %i %i %i", IDH, IDL, Value);
	while( count != (IDH + 1) &&  Graph[i].Direction < 0){//dodac jeszcze by szlo na koniec tego id
		
		if ( IDH == count){
			printf("I tu");
			if (Graph[i].ID != 0){
				Graph[i].Direction = Graph[i].Direction * -1;
				i += 1;
				count += 1;
				graphManager(Graph, i, rozdroza, count);
			}
			Graph[i].ID = IDL;
			Graph[i].Value = Value + 1;
			Graph[i].Direction = kierunek * -1;
		}

		if (Graph[i].Direction < 0){
                        count ++;
                }


		i++;
	}
	*/
	int i = 1;
	int count = 1; // count
	
	while( count <= IDH){
		
		while( Graph[i].X == 0){
			i++;
		}

		if( IDH == count){
			
			if (Graph[i].ID == 0){	
				
				Graph[i].ID = IDL;
                        	Graph[i].Value = Value + 1;
                        	Graph[i].Direction = kierunek;
				count ++;
			
			} else {
			
				graphManager(Graph,i, rozdroza, count); //przenosi reszte do gory
				
				Graph[i+1].ID = IDL;
	                        Graph[i+1].Value = Value + 1;
        	                Graph[i+1].Direction = kierunek;
				Graph[i+1].X = Graph[i].X;

				Graph[i].X = 0;	
				count ++;

			}

		}else if ( IDH > count && IDH < (count + Graph[i].X) ){
			
			int tempg = Graph[i].X;			
			Graph[i].X = IDH - count;	

			graphManager(Graph,i, rozdroza, count); //przenosi reszte do gory

			Graph[i+1].ID = IDL;
                        Graph[i+1].Value = Value + 1;
                        Graph[i+1].Direction = kierunek;
                        Graph[i+1].X = tempg - (IDH - count);

			count = IDH + 1;
		
		} else {
		
			count += Graph[i].X;
			i++;
		}

	}
}

void analyzemaze(char x[][3], int kolumny, int * ost, int * edg, int * medg, int * unknown, Node Graph[], int rozdroza, int * edge, int fo){ //funkcja analizujaca wiersz by moc stworzyc graf

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
			if(x[i][0] == ' ' || x[i][0] == 'P' || x[i][0] == 'K') {
				G+=1;
				h++;
			}
			//printf ("G:%c:G, %i \n", x[i][0],G);

			//lewo
			if(x[i-1][1] == ' '|| x[i-1][1] == 'P' || x[i-1][1] == 'K'){
                        	L+=1;
				h++;
        	        }
       	                //printf ("L:%c:L, %i \n", x[i-1][1],L);

			//prawo
	                if(x[i+1][1] == ' ' || x[i+1][1] == 'P' || x[i+1][1] == 'K'){
                                P+=1;
				h++;
                        }
                        //printf ("P:%c:P, %i\n", x[i+1][1],P);

			//dol
                        if(x[i][2] ==  ' ' || x[i][2] == 'P' || x[i][2] == 'K'){
                                D+=1;
				h++;
                        }
                        //printf ("D:%c:D, %i \n", x[i][2], D);


			//znaleziono rozdroze, przypadki dot rozdroza
			if( h >= 3 || (x[i][0] == 'P' || x[i-1][1] == 'P' || x[i+1][1] == 'P' || x[i][2] == 'P' ||   x[i][0] == 'K' ||  x[i][2] == 'K' ||  x[i-1][1] == 'K' ||  x[i+1][1] == 'K')){

				//zaznaczamy w arrayu z 3 wierszami rozdroze jako O
				x[i][1] = 'O';

				//zwiekszamy liczbe ktora indeksuje rozdroza (przetrzymuje id poprzedniego rozdroza)
				*ost += 1;

				//sciezka u gory i nie jest to zaulek ani unknown
				if (G == 1 && medg[i] >0){

					//zapisanie edgow w grafie
					if( fo == 0){

						*edge += 1;
						
					}else{
						if(medg[i]/10 > * ost){
		
							addNode( Graph, medg[i]/10, *ost, edg[i], kierunek(kierunekdekod(medg[i]), 'N'), rozdroza);
	
						}else{
	
							addNode( Graph, *ost, medg[i]/10, edg[i], kierunek( 'N', kierunekdekod(medg[i])), rozdroza);
						
						}
					}
					//wyzerowanie wart. pola
					edg[i] = 0;

				}else if ( G == 1 && medg[i] < 0 && edg[i] > 0){

					IDupdate(medg, medg[i], kierunekkod(*ost, 'N'), kolumny);
					edg[i] = 0;
				}

				//sciezka po lewej i jest to albo zwykla liczba albo unknown
				if (L == 1 && x[i-1][1] != 'P' && (medg[i-1] > 0 || (medg[i-1] < 0 && edg[i-1] >0))){

					//jezeli unknown
					if( medg[i-1] < 0){

						//to otrzymuje on wartosc indeksu od rozdroza
						IDupdate(medg, medg[i-1], kierunekkod(*ost, 'W'), kolumny);

					//jezeli juz oindeksowana liczba
					}else{

						//zapisujemy edge w grafie
						if(fo == 0){
							
							*edge += 1;
						
						}else{
							if(medg[i]/10 > * ost){
	
	                                        	        addNode( Graph, medg[i-1]/10, *ost, edg[i-1], kierunek(kierunekdekod(medg[i-1]), 'W'), rozdroza);
	
	                                        	}else{
	
        	                                	        addNode( Graph, *ost, medg[i-1]/10, edg[i-1], kierunek('W', kierunekdekod(medg[i-1])), rozdroza);
	
	                                        	}
						}
						
					}

				}

				//sciezka na dole to rozpoczynamy w niej liczenie od rozdroza
				if (D == 1){

					edg[i] = 1;
					medg[i] = kierunekkod(*ost,'P');

				}

				//sciezka na prawo to zaczynamy w niej liczenie od rozdroza
				if (P == 1 && i <= kolumny - 2){ //K?

					edg[i+1] = 1;
					medg[i+1] = kierunekkod(*ost, 'E');
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

							IDupdate( medg, medg[i-1], medg[i], kolumny);

						//jezeli zaulek -> lewo zaulek gora ID lub unknown
						} else if ( edg[i-1] < -5){

							IDdestroyer( edg, medg, kolumny, medg[i], i);

						}

					//jeżeli gora zaulek/unknown
					} else if ( medg[i] < -1){

						// gora unknown lewo ID
						if( edg[i] > 0){

							IDupdate( medg, medg[i], medg[i-1], kolumny);

						//gora zaulek lewo ID/unknown
						}else if ( edg[i] < -5){

							IDdestroyer( edg, medg, kolumny, medg[i-1], i);

						}


					// ID - ID
					} else {

						//zapisanie edge to grafu
						if(fo == 0){
						
							*edge += 1;
						
						}else{
							if(medg[i]/10 > * ost){
                                                	
                                                		addNode( Graph, medg[i]/10, medg[i-1]/10, edg[i], kierunek(kierunekdekod(medg[i]), kierunekdekod(medg[i-1])), rozdroza);
	
	                                        	}else{
	
	                                                	addNode( Graph, medg[i-1]/10, medg[i]/10, edg[i], kierunek( kierunekdekod(medg[i-1]), kierunekdekod(medg[i])), rozdroza);
	
	                                        	}
						}
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
                                        IDdestroyer( edg, medg, kolumny, medg[i], i);
					edg[i] = -100;

                                        //zaułek usuń liczbe ktora tu szla lub wstaw -1 = tam zaulek => nie licz
				}
			}

			//do testow
	                //printf("it:%i, h:%i, r:%i \n", i,h, rozdroza);

		//sciana wiec ustawiamy -1 -1
		}else{
	      		edg[i] = -1;
			medg[i] = -1;
		}

		//do testow drukowanie wart edg medg
			
		for(int o = 1; o < kolumny -1 ; o++){
                        printf(" \n %i X: EDG: %i  MEDG:%i \n" , i, edg[o], medg[o]);
                }
		printf("\n \n");
		IDmanager(edg,medg,kolumny);
		

	}
	//updatujemy edg w wierszu, tak by wszystkie o tym samym id mialy wart max z tego id
	//IDmanager(edg,medg,kolumny);
}
