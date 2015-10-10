

#include <stdlib.h>
#include "Adhesion_Factor.h"

int main()
{
    Adhesion_Factor a;
    Adhesion_Factor_Init(&a);
    Adhesion_Factor_Print(stdout, &a);
    printf("\n");

    return EXIT_SUCCESS;
}

