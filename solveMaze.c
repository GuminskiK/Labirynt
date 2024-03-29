#include "solveMaze.h"



int manageSolving (FILE * in, int * rozdroza, int wezel_p, int wezel_k, int PD, int KD){
   
	node_t Nodes[(*rozdroza) + 1];
	int x [8];
  	int l_min = 0;

	if( Nodes == NULL || x == NULL){
		printf("Nie udało się zaalokować odpowiedniej ilości pamięci.");
		return 1;
	}

	for(int i = 1; i < (*rozdroza) + 1 ; i++){
 
		Nodes[i].Y = 0;
		Nodes[i].fromDirection = 0;
	}

	Nodes[0].Y = 1;

	solveMaze(wezel_p, wezel_k, Nodes, in, x, 0, PD, KD, &l_min);
	solveMaze(wezel_p, wezel_k, Nodes, in, x, 1, PD, KD, &l_min);
	Nodes[0].Y = 0;
	dictateSolution( wezel_p, wezel_k, Nodes, in, x, PD, KD);
	return 0;
}

void manageNodes( node_t Nodes[], int ID, int D, int Z){

   if( Z == 0){
   
      Nodes[ID].Y = 1;
      Nodes[ID]. fromDirection = D;
   } else if ( Z == 1) {
      Nodes[ID].Y = 0;
      Nodes[ID]. fromDirection = 0;
   } 
}

void solveMaze(int wezel_p, int wezel_k, node_t Nodes[], FILE * in, int x [], int Ready,int PD, int KD, int * l_min){

	int ID_now;
	int l_now = 1;
	int ID_next = wezel_p;
	int D = PD; // do poprzedniego
	int D2 = 0; // direction do następnego
	int g = 0; // czy cofany
	int p = 0;
	//Trzy kroki
	while( p == 0){
		ID_now = ID_next;
		if( g == 1 ){
			manageNodes( Nodes, ID_now, D, 2);
         		g = 0;
      		} else {
         		manageNodes( Nodes, ID_now, D, 0);
      		}
      		readGraph( ID_now, x, in);
      		ID_next = whichNext( Nodes, x, &D2, &l_now);
      		D = searchForDirection( Nodes, x, ID_next, ID_now, in);
      		if ( ID_next == 0){
        	 	p = endDeadEnd( &ID_now, &ID_next, wezel_p, wezel_k, &g, &l_now, l_min, Ready, in, &D2, x, Nodes, &D);
      		}
   	}
}
int endDeadEnd ( int * ID_now, int * ID_next, int wezel_p, int wezel_k, int * g, int * l_now, int * l_min,int Ready, FILE * in, int * D2, int x[], node_t Nodes[], int * D){
	
	readGraph ( *ID_now, x, in);
	if( *ID_now != wezel_p) {
		if( *ID_now == wezel_k ){ 
			if( *l_min == 0 || *l_min > *l_now){
         
				*l_min = *l_now;
			} else if ( Ready == 1 ){
				
				if ( *l_min == *l_now){
					return 1;
				}
			}
		} else {
			*l_now -= x[((Nodes[*ID_now].fromDirection) * 2 )+1];
      		}
		*ID_next = x[(Nodes[*ID_now].fromDirection) * 2];
      		*D2 = searchForDirection(Nodes, x, *ID_next, *ID_now, in) + 1;
      		*g = 1;
		manageNodes( Nodes, *ID_now, *D, 1);
      		return 0;
   	} else {
		return 1;
   	}
}

int whichNext( node_t Nodes[], int x[], int * D2, int * l_now){
   
	int y = (*D2) * 2;
	int ID_next = x[y];
	
	while ( y != 8){
		
		if( Nodes[x[y]].Y == 0){
			break;
		}
		
		y += 2;
		ID_next = x[y];
	}
	
	if ( y == 8) {
		ID_next = 0;
	} 
	
	if ( ID_next != 0) {
		*l_now += x[y+1];
	}
	*D2 = 0;
	return ID_next;
}

int whichNextSolution( node_t Nodes[], int x[], int * D, int * ile, int KD){
   
   int y = 0;
   int ID_next = x[y];
   while ( y < 7){
      if( Nodes[x[y]].Y == 1){
      	break;
      }
      y += 2;
      ID_next = x[y];
   }
   //koniec
   if( y == 8){
   	*D = KD;
	return ID_next;
   }
   *ile = x[y+1];
   *D = y/2;
   return ID_next;
}


void dictateSolution( int wezel_p, int wezel_k, node_t Nodes[], FILE * in, int x [], int PD, int KD) {
	
   Nodes[0].Y = 0;	
   int ID_now;
   int D = PD;
   int ID_next = wezel_p;
   int directionA;
   int ile = 0;
   writingSolution(2,1);
   //Trzy kroki
   while( ID_now != wezel_k ){
      ID_now = ID_next;
      readGraph( ID_now, x, in);
      ID_next = whichNextSolution( Nodes, x, &directionA, &ile, KD);
   
 
      if ( Nodes[ID_now].fromDirection == ((directionA + 3) % 4) ) {
         writingSolution( 1, 0);
	
      } else if (Nodes[ID_now].fromDirection == ((directionA + 1) % 4)){
         writingSolution(3,0);
      }
	 if( ID_now != wezel_k){
         	writingSolution(2,ile);
	 }
	 manageNodes( Nodes, ID_now, D, 1);
   }
   writingSolution(2,1);
}

int searchForDirection ( node_t Nodes [], int x[], int ID_next, int ID_now, FILE * in) {
   
   readGraph ( ID_next, x, in);
   int y = 0;
   while ( (ID_now != x[y] && y < 7)){
      y += 2;
   }
   
   return y/2;
}
