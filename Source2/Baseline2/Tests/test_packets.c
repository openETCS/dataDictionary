
#include <assert.h>
#include "AdhesionFactor_Tests.h"
#include "ErrorReporting_Tests.h"
#include "TemporarySpeedRestriction_Tests.h"
#include "Level23TransitionInformation_Tests.h"
#include "EndOfInformation_Tests.h"
#include "PacketFactory.h"
#include "EurobaliseTelegram.h"

int main(void)
{
    AdhesionFactor_Tests();
    TemporarySpeedRestriction_Tests();
    ErrorReporting_Tests();
    Level23TransitionInformation_Tests();
    EndOfInformation_Tests();

    {
        // set up test data
        EurobaliseTelegram t;
        EurobaliseTelegram_Init(&t);

        t.header.Q_UPDOWN = 1;
        //printf("telegram size of t = %d\n", EurobaliseTelegram_Size(&t));
        EurobaliseTelegram_Print(&t, stdout);

        AdhesionFactor a;
        AdhesionFactor_Init(&a);
        a.L_PACKET = 56;
        a.D_ADHESION  = 2;
        EurobaliseTelegram_Add(&t, &a.header);
        EurobaliseTelegram_Print(&t, stdout);

        AdhesionFactor a1;
        AdhesionFactor_Init(&a1);
        a1.L_PACKET = 56;
        a1.D_ADHESION  = 3;
        EurobaliseTelegram_Add(&t, &a1.header);
        EurobaliseTelegram_Print(&t, stdout);

        EndOfInformation e;
        EndOfInformation_Init(&e);
        EurobaliseTelegram_Add(&t, &e.header);
        EurobaliseTelegram_Print(&t, stdout);

        // encode
        uint8_t raw[1024];
        Bitstream stream1;
        Bitstream_Init(&stream1, raw, 1024, 0);

        TelegramHeader_EncodeBit(&t.header, &stream1);

        PacketHeader_EncodeBit(&a.header, &stream1);
        AdhesionFactor_EncodeBit((const AdhesionFactor*)EurobaliseTelegram_Get(&t, 0), &stream1);

        PacketHeader_EncodeBit(&a1.header, &stream1);
        AdhesionFactor_EncodeBit((const AdhesionFactor*)EurobaliseTelegram_Get(&t, 1), &stream1);

        PacketHeader_EncodeBit(&e.header, &stream1);
        EndOfInformation_EncodeBit((const EndOfInformation*)EurobaliseTelegram_Get(&t, 1), &stream1);

        stream1.bitpos = 0; // reset

        EurobaliseTelegram u1;
        EurobaliseTelegram_Init(&u1);
        EurobaliseTelegram_DecodeBit(&u1, &stream1);

        EurobaliseTelegram_Print(&u1, stdout);

        assert(EurobaliseTelegram_Equal(&t, &u1));

        Bitstream stream2;
        Bitstream_Init(&stream2, raw, 1024, 0);

        EurobaliseTelegram_EncodeBit(&t, &stream2);
        stream2.bitpos = 0; // reset

        EurobaliseTelegram u2;
        EurobaliseTelegram_Init(&u2);
        EurobaliseTelegram_DecodeBit(&u2, &stream2);

        EurobaliseTelegram_Print(&u2, stdout);
        EurobaliseTelegram_Print(&u1, stdout);

        assert(EurobaliseTelegram_Equal(&t, &u2));
        assert(EurobaliseTelegram_Equal(&u2, &t));
        assert(EurobaliseTelegram_Equal(&u1, &u2));
        assert(EurobaliseTelegram_Equal(&u2, &u1));

        EurobaliseTelegram_Clear(&u1);
        EurobaliseTelegram_Clear(&u2);
    }


    return EXIT_SUCCESS;
}

