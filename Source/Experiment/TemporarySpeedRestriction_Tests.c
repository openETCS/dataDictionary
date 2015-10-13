
#include "TemporarySpeedRestriction.h"
#include "PacketFactory.h"
#include <assert.h>

void TemporarySpeedRestriction_Tests()
{
    TemporarySpeedRestriction a;
    TemporarySpeedRestriction_Init(&a);
    TemporarySpeedRestriction_Print(stdout, &a);
    printf("\n");

    TemporarySpeedRestriction b;
    TemporarySpeedRestriction_Init(&b);
    assert(TemporarySpeedRestriction_Equal(&a, &b));

    b.D_TSR  = 2;
    assert(!TemporarySpeedRestriction_Equal(&a, &b));

    PacketHeader header = {65,1};
    PacketHeader* base = PacketFactory_TrackToTrain(header);
    TemporarySpeedRestriction* p = (TemporarySpeedRestriction*)(base);
    TemporarySpeedRestriction_Print(stdout, p);
    printf("\n");
    assert(TemporarySpeedRestriction_Equal(&a, p));
    TemporarySpeedRestriction_Delete(p);
}

