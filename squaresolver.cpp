#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include "squaresolver.h"

double Discrim(double a, double b, double c)
{
    double D = 0;

    D = b * b - 4 * a * c;

    return D;
}

int IsEqual(double val1, double val2)
{
    return (fabs(val1 - val2) < EPS);
}

int SquareSolver(double a, double b, double c, double *x1, double *x2)
{

   if (!isfinite(a)) {
        printf("a is not double\n");
        return CountOfRoots :: ERROR;}
    if (!isfinite(b)) {
        printf("b is not double\n");
        return CountOfRoots :: ERROR;}
    if (!isfinite(c)) {
        printf("c is not double\n");
        return CountOfRoots :: ERROR;}
    if (&x1 == NULL){
        printf("x1 has no adress\n");
        return CountOfRoots :: ERROR;}
    if (&x2 == NULL){
        printf("x2 has no adress\n");
        return CountOfRoots :: ERROR;
    }

    if (IsEqual(a, 0)){
        if (IsEqual(b, 0)){
            if (IsEqual(c, 0)) return CountOfRoots :: INFROOTS;
            else return CountOfRoots :: ZEROROOTS;
        }
        else {
            *x1 = -c/b;
            return CountOfRoots :: ONEROOT;
        }
    }
    else{
        if (IsEqual(c, 0)) {
           if (IsEqual(b, 0)){
                *x1 = 0;
                return CountOfRoots :: ONEROOT;
           }
           else {
                *x1 = 0;
                *x2 = -b/a;
                return CountOfRoots :: TWOROOTS;
           }
        }
        else {
            if (IsEqual(b, 0)){
                if (a*c < 0){
                    *x1 = sqrt(-c/a);
                    *x2 = -sqrt(-c/a);
                    return CountOfRoots :: TWOROOTS;
                }
                else return CountOfRoots :: ZEROROOTS;
            }
            else {
                if (Discrim(a,b,c) > 0){
                    *x1 = (-b + sqrt(Discrim(a,b,c))) / (2 * a);
                    *x2 = (-b - sqrt(Discrim(a,b,c))) / (2 * a);
                    return CountOfRoots :: TWOROOTS;
                }
                else if (IsEqual(Discrim(a,b,c), 0)){ // elif
                        *x1 = (-b) / (2 * a);
                        return CountOfRoots :: ONEROOT;
                }
                else return CountOfRoots :: ZEROROOTS;
            }
        }
    }
}

void PrintRoots(double x1, double x2, int numRoots)
{

    switch(numRoots){

        case CountOfRoots :: ZEROROOTS: printf("This equation has no solve.\n");
                        break;
        case CountOfRoots :: ONEROOT: printf("This equation has one solve: %lg.\n", x1);
                        break;
        case CountOfRoots :: TWOROOTS: printf("This equation has two solves: %lg and %lg.\n", x1, x2);
                        break;
        case CountOfRoots :: INFROOTS: printf("This equation has an infinite set of solves.\n");
                        break;
    }

}
