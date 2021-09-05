#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
        return ERROR;}
    if (!isfinite(b)) {
        printf("b is not double\n");
        return ERROR;}
    if (!isfinite(c)) {
        printf("c is not double\n");
        return ERROR;}
    if (&x1 == NULL){
        printf("x1 has no adress\n");
        return ERROR;}
    if (&x2 == NULL){
        printf("x2 has no adress\n");
        return ERROR;
    }

    if (IsEqual(a, 0)){
        if (IsEqual(b, 0)){
            if (IsEqual(c, 0)) return INFROOTS;
            else return ZEROROOTS;
        }
        else {
            *x1 = -c/b;
            return ONEROOT;
        }
    }
    else{
        if (IsEqual(c, 0)) {
           if (IsEqual(b, 0)){
                *x1 = 0;
                return ONEROOT;
           }
           else {
                *x1 = 0;
                *x2 = -b/a;
                return TWOROOTS;
           }
        }
        else {
            if (IsEqual(b, 0)){
                if (a*c < 0){
                    *x1 = sqrt(-c/a);
                    *x2 = -sqrt(-c/a);
                    return TWOROOTS;
                }
                else return ZEROROOTS;
            }
            else {
                if (Discrim(a,b,c) > 0){
                    *x1 = (-b + sqrt(Discrim(a,b,c))) / (2 * a);
                    *x2 = (-b - sqrt(Discrim(a,b,c))) / (2 * a);
                    return TWOROOTS;
                }
                else if (IsEqual(Discrim(a,b,c), 0)){ // elif
                        *x1 = (-b) / (2 * a);
                        return ONEROOT;
                }
                else return ZEROROOTS;
            }
        }
    }
}

void PrintRoots(double x1, double x2, int numRoots)
{

    switch(numRoots){

        case ZEROROOTS: printf("This equation has no solve.\n");
                        break;
        case ONEROOT: printf("This equation has one solve: %lg.\n", x1);
                        break;
        case TWOROOTS: printf("This equation has two solves: %lg and %lg.\n", x1, x2);
                        break;
        case INFROOTS: printf("This equation has an infinite set of solves.\n");
                        break;
    }

}

