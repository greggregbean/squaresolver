int Testing(){

    double x1 = NAN;
    double x2 = NAN;


    if (SquareSolver(0, 0, 0, &x1, &x2) != INFROOTS) {
        printf("Error\n"
               "Input: 0, 0, 0\n"
               "Expected outut: This equation has an infinite set of solves.\n"
               "Output: ");
        PrintRoots(0, 0, 0);
        return 0;
        }

    if (!((SquareSolver(1, 0, 0, &x1, &x2) == ONEROOT) && IsEqual(x1, 0))) {
        printf("Error\n"
               "Input: 1, 0, 0\n"
               "Expected outut: This equation has one solve: 0.\n"
               "Output:  ");
        PrintRoots(1, 0, 0);
        return 0;
        }

    if (!((SquareSolver(1, -6, 9, &x1, &x2) == ONEROOT) && IsEqual(x1, 3)) ) {
        printf ("Error\n"
                "Input: 1, -6, 9\n"
                "Expected outut: This equation has one solve: 3.\n"
                "Output: ");
        PrintRoots(1, -6, 9);
        return 0;
        }

    if (!((SquareSolver(1, 1, 0, &x1, &x2) == TWOROOTS) && IsEqual(x1, 0) && IsEqual(x2, -1))) {
        printf ("Error\n"
                "Input: 1, 1, 0\n"
                "Expected outut:  This equation has two solves: 0 and -1.\n"
                "Output: ");
        PrintRoots(1, 1, 0);}

    if (SquareSolver(0, 0, 1, &x1, &x2) != ZEROROOTS) {
        printf("Error\n"
               "Input: 0, 0, 1\n"
               "Expected outut: This equation has no solves.\n"
               "Output: ");
        PrintRoots(0, 0, 1);
        return 0;
        }

    if (!((SquareSolver(1, 0, -1, &x1, &x2) == TWOROOTS) && IsEqual(x1, 1) && IsEqual(x2, -1))) {
        printf ("Error\n"
                "Input: 1, 0, -1\n"
                "Expected outut: This equation has two solves: 1 and -1.\n"
                "Output: ");
        PrintRoots(1, 0, -1);
        return 0;
        }

     return 1;
}

