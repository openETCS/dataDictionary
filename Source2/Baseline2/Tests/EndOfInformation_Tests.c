
/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: EndOfInformation_Tests.c
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

