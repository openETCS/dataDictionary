
#include "EndOfInformation.h"
#include "PacketFactory.h"
#include <assert.h>

void EndOfInformation_Tests()
{
    EndOfInformation a;
    EndOfInformation_Init(&a);
    EndOfInformation_Print(stdout, &a);
    printf("\n");

    EndOfInformation b;
    EndOfInformation_Init(&b);
    assert(EndOfInformation_Equal(&a, &b));

    PacketHeader header = {255};
    PacketHeader* base = PacketFactory_TrackToTrain(header);
    EndOfInformation* p = (EndOfInformation*)(base);
    EndOfInformation_Print(stdout, p);
    printf("\n");
    assert(EndOfInformation_Equal(&a, p));
    EndOfInformation_Delete(p);
}

