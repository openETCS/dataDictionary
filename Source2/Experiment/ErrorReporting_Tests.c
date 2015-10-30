
#include "ErrorReporting_Tests.h"
#include "PacketFactory.h"
#include <assert.h>

void ErrorReporting_Tests(void)
{
    ErrorReporting a;
    ErrorReporting_Init(&a);
    ErrorReporting_Print(&a, stdout);
    printf("\n");

    ErrorReporting b;
    ErrorReporting_Init(&b);
    assert(ErrorReporting_Equal(&a, &b));

    b.M_ERROR  = 4;
    assert(!ErrorReporting_Equal(&a, &b));

    PacketHeader header = {4, 0};
    PacketHeader* base = PacketFactory_TrainToTrack(header);
    ErrorReporting* p = (ErrorReporting*)(base);
    ErrorReporting_Print(p, stdout);
    printf("\n");
    assert(ErrorReporting_Equal(&a, p));
    ErrorReporting_Delete(p);
}

