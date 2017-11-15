#include <stdio.h>
#ifndef _OPENMP
#   include "omp.h"
#endif
#include <stdlib.h>

int main(int argc, char* argv[]) {
    long long int num_tosses = strtol(argv[1], NULL, 10);
    printf("Number of tosses: %li\n", num_tosses);
    long long int global_result = 0;
#pragma omp parallel num_threads(num_tosses) \
        reduction(+:global_result)
    global_result += 1;
    printf("Result: %li", global_result);
    return 0;
}
