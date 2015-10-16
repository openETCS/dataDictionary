
#include "TemporarySpeedRestriction_Tests.h"
#include "PacketFactory.h"
#include <assert.h>

void TemporarySpeedRestriction_Tests(void)
{
    TemporarySpeedRestriction a;
    TemporarySpeedRestriction_Init(&a);
    TemporarySpeedRestriction_Print(&a, stdout);
    printf("\n");

    TemporarySpeedRestriction b;
    TemporarySpeedRestriction_Init(&b);
    assert(TemporarySpeedRestriction_Equal(&a, &b));

    b.D_TSR  = 2;
    assert(!TemporarySpeedRestriction_Equal(&a, &b));

    PacketHeader header = {65, 1};
    PacketHeader* base = PacketFactory_TrackToTrain(header);
    TemporarySpeedRestriction* p = (TemporarySpeedRestriction*)(base);
    TemporarySpeedRestriction_Print(p, stdout);
    printf("\n");
    assert(TemporarySpeedRestriction_Equal(&a, p));
    TemporarySpeedRestriction_Delete(p);
}

