#ifndef _define_
#define _define_

#include <stdio.h>
#include <stdlib.h>

#define GX x[i][0]
#define PX x[i+1][1]
#define LX x[i-1][1]
#define DX x[i][2]

#define Path(a) a == ' ' || a == 'P' || a == 'K'
#define InOut(a,b,c,d,e) a == e || b == e || c == e || d == e



#endif

