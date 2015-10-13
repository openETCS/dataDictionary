
#include <assert.h>
#include "AdhesionFactor_Tests.h"
#include "ErrorReporting_Tests.h"
#include "TemporarySpeedRestriction_Tests.h"
#include "Level23TransitionInformation_Tests.h"
#include "EndOfInformation_Tests.h"
#include "PacketFactory.h"
#include "EurobaliseTelegram.h"

int main()
{
    AdhesionFactor_Tests();
    TemporarySpeedRestriction_Tests();
    ErrorReporting_Tests();
    Level23TransitionInformation_Tests();
    EndOfInformation_Tests();

    {
        // set up test data
        printf("hello\n");
        EurobaliseTelegram t;
        EurobaliseTelegram_Init(&t);

        t.header.Q_UPDOWN = 1;
        printf("telegram size of t = %d\n", EurobaliseTelegram_Size(&t));

        AdhesionFactor a;
        AdhesionFactor_Init(&a);
        a.D_ADHESION  = 2;
        EurobaliseTelegram_Add(&t, &a.header);
        printf("telegram size of t = %d\n", EurobaliseTelegram_Size(&t));

        AdhesionFactor a1;
        AdhesionFactor_Init(&a1);
        a1.D_ADHESION  = 3;
        EurobaliseTelegram_Add(&t, &a1.header);
        printf("telegram size of t = %d\n", EurobaliseTelegram_Size(&t));

        EndOfInformation e;
        EndOfInformation_Init(&e);
        EurobaliseTelegram_Add(&t, &e.header);
        printf("telegram size of t = %d\n", EurobaliseTelegram_Size(&t));

        printf("telegram size of t = %d\n", EurobaliseTelegram_Size(&t));

        // encode
        uint8_t raw[1024];
        Bitstream stream;
        Bitstream_Init(&stream, raw, 1024, 0);

        TelegramHeader_EncodeBit(&stream, &t.header);

        PacketHeader_EncodeBit(&a.header, &stream);
        AdhesionFactor_EncodeBit(&stream, (const AdhesionFactor*)EurobaliseTelegram_Get(&t, 0));

        PacketHeader_EncodeBit(&e.header, &stream);
        EndOfInformation_EncodeBit(&stream, (const EndOfInformation*)EurobaliseTelegram_Get(&t, 1));

        stream.bitpos = 0; // reset

        EurobaliseTelegram u;
        EurobaliseTelegram_Init(&u);
        EurobaliseTelegram_DecodeBit(&u, &stream);

        printf("telegram size of u = %d\n", EurobaliseTelegram_Size(&u));
    }


    return EXIT_SUCCESS;
}

