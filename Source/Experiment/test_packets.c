
#include <assert.h>
#include "AdhesionFactor.h"
#include "PacketFactory.h"

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

    PacketHeader header = {71};
    PacketHeader* base = PacketFactory_TrackToTrain(header);
    printf("main::base = %p\n", (void*)base);
    printf("main::base->NID_PACKET = %u\n", base->NID_PACKET);
    AdhesionFactor* p = (AdhesionFactor*)(base);
    printf("main::p = %p\n", (void*)p);
    AdhesionFactor_Print(stdout, p);
    printf("\n");
    assert(AdhesionFactor_Equal(&a, p));
    //AdhesionFactor_Delete(p);

    return EXIT_SUCCESS;
}

