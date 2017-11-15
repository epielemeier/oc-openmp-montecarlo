#include <stdio.h>
#ifndef _OPENMP
#   include "omp.h"
#endif
#include <stdlib.h>

int throw_dart();

int main(int argc, char* argv[]) {
    long long int num_tosses = strtol(argv[1], NULL, 10);
    printf("Number of tosses: %li\n", num_tosses);
    long long int num_hits = 0;
#pragma omp parallel num_threads(num_tosses) \
        reduction(+:num_hits)
    num_hits += throw_dart();
    double pi_estimate = 4 * num_hits / ((double) num_tosses);
    printf("Result: %f", pi_estimate);
    return 0;
}

int throw_dart() {
    double x = ((double)rand()) / RAND_MAX * 2 - 1;
    double y = ((double)rand()) / RAND_MAX * 2 - 1;
    double distance_squared = x*x + y*y;
    if (distance_squared <= 1)
        return 1;
    else
        return 0;
}
