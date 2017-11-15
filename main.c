#include <stdio.h>
#ifndef _OPENMP
#   include "omp.h"
#endif

int main() {
    printf("Hello, World!\n");
    return 0;
}