
#include "ErrorReporting.h"
#include "PacketFactory.h"
#include <assert.h>

void ErrorReporting_Tests()
{
    ErrorReporting a;
    ErrorReporting_Init(&a);
    ErrorReporting_Print(stdout, &a);
    printf("\n");

    ErrorReporting b;
    ErrorReporting_Init(&b);
    assert(ErrorReporting_Equal(&a, &b));

    b.M_ERROR  = 4;
    assert(!ErrorReporting_Equal(&a, &b));

    PacketHeader header = {4};
    PacketHeader* base = PacketFactory_TrainToTrack(header);
    ErrorReporting* p = (ErrorReporting*)(base);
    ErrorReporting_Print(stdout, p);
    printf("\n");
    assert(ErrorReporting_Equal(&a, p));
    ErrorReporting_Delete(p);
}

