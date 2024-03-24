#ifndef _Wczyt_podst_
#define _Wczyt_podst_

#include <stdlib.h>
#include <stdio.h>

void policz_kolumny(FILE * f, int * kolumny);
void policz_wiersze(FILE * f, int * wiersze);
void szukajwezlow(char x[][3], int kolumny, int * rozdroza, int * wezel_P, int * wezel_K);

#endif
