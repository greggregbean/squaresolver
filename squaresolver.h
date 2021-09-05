/// @file squaresolver.h

const double EPS = 0.000001;

enum CountOfRoots
{
    ZEROROOTS = 0,
    ONEROOT = 1,
    TWOROOTS = 2,
    INFROOTS = -1,
    ERROR = -2
};

//!    @brief Discriminant
//!
//!    @note Function counts a discriminant in relation to the cofficients (a, b, c)
//!
//!    @param [in] a 1st cofficient
//!    @param [in] b 2nd cofficient
//!    @param [in] c 3d  cofficient
//!
//!    @return Discriminant of an equation

double Discrim(double a, double b, double c);

//!    @brief Is val1 equal to val2.
//!
//!    @note This function determines how two numbers are close to each other in the epsilon neighborhood. \n
//!          epsilon = 10^(-6)
//!
//!    @param [in] val1 First value that will be compared with the second one
//!    @param [in] val2 Second value that will be compared with the first one
//!
//!    @return Returns 1 if these two numbers are close to each other in the epsilon neighborhood, \n
//!            else returns 0.

int IsEqual(double val1, double val2);


//!    @brief This functioun solves a quadratic equation.
//!
//!    @note In relation to coffients that are gave (a, b, c), the function solves the quadratic equation \n
//!          with these cofficients and puts the solves in x1 and x2 correspondingly.
//!
//!    @param [in] a First cofficient
//!    @param [in] b Second cofficient
//!    @param [in] c Third  cofficient                  //[in] [out]
//!    @param [out] *x1 The pointer for the first solve x1
//!    @param [out] *x2 The pointer fot the second solve x2
//!
//!    @return Returns 0 if an equation has 0 solves. \n
//!            Returns 1 if an equation has 1 solve. \n
//!            Returns 2 if an equation has 2 solves. \n
//!            Returns 4 if an equation has an infinite set of solves.

int SquareSolver(double a, double b, double c, double* x1, double* x2);


//!    @brief This function print the number of roots
//!
//!    @note The function print the roots and the number of roots of an equation. \n
//!          If an equation has no solve, the function will print: \n
//!          "This equation has no solve." \n
//!          If an equation has 1 solve, the function will print: \n
//!          "This equation has one solve: x1." \n
//!          If an equation has 2 solves, the function will print \n
//!          "This equation has two solves: x1 and x2." \n
//!          If an equation has an infinite set of solves, the function will print: \n
//!          "This equation has an infinite set of solves."
//!
//!    @param [in] x1 The first solve of an equation.
//!    @param [in] x2 The second solve of an equation.
//!    @param [in] numRoots The number of roots of an equation.
//!
//!    @return Nothing.

void PrintRoots(double x1, double x2, int numRoots);

