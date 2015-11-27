
/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: test_issue31_1.c
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

#include "EurobaliseTelegram.h"
#include "AllPackets.h"
#include <assert.h>

int main(void)
{
    printf("\nstart issue31_1 test\n");
    uint8_t raw[1024];
    Bitstream stream1;
    Bitstream_Init(&stream1, raw, 1024, 0);

    TelegramHeader header;
    {
        header.Q_UPDOWN  = 1;
        header.M_VERSION = 32;
        header.Q_MEDIA   = 0;
        header.N_PIG     = 1;
        header.N_TOTAL   = 1;
        header.M_DUP     = 0;
        header.M_MCOUNT  = 0;
        header.NID_C     = 64;
        header.NID_BG    = 3;
        header.Q_LINK    = 1;
    }

    EndOfInformation* f = EndOfInformation_New();

    EurobaliseTelegram t1;
    EurobaliseTelegram_Init(&t1);
    t1.header = header;
    EurobaliseTelegram_Add(&t1, &f->header);

    EurobaliseTelegram_Print(&t1, stdout);
    EurobaliseTelegram_EncodeBit(&t1, &stream1);

    EurobaliseTelegram t2;
    EurobaliseTelegram_Init(&t2);

    stream1.bitpos = 0; // reset bitpos
    EurobaliseTelegram_DecodeBit(&t2, &stream1);
    EurobaliseTelegram_Print(&t2, stdout);

    assert(EurobaliseTelegram_Equal(&t1, &t2));

    printf("end issue31_1 test\n");
    return EXIT_SUCCESS;
}

