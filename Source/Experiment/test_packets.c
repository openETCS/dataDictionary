

#include <stdlib.h>
#include <assert.h>
#include "Adhesion_Factor.h"

int main()
{
    Adhesion_Factor a;
    Adhesion_Factor_Init(&a);
    Adhesion_Factor_Print(stdout, &a);
    printf("\n");

    Adhesion_Factor b;
    Adhesion_Factor_Init(&b);
    assert(Adhesion_Factor_Equal(&a, &b));

    b.D_ADHESION  = 2;
    assert(!Adhesion_Factor_Equal(&a, &b));

    return EXIT_SUCCESS;
}

