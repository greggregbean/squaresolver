#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "squaresolver.h"
#include "squaresolver.cpp"
#include "testing.h"
#include "testing.cpp"

int main(){

    printf("This program was built by Ivan Zinin.\n\n");

    printf("The autotesting started.\n");
    if (!Testing()){
        return 1;
    };
    printf("The autotesting completed.\n\n");

    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
    printf ("Please, enter the coefficients of the equation:\n\n");
    scanf("%lg %lg %lg", &a, &b, &c);  // fflush

    printf ("\n");

    int numRoots = SquareSolver(a, b, c, &x1, &x2);
    if (numRoots == ERROR) printf("ERROR\n");
    PrintRoots(x1, x2, numRoots);

    return 0;
}

// 1e-20 2e-20 1e-20 -> 0.5 1 0.5
// 1e+20 2 1e-20


