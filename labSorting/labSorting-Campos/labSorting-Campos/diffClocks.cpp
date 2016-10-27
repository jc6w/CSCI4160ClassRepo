#include "diffClocks.h"


double diffClocks(clock_t clock1, clock_t clock2){
    double diffticks = clock1 - clock2;
    double diffsecs = diffticks / CLOCKS_PER_SEC;
    return diffsecs;
}