
/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: ErrorReporting_Tests.c
- Description: UNISIG SUBSET-026-7, ISSUE : 3.3.0, 3.5 ERTMS/ETCS language) 
- Copyright (c) 

- Licensed under the EUPL V.1.1 ( http://joinup.ec.europa.eu/software/page/eupl/licence-eupl )
- Gist URL: none
- Cryptography: No
- Author(s): Fraunhofer FOKUS

Disclaimer:

The use of this software is limited to NON-vital applications. 
It has NOT been developed for vital operation purposes and MUST NOT be used for applications 
which may cause harm to people, physical accidents or financial loss. 

THEREFORE, NO LIABILITY WILL BE GIVEN FOR SUCH AND ANY OTHER KIND OF USE.       
============================================================================= */

#include "ErrorReporting_Tests.h"
#include "PacketFactory.h"
#include <assert.h>

void ErrorReporting_Tests(void)
{
    printf("\nstart ErrorReporting_Tests\n");
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

    printf("end ErrorReporting_Test\n");
}

