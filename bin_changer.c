#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "bin_changer.h"


int binfile( char *tab, double dl ) // dostajemy tablice zer i jedynek oraz liczbe mowiaca o dlugosci danego ciagu binarnego
{
    int liczba = 0;
    int k = (int) dl, i;
    for( i = 0; i < k; i++)
    {
      liczba += (argv[2][i] - '0') * (int) pow(2, --dl);
    }
    return liczba;
}
