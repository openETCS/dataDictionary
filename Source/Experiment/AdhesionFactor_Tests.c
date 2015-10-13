
#include "AdhesionFactor.h"
#include "PacketFactory.h"
#include <assert.h>

void AdhesionFactor_Tests()
{
    AdhesionFactor a;
    AdhesionFactor_Init(&a);
    AdhesionFactor_Print(stdout, &a);
    printf("\n");

    AdhesionFactor b;
    AdhesionFactor_Init(&b);
    assert(AdhesionFactor_Equal(&a, &b));

    assert(PacketHeader_Equal(&a.header, &b.header));

    b.D_ADHESION  = 2;
    assert(!AdhesionFactor_Equal(&a, &b));

    assert(PacketHeader_Equal(&a.header, &b.header));

    PacketHeader header = {71, 1};
    PacketHeader* base = PacketFactory_TrackToTrain(header);
    AdhesionFactor* p = (AdhesionFactor*)(base);
    AdhesionFactor_Print(stdout, p);
    printf("\n");
    assert(AdhesionFactor_Equal(&a, p));
    AdhesionFactor_Delete(p);
}
