
/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Level23TransitionInformation_Tests.c
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

#include "Level23TransitionInformation_Tests.h"
#include "PacketFactory.h"
#include <assert.h>

void Level23TransitionInformation_Tests(void)
{
    printf("\nstart Level23TransitionInformation_Tests\n");
    Level23TransitionInformation a;
    Level23TransitionInformation_Init(&a);
    Level23TransitionInformation_Print(&a, stdout);
    printf("\n");

    Level23TransitionInformation b;
    Level23TransitionInformation_Init(&b);
    assert(Level23TransitionInformation_Equal(&a, &b));

    b.NID_LTRBG  = 17;
    assert(!Level23TransitionInformation_Equal(&a, &b));

    PacketHeader header = {9, 0};
    PacketHeader* base = PacketFactory_TrainToTrack(header);
    Level23TransitionInformation* p = (Level23TransitionInformation*)(base);
    Level23TransitionInformation_Print(p, stdout);
    printf("\n");
    assert(Level23TransitionInformation_Equal(&a, p));
    Level23TransitionInformation_Delete(p);

    printf("end Level23TransitionInformation_Tests\n");
}

