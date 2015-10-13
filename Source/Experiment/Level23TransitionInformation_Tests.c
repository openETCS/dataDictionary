
#include "Level23TransitionInformation.h"
#include "PacketFactory.h"
#include <assert.h>

void Level23TransitionInformation_Tests()
{
    Level23TransitionInformation a;
    Level23TransitionInformation_Init(&a);
    Level23TransitionInformation_Print(stdout, &a);
    printf("\n");

    Level23TransitionInformation b;
    Level23TransitionInformation_Init(&b);
    assert(Level23TransitionInformation_Equal(&a, &b));

    b.NID_LTRBG  = 17;
    assert(!Level23TransitionInformation_Equal(&a, &b));

    PacketHeader header = {9, 0};
    PacketHeader* base = PacketFactory_TrainToTrack(header);
    Level23TransitionInformation* p = (Level23TransitionInformation*)(base);
    Level23TransitionInformation_Print(stdout, p);
    printf("\n");
    assert(Level23TransitionInformation_Equal(&a, p));
    Level23TransitionInformation_Delete(p);
}

