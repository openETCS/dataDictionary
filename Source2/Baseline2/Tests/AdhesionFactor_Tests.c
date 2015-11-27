
/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: AdhesionFactor_Tests.c
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

#include "AdhesionFactor_Tests.h"
#include "PacketFactory.h"
#include <assert.h>

void AdhesionFactor_Tests(void)
{
    printf("\nstart AdhesionFactor_Tests\n");
    AdhesionFactor a;
    AdhesionFactor_Init(&a);
    AdhesionFactor_Print(&a, stdout);
    printf("\n");

    AdhesionFactor b;
    AdhesionFactor_Init(&b);
    assert(AdhesionFactor_Equal(&a, &b));

    assert(PacketHeader_Equal(&a.header, &b.header));

    b.D_ADHESION  = 2;
    assert(!AdhesionFactor_Equal(&a, &b));

    assert(PacketHeader_Equal(&a.header, &b.header));

    PacketHeader header = {71, 1};
    PacketHeader* base = PacketFactory_TrackToTrain(header);
    AdhesionFactor* p = (AdhesionFactor*)(base);
    AdhesionFactor_Print(p, stdout);
    printf("\n");
    assert(AdhesionFactor_Equal(&a, p));
    AdhesionFactor_Delete(p);

    // new and delete
    {
        AdhesionFactor* p = AdhesionFactor_New();
        AdhesionFactor_Init(p);
        //AdhesionFactor_Print(p, stdout); printf("\n");
        //printf("allocated at %p\n", p);

        AdhesionFactor* q = AdhesionFactor_New();
        AdhesionFactor_Init(q);
        //AdhesionFactor_Print(q, stdout); printf("\n");
        //printf("allocated at %p\n", q);

        AdhesionFactor* r = AdhesionFactor_New();
        AdhesionFactor_Init(r);
        //AdhesionFactor_Print(r, stdout); printf("\n");
        //printf("allocated at %p\n", r);

        AdhesionFactor* s = AdhesionFactor_New();
        AdhesionFactor_Init(s);
        //AdhesionFactor_Print(s, stdout); printf("\n");
        //printf("allocated at %p\n", s);

        //printf("delete at %p\n", q);
        AdhesionFactor_Delete(q);
        //printf("delete at %p\n", s);
        AdhesionFactor_Delete(s);

        AdhesionFactor* t = AdhesionFactor_New();
        AdhesionFactor_Init(t);
        //AdhesionFactor_Print(t, stdout); printf("\n");
        //printf("allocated at %p\n", t);

        AdhesionFactor* u = AdhesionFactor_New();
        AdhesionFactor_Init(u);
        //AdhesionFactor_Print(u, stdout); //printf("\n");
        //printf("allocated at %p\n", u);

        AdhesionFactor* v = AdhesionFactor_New();
        AdhesionFactor_Init(v);
        //AdhesionFactor_Print(v, stdout); printf("\n");
        //printf("allocated at %p\n", v);

	AdhesionFactor_Delete(p);
	AdhesionFactor_Delete(r);
	AdhesionFactor_Delete(t);
	AdhesionFactor_Delete(u);

    }
    printf("end AdhesionFactor_Test\n");
}

