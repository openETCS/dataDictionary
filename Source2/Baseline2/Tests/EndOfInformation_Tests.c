
#include "EndOfInformation_Tests.h"
#include "PacketFactory.h"
#include <assert.h>

void EndOfInformation_Tests(void)
{
    printf("\nstart EndOfInformation_Tests\n");
    EndOfInformation a;
    EndOfInformation_Init(&a);
    EndOfInformation_Print(&a, stdout);
    printf("\n");

    EndOfInformation b;
    EndOfInformation_Init(&b);
    assert(EndOfInformation_Equal(&a, &b));

    PacketHeader header = {255, 2};
    PacketHeader* base = PacketFactory_BothWays(header);
    assert(base);
    EndOfInformation* p = (EndOfInformation*)(base);
    EndOfInformation_Print(p, stdout);
    printf("\n");
    assert(EndOfInformation_Equal(&a, p));
    EndOfInformation_Delete(p);

    printf("end EndOfInformation_Test\n");
}

