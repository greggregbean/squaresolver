#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include "squaresolver.h"
#include "squaresolver.cpp"
#include "testing.h"
#include "testing.cpp"

double Discrim(double a, double b, double c);
int IsEqual(double val1, double val2);
int SquareSolver(double a, double b, double c, double *x1, double *x2);
void PrintRoots(double x1, double x2, int numRoots);
int Testing();

int main(){

    printf("This program was built by Ivan Zinin.\n\n");

    printf("The autotesting started.\n");
    if (!Testing()){
        return 1;
    };
    printf("The autotesting completed.\n\n");

    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
    printf ("Please, enter the coefficients of the equation:\n\n");
    scanf("%lg %lg %lg", &a, &b, &c);

    printf ("\n");

    int numRoots = SquareSolver(a, b, c, &x1, &x2);
    if (numRoots == CountOfRoots :: ERROR) printf("ERROR\n");
    PrintRoots(x1, x2, numRoots);

    return 0;
}


