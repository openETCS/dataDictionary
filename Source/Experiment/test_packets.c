
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
        EurobaliseTelegram t;
        EurobaliseTelegram_Init(&t);

        t.header.Q_UPDOWN = 1;
        //printf("telegram size of t = %d\n", EurobaliseTelegram_Size(&t));
	EurobaliseTelegram_Print(stdout, &t);

        AdhesionFactor a;
        AdhesionFactor_Init(&a);
	a.L_PACKET = 56;
        a.D_ADHESION  = 2;
        EurobaliseTelegram_Add(&t, &a.header);
	EurobaliseTelegram_Print(stdout, &t);

        AdhesionFactor a1;
        AdhesionFactor_Init(&a1);
        a1.L_PACKET = 56;
        a1.D_ADHESION  = 3;
        EurobaliseTelegram_Add(&t, &a1.header);
	EurobaliseTelegram_Print(stdout, &t);

        EndOfInformation e;
        EndOfInformation_Init(&e);
        EurobaliseTelegram_Add(&t, &e.header);
	EurobaliseTelegram_Print(stdout, &t);

        // encode
        uint8_t raw[1024];
        Bitstream stream;
        Bitstream_Init(&stream, raw, 1024, 0);

        TelegramHeader_EncodeBit(&stream, &t.header);

        PacketHeader_EncodeBit(&a.header, &stream);
        AdhesionFactor_EncodeBit(&stream, (AdhesionFactor*)EurobaliseTelegram_Get(&t, 0));

        PacketHeader_EncodeBit(&a1.header, &stream);
        AdhesionFactor_EncodeBit(&stream, (AdhesionFactor*)EurobaliseTelegram_Get(&t, 1));

        PacketHeader_EncodeBit(&e.header, &stream);
        EndOfInformation_EncodeBit(&stream, (EndOfInformation*)EurobaliseTelegram_Get(&t, 2));

        stream.bitpos = 0; // reset

        EurobaliseTelegram u;
        EurobaliseTelegram_Init(&u);
        EurobaliseTelegram_DecodeBit(&u, &stream);

	EurobaliseTelegram_Print(stdout, &u);
    }


    return EXIT_SUCCESS;
}

