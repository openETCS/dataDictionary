

#include <stdlib.h>
#include <assert.h>
#include "AdhesionFactor.h"

int main()
{
    AdhesionFactor a;
    AdhesionFactor_Init(&a);
    AdhesionFactor_Print(stdout, &a);
    printf("\n");

    AdhesionFactor b;
    AdhesionFactor_Init(&b);
    assert(AdhesionFactor_Equal(&a, &b));

    b.D_ADHESION  = 2;
    assert(!AdhesionFactor_Equal(&a, &b));

    return EXIT_SUCCESS;
}

