#include "solutionWriter.h"

void writingSolution( int Direction, int ile ){

   switch(Direction){
      case 1:
         printf("TURN LEFT\n");
	 break;
      case 2:
         printf("MOVE FORWARD %i\n", ile);
	 break;
      case 3:
         printf("TURN RIGHT\n");
	 break;
   }

}
