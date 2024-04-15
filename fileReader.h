#ifndef _fileReader_
#define _fileReader_

#include <stdio.h>
#include <stdlib.h>

int checkFormat( char* );
void readTXT(char x[][3], FILE * f, int y);
void readRLE(FILE *f, int kol);
void rewrite(char x[][3], int kolumny);

#endif
