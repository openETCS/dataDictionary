

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

    AdhesionFactor* p = AdhesionFactor_New();
    assert(AdhesionFactor_Equal(&a, p));
    AdhesionFactor_Delete(p);

    return EXIT_SUCCESS;
}

