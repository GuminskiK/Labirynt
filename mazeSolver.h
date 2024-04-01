#ifndef _solveMaze_
#define _solveMaze_

#include <stdlib.h>
#include <stdio.h>

#include "node.h"
#include "graphReader.h"
#include "solutionWriter.h"

int manageSolving (FILE * in, int * rozdroza, int wezel_p, int wezel_k, int PD, int KD);
void manageNodes( node_t Nodes[], int ID, int D, int Z);
void solveMaze(int wezel_p, int wezel_k, node_t Nodes[], FILE * in, int x [], int Ready, int PD, int KD, int * l_min);
int endDeadEnd ( int * ID_now, int * ID_next, int wezel_p, int wezel_k, int * g, int * l_now, int * l_min, int Ready, FILE * in, int * D2, int x[], node_t Nodes[], int * D);
int whichNext( node_t Nodes[], int x[], int * D2, int *l_now);
int searchForDirection ( node_t Nodes[], int x[], int ID_next, int ID_now, FILE * in);


void dictateSolution( int wezel_p, int wezel_k, node_t Nodes[], FILE * in, int x [], int PD, int KD);
int whichNextSolution( node_t Nodes [], int x[], int * D, int * ile, int KD);


#endif
