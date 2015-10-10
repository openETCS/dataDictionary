
#include <assert.h>
#include "AdhesionFactor.h"
#include "EndOfInformation.h"
#include "PacketFactory.h"
#include "EurobaliseTelegram.h"

int main()
{
    {
        AdhesionFactor a;
        AdhesionFactor_Init(&a);
        AdhesionFactor_Print(stdout, &a);
        printf("\n");

        AdhesionFactor b;
        AdhesionFactor_Init(&b);
        assert(AdhesionFactor_Equal(&a, &b));

        b.D_ADHESION  = 2;
        assert(!AdhesionFactor_Equal(&a, &b));

        PacketHeader header = {71};
        PacketHeader* base = PacketFactory_TrackToTrain(header);
        AdhesionFactor* p = (AdhesionFactor*)(base);
        AdhesionFactor_Print(stdout, p);
        printf("\n");
        assert(AdhesionFactor_Equal(&a, p));
        AdhesionFactor_Delete(p);
    }

    {
        // set up test data
        EurobaliseTelegram t;
        EurobaliseTelegram_Init(&t);

        t.header.Q_UPDOWN = 1;

        AdhesionFactor a;
        AdhesionFactor_Init(&a);
        a.D_ADHESION  = 2;
        EurobaliseTelegram_Add(&t, &a.header);

        EndOfInformation e;
        EndOfInformation_Init(&e);
        EurobaliseTelegram_Add(&t, &e.header);

        printf("telegram size of t = %d\n", EurobaliseTelegram_Size(&t));

        // encode
        uint8_t raw[1024];
        Bitstream stream;
        Bitstream_Init(&stream, raw, 1024, 0);

        TelegramHeader_EncodeBit(&stream, &t.header);
        AdhesionFactor_EncodeBit(&stream, (AdhesionFactor*)EurobaliseTelegram_Get(&t, 0));
        EndOfInformation_EncodeBit(&stream, (EndOfInformation*)EurobaliseTelegram_Get(&t, 1));


        EurobaliseTelegram u;
        EurobaliseTelegram_Init(&u);
        EurobaliseTelegram_DecodeBit(&u, &stream);

        printf("telegram size of u = %d\n", EurobaliseTelegram_Size(&u));
    }


    return EXIT_SUCCESS;
}

